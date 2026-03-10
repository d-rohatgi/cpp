#include "course/algorithms.hpp"

#include <gtest/gtest.h>
#include <list>
#include <numeric>
#include <vector>

TEST(AlgorithmsPublicTest, FindReturnsIteratorToMatchingValue) {
    std::vector<int> v{1, 2, 3, 4};
    auto it = course::find(v.begin(), v.end(), 3);
    ASSERT_NE(it, v.end());
    EXPECT_EQ(*it, 3);
}

TEST(AlgorithmsPublicTest, AccumulateSumsValues) {
    std::vector<int> v{1, 2, 3, 4};
    EXPECT_EQ(course::accumulate(v.begin(), v.end(), 0), 10);
}

TEST(AlgorithmsPublicTest, CopyIfFiltersValues) {
    std::vector<int> v{1, 2, 3, 4, 5, 6};
    std::vector<int> out;
    course::copy_if(v.begin(), v.end(), std::back_inserter(out), [](int x) { return x % 2 == 0; });

    std::vector<int> expected{2, 4, 6};
    EXPECT_EQ(out, expected);
}

TEST(AlgorithmsPublicTest, LowerBoundFindsFirstNotLessThanValue) {
    std::vector<int> v{1, 3, 3, 5, 7};
    auto it = course::lower_bound(v.begin(), v.end(), 3);
    ASSERT_NE(it, v.end());
    EXPECT_EQ(*it, 3);
}

TEST(AlgorithmsPublicTest, WorksWithNonRandomAccessIteratorForLinearAlgorithms) {
    std::list<int> items{10, 20, 30};
    auto it = course::find(items.begin(), items.end(), 20);
    ASSERT_NE(it, items.end());
    EXPECT_EQ(*it, 20);
}

// TODO(student):
// Add boundary tests for empty ranges.
// Add tests comparing outputs against STL on random vectors.
// Add duplicate-boundary tests for lower_bound.
