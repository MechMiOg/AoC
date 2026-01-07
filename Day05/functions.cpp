#include "functions.h"
#include <algorithm>



Range parseRange(const std::string& s)
{
    Range r;

    auto dashPos = s.find('-');

    r.from = std::stoll(s.substr(0, dashPos));
    r.to   = std::stoll(s.substr(dashPos + 1));

    return r;
}


// bool contains(const Range& r, long long id)
// {
//     return id >= r.from && id <= r.to;
// }


// bool isFresh(long long id, const std::vector<Range>& ranges)
// {
//     for (const auto& r : ranges)
//         if (contains(r, id))
//             return true;

//     return false;
// }


// int countFreshIDs(const std::vector<long long>& availableIDs,
//                   const std::vector<Range>& ranges)
// {
//     int count = 0;

//     for (long long id : availableIDs)
//         if (isFresh(id, ranges))
//             ++count;

//     return count;
// }




//part two

long long countFreshFromRanges(std::vector<Range> ranges)
{
    if (ranges.empty())
        return 0;

    // 1) uredimo po začetku intervala
    std::sort(ranges.begin(), ranges.end(),
              [](const Range& a, const Range& b) {
                  return a.from < b.from;
              });

    long long total = 0;

    long long curFrom = ranges[0].from;
    long long curTo   = ranges[0].to;

    // 2) gremo čez intervale in jih združujemo
    for (std::size_t i = 1; i < ranges.size(); ++i) {
        const auto& r = ranges[i];

        if (r.from <= curTo + 1) {
            // prekrivanje ali stik (npr. 3-5 in 6-10)
            if (r.to > curTo)
                curTo = r.to;
        } else {
            // prejšnji interval zaključimo
            total += (curTo - curFrom + 1);

            // začnemo novega
            curFrom = r.from;
            curTo   = r.to;
        }
    }

    // zadnji interval še dodamo
    total += (curTo - curFrom + 1);

    return total;
}
