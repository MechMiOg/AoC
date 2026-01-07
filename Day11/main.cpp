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

    solve();
    
    return 0;
}
