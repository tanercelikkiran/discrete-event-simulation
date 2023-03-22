#include "Barista.h"

/**
 * Constructor for barista
 */
Barista::Barista(int id_num) : Employee(id_num) {}

/**
 * Assigns the new order to the barista and updates the total working time
 * @param order New order
 */
void Barista::assignNewOrder(Order *order) {
    work_time += order->getBrewTime();
    current_order = order;
}