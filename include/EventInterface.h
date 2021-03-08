#ifndef EVENTINTERFACE_H
#define EVENTINTERFACE_H

#include <iostream>

class EventInterface
{
    public:
        virtual const EventType& getEventType(void) const = 0;
        virtual float GetTimeStamp(void) const = 0;
        virtual Serialize(const std::ostream& o) const = 0;
        virtual EventDataInterface* Copy(void) const = 0; 
};

#endif /* EVENTINTERFACE_H */

/*
How to make events from this template:

class SomeEvent : public EventInterface
{
public:
    static const EventType eventType;
}

const EventType SomeEvent::eventType = EventType(&SomeEvent::eventType);

We use this instead of enums for custom events
Example:

class ActorDestroyedEvent : public baseEvent
{
    ActorId id;
public
    static const EventType eventType;

    explicit ActorDestroyedEvent(ActorId i) : id(i) {}
    explicit ActorDestroyedEvent(std::istream& i) { i >> id; }

    virtual const EventType& getEventType(void) const { return eventType; }
    virtual EventDataInterface* copy(void) const { … }
    virtual void Serialize(std::ostream& o) { o << id; }
    ActorId getId(void) const { return id; }
}

const EventType ActorDestroyedEvent::eventType = EventType(&ActorDestroyedEvent::eventType);
*/

// event_object_moved,
// event_object_created,
// …
// event_object_destroyed,
