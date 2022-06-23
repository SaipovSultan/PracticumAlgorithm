#include "streamcollection.h"
#include "graph.h"
#include <iostream>

using namespace std;

int main() {
    size_t n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for(auto& edge : edges) cin >> edge.first >> edge.second;

    int time = -1;
    vector<int> Entry(n + 1);
    vector<int> Leave(n + 1);
    auto Entrypred = [&time, &Entry](size_t vertex) {
        time += 1;
        Entry[vertex] = time;
    };
    auto Leavepred = [&time, &Leave](size_t vertex) {
        time += 1;
        Leave[vertex] = time;
    };
    dfs(n, edges, Entrypred, Leavepred);

    for(size_t vertex = 1u;vertex < Entry.size();++vertex) {
        cout << Entry[vertex] << " " << Leave[vertex] << "\n";
    }
    return 0;
}