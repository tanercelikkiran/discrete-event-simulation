#ifndef AS3_BARISTA_H
#define AS3_BARISTA_H

#include "Employee.h"

class Barista : public Employee{
public:
    Barista() = default;
    explicit Barista(int);
    virtual ~Barista() = default;

    void assignNewOrder(Order *order) override;
};

#endif//AS3_BARISTA_H
