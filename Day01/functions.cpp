#include "functions.h"
#include <sstream>
#include <string>



int rotations(int current, char direction, int distance, int& zeroHits) {
    zeroHits = 0;

    for (int i = 0; i < distance; i++) {
        if (direction == 'R') {
            current = (current + 1) % 100;
        } else {
            current = (current - 1 + 100) % 100;
        }

        if (current == 0) {
            zeroHits++;
        }
    }

    return current;
}


void parseRotation(const std::string& line, char& direction, int& value) {
    direction = line[0];
    value = std::stoi(line.substr(1));
}

int processInput(std::istream& in) {
    int current = 50;
    int totalZeros = 0;
    std::string line;

    while (std::getline(in, line)) {
        char direction;
        int distance;

        parseRotation(line, direction, distance);

        int zeroHits;
        current = rotations(current, direction, distance, zeroHits);

        totalZeros += zeroHits;
    }

    return totalZeros;
}









