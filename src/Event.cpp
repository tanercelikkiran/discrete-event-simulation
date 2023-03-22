#include "Event.h"

double current_time = 0.0; //Initially, equals to zero.

/**
 * Constructor for event
 * @param time: It's the end of the event. Depends on what the event is. Sum with current_time to get the end time of the event.
 * @param type: Event type
 * @param current_order: Event's order
 * @param current_employee: Event's employee
 */
Event::Event(double time, EventType type, Order* current_order, Employee* current_employee) {
    action_time = current_time + time;
    event_type = type;
    order = current_order;
    employee = current_employee;
}

/**
 * @return Action time
 */
double Event::getActionTime() const {
    return action_time;
}

/**
 * @return Event's type
 */
EventType Event::getEventType() const {
    return event_type;
}

/**
 * @return Event's order
 */
Order* Event::getOrder() {
    return order;
}

/**
 * @return Event's employee
 */
Employee* Event::getEmployee() {
    return employee;
}


