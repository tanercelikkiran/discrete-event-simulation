#include "Order.h"

/**
 * Constructor for order
 * @param price Order price
 * @param arrival_time Order arrival time
 * @param order_time Time for the cashier to take the order
 * @param brew_time Order brew time
 */
Order::Order(double new_price, double new_arrival_time, double new_order_time, double new_brew_time) :
    price(new_price), arrival_time(new_arrival_time), order_time(new_order_time), brew_time(new_brew_time) {}

/**
 * @return Order price
 */
double Order::getPrice() const {
    return price;
}

/**
 * @return Order arrival time
 */
double Order::getArrivalTime() const {
    return arrival_time;
}

/**
 * @return Time for the cashier to take the order
 */
double Order::getOrderTime() const {
    return order_time;
}

/**
 * @return Order brew time
 */
double Order::getBrewTime() const {
    return brew_time;
}

/**
 * Setter for finish time
 * @param time Order finish time
 */
void Order::setFinishTime(double time) {
    finish_time = time;
}

/**
 * @return Order turnaround time
 */
double Order::getTurnaroundTime() const {
    return finish_time-arrival_time;
}
