#include <sstream>
#include "InputReader.h"

using namespace std;

InputStruct::~InputStruct() {
    for (Order *order: order_list) {
      delete order;
    }
}

/**
 * Reads the input file and assigns necessary variables to the input struct
 * @param input_name: Input file's name
 * @return Input struct that contains orders and cashier number
 */
InputStruct Input::getInput(const string &input_name) {
    string line;
    ifstream input(input_name);

    getline(input, line);
    int N = stoi(line);
    getline(input, line);

    vector<Order *> order_list;

    double arrival_time, order_time, brew_time, price;

    while (getline(input, line)) {
        istringstream ss(line);

        ss >> arrival_time >> order_time >> brew_time >> price;

        auto* new_order = new Order(price, arrival_time, order_time, brew_time);
        order_list.push_back(new_order);
    }

    input.close();

    InputStruct input_struct{};
    input_struct.N = N;
    input_struct.order_list = order_list;

    return input_struct;
}
