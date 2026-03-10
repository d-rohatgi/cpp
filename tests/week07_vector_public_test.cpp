#include "course/vector.hpp"

#include <gtest/gtest.h>

namespace {
struct CountingValue {
    static inline int live_count = 0;
    int value = 0;

    explicit CountingValue(int v = 0) : value(v) { ++live_count; }
    CountingValue(const CountingValue& other) : value(other.value) { ++live_count; }
    CountingValue(CountingValue&& other) noexcept : value(other.value) { ++live_count; }
    ~CountingValue() { --live_count; }
};
}  // namespace

TEST(VectorPublicTest, StartsEmpty) {
    course::Vector<int> v;
    EXPECT_TRUE(v.empty());
    EXPECT_EQ(v.size(), 0u);
}

TEST(VectorPublicTest, PushBackStoresElementsInOrder) {
    course::Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    ASSERT_EQ(v.size(), 2u);
    EXPECT_EQ(v[0], 10);
    EXPECT_EQ(v[1], 20);
}

TEST(VectorPublicTest, ReserveDoesNotChangeSize) {
    course::Vector<int> v;
    v.push_back(1);
    v.reserve(32);
    EXPECT_EQ(v.size(), 1u);
    EXPECT_GE(v.capacity(), 32u);
}

TEST(VectorPublicTest, ClearDestroysElements) {
    {
        course::Vector<CountingValue> v;
        v.push_back(CountingValue{1});
        v.push_back(CountingValue{2});
        v.clear();
        EXPECT_EQ(v.size(), 0u);
    }
    EXPECT_EQ(CountingValue::live_count, 0);
}
