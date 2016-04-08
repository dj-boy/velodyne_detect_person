#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sensor_msgs/PointCloud2.h>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/console/print.h>
#include <pcl/console/parse.h>
#include <pcl/console/time.h>
#include <pcl/common/boost.h>
#include <pcl/common/centroid.h>
#include <vector>
#include <pcl_ros/point_cloud.h>
#include "geometry_msgs/Point.h"
#include <boost/shared_ptr.hpp>
#include "velodyne_detect_person/pointCloudVector.h"
#include <tf/transform_listener.h>
#include "Ice/Ice.h"
#include "../include/PersonPosition.h"

using namespace RoboCompPersonPosition;
using namespace std;

typedef pcl::PointCloud<pcl::PointXYZ> PointCloud;
sensor_msgs::PointCloud2::Ptr backgroundCloud (new sensor_msgs::PointCloud2);
pcl::PointCloud< pcl::PointXYZ > backgroundCloudPCL;
pcl::PointCloud< pcl::PointXYZ > clusterPCL;
int backgroundSize = 0; //Number of points in background cloud
bool backgroundGrid[100][100][30];
Eigen::Vector4f centroid;
geometry_msgs::PointStamped personCentroid;
geometry_msgs::PointStamped personCentroidTransformed;
MapPose detectedPersonPose; //TODO: This will probably fail. MapPose defined in .ice file or .h file


void transformPersonPosition (const tf::TransformListener& listener){
	personCentroid.header.frame_id = "velodyne";
	personCentroid.header.stamp = ros::Time();
	try{
    listener.transformPoint("world", personCentroid, personCentroidTransformed);

    ROS_INFO("personCentroid: (%.2f, %.2f, %.2f) -----> personCentroidTransformed: (%.2f, %.2f, %.2f)",
     	personCentroid.point.x, personCentroid.point.y, personCentroid.point.z,
    	personCentroidTransformed.point.x, personCentroidTransformed.point.y,
    	personCentroidTransformed.point.z);
  }
  catch(tf::TransformException& ex){
  	ROS_ERROR("Received an exception trying to transform a point from \"personCentroid\" to 		\"personCentroidTransformed\": %s", ex.what());
  }
}

class FindPerson
{
  protected:
    ros::NodeHandle n;
  public:
    ros::Publisher pub = n.advertise<sensor_msgs::PointCloud2> ("person_cloud", 1);
    ros::Publisher pub2 = n.advertise<geometry_msgs::PointStamped> ("person_position", 1);
    ros::Subscriber subBackground;
    ros::Subscriber subClusters;
    tf::TransformListener listener;
    Ice::CommunicatorPtr ic;
    
	//Set background cloud in a global variable. One message every X seconds
	void findPersonBackgroundCallback(const boost::shared_ptr<sensor_msgs::PointCloud2>& inputBackgroundCloud)
	{
		backgroundCloud = inputBackgroundCloud;
		pcl::fromROSMsg(*backgroundCloud,backgroundCloudPCL);
		backgroundSize = backgroundCloud->width;
		
		
		pcl::PointCloud<pcl::PointXYZ>::iterator it;
		for(it = backgroundCloudPCL.points.begin(); it < backgroundCloudPCL.points.end(); it++)
		{
			if (-5 <= it->x && it->x < 5 && -5 <= it->y && it->y < 5 && -1.5 <= it->z && it->z < 1.5)
     	{
				backgroundGrid[int((it->x)*10+50)][int((it->y)*10+50)][int((it->z)*10+15)] = true;
			}
		}	
	}
	
	
	//Receive data and perform the actual person detection. Lots of messages every second
	void findPersonClustersCallback(const boost::shared_ptr<velodyne_detect_person::pointCloudVector>& clusterVector)
	{
		pcl::PointCloud<pcl::PointXYZ>::Ptr clustersCloud (new pcl::PointCloud<pcl::PointXYZ>); //Contains every person cluster and is visible in rviz
		pcl::PointCloud<pcl::PointXYZ> auxiliarCluster;
		sensor_msgs::PointCloud2::Ptr clustersCloudRos (new sensor_msgs::PointCloud2);
		personCentroid.point.x = 0;
		personCentroid.point.y = 0;
	
	
		if(backgroundSize == 0) {
			std::cout << "I need a background cloud!" << std::endl;
		}
		else {		
			//For each cluster
			for(int i = 0; i < clusterVector->pointCloudVector.size(); i++) {
				int clusterPoints = clusterVector->pointCloudVector[i].width;  //cluster size
				int numCoincidentPoints = 0;
				pcl::fromROSMsg(clusterVector->pointCloudVector[i],clusterPCL);
				
				//Add 1 to counter if a point is in cluster and background
				for(int pointCluster = 0; pointCluster < clusterPoints; pointCluster++) {
					if (-5 <= clusterPCL.points[pointCluster].x &&
				  	clusterPCL.points[pointCluster].x < 5 &&
					  -5 <= clusterPCL.points[pointCluster].y &&
					  clusterPCL.points[pointCluster].y < 5 &&
					  -1.5 <= clusterPCL.points[pointCluster].z &&
					  clusterPCL.points[pointCluster].z < 1.5)
     			{								
						if(backgroundGrid[int((clusterPCL.points[pointCluster].x)*10+50)][int((clusterPCL.points[pointCluster].y)*10+50)][int((clusterPCL.points[pointCluster].z)*10+15)] == true){
							numCoincidentPoints++;
						}	
					}		
				}
				
				//If cluster is not in background (coincident points < 20%), the cluster is a person
				if(float(float(numCoincidentPoints)/float(clusterPoints)) < 0.2){
					pcl::fromROSMsg(clusterVector->pointCloudVector[i],auxiliarCluster);
					*clustersCloud += auxiliarCluster;
					
					//Save the position of the last person seen. This position will be sent to the robot
					pcl::compute3DCentroid(clusterPCL, centroid);
					personCentroid.point.x = centroid(0,0);
					personCentroid.point.y = centroid(1,0);
					personCentroid.point.z = 0;
					personCentroid.header.stamp = ros::Time();
				}
			
			}
			pcl::toROSMsg (*clustersCloud , *clustersCloudRos);
	  	clustersCloudRos->header.frame_id = "/velodyne";
	  	clustersCloudRos->header.stamp = ros::Time::now();
			
			pub.publish (clustersCloudRos);
			
			//Publish person position only when someone is found
			if(personCentroid.point.x != 0 || personCentroid.point.y != 0){
				//Transform position into world frame
				transformPersonPosition(listener);
				pub2.publish (personCentroid);
				detectedPersonPose.x = personCentroid.point.x;
				detectedPersonPose.y = personCentroid.point.y;
				
				
				Ice::CommunicatorPtr ic;
				try {
					ic = Ice::initialize();
					Ice::ObjectPrx base = ic->stringToProxy("PersonPositionTopic.Endpoints:default -p 10000");
					personPositionPrx personPosition = personPositionPrx::checkedCast(base);
					if (!personPosition)
						throw "Invalid proxy";
					personPosition->personPose(detectedPersonPose);
				} catch (const Ice::Exception& ex) {
					cerr << ex << endl;
				} catch (const char* msg) {
					cerr << msg << endl;
				}
				if (ic)
					ic->destroy();
				
			}
		
		}
	}
	
	FindPerson()
    {
      subBackground = n.subscribe("scene_background", 1, &FindPerson::findPersonBackgroundCallback, this);
      subClusters = n.subscribe("scene_clusters", 1, &FindPerson::findPersonClustersCallback, this);
    }
};



int main(int argc, char **argv)
{
  ros::init(argc, argv, "find_person");
  //ros::NodeHandle n;
  
  FindPerson findP;
  
  //we'll transform a point once every second
  //ros::Timer timer = n.createTimer(ros::Duration(1.0), boost::bind(&transformPoint, boost::ref(listener)));
  
  ros::spin();

  return 0;
}

