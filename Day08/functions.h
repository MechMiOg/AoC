#pragma once

#include <vector>
#include <string>
#include <iostream>   
#include <algorithm>

struct Point {
    long long x;
    long long y;
    long long z;
};

struct Connection {
    int a;          // indeks prve škatle
    int b;          // indeks druge škatle
    long long dist2; // kvadrat razdalje med njima
};

class DSU {
public:
    DSU(int n) : parent(n), sz(n, 1) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int v) {
        if (parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) std::swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }

    int size(int v) {
        return sz[find(v)];
    }

private:
    std::vector<int> parent;
    std::vector<int> sz;
};

std::vector<Point> read_points(std::istream &file);
long long distance_squared(const Point &a, const Point &b);
std::vector<Connection> build_all_connections(const std::vector<Point> &points);
long long solve_circuits(const std::vector<Point> &points, int pairs_to_connect);
long long solve_last_connection_product(const std::vector<Point> &points);