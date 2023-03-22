#include <string>
#include <vector>
#include <iomanip>
#include <iostream>

#include "Solutions.h"
#include "Cashier.h"
#include "Barista.h"
#include "CashierQueue.h"
#include "BaristaQueue.h"
#include "EventQueue.h"

using namespace std;

/*
 * In this model, the cashier assigns the order to the first available
 * barista after receiving it.
 */
void Solutions::solution_model_1(const string& output_name, const InputStruct& input) {
    //Taking input variables
    int N = input.N;
    vector<Order*> order_list = input.order_list;

    //List of cashiers
    Cashier cashier_list[N];
    //List of baristas
    Barista barista_list[N/3];

    //Assignment of all cashiers and baristas
    for (int i = 0; i < N; i++) {
        Cashier new_cashier;
        cashier_list[i] = new_cashier;
        if (i < N/3) {
            Barista new_barista;
            barista_list[i] = new_barista;
        }
    }

    EventQueue event_queue;

    //Creating events for all orders and sending them to the event queue
    for (Order *order : order_list) {
        auto *new_order_event = new Event(order->getArrivalTime(), order_event, order, nullptr);
        event_queue.enqueue(new_order_event);
    }
    //Queues of cashiers and baristas for orders to wait in line
    CashierQueue cashier_queue;
    BaristaQueue barista_queue;

    //Main loop
    while(!event_queue.isEmpty()) {
        Employee* current_employee;
        Order* current_order;
        Event* event = event_queue.dequeue();

        if (event->getEventType() == order_event) {
            //If event type is order event, that means the first available cashier
            //will take the order. If there isn't any cashier available, order will
            //wait in the cashier queue.
            current_order = event->getOrder();
            bool order_is_not_assigned = true;

            //In this loop, the order will be tried to be assigned
            //to a cashier. If not, it will be sent to the queue.
            for (int i = 0; i < N && order_is_not_assigned; i++) {
                if (cashier_list[i].isAvailable()) {
                    order_is_not_assigned = false;
                    cashier_list[i].assignNewOrder(current_order);
                    auto *new_cashier_event = new Event(current_order->getOrderTime(), cashier_event, nullptr, &cashier_list[i]);
                    event_queue.enqueue(new_cashier_event);
                }
            }
            if (order_is_not_assigned) {
                cashier_queue.enqueue(current_order);
            }
        }
        else if (event->getEventType() == cashier_event){
            // If this is a cashier event, firstly it will check whether there is
            // an order waiting in the queue. If there is an order, the cashier
            // will take the new order from the queue. If there is no order, it will
            // be idle. Then, the order will be directed to the available barista. If there
            // is no barista available, it will be sent to the barista queue.

            current_employee = (Cashier *) event->getEmployee();
            current_order = current_employee->getCurrentOrder();

            if (cashier_queue.isEmpty()) {
                current_employee->finishOrder();
            }
            else {
                Order* next_order = cashier_queue.dequeue();
                current_employee->assignNewOrder(next_order);
                auto *new_cashier_event = new Event(next_order->getOrderTime(), cashier_event, nullptr, current_employee);
                event_queue.enqueue(new_cashier_event);
            }

            //Now, order is received and will be sent to the barista.
            bool order_is_not_assigned = true;

            for (int i = 0; i < N/3 && order_is_not_assigned; i++) {
                if (barista_list[i].isAvailable()) {
                    order_is_not_assigned = false;
                    barista_list[i].assignNewOrder(current_order);
                    auto *new_barista_event = new Event(current_order->getBrewTime(), barista_event, nullptr, &barista_list[i]);
                    event_queue.enqueue(new_barista_event);
                }
            }
            if (order_is_not_assigned) {
                barista_queue.enqueue(current_order);
            }
        }
        else {
            //In the barista event, this time it will be checked whether
            // there is an order waiting in the queue for the barista. If
            // there is a waiting order, this order will be assigned to
            // the barista. If there is no order, the barista will be idle.
            // Finally, the order will be finished and the time the order
            // was completed will be entered.

            current_employee =(Barista *) event->getEmployee();
            current_order = current_employee->getCurrentOrder();

            if (barista_queue.isEmpty()) {
                current_employee->finishOrder();
            }
            else {
                Order* next_order = barista_queue.dequeue();
                current_employee->assignNewOrder(next_order);
                auto *new_barista_event = new Event(next_order->getBrewTime(), barista_event, nullptr, current_employee);
                event_queue.enqueue(new_barista_event);
            }

            //Now, the order is ready.
            current_order->setFinishTime(current_time);
        }
        delete event;
        cashier_queue.setMaxLength();
        barista_queue.setMaxLength();
    }

    ofstream output(output_name);

    output << current_time << fixed << setprecision(2) << "\n";
    output << cashier_queue.getMaxLength() << "\n";
    output << barista_queue.getMaxLength() << "\n";
    for (int i = 0; i < N; i++) {
        output << cashier_list[i].getTotalWorkTime() / current_time << "\n";
    }
    for (int i = 0; i < N/3; i++) {
        output << barista_list[i].getTotalWorkTime() / current_time << "\n";
    }
    for (Order* order : order_list) {
        output << order->getTurnaroundTime() << "\n";
    }
    output << "\n";
    output.close();

    for (Order* order : order_list) {
        order->setFinishTime(0);
    }
    current_time = 0;
}

