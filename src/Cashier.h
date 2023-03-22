#ifndef AS3_CASHIER_H
#define AS3_CASHIER_H

#include "Employee.h"

class Cashier : public Employee {
public:
    Cashier() = default;
    explicit Cashier(int);
    virtual ~Cashier() = default;

    void assignNewOrder(Order *order) override;
};
#endif//AS3_CASHIER_H
