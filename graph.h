#pragma once
#include <vector>
#include <forward_list>
#include <stack>

enum class Colors {WHITE, GRAY, BLACK};

using Edge = std::pair<size_t, size_t>;

std::vector<std::vector<bool>> create_adjacency_matrix(size_t count_vertex, const std::vector<Edge>& edges) {
    const auto it_max_element = std::max_element(cbegin(edges), cend(edges), [](const Edge& lhs, const Edge& rhs) {
        return std::max(lhs.first, rhs.second) < std::max(rhs.first, rhs.second);
    });
    const size_t max_vertex = std::max(it_max_element->first, it_max_element->second);

    std::vector<std::vector<bool>> adjacency_matrix(std::max(count_vertex, max_vertex) + 1u, std::vector<bool>(max_vertex + 1u, false));
    for(const auto& [from, to] : edges) {
        adjacency_matrix[from][to] = true;
    }
    return adjacency_matrix;
}

std::vector<std::forward_list<int>> create_adjacency_list(size_t count_vertex, const std::vector<Edge>& edges) {
    const auto it_max_element = std::max_element(cbegin(edges), cend(edges), [](const Edge& lhs, const Edge& rhs) {
        return std::max(lhs.first, rhs.second) < std::max(rhs.first, rhs.second);
    });
    const size_t max_vertex = std::max(it_max_element->first, it_max_element->second);

    std::vector<std::forward_list<int>>  adjacency_list(std::max(count_vertex, max_vertex) + 1u);
    for(const auto& [from, to] : edges) {
        adjacency_list[from].push_front(to);
    }
    return adjacency_list;
}

void component_dfs(size_t vertex, const std::vector<std::forward_list<int>>& adjacency_list, std::vector<Colors>& colors) {
    std::stack<size_t> stk;
    stk.push(vertex);
    while(!stk.empty()) {
        auto current_vertex = stk.top();
        stk.pop();
        if(colors[current_vertex] == Colors::WHITE) {
            stk.push(current_vertex);
            colors[current_vertex] = Colors::GRAY;
            for(auto adjacency_vertex : adjacency_list[current_vertex]) {
                if(colors[adjacency_vertex] == Colors::WHITE) stk.push(adjacency_vertex);
            }
        } else if(colors[current_vertex] == Colors::GRAY) {
            colors[current_vertex] = Colors::BLACK;
        }
    }
}

void dfs(size_t count_vertex, const std::vector<Edge>& edges) {
    const auto adjacency_list = create_adjacency_list(count_vertex, edges);
    std::vector<Colors> colors(adjacency_list.size(), Colors::WHITE);
    for(size_t vertex = 0u;vertex < adjacency_list.size();++vertex) {
        if(colors[vertex] == Colors::WHITE) {
            component_dfs(vertex, adjacency_list, colors);
        }
    }
}

template <typename Inpred, typename Postpred>
void component_dfs(size_t vertex, const std::vector<std::forward_list<int>>& adjacency_list, std::vector<Colors>& colors,
                   const Inpred& inepred, const Postpred& postpred) {
    std::stack<size_t> stk;
    stk.push(vertex);
    while(!stk.empty()) {
        auto current_vertex = stk.top();
        stk.pop();
        if(colors[current_vertex] == Colors::WHITE) {
            stk.push(current_vertex);
            colors[current_vertex] = Colors::GRAY;
            inepred(current_vertex);
            for(auto adjacency_vertex : adjacency_list[current_vertex]) {
                if(colors[adjacency_vertex] == Colors::WHITE) stk.push(adjacency_vertex);
            }
        } else if(colors[current_vertex] == Colors::GRAY) {
            colors[current_vertex] = Colors::BLACK;
            postpred(current_vertex);
        }
    }
}

template <typename Inpred, typename Postpred>
void dfs(size_t count_vertex, const std::vector<Edge>& edges, const Inpred& inepred, const Postpred& postpred) {
    const auto adjacency_list = create_adjacency_list(count_vertex, edges);
    std::vector<Colors> colors(adjacency_list.size(), Colors::WHITE);
    for(size_t vertex = 0u;vertex < adjacency_list.size();++vertex) {
        if(colors[vertex] == Colors::WHITE) {
            component_dfs(vertex, adjacency_list, colors, inepred, postpred);
        }
    }
}