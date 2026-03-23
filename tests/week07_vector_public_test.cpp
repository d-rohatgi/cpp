#include "course/week07_vector.hpp"

#include <gtest/gtest.h>
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

TEST(Week07Vector, StartsEmpty) {
    course::Vector<int> v;
    EXPECT_TRUE(v.empty());
    EXPECT_EQ(v.size(), 0u);
}

TEST(Week07Vector, PushBackStoresElementsInOrder) {
    course::Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    ASSERT_EQ(v.size(), 2u);
    EXPECT_EQ(v[0], 10);
    EXPECT_EQ(v[1], 20);
}

TEST(Week07Vector, ReserveDoesNotChangeSizeAndPreservesElements) {
    course::Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.reserve(32);
    EXPECT_EQ(v.size(), 2u);
    EXPECT_GE(v.capacity(), 32u);
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
}

TEST(Week07Vector, ReserveBelowCurrentCapacityDoesNotLoseElements) {
    course::Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    const auto old_capacity = v.capacity();
    v.reserve(1);
    EXPECT_EQ(v.size(), 2u);
    EXPECT_GE(v.capacity(), 2u);
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
    EXPECT_GE(v.capacity(), old_capacity == 0 ? 2u : 0u);
}

TEST(Week07Vector, PopBackShrinksSize) {
    course::Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.pop_back();
    EXPECT_EQ(v.size(), 1u);
    EXPECT_EQ(v[0], 1);
}

TEST(Week07Vector, AtThrowsOutOfRange) {
    course::Vector<int> v;
    v.push_back(1);
    EXPECT_THROW(v.at(1), std::out_of_range);
}

TEST(Week07Vector, ClearDestroysElementsAndContainerRemainsUsable) {
    {
        course::Vector<CountingValue> v;
        v.push_back(CountingValue{1});
        v.push_back(CountingValue{2});
        v.clear();
        EXPECT_EQ(v.size(), 0u);
        v.push_back(CountingValue{3});
        EXPECT_EQ(v.size(), 1u);
    }
    EXPECT_EQ(CountingValue::live_count, 0);
}

TEST(Week07Vector, CopyCreatesIndependentContainer) {
    course::Vector<std::string> a;
    a.push_back("alpha");
    a.push_back("beta");

    course::Vector<std::string> b(a);
    b[0] = "changed";

    EXPECT_EQ(a[0], "alpha");
    EXPECT_EQ(b[0], "changed");
}

TEST(Week07Vector, CopyAssignmentCreatesIndependentContainer) {
    course::Vector<std::string> a;
    a.push_back("x");
    a.push_back("y");

    course::Vector<std::string> b;
    b = a;
    b[1] = "changed";

    EXPECT_EQ(a[1], "y");
    EXPECT_EQ(b[1], "changed");
}

TEST(Week07Vector, MoveLeavesSourceValid) {
    course::Vector<std::string> a;
    a.push_back("x");
    a.push_back("y");

    course::Vector<std::string> b(std::move(a));

    EXPECT_EQ(b.size(), 2u);
    EXPECT_EQ(b[0], "x");
    EXPECT_EQ(b[1], "y");
    EXPECT_TRUE(a.empty() || a.size() == 0u);
}

TEST(Week07Vector, MoveAssignmentLeavesSourceValid) {
    course::Vector<std::string> a;
    a.push_back("left");
    a.push_back("right");

    course::Vector<std::string> b;
    b = std::move(a);

    EXPECT_EQ(b.size(), 2u);
    EXPECT_EQ(b[0], "left");
    EXPECT_EQ(b[1], "right");
    EXPECT_TRUE(a.empty() || a.size() == 0u);
}
