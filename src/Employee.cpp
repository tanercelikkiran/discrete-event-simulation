#include "Employee.h"

/**
 * Constructor for employee
 */
Employee::Employee(int id_num) : id(id_num){}

/**
 * @return Order the employee is dealing with
 */
Order *Employee::getCurrentOrder() {
    return current_order;
}

/**
 * @return Total working time of the employee
 */
double Employee::getTotalWorkTime() const {
    return work_time;
}

/**
 * @return Employee's id number
 */
int Employee::getId() const {
    return id;
}

/**
 * Sets the employee's order to null
 */
void Employee::finishOrder() {
    current_order = nullptr;
}

/**
 * @return Whether the employee has an order or not
 */
bool Employee::isAvailable() {
    return current_order == nullptr;
}
