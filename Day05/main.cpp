#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "functions.h"



// int main() {
//     std::ifstream file("input.txt");

//     if (!file.is_open()){
//         std::cout << "error \n";
//         return 1; 
//     }

  
//     std::vector<long long> availableIDs;
//     std::vector<Range> ranges;
//     std::string line;

//     // prvi del – beremo range
//     while (std::getline(file, line)) {
//         if (line.empty())
//             break;

//         ranges.push_back(parseRange(line));   // tukaj uporabimo funkcijo parseRange
//     }

//     // drugi del — bere naprej od iste pozicije v datoteki
//     while (std::getline(file, line)) {
//         if (!line.empty())
//             availableIDs.push_back(std::stoll(line));
//     }


//     int result = countFreshIDs(availableIDs, ranges);

//     std::cout << result << std::endl;
//     return 0;
// }


// part two

int main() {
    std::ifstream file("input.txt");

    if (!file.is_open()){
        std::cout << "error\n";
        return 1; 
    }

    std::vector<Range> ranges;
    std::string line;

    // beremo SAMO prvi del – range-e
    while (std::getline(file, line)) {
        if (line.empty())
            break;

        ranges.push_back(parseRange(line));
    }

    long long result = countFreshFromRanges(ranges);

    std::cout << result << std::endl;
    return 0;
}
