#ifndef AS3_EVENT_H
#define AS3_EVENT_H

#include "Employee.h"

extern double current_time; //This variable measures how many seconds have passed. It is updated at each event transition.

enum EventType {
    order_event, cashier_event, barista_event
};

class Event {
public:
    explicit Event(double, EventType, Order*, Employee*);
    ~Event() = default;

    double getActionTime() const;
    EventType getEventType() const;
    Order* getOrder();
    Employee* getEmployee();
private:
    Order *order{};
    Employee *employee{};
    double action_time;
    EventType event_type;
};

#endif//AS3_EVENT_H
