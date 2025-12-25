
#include "functions.h"



/*bool isInvalid(long long num){
    std::string str = std::to_string(num);
    size_t len = str.length();

    if (len % 2 != 0){
        return false;
    }

    size_t half = len / 2;

    return str.substr(0, half) == str.substr(half);
} */

bool isInvalid(long long num) {
    std::string s = std::to_string(num);
    size_t len = s.length();

    
    for (size_t k = 1; k <= len / 2; ++k) {
        if (len % k != 0)
            continue;  

        std::string block = s.substr(0, k);
        bool validRepeat = true;

        for (size_t i = k; i < len; i += k) {
            if (s.substr(i, k) != block) {
                validRepeat = false;
                break;
            }
        }

        if (validRepeat)
            return true;  
    }

    return false; 
}


void parseRanges(const std::string& line, std::vector<std::pair<long long, long long>>& ranges){

    std::stringstream ss(line);
    std::string range;

    while (std::getline(ss, range,',')){

        size_t dash = range.find('-');   //poiščemo indeks, kjer se nahaja -
        long long start = std::stoll(range.substr(0, dash));   // vzamemo string od indeksa 0 do indeksa -, pretvorimo string v long long
        long long end = std::stoll(range.substr(dash + 1));    // vzamemo string od indeksa - naprej


        ranges.push_back({start, end});
    }
}

std::vector<long long> collectInvalid(
    const std::vector<std::pair<long long, long long>>& ranges)
{
    std::vector<long long> invalids;

    for (const auto& r : ranges) {
        long long start = r.first;
        long long end   = r.second;

        for (long long n = start; n <= end; ++n) {
            if (isInvalid(n)) {
                invalids.push_back(n);
            }
        }
    }

    return invalids;
}

long long sumAll( std::vector<long long>& nums){
    long long sum = 0;

    for(long long n : nums){
        sum += n;
    }

    return sum;
}

