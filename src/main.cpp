#include "Solutions.h"

using namespace std;

int main(int argc, char** argv) {
    InputStruct input = Input::getInput(argv[1]); // Taking the input
    Solutions::solution_model_1(argv[2], input); // First model
    Solutions::solution_model_2(argv[2], input); // Second model
    return 0;
}
