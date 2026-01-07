#include "functions.h"
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>




std::vector<Point> read_points(std::istream &file) {
    std::vector<Point> points;
    std::string line;
    while (std::getline(file, line)) {
        std::replace(line.begin(), line.end(), ',', ' ');
        std::istringstream iss(line);
        Point p;
        if (iss >> p.x >> p.y >> p.z) {
            points.push_back(p);
        }
    }
    return points;
}

long long distance_squared(const Point &a, const Point &b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    long long dz = a.z - b.z;
    return dx*dx + dy*dy + dz*dz;
}


std::vector<Connection> build_all_connections(const std::vector<Point> &points) {
    std::vector<Connection> connections;

    int n = (int)points.size();
    connections.reserve((long long)n * (n - 1) / 2);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {

            Connection c;
            c.a = i;
            c.b = j;
            c.dist2 = distance_squared(points[i], points[j]);

            connections.push_back(c);
        }
    }

    return connections;
}

long long solve_circuits(const std::vector<Point> &points, int pairs_to_connect) {
    int n = (int)points.size();
    if (n == 0) return 0;

    auto connections = build_all_connections(points);

    std::sort(connections.begin(), connections.end(),
              [](const Connection &c1, const Connection &c2) {
                  return c1.dist2 < c2.dist2;
              });

    DSU dsu(n);

    int limit = std::min((int)connections.size(), pairs_to_connect);
    for (int i = 0; i < limit; ++i) {
        dsu.unite(connections[i].a, connections[i].b);
    }

   
    std::vector<int> comp_sizes;
    comp_sizes.reserve(n);
    std::vector<bool> is_first(n, false);

    for (int i = 0; i < n; ++i) {
        int first = dsu.find(i);
        if (!is_first[first]) {
            is_first[first] = true;
            comp_sizes.push_back(dsu.size(first));
        }
    }

   
    std::sort(comp_sizes.begin(), comp_sizes.end(), std::greater<int>());

    if (comp_sizes.size() < 3) {
        
        return 0;
    }

    long long a = comp_sizes[0];
    long long b = comp_sizes[1];
    long long c = comp_sizes[2];

    return a * b * c;
}




long long solve_last_connection_product(const std::vector<Point> &points) {
    int n = (int)points.size();
    if (n == 0) return 0;
    if (n == 1) {
        return points[0].x * points[0].x; 
    auto connections = build_all_connections(points);

    std::sort(connections.begin(), connections.end(),
              [](const Connection &c1, const Connection &c2) {
                  return c1.dist2 < c2.dist2;
              });

    DSU dsu(n);
    int components = n;

    int last_a = -1;
    int last_b = -1;

    for (const auto &c : connections) {
        if (dsu.unite(c.a, c.b)) {
            components--;
            last_a = c.a;
            last_b = c.b;

            if (components == 1) {
                break;
            }
        }
    }

    if (components != 1 || last_a == -1) {
        return 0;
    }

    long long x1 = points[last_a].x;
    long long x2 = points[last_b].x;
    return x1 * x2;
}
