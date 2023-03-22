#ifndef AS3_BARISTA_QUEUE_H
#define AS3_BARISTA_QUEUE_H

#include "Order.h"

/**
 * Node for barista queue. Keeps order and next node.
 */
struct BaristaNode {
    Order* order{};
    BaristaNode* next{};
};

class BaristaQueue {
public:
    BaristaQueue() = default;
    ~BaristaQueue() = default;

    void enqueue(Order *);
    Order* dequeue();
    bool isEmpty();
    void setMaxLength();
    int getMaxLength() const;
private:
    int max_length{};
    BaristaNode *head{};
    BaristaNode *tail{};
};

#endif //AS3_BARISTA_QUEUE_H
