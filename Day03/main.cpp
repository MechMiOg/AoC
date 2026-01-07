#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include "functions.h"



int main() {
    std::ifstream file("input.txt");

    if (!file.is_open()){
        std::cout << "error \n";
        return 1; 
    }

    std::string line;
    long long allNumbers = 0;  // vsota največjih dvomestnih števil za vsako vrstice

    while (std::getline(file, line)) {
    
        std::string number = maxTwelveDigits(line);
        allNumbers += std::stoll(number);
    }

    std::cout << allNumbers << '\n';


    return 0;
}
