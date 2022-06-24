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

vector<forward_list<size_t>> create_adjacency_list(const vector<Edge>& edges) {
    vector<forward_list<size_t>>  adjacency_list;
    for(const auto& [from, to] : edges) {
        if(size_t max_ = max(from, to);adjacency_list.size() <= max_) {
            adjacency_list.resize( max_ + 1u);
        }
        adjacency_list[from].push_front(to);
    }
    return adjacency_list;
}

enum class Colors {WHITE, GRAY, BLACK};

size_t iotime = 0u;
vector<size_t> Entry, Leave;

void dfs(const vector<Edge>& edges, size_t s) {
    auto adjacency_list = create_adjacency_list(edges);
    vector<Colors> colors(adjacency_list.size(), Colors::WHITE);
    stack<size_t> stk;
    stk.push(s);
    while(!stk.empty()) {
        auto cur_vertex = stk.top();
        stk.pop();
        if(colors[cur_vertex] == Colors::WHITE) {
            stk.push(cur_vertex);
            iotime += 1u;
            if(Entry.size() <= cur_vertex) {
                Entry.resize(cur_vertex + 1u);
            }
            Entry[cur_vertex] = iotime;
            colors[cur_vertex] = Colors::GRAY;

            cout << cur_vertex << " ";

            adjacency_list[cur_vertex].sort(greater<size_t>());
            for(auto vertex : adjacency_list[cur_vertex]) {
                if(colors[vertex] == Colors::WHITE) stk.push(vertex);
            }
        } else if(colors[cur_vertex] == Colors::GRAY) {
            if(Leave.size() <= cur_vertex) {
                Leave.resize(cur_vertex + 1u);
            }
            iotime += 1u;
            Leave[cur_vertex] = iotime;
            colors[cur_vertex] = Colors::BLACK;
        }
    }
}

void TopSort(size_t vertex, vector<forward_list<size_t>>& adjacency_list, stack<size_t>& order, vector<Colors>& colors) {
    colors[vertex] = Colors::GRAY;
    for(auto adjacency_vertex : adjacency_list[vertex]) {
        if(colors[adjacency_vertex] == Colors::WHITE) {
            TopSort(adjacency_vertex, adjacency_list, order, colors);
        }
    }
    colors[vertex] = Colors::BLACK;
    order.push(vertex);
}

vector<size_t> MainTopSort(const vector<Edge>& edges) {
    auto adjacency_list = create_adjacency_list(edges);
    vector<Colors> colors(adjacency_list.size());
    stack<size_t> order;
    for(size_t i = 0u;i < colors.size();++i) {
        if(colors[i] == Colors::WHITE) {
            TopSort(i, adjacency_list, order, colors);
        }
    }
    vector<size_t> tmp;
    while(!order.empty()) {
        tmp.push_back(order.top());
        order.pop();
    }
    return tmp;
}

int main() {
    size_t n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for(auto& [from, to] : edges) cin >> from >> to;
    auto top_sort = MainTopSort(edges);
    cout << top_sort << endl;
    return 0;
}