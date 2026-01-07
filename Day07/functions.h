#pragma once

#include <vector>
#include <string>

std::vector<std::string> readGrid();

// long long countSplits(const std::vector<std::string>& grid);

long long countTimelines(const std::vector<std::string>& grid);

static long long dfsTimelines(    
    const std::vector<std::string>& grid,
    int r,
    int c,
    std::vector<std::vector<long long>>& memo);