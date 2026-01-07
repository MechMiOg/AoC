#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <fstream>
#include "functions.h"


static std::unordered_map<std::string, std::vector<std::string>> graf;
static std::unordered_map<std::string, long long> memo;

static long long dfs(const std::string &u) {
    if (u == "out") {
        return 1;
    }

    if (memo.count(u)) {
        return memo[u];
    }

    long long ans = 0;

    for (const std::string &v : graf[u]) {
        ans += dfs(v);
    }

    memo[u] = ans;
    return ans;
}


void solve() {
    std::ifstream file("input.txt");

    std::string line;

    while (std::getline(file, line)) {
        std::size_t pos = line.find(':');

        std::string from = line.substr(0, pos);
        std::string rest = line.substr(pos + 2); 

        std::stringstream ss(rest);
        std::string to;

        while (ss >> to) {
            graf[from].push_back(to);
        }
    }

    std::cout << dfs("you") << '\n';
}

