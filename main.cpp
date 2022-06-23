#include "streamcollection.h"
#include <iostream>
#include <vector>
#include <forward_list>
#include <stack>

using namespace std;

using Edge = pair<size_t, size_t>;

vector<vector<bool>> create_adjacency_matrix(const vector<Edge>& edges) {
    vector<vector<bool>> adjacency_matrix;
    for(const auto& [from, to] : edges) {
        if(size_t max_ = max(from, to);adjacency_matrix.size() <= max_) {
            adjacency_matrix.resize(max_+ 1u);
        }
        if(adjacency_matrix[from].size() <= to) {
            adjacency_matrix[from].resize(to + 1u);
        }
        if(adjacency_matrix[to].size() <= from) {
            adjacency_matrix[to].resize(from + 1u);
        }
        adjacency_matrix[from][to] = true;
        adjacency_matrix[to][from] = true;
    }
    return adjacency_matrix;
}

vector<forward_list<int>> create_adjacency_list(const vector<Edge>& edges) {
    vector<forward_list<int>>  adjacency_list;
    for(const auto& [from, to] : edges) {
        if(adjacency_list.size() <= max(from, to)) {
            adjacency_list.resize( max(from, to) + 1u);
        }
        adjacency_list[from].push_front(to);
        adjacency_list[to].push_front(from);
    }
    return adjacency_list;
}

enum class Colors {WHITE, GRAY, BLACK};

void dfs(const vector<Edge>& edges, size_t s) {
    auto adjacency_list = create_adjacency_list(edges);
    vector<Colors> colors(adjacency_list.size() + 1u, Colors::WHITE);
    stack<size_t> stk;
    stk.push(s);
    while(!stk.empty()) {
        auto cur_vertex = stk.top();
        stk.pop();
        if(colors[cur_vertex] == Colors::WHITE) {
            stk.push(cur_vertex);
            colors[cur_vertex] = Colors::GRAY;

            cout << cur_vertex << " ";

            adjacency_list[cur_vertex].sort(greater<size_t>());
            for(auto vertex : adjacency_list[cur_vertex]) {
                if(colors[vertex] == Colors::WHITE) stk.push(vertex);
            }
        } else if(colors[cur_vertex] == Colors::GRAY) {
            colors[cur_vertex] = Colors::BLACK;
        }
    }
}

int main() {
    size_t n, m, s;
    cin >> n >> m;
    vector<Edge> edges(m);
    for(auto& [from, to] : edges) cin >> from >> to;
    cin >> s;
    dfs(edges, s);
    return 0;
}