#ifndef AS3_ORDER_H
#define AS3_ORDER_H

class Order {
private:
    double price, arrival_time, order_time, brew_time, finish_time{};
public:
    explicit Order(double , double , double , double);
    ~Order() = default;

    double getPrice() const;
    double getArrivalTime() const;
    double getOrderTime() const;
    double getBrewTime() const;
    void setFinishTime(double);
    double getTurnaroundTime() const;
};
#endif//AS3_ORDER_H
