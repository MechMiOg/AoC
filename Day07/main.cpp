#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "functions.h"




int main() {

    auto grid = readGrid();
    long long result = countTimelines(grid);
    std::cout << result << std::endl;
    return 0;
}

