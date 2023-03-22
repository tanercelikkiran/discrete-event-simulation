#include "Cashier.h"

/**
 * Constructor for cashier
 */
Cashier::Cashier(int id_num) : Employee(id_num){}

/**
 * Assigns the new order to the cashier and updates the total working time
 * @param order New order
 */
void Cashier::assignNewOrder(Order *order) {
    work_time += order->getOrderTime();
    current_order = order;
}
