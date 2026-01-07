#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>

using Point = std::pair<long long, long long>;

std::vector<Point> readPoints(std::istream& in);

long long rectangleArea(const Point& a, const Point& b);

long long largestRectangleArea(const std::vector<Point>& pts);