/*
 * In this model, unlike the first model, the cashier can assign the
 * order to only one barista after receiving it.
 */
void Solutions::solution_model_2(const string& output_name, const InputStruct& input) {
    // Taking input variables
    int N = input.N;
    vector<Order*> order_list = input.order_list;

    // List of cashiers
    Cashier cashier_list[N];
    // List of baristas
    Barista barista_list[N/3];

    // Assignment of all cashiers and baristas
    for (int i = 0; i < N; i++) {
        Cashier new_cashier(i);
        cashier_list[i] = new_cashier;
        if (i < N/3) {
            Barista new_barista(i);
            barista_list[i] = new_barista;
        }
    }

    EventQueue event_queue;

    // Creating events for all orders and sending them to the event queue
    for (Order *order : order_list) {
        auto *new_order_event = new Event(order->getArrivalTime(), order_event, order, nullptr);
        event_queue.enqueue(new_order_event);
    }
    // Queues of cashiers and baristas for orders to wait in line
    CashierQueue cashier_queue;
    BaristaQueue barista_queue[N/3];

    // Main loop
    while(!event_queue.isEmpty()) {
        Employee* current_employee;
        Order* current_order;
        Event* event = event_queue.dequeue();

        if (event->getEventType() == order_event) {

            // If event type is order event, that means the first available cashier
            // will take the order. If there isn't any cashier available, order will
            // wait in the cashier queue.

            current_order = event->getOrder();
            bool order_is_not_assigned = true;

            // In this loop, the order will be tried to be assigned
            // to a cashier. If not, it will be sent to the queue.

            for (int i = 0; i < N && order_is_not_assigned; i++) {
                if (cashier_list[i].isAvailable()) {
                    order_is_not_assigned = false;
                    cashier_list[i].assignNewOrder(current_order);
                    auto *new_cashier_event = new Event(current_order->getOrderTime(), cashier_event, nullptr, &cashier_list[i]);
                    event_queue.enqueue(new_cashier_event);
                }
            }
            if (order_is_not_assigned) {
                cashier_queue.enqueue(current_order);
            }
        }
        else if (event->getEventType() == cashier_event){

            // If this is a cashier event, firstly it will check whether there is
            // an order waiting in the queue. If there is an order, the cashier
            // will take the new order from the queue. If there is no order, it will
            // be idle. Then, the order will be directed to the available barista. If there
            // is no barista available, it will be sent to the barista queue.

            current_employee = (Cashier *) event->getEmployee();
            current_order = current_employee->getCurrentOrder();

            if (cashier_queue.isEmpty()) {
                current_employee->finishOrder();
            }
            else {
                Order* next_order = cashier_queue.dequeue();
                current_employee->assignNewOrder(next_order);
                auto *new_cashier_event = new Event(next_order->getOrderTime(), cashier_event, nullptr, current_employee);
                event_queue.enqueue(new_cashier_event);
            }

            // Now, order is received and will be sent to the barista.
            bool order_is_not_assigned = true;

            for (int i = 0; i < N/3 && order_is_not_assigned; i++) {
                if (barista_list[i].isAvailable()) {
                    order_is_not_assigned = false;
                    barista_list[i].assignNewOrder(current_order);
                    auto *new_barista_event = new Event(current_order->getBrewTime(), barista_event, nullptr, &barista_list[i]);
                    event_queue.enqueue(new_barista_event);
                }
            }
            if (order_is_not_assigned) {
                barista_queue[current_employee->getId() / 3].enqueue(current_order);
            }
        }
        else {

            // In the barista event, this time it will be checked whether
            // there is an order waiting in the queue for the barista. If
            // there is a waiting order, this order will be assigned to
            // the barista. If there is no order, the barista will be idle.
            // Finally, the order will be finished and the time the order
            // was completed will be entered.

            current_employee =(Barista *) event->getEmployee();
            current_order = current_employee->getCurrentOrder();

            if (barista_queue[current_employee->getId()].isEmpty()) {
                current_employee->finishOrder();
            }
            else {
                Order* next_order = barista_queue[current_employee->getId()].dequeue();
                current_employee->assignNewOrder(next_order);
                auto *new_barista_event = new Event(next_order->getBrewTime(), barista_event, nullptr, current_employee);
                event_queue.enqueue(new_barista_event);
            }
            // Now, the order is ready.
            current_order->setFinishTime(current_time);
        }
        delete event;
        cashier_queue.setMaxLength();
        for (int i = 0; i < N/3; i++) {
            barista_queue[i].setMaxLength();
        }
    }

    ofstream output(output_name, ios_base::app);

    output << current_time << fixed << setprecision(2) << "\n";
    output << cashier_queue.getMaxLength() << "\n";
    for (int i = 0; i < N/3; i++) {
        output << barista_queue[i].getMaxLength() << "\n";
    }
    for (int i = 0; i < N; i++) {
        output << cashier_list[i].getTotalWorkTime() / current_time << "\n";
    }
    for (int i = 0; i < N/3; i++) {
        output << barista_list[i].getTotalWorkTime() / current_time << "\n";
    }
    for (Order* order : order_list) {
        output << order->getTurnaroundTime() << "\n";
    }
    output.close();
}