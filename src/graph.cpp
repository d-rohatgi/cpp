#include "course/graph.hpp"

namespace course {

Graph::Graph(std::size_t n) : adj_(n) {}

void Graph::add_edge(std::size_t u, std::size_t v, bool undirected) {
    if (u >= adj_.size() || v >= adj_.size()) {
        return;
    }
    adj_[u].push_back(v);
    if (undirected) {
        adj_[v].push_back(u);
    }
}

std::vector<std::size_t> Graph::bfs(std::size_t start) const {
    (void)start;
    // TODO(student): implement BFS.
    return {};
}

std::vector<std::size_t> Graph::dfs(std::size_t start) const {
    (void)start;
    // TODO(student): implement DFS.
    return {};
}

}  // namespace course
