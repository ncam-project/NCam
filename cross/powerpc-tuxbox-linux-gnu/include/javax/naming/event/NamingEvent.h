// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_naming_event_NamingEvent__
#define __javax_naming_event_NamingEvent__

#pragma interface

#include <java/util/EventObject.h>

extern "Java"
{
  namespace javax
  {
    namespace naming
    {
      namespace event
      {
        class NamingEvent;
        class NamingListener;
        class EventContext;
      }
      class Binding;
    }
  }
}

class javax::naming::event::NamingEvent : public ::java::util::EventObject
{
public:
  NamingEvent (::javax::naming::event::EventContext *, jint, ::javax::naming::Binding *, ::javax::naming::Binding *, ::java::lang::Object *);
  virtual jint getType () { return type; }
  virtual ::javax::naming::event::EventContext *getEventContext ();
  virtual ::javax::naming::Binding *getOldBinding () { return oldBinding; }
  virtual ::javax::naming::Binding *getNewBinding () { return newBinding; }
  virtual ::java::lang::Object *getChangeInfo () { return changeInfo; }
  virtual void dispatch (::javax::naming::event::NamingListener *);
  static const jint OBJECT_ADDED = 0L;
  static const jint OBJECT_REMOVED = 1L;
  static const jint OBJECT_RENAMED = 2L;
  static const jint OBJECT_CHANGED = 3L;
public:  // actually protected
  ::java::lang::Object * __attribute__((aligned(__alignof__( ::java::util::EventObject )))) changeInfo;
  jint type;
  ::javax::naming::Binding *oldBinding;
  ::javax::naming::Binding *newBinding;
public:

  static ::java::lang::Class class$;
};

#endif /* __javax_naming_event_NamingEvent__ */