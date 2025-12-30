#include "functions.h"

// int countAccessibleRolls(const std::vector<std::string>& grid) {
//     int h = (int)grid.size();
//     if (h == 0) return 0;
//     int w = (int)grid[0].size();

//     // 8 smeri: (dx, dy)
//     const int dx[8] = {-1, -1, -1,  0, 0, 1, 1, 1};
//     const int dy[8] = {-1,  0,  1, -1, 1,-1, 0, 1};

//     int accessible = 0;

//     for (int i = 0; i < h; ++i) {
//         for (int j = 0; j < w; ++j) {
//             if (grid[i][j] != '@') continue;

//             int neighbours = 0;
//             for (int k = 0; k < 8; ++k) {
//                 int ni = i + dx[k];
//                 int nj = j + dy[k];
//                 if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
//                 if (grid[ni][nj] == '@') {
//                     ++neighbours;
//                 }
//             }

//             if (neighbours < 4) {
//                 ++accessible;
//             }
//         }
//     }

//     return accessible;
// }

#include <vector>
#include <string>
#include <queue>

int countRemovableRolls(std::vector<std::string> grid) {
    int h = (int)grid.size();
    if (h == 0) return 0;
    int w = (int)grid[0].size();

    const int dx[8] = {-1, -1, -1,  0, 0, 1, 1, 1};
    const int dy[8] = {-1,  0,  1, -1, 1,-1, 0, 1};

    // stopnje (število sosednjih @) za vsako polje
    std::vector<std::vector<int>> deg(h, std::vector<int>(w, 0));

    // 1) inicialno preštej sosede za vsako '@'
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] != '@') continue;

            int neighbours = 0;
            for (int k = 0; k < 8; ++k) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
                if (grid[ni][nj] == '@') {
                    ++neighbours;
                }
            }
            deg[i][j] = neighbours;
        }
    }

    // 2) vrsta vseh @, ki so trenutno dostopni (stopnja < 4)
    std::queue<std::pair<int,int>> q;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] == '@' && deg[i][j] < 4) {
                q.push({i, j});
            }
        }
    }

    int removed = 0;

    // 3) postopno "lupljenje" vseh, ki postanejo dostopni
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        // če je že odstranjen, preskoči
        if (grid[i][j] != '@') continue;

        // odstrani trenutni zvitek
        grid[i][j] = '.';
        ++removed;

        // posodobi sosede
        for (int k = 0; k < 8; ++k) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
            if (grid[ni][nj] != '@') continue;

            // zmanjšaj število sosedov
            --deg[ni][nj];

            // če je sosed zdaj postal dostopen, ga daj v vrsto
            if (deg[ni][nj] < 4) {
                q.push({ni, nj});
            }
        }
    }

    return removed;
}
