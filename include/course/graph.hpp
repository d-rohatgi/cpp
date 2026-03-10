#pragma once

#include <cstddef>
#include <vector>

namespace course {

class Graph {
public:
    explicit Graph(std::size_t n = 0);
    void add_edge(std::size_t u, std::size_t v, bool undirected = true);
    std::vector<std::size_t> bfs(std::size_t start) const;
    std::vector<std::size_t> dfs(std::size_t start) const;

private:
    std::vector<std::vector<std::size_t>> adj_;
};

}  // namespace course
