#include "CashierQueue.h"

/**
 * Sends the order to the queue for wait.
 * @param new_order: Order that will wait
 */
void CashierQueue::enqueue(Order *new_order) {
    auto *new_node = new CashierNode;
    new_node->order = new_order;
    new_node->next = nullptr;
    if (head == nullptr || tail == nullptr) {
        head = tail = new_node;
        return;
    }
    tail->next = new_node;
    tail = new_node;
}

/**
 * @return The first order in the queue
 */
Order* CashierQueue::dequeue() {
    if (head == nullptr){
        return nullptr;
    }
    Order *returned_order = head->order;
    CashierNode *temp = head;
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
bool CashierQueue::isEmpty() {
    return head == nullptr;
}

/**
 * Updates the max length of the queue
 */
void CashierQueue::setMaxLength() {
    CashierNode *current_node = head;
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
int CashierQueue::getMaxLength() const {
    return max_length;
}
