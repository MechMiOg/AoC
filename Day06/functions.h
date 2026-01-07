#pragma once

#include <vector>
#include <string>
#include <queue>

long long computeColumnValue(const std::vector<std::vector<long long>>& numberLines,
                             const std::vector<char>& operators,
                             std::size_t columnIndex);

long long computeGrandTotal(const std::vector<std::vector<long long>>& numberLines,
                            const std::vector<char>& operators);

long long computeGrandTotalPart2(const std::vector<std::string>& lines);
