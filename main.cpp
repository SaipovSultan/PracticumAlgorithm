#include "streamcollection.h"
#include <iostream>
#include <vector>
#include <forward_list>
using namespace std;

vector<vector<bool>> create_adjacency_matrix(const vector<pair<size_t, size_t>>& edges) {
    vector<vector<bool>> adjacency_matrix;
    for(const auto& [from, to] : edges) {
        if(adjacency_matrix.size() <= from) {
            adjacency_matrix.resize(from + 1u);
        }
        if(adjacency_matrix[from].size() <= to) {
            adjacency_matrix[from].resize(to + 1u);
        }
        adjacency_matrix[from][to] = true;
    }
    return adjacency_matrix;
}

vector<forward_list<int>> create_adjacency_list(const vector<pair<size_t, size_t>>& edges) {
    vector<forward_list<int>>  adjacency_list;
    for(const auto& [from, to] : edges) {
        if(adjacency_list.size() <= from) {
            adjacency_list.resize(from + 1u);
        }
        adjacency_list[from].push_front(to);
    }
    return adjacency_list;
}

int main() {
    size_t from, to;
    vector<pair<size_t, size_t>> edges;
    while(cin >> from && cin >> to) {
        edges.push_back(make_pair(from, to));
    }
    auto adjacency_matrix = create_adjacency_matrix(edges);
    auto adjacency_list = create_adjacency_list(edges);
    return 0;
}