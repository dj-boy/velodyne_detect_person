// **********************************************************************
//
// Copyright (c) 2003-2013 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************
//
// Ice version 3.5.1
//
// <auto-generated>
//
// Generated from file `PersonPosition.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef __PersonPosition_h__
#define __PersonPosition_h__

#include <Ice/ProxyF.h>
#include <Ice/ObjectF.h>
#include <Ice/Exception.h>
#include <Ice/LocalObject.h>
#include <Ice/StreamHelpers.h>
#include <Ice/Proxy.h>
#include <Ice/Object.h>
#include <Ice/Outgoing.h>
#include <Ice/OutgoingAsync.h>
#include <Ice/Incoming.h>
#include <Ice/Direct.h>
#include <IceUtil/ScopedArray.h>
#include <IceUtil/Optional.h>
#include <Ice/StreamF.h>
#include <Ice/UndefSysMacros.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 305
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 > 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 1
#       error Ice patch level mismatch!
#   endif
#endif

namespace IceProxy
{

namespace RoboCompPersonPosition
{

class personPosition;
void __read(::IceInternal::BasicStream*, ::IceInternal::ProxyHandle< ::IceProxy::RoboCompPersonPosition::personPosition>&);
::IceProxy::Ice::Object* upCast(::IceProxy::RoboCompPersonPosition::personPosition*);

}

}

namespace RoboCompPersonPosition
{

class personPosition;
bool operator==(const personPosition&, const personPosition&);
bool operator<(const personPosition&, const personPosition&);
::Ice::Object* upCast(::RoboCompPersonPosition::personPosition*);
typedef ::IceInternal::Handle< ::RoboCompPersonPosition::personPosition> personPositionPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::RoboCompPersonPosition::personPosition> personPositionPrx;
void __patch(personPositionPtr&, const ::Ice::ObjectPtr&);

}

namespace RoboCompPersonPosition
{

struct MapPose
{
    ::Ice::Double x;
    ::Ice::Double y;
};

}

namespace Ice
{
template<>
struct StreamableTraits< ::RoboCompPersonPosition::MapPose>
{
    static const StreamHelperCategory helper = StreamHelperCategoryStruct;
    static const int minWireSize = 16;
    static const bool fixedLength = true;
};

template<class S>
struct StreamWriter< ::RoboCompPersonPosition::MapPose, S>
{
    static void write(S* __os, const ::RoboCompPersonPosition::MapPose& v)
    {
        __os->write(v.x);
        __os->write(v.y);
    }
};

template<class S>
struct StreamReader< ::RoboCompPersonPosition::MapPose, S>
{
    static void read(S* __is, ::RoboCompPersonPosition::MapPose& v)
    {
        __is->read(v.x);
        __is->read(v.y);
    }
};

}

namespace RoboCompPersonPosition
{

class Callback_personPosition_personPose_Base : virtual public ::IceInternal::CallbackBase { };
typedef ::IceUtil::Handle< Callback_personPosition_personPose_Base> Callback_personPosition_personPosePtr;

}

namespace IceProxy
{

namespace RoboCompPersonPosition
{

class personPosition : virtual public ::IceProxy::Ice::Object
{
public:

    void personPose(const ::RoboCompPersonPosition::MapPose& personPosition)
    {
        personPose(personPosition, 0);
    }
    void personPose(const ::RoboCompPersonPosition::MapPose& personPosition, const ::Ice::Context& __ctx)
    {
        personPose(personPosition, &__ctx);
    }
#ifdef ICE_CPP11
    ::Ice::AsyncResultPtr
    begin_personPose(const ::RoboCompPersonPosition::MapPose& personPosition, const ::IceInternal::Function<void ()>& __response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& __exception = ::IceInternal::Function<void (const ::Ice::Exception&)>(), const ::IceInternal::Function<void (bool)>& __sent = ::IceInternal::Function<void (bool)>())
    {
        return begin_personPose(personPosition, 0, new ::IceInternal::Cpp11FnOnewayCallbackNC(__response, __exception, __sent));
    }
    ::Ice::AsyncResultPtr
    begin_personPose(const ::RoboCompPersonPosition::MapPose& personPosition, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& __completed, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& __sent = ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>())
    {
        return begin_personPose(personPosition, 0, ::Ice::newCallback(__completed, __sent), 0);
    }
    ::Ice::AsyncResultPtr
    begin_personPose(const ::RoboCompPersonPosition::MapPose& personPosition, const ::Ice::Context& __ctx, const ::IceInternal::Function<void ()>& __response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& __exception = ::IceInternal::Function<void (const ::Ice::Exception&)>(), const ::IceInternal::Function<void (bool)>& __sent = ::IceInternal::Function<void (bool)>())
    {
        return begin_personPose(personPosition, &__ctx, new ::IceInternal::Cpp11FnOnewayCallbackNC(__response, __exception, __sent), 0);
    }
    ::Ice::AsyncResultPtr
    begin_personPose(const ::RoboCompPersonPosition::MapPose& personPosition, const ::Ice::Context& __ctx, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& __completed, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& __sent = ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>())
    {
        return begin_personPose(personPosition, &__ctx, ::Ice::newCallback(__completed, __sent));
    }
#endif

