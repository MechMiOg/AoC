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
    std::getline(file, line);
    file.close();

    std::vector<std::pair<long long, long long>> ranges;
    parseRanges(line, ranges);

    std::vector<long long> invalids = collectInvalid(ranges);

    long long result = sumAll(invalids);

    std::cout << "sum: " << result << "\n";


    return 0;
}
