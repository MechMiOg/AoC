
#include "functions.h"
#include <string>


// int maxPairValue(const std::string &s)
// {
//     int bestPair = -1;
//     int maxRight = -1;

//     for (int i = static_cast<int>(s.length()) - 1; i >= 0; --i){
//         int currentValue = s[i] - '0';      // odštejemo ascii znak '0'=48, da dobimo pravo vrednost

//         if(maxRight != -1){
//             int candidatePair =10 *currentValue + maxRight;
//             if (candidatePair > bestPair){
//                 bestPair = candidatePair;
//             }
//         }

//         if(currentValue > maxRight){
//                 maxRight = currentValue;
//             }    
    

// }

//     return bestPair;
// }

std::string maxTwelveDigits(const std::string &s)
{
    const int K = 12;
    int n = static_cast<int>(s.size());
    int toRemove = n - K;

    std::string st;
    st.reserve(n);

    for (char c : s) {
        while (!st.empty() && toRemove > 0 && st.back() < c) {
            st.pop_back();
            --toRemove;
        }
        st.push_back(c);
    }

    if ((int)st.size() > K)
        st.resize(K);

    return st;
}
