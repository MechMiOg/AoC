#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "functions.h"



int main() {
    std::ifstream file("input.txt");

    if (!file.is_open()){
        std::cout << "error \n";
        return 1; 
    }

    std::vector<std::string> grid;
    std::string line;

    // Branje vhodne mreže do EOF
    while (std::getline(file, line)) {
        grid.push_back(line);
    }

    int result = countRemovableRolls(grid);

    std::cout << result << std::endl;
    return 0;
}
