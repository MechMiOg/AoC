#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include "functions.h"



int main() {
    // Open the input file
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "Error: Could not open input.txt\n";
        return 1;
    }

    // Process the file and compute the result
    int result = processInput(file);

    // Output the answer
    std::cout << "The answer is: " << result << std::endl;

    return 0;
}
