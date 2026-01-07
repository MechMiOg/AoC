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

  
//     std::vector<std::string> lines;
//     std::string line;

//     // prvi del – beremo range
//     while (std::getline(file, line)) {
//         if (!line.empty())
//         lines.push_back(line);
//     }

//         // zadnja vrstica = operatorji
//     std::string opsLine = lines.back();
//     lines.pop_back();   // odstranimo jo iz seznama

//   // pretvorimo vrstice števil v numberLines
//     std::vector<std::vector<long long>> numberLines;

//     for (const std::string& l : lines)
//     {
//         std::stringstream ss(l);
//         std::vector<long long> row;
//         long long x;

//         while (ss >> x)
//             row.push_back(x);

//         numberLines.push_back(row);
//     }

//         // pretvorimo operatorje v vector<char>
//     std::vector<char> operators;
//     {
//         std::stringstream ss(opsLine);
//         char op;
//         while (ss >> op)
//             operators.push_back(op);
//     }


//     // izračun grand total
//     long long total = computeGrandTotal(numberLines, operators);

//     std::cout << total << '\n';
//     return 0;
// }



int main() {
    std::ifstream file("input.txt");

    if (!file.is_open()) {
        std::cout << "error\n";
        return 1;
    }

    std::vector<std::string> lines;
    std::string line;

    // preberemo vse vrstice (vključno z zadnjo, kjer so operatorji)
    while (std::getline(file, line)) {
        // ne briši praznih vrstic, za vsak slučaj
        lines.push_back(line);
    }

    long long total = computeGrandTotalPart2(lines);

    std::cout << total << '\n';
    return 0;
}