    ::Ice::AsyncResultPtr begin_personPose(const ::RoboCompPersonPosition::MapPose& personPosition)
    {
        return begin_personPose(personPosition, 0, ::IceInternal::__dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_personPose(const ::RoboCompPersonPosition::MapPose& personPosition, const ::Ice::Context& __ctx)
    {
        return begin_personPose(personPosition, &__ctx, ::IceInternal::__dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_personPose(const ::RoboCompPersonPosition::MapPose& personPosition, const ::Ice::CallbackPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_personPose(personPosition, 0, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_personPose(const ::RoboCompPersonPosition::MapPose& personPosition, const ::Ice::Context& __ctx, const ::Ice::CallbackPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_personPose(personPosition, &__ctx, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_personPose(const ::RoboCompPersonPosition::MapPose& personPosition, const ::RoboCompPersonPosition::Callback_personPosition_personPosePtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_personPose(personPosition, 0, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_personPose(const ::RoboCompPersonPosition::MapPose& personPosition, const ::Ice::Context& __ctx, const ::RoboCompPersonPosition::Callback_personPosition_personPosePtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_personPose(personPosition, &__ctx, __del, __cookie);
    }

    void end_personPose(const ::Ice::AsyncResultPtr&);
    
private:

    void personPose(const ::RoboCompPersonPosition::MapPose&, const ::Ice::Context*);
    ::Ice::AsyncResultPtr begin_personPose(const ::RoboCompPersonPosition::MapPose&, const ::Ice::Context*, const ::IceInternal::CallbackBasePtr&, const ::Ice::LocalObjectPtr& __cookie = 0);
    
public:
    
    ::IceInternal::ProxyHandle<personPosition> ice_context(const ::Ice::Context& __context) const
    {
        return dynamic_cast<personPosition*>(::IceProxy::Ice::Object::ice_context(__context).get());
    }
    
    ::IceInternal::ProxyHandle<personPosition> ice_adapterId(const ::std::string& __id) const
    {
        return dynamic_cast<personPosition*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    }
    
    ::IceInternal::ProxyHandle<personPosition> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
        return dynamic_cast<personPosition*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    }
    
    ::IceInternal::ProxyHandle<personPosition> ice_locatorCacheTimeout(int __timeout) const
    {
        return dynamic_cast<personPosition*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    }
    
    ::IceInternal::ProxyHandle<personPosition> ice_connectionCached(bool __cached) const
    {
        return dynamic_cast<personPosition*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    }
    
    ::IceInternal::ProxyHandle<personPosition> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
        return dynamic_cast<personPosition*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    }
    
    ::IceInternal::ProxyHandle<personPosition> ice_secure(bool __secure) const
    {
        return dynamic_cast<personPosition*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    }
    
    ::IceInternal::ProxyHandle<personPosition> ice_preferSecure(bool __preferSecure) const
    {
        return dynamic_cast<personPosition*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    }
    
    ::IceInternal::ProxyHandle<personPosition> ice_router(const ::Ice::RouterPrx& __router) const
    {
        return dynamic_cast<personPosition*>(::IceProxy::Ice::Object::ice_router(__router).get());
    }
    
    ::IceInternal::ProxyHandle<personPosition> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
        return dynamic_cast<personPosition*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    }
    
    ::IceInternal::ProxyHandle<personPosition> ice_collocationOptimized(bool __co) const
    {
        return dynamic_cast<personPosition*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    }
    
    ::IceInternal::ProxyHandle<personPosition> ice_twoway() const
    {
        return dynamic_cast<personPosition*>(::IceProxy::Ice::Object::ice_twoway().get());
    }
    
    ::IceInternal::ProxyHandle<personPosition> ice_oneway() const
    {
        return dynamic_cast<personPosition*>(::IceProxy::Ice::Object::ice_oneway().get());
    }
    
    ::IceInternal::ProxyHandle<personPosition> ice_batchOneway() const
    {
        return dynamic_cast<personPosition*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    }
    
    ::IceInternal::ProxyHandle<personPosition> ice_datagram() const
    {
        return dynamic_cast<personPosition*>(::IceProxy::Ice::Object::ice_datagram().get());
    }
    
    ::IceInternal::ProxyHandle<personPosition> ice_batchDatagram() const
    {
        return dynamic_cast<personPosition*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    }
    
    ::IceInternal::ProxyHandle<personPosition> ice_compress(bool __compress) const
    {
        return dynamic_cast<personPosition*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    }
    
    ::IceInternal::ProxyHandle<personPosition> ice_timeout(int __timeout) const
    {
        return dynamic_cast<personPosition*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    }
    
    ::IceInternal::ProxyHandle<personPosition> ice_connectionId(const ::std::string& __id) const
    {
        return dynamic_cast<personPosition*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
    }
    
    ::IceInternal::ProxyHandle<personPosition> ice_encodingVersion(const ::Ice::EncodingVersion& __v) const
    {
        return dynamic_cast<personPosition*>(::IceProxy::Ice::Object::ice_encodingVersion(__v).get());
    }
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

}

}

namespace IceDelegate
{

namespace RoboCompPersonPosition
{

class personPosition : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual void personPose(const ::RoboCompPersonPosition::MapPose&, const ::Ice::Context*, ::IceInternal::InvocationObserver&) = 0;
};

}

}

namespace IceDelegateM
{

namespace RoboCompPersonPosition
{

class personPosition : virtual public ::IceDelegate::RoboCompPersonPosition::personPosition,
                       virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual void personPose(const ::RoboCompPersonPosition::MapPose&, const ::Ice::Context*, ::IceInternal::InvocationObserver&);
};

}

}

namespace IceDelegateD
{

namespace RoboCompPersonPosition
{

class personPosition : virtual public ::IceDelegate::RoboCompPersonPosition::personPosition,
                       virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual void personPose(const ::RoboCompPersonPosition::MapPose&, const ::Ice::Context*, ::IceInternal::InvocationObserver&);
};

}

}

namespace RoboCompPersonPosition
{

class personPosition : virtual public ::Ice::Object
{
public:

    typedef personPositionPrx ProxyType;
    typedef personPositionPtr PointerType;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual void personPose(const ::RoboCompPersonPosition::MapPose&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___personPose(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

protected:
    virtual void __writeImpl(::IceInternal::BasicStream*) const;
    virtual void __readImpl(::IceInternal::BasicStream*);
    #ifdef __SUNPRO_CC
    using ::Ice::Object::__writeImpl;
    using ::Ice::Object::__readImpl;
    #endif
};

inline bool operator==(const personPosition& l, const personPosition& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

inline bool operator<(const personPosition& l, const personPosition& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

}

namespace RoboCompPersonPosition
{

template<class T>
class CallbackNC_personPosition_personPose : public Callback_personPosition_personPose_Base, public ::IceInternal::OnewayCallbackNC<T>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception&);
    typedef void (T::*Sent)(bool);
    typedef void (T::*Response)();

    CallbackNC_personPosition_personPose(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::OnewayCallbackNC<T>(obj, cb, excb, sentcb)
    {
    }
};

template<class T> Callback_personPosition_personPosePtr
newCallback_personPosition_personPose(const IceUtil::Handle<T>& instance, void (T::*cb)(), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_personPosition_personPose<T>(instance, cb, excb, sentcb);
}

template<class T> Callback_personPosition_personPosePtr
newCallback_personPosition_personPose(const IceUtil::Handle<T>& instance, void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_personPosition_personPose<T>(instance, 0, excb, sentcb);
}

template<class T> Callback_personPosition_personPosePtr
newCallback_personPosition_personPose(T* instance, void (T::*cb)(), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_personPosition_personPose<T>(instance, cb, excb, sentcb);
}

template<class T> Callback_personPosition_personPosePtr
newCallback_personPosition_personPose(T* instance, void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_personPosition_personPose<T>(instance, 0, excb, sentcb);
}

template<class T, typename CT>
class Callback_personPosition_personPose : public Callback_personPosition_personPose_Base, public ::IceInternal::OnewayCallback<T, CT>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception& , const CT&);
    typedef void (T::*Sent)(bool , const CT&);
    typedef void (T::*Response)(const CT&);

    Callback_personPosition_personPose(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::OnewayCallback<T, CT>(obj, cb, excb, sentcb)
    {
    }
};

template<class T, typename CT> Callback_personPosition_personPosePtr
newCallback_personPosition_personPose(const IceUtil::Handle<T>& instance, void (T::*cb)(const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_personPosition_personPose<T, CT>(instance, cb, excb, sentcb);
}

template<class T, typename CT> Callback_personPosition_personPosePtr
newCallback_personPosition_personPose(const IceUtil::Handle<T>& instance, void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_personPosition_personPose<T, CT>(instance, 0, excb, sentcb);
}

template<class T, typename CT> Callback_personPosition_personPosePtr
newCallback_personPosition_personPose(T* instance, void (T::*cb)(const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_personPosition_personPose<T, CT>(instance, cb, excb, sentcb);
}

template<class T, typename CT> Callback_personPosition_personPosePtr
newCallback_personPosition_personPose(T* instance, void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_personPosition_personPose<T, CT>(instance, 0, excb, sentcb);
}

}

#endif
