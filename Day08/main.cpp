#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "functions.h"




#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "functions.h"

int main() {
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cout << "error\n";
        return 1;
    }

    std::vector<Point> points = read_points(file);

    long long answer = solve_last_connection_product(points);

    std::cout << answer << '\n';
    return 0;
}


