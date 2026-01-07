#include <iostream>
#include <fstream>
#include <vector>
#include "functions.h"  



int main()
{
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "error\n";
        return 1;
    }

    const auto points = readPoints(file);

    const long long largest = largestRectangleArea(points);

    std::cout << largest << '\n';
    return 0;
}
