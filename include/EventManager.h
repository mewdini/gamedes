//Edited by Yixuan Xu on 02/28

#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <list>
#include <map>

typedef std::list<EventInterface*> event_queue;
typedef std::list<EventDelegate> event_delegates;
typedef std::map<EventType, event_delegates> event_map;

class EventManager
{
    public:
        event_queue queues[2];
        event_queue* process_queue = &queues[0];
        event_queue* register_queue = &queues[1];
        virtual void QueueEvent(const EventInterface*);
        virtual void addDelegate(const EventDelegate& d, const EventType& type);
        virtual void triggerEvent(const EventInterface& event) const;
        virtual void processEvents(void);
};


#endif /* EVENTMANAGER_H */