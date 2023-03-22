#ifndef AS3_EVENT_QUEUE_H
#define AS3_EVENT_QUEUE_H

#include "Event.h"

/**
 * Node for cashier queue. Keeps event and next node.
 */
struct EventNode{
    /**
     * Node constructor for event queue
     * @param event: Node's event
     */
    explicit EventNode(Event *event);

    Event *event;
    EventNode *next{};
};

class EventQueue {
public:
    EventQueue() = default;
    ~EventQueue() = default;

    void enqueue(Event *);
    Event* dequeue();
    bool isEmpty();
private:
    EventNode* head{};
    EventNode* tail{};
};

#endif //AS3_EVENT_QUEUE_H
