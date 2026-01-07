#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>




bool isValid(long long num);
void parseRanges(const std::string& line, std::vector<std::pair<long long, long long>>& ranges);
std::vector<long long> collectInvalid(const std::vector<std::pair<long long, long long>>& ranges);
long long sumAll( std::vector<long long>& nums);
