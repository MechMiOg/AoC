#include "functions.h"
#include <string>
#include <fstream>
#include <iostream>

std::vector<std::string> readGrid(){
    std::ifstream file("input.txt");

    if (!file.is_open()) {
        throw std::runtime_error("Could not open input.txt");
    }

    std::vector<std::string> grid;
    std::string line;

    while(std::getline(file, line)){
        grid.push_back(line);
    }

    return grid;
}



// long long countSplits(const std::vector<std::string>& grid) {
//     const int H = static_cast<int>(grid.size());
//     const int W = static_cast<int>(grid[0].size());

//     // Poiščemo start 'S'
//     int startRow = -1;
//     int startCol = -1;

//     for (int r = 0; r < H; ++r) {
//         if ((int)grid[r].size() != W) {
//             throw std::runtime_error("All rows in the grid must have the same width.");
//         }
//         for (int c = 0; c < W; ++c) {
//             if (grid[r][c] == 'S') {
//                 startRow = r;
//                 startCol = c;
//                 break;
//             }
//         }
//         if (startRow != -1) break;
//     }

//     if (startRow == -1 || startCol == -1) {
//         throw std::runtime_error("Start position 'S' not found in grid.");
//     }

//     // Vektorji, ki opisujejo, v katerih stolpcih je trenutno žarek
//     std::vector<bool> beamsCur(W, false);
//     std::vector<bool> beamsNext(W, false);

//     // Žarek vstopi pri S in gre navzdol
//     beamsCur[startCol] = true;

//     long long splits = 0;

//     // Gremo od vrstice pod S do zadnje vrstice
//     for (int r = startRow + 1; r < H; ++r) {
//         std::fill(beamsNext.begin(), beamsNext.end(), false);

//         for (int c = 0; c < W; ++c) {
//             if (!beamsCur[c]) continue;  // v tem stolpcu ni žarka

//             char cell = grid[r][c];

//             if (cell == '^') {
//                 // Splitter: žarek se konča, nastaneta dva nova (levo in desno)
//                 ++splits;

//                 if (c - 1 >= 0) {
//                     beamsNext[c - 1] = true;
//                 }
//                 if (c + 1 < W) {
//                     beamsNext[c + 1] = true;
//                 }
//             } else {
//                 // Prazno (.) ali karkoli drugega:
//                 // žarek gre samo navzdol v isti stolpec.
//                 beamsNext[c] = true;
//             }
//         }

//         beamsCur.swap(beamsNext);
//     }

//     return splits;
// }


// Pomožna funkcija: vrne število časovnic, če je tachyon trenutno
// "na poti" proti celici (r, c).
static long long dfsTimelines(
    const std::vector<std::string>& grid,
    int r,
    int c,
    std::vector<std::vector<long long>>& memo
) {
    const int H = static_cast<int>(grid.size());
    const int W = static_cast<int>(grid[0].size());

    // 1) če gre izven stolpcev → zapusti manifold → ena zaključena časovnica
    if (c < 0 || c >= W) {
        return 1;
    }

    // 2) če gre pod zadnjo vrstico → tudi ena zaključena časovnica
    if (r >= H) {
        return 1;
    }

    // 3) memoizacija: če smo že izračunali, vrni shranjeno
    if (memo[r][c] != -1) {
        return memo[r][c];
    }

    char cell = grid[r][c];
    long long result = 0;

    if (cell == '^') {
        // 4) splitter: čas se razcepi

        // leva vejo
        result += dfsTimelines(grid, r + 1, c - 1, memo);

        // desna veja
        result += dfsTimelines(grid, r + 1, c + 1, memo);
    } else {
        // 5) navadno polje: gre samo navzdol
        result = dfsTimelines(grid, r + 1, c, memo);
    }

    memo[r][c] = result;
    return result;
}




long long countTimelines(const std::vector<std::string>& grid) {
    const int H = static_cast<int>(grid.size());
    const int W = static_cast<int>(grid[0].size());

    // 1) poiščemo 'S'
    int startRow = -1;
    int startCol = -1;

    for (int r = 0; r < H; ++r) {
        if ((int)grid[r].size() != W) {
            throw std::runtime_error("All rows in the grid must have the same width.");
        }
        for (int c = 0; c < W; ++c) {
            if (grid[r][c] == 'S') {
                startRow = r;
                startCol = c;
                break;
            }
        }
        if (startRow != -1) break;
    }

    if (startRow == -1) {
        throw std::runtime_error("Start position 'S' not found.");
    }

    // 2) tachyon po pravilih takoj gre navzdol iz S,
    //    zato začnemo pri vrstici startRow + 1 in stolpcu startCol
    std::vector<std::vector<long long>> memo(
        H, std::vector<long long>(W, -1)
    );

    return dfsTimelines(grid, startRow + 1, startCol, memo);
}


