#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>
#include <array>

using Point = std::pair<long long, long long>;

std::vector<Point> readPoints(std::istream& in)
{
    std::vector<Point> pts;
    std::string line;

    while (std::getline(in, line)) {

        std::size_t comma = line.find(',');
        long long x = std::stoll(line.substr(0, comma));
        long long y = std::stoll(line.substr(comma + 1));

        pts.emplace_back(x, y);
    }

    return pts;
}

long long rectangleArea(const Point& a, const Point& b)
{
    long long dx = llabs(a.first  - b.first);
    long long dy = llabs(a.second - b.second);

    if (dx == 0 && dy == 0) return 0;

    return (dx + 1) * (dy + 1);
}

long long largestRectangleArea(const std::vector<Point>& pts)
{
    long long best = 0;
    int n = (int)pts.size();

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            long long area = rectangleArea(pts[i], pts[j]);
            if (area > best) best = area;
        }
    }

    return best;
}

