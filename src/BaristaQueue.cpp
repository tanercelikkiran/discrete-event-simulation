#include "BaristaQueue.h"

/**
 * Sends the order to the queue for wait.
 * @param new_order: Order that will wait
 */
void BaristaQueue::enqueue(Order *new_order) {
    auto *new_node = new BaristaNode;
    new_node->order = new_order;

    if (head == nullptr) {
        head = tail = new_node;
        return;
    }
    if (head->order->getPrice() < new_node->order->getPrice()) {
        new_node->next = head;
        head = new_node;
    }
    else {
        BaristaNode *current_node = head;
        while (current_node->next != nullptr
               && current_node->next->order->getPrice() > new_node->order->getPrice())
            current_node = current_node->next;

        new_node->next = current_node->next;
        current_node->next = new_node;
        if (current_node == tail) {
            tail = new_node;
        }
    }
}

/**
 * @return The first order in the queue
 */
Order *BaristaQueue::dequeue() {
    Order *returned_order = head->order;
    BaristaNode *temp = head;
    head = head->next;
    if (head == nullptr) {
        tail = nullptr;
    }
    delete temp;
    return returned_order;
}

/**
 * @return Whether the queue has node or not
 */
bool BaristaQueue::isEmpty() {
    return head == nullptr;
}

/**
 * Updates the max length of the queue
 */
void BaristaQueue::setMaxLength() {
    BaristaNode *current_node = head;
    int current_length = 0;
    while (current_node != nullptr) {
        current_length++;
        current_node = current_node->next;
    }
    max_length = current_length > max_length ? current_length : max_length;
}

/**
 * @return Mex length of the queue
 */
int BaristaQueue::getMaxLength() const {
    return max_length;
}

