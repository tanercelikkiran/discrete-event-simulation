#ifndef AS3_INPUT_OUTPUT_H
#define AS3_INPUT_OUTPUT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Order.h"

using namespace std;

/**
 * Struct for input. Keeps orders in vector and cashier number
 */
struct InputStruct {
    int N;
    vector<Order *> order_list;

    ~InputStruct();
};

namespace Input {
    InputStruct getInput(const string&);
}

#endif //AS3_INPUT_OUTPUT_H