#include "streamcollection.h"
#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> create_adjacency_matrix(const vector<pair<size_t, size_t>>& edges) {
    size_t n = 0u;
    for(const auto& [from, to] : edges) {
        n = max(n, max(from, to));
    }
    vector<vector<bool>> adjacency_matrix(n + 1u, vector<bool>(n + 1u, false));
    for(const auto& [from, to] : edges) {
        adjacency_matrix[from][to] = true;
    }
    return adjacency_matrix;
}

int main() {
    size_t from, to;
    vector<pair<size_t, size_t>> edges;
    while(cin >> from && cin >> to) {
        edges.push_back(make_pair(from, to));
    }
    vector<vector<bool>> adjacency_matrix = create_adjacency_matrix(edges);
    for(const auto& edges : adjacency_matrix) {
        cout << count(cbegin(edges), cend(edges), true);
        for(size_t i = 0u;i < edges.size();++i) {
            if(edges[i]) cout << " " << i;
        }
        cout << "\n";
    }
    cout << adjacency_matrix << endl;
    return 0;
}