#pragma once

#include <vector>
#include <string>
#include <queue>

struct Range {
    long long from;
    long long to;
};

Range parseRange(const std::string& s);

// bool contains(const Range& r, long long id);

// bool isFresh(long long id, const std::vector<Range>& ranges);

// int countFreshIDs(const std::vector<long long>& availableIDs,
//                   const std::vector<Range>& ranges);



// part two

long long countFreshFromRanges(std::vector<Range> ranges);
