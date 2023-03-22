#include "EventQueue.h"

EventNode::EventNode(Event *event) : event(event) {}

/**
 * Sends the order to the queue for wait.
 * @param new_event: Event that will wait
 */
void EventQueue::enqueue(Event *new_event) {
    auto *new_node = new EventNode(new_event);
    new_node->event = new_event;

    if (head == nullptr) {
        head = tail = new_node;
        return;
    }
    if (head->event->getActionTime() > new_node->event->getActionTime()) {
        new_node->next = head;
        head = new_node;
    }
    else {
        EventNode *current_node = head;
        while (current_node->next != nullptr && current_node->next->event->getActionTime() < new_node->event->getActionTime())
            current_node = current_node->next;

        new_node->next = current_node->next;
        current_node->next = new_node;
        if (current_node == tail) {
            tail = new_node;
        }
    }
}

/**
 * @return The first event in the queue
 */
Event* EventQueue::dequeue() {
    Event* returned_event = head->event;
    current_time = returned_event->getActionTime();
    EventNode *temp = head;
    head = head->next;
    if (head == nullptr) {
        tail = nullptr;
    }
    delete temp;
    return returned_event;
}

/**
 * @return Whether the queue has node or not
 */
bool EventQueue::isEmpty() {
    return head == nullptr;
}
