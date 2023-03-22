#ifndef AS3_CASHIER_QUEUE_H
#define AS3_CASHIER_QUEUE_H

#include "Order.h"

/**
 * Node for cashier queue. Keeps order and next node.
 */
struct CashierNode {
    Order *order{};
    CashierNode* next{};
};

class CashierQueue {
public:
    CashierQueue() = default;
    ~CashierQueue() = default;

    int getMaxLength() const;
    void setMaxLength();

    void enqueue(Order *);
    Order* dequeue();
    bool isEmpty();

private:
    int max_length{};
    CashierNode *head{};
    CashierNode *tail{};
};

#endif //AS3_CASHIER_QUEUE_H
