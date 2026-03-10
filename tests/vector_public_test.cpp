#include "course/vector.hpp"

#include <gtest/gtest.h>
#include <stdexcept>
#include <string>

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
    EXPECT_EQ(v.capacity(), 0u);
}

TEST(VectorPublicTest, PushBackStoresElementsInOrder) {
    course::Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    ASSERT_EQ(v.size(), 3u);
    EXPECT_EQ(v[0], 10);
    EXPECT_EQ(v[1], 20);
    EXPECT_EQ(v[2], 30);
}

TEST(VectorPublicTest, AtThrowsOutOfRange) {
    course::Vector<int> v;
    v.push_back(1);
    EXPECT_THROW(v.at(1), std::out_of_range);
}

TEST(VectorPublicTest, ReserveDoesNotChangeSize) {
    course::Vector<int> v;
    v.push_back(1);
    v.reserve(32);

    EXPECT_EQ(v.size(), 1u);
    EXPECT_GE(v.capacity(), 32u);
    EXPECT_EQ(v[0], 1);
}

TEST(VectorPublicTest, CopyConstructorCreatesIndependentCopy) {
    course::Vector<std::string> a;
    a.push_back("alpha");
    a.push_back("beta");

    course::Vector<std::string> b(a);
    b[0] = "changed";

    EXPECT_EQ(a[0], "alpha");
    EXPECT_EQ(b[0], "changed");
}

TEST(VectorPublicTest, MoveConstructorLeavesSourceValid) {
    course::Vector<std::string> a;
    a.push_back("x");
    a.push_back("y");

    course::Vector<std::string> b(std::move(a));

    EXPECT_EQ(b.size(), 2u);
    EXPECT_EQ(b[0], "x");
    EXPECT_EQ(b[1], "y");
    EXPECT_TRUE(a.empty() || a.size() == 0u);
}

TEST(VectorPublicTest, PopBackShrinksSize) {
    course::Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.pop_back();

    ASSERT_EQ(v.size(), 1u);
    EXPECT_EQ(v[0], 1);
}

TEST(VectorPublicTest, ClearDestroysElementsAndKeepsContainerUsable) {
    {
        course::Vector<CountingValue> v;
        v.push_back(CountingValue{1});
        v.push_back(CountingValue{2});
        v.clear();
        EXPECT_EQ(v.size(), 0u);
    }
    EXPECT_EQ(CountingValue::live_count, 0);
}

// TODO(student):
// Add randomized model-based tests against std::vector.
// Add repeated push/pop growth tests.
// Add self-assignment and move-assignment tests.
// Add tests for clear() followed by reuse.
