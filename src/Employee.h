#ifndef AS3_EMPLOYEE_H
#define AS3_EMPLOYEE_H

#include "Order.h"

class Employee {
protected:
    int id{};
    Order *current_order{};
    double work_time{};
public:
    Employee() = default;
    explicit Employee(int);
    ~Employee() = default;

    Order* getCurrentOrder();
    double getTotalWorkTime() const;
    int getId() const;

    virtual void assignNewOrder(Order *) = 0; //pure virtual
    void finishOrder();
    bool isAvailable();
};

#endif//AS3_EMPLOYEE_H
