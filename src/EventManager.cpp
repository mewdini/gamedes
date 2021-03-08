#include "EventManager.h"
#include <algorithm>

void EventManager::QueueEvent(const EventInterface* event)
{
    register_queue->push_back(event);
}

void EventManager::addDelegate(const EventDelegate& d, const eventType& type)
{
    event_delegates eventList = event_map[type];
    if(eventList.find(d) == eventList.end())
        // not registered yet
        eventList.push_back(d);
}

void EventManager::triggerEvent(const EventInterface& event)
const
{
    auto delegateList = event_map.find(event.getEventType());
    if (delegateList == event_map.end())
        // not found
        return;
    for(auto itr = delegateList.begin();
            itr != delegateList.end();
            itr++)
        (*itr)(event);
}

void EventManager::processEvents(void)
{
    // swap queues
    std::swap(process_queue, register_queue);
    register_queue->clear();
    // process all
    while(!process_queue->empty())
    {
        EventInterface* event = process_queue->front();
        process_queue->pop_front();
        triggerEvent(*event);
    }
}

// game logic calls addDelegate() to 
// actors and player view call queueEvent() to add an event
