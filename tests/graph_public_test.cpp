#include "course/graph.hpp"

#include <gtest/gtest.h>
#include <vector>

TEST(GraphPublicTest, BfsVisitsExpectedNodesInSimpleChain) {
    course::Graph g(4);
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);

    std::vector<std::size_t> order = g.bfs(0);
    std::vector<std::size_t> expected{0, 1, 2, 3};
    EXPECT_EQ(order, expected);
}

TEST(GraphPublicTest, DfsVisitsStartNodeAtMinimum) {
    course::Graph g(3);
    g.add_edge(0, 1);
    g.add_edge(0, 2);

    auto order = g.dfs(0);
    ASSERT_FALSE(order.empty());
    EXPECT_EQ(order.front(), 0u);
}

// TODO(student):
// Add disconnected graph tests.
// Add repeated-edge policy tests.
// Add component and reachability validation.
