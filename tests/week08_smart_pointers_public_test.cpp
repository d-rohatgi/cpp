#include "course/week08_shared_ptr.hpp"
#include "course/week08_unique_ptr.hpp"

#include <gtest/gtest.h>

namespace {
struct Counter {
    static inline int destructions = 0;
    int value = 0;

    explicit Counter(int v = 0) : value(v) {}
    ~Counter() { ++destructions; }
};
}  // namespace

TEST(Week08UniquePtr, OwnsRawPointer) {
    auto* raw = new Counter(7);
    course::UniquePtr<Counter> ptr(raw);

    ASSERT_NE(ptr.get(), nullptr);
    EXPECT_EQ(ptr->value, 7);
}

TEST(Week08UniquePtr, ReleaseReturnsRawPointerAndNullsOwner) {
    course::UniquePtr<Counter> ptr(new Counter(3));
    Counter* raw = ptr.release();

    ASSERT_NE(raw, nullptr);
    EXPECT_EQ(ptr.get(), nullptr);
    delete raw;
}

TEST(Week08UniquePtr, ResetCanPointToNewObject) {
    course::UniquePtr<Counter> ptr;
    ptr.reset(new Counter(9));
    ASSERT_NE(ptr.get(), nullptr);
    EXPECT_EQ(ptr->value, 9);
}

TEST(Week08UniquePtr, MoveConstructorTransfersOwnership) {
    course::UniquePtr<Counter> a(new Counter(5));
    course::UniquePtr<Counter> b(std::move(a));

    EXPECT_EQ(a.get(), nullptr);
    ASSERT_NE(b.get(), nullptr);
    EXPECT_EQ(b->value, 5);
}

TEST(Week08UniquePtr, MoveAssignmentTransfersOwnership) {
    course::UniquePtr<Counter> a(new Counter(6));
    course::UniquePtr<Counter> b;
    b = std::move(a);

    EXPECT_EQ(a.get(), nullptr);
    ASSERT_NE(b.get(), nullptr);
    EXPECT_EQ(b->value, 6);
}

TEST(Week08UniquePtr, ResetDeletesOldObject) {
    Counter::destructions = 0;
    {
        course::UniquePtr<Counter> ptr(new Counter(1));
        ptr.reset(new Counter(2));
    }
    EXPECT_GE(Counter::destructions, 2);
}

TEST(Week08SharedPtr, DefaultConstructionIsNull) {
    course::SharedPtr<Counter> ptr;
    EXPECT_EQ(ptr.get(), nullptr);
    EXPECT_EQ(ptr.use_count(), 0u);
}

TEST(Week08SharedPtr, StartsWithUseCountOne) {
    course::SharedPtr<Counter> ptr(new Counter(11));
    EXPECT_EQ(ptr.use_count(), 1u);
    EXPECT_EQ(ptr->value, 11);
}

TEST(Week08SharedPtr, CopyIncrementsUseCount) {
    course::SharedPtr<Counter> a(new Counter(1));
    course::SharedPtr<Counter> b(a);

    EXPECT_EQ(a.use_count(), 2u);
    EXPECT_EQ(b.use_count(), 2u);
}

TEST(Week08SharedPtr, CopyAssignmentIncrementsUseCount) {
    course::SharedPtr<Counter> a(new Counter(3));
    course::SharedPtr<Counter> b;
    b = a;

    EXPECT_EQ(a.use_count(), 2u);
    EXPECT_EQ(b.use_count(), 2u);
}

TEST(Week08SharedPtr, NestedScopeDropsCountBackDown) {
    course::SharedPtr<Counter> a(new Counter(4));
    {
        course::SharedPtr<Counter> b(a);
        EXPECT_EQ(a.use_count(), 2u);
        EXPECT_EQ(b.use_count(), 2u);
    }
    EXPECT_EQ(a.use_count(), 1u);
}

TEST(Week08SharedPtr, MoveConstructorTransfersOwnership) {
    course::SharedPtr<Counter> a(new Counter(5));
    course::SharedPtr<Counter> b(std::move(a));

    EXPECT_EQ(a.get(), nullptr);
    EXPECT_EQ(a.use_count(), 0u);
    ASSERT_NE(b.get(), nullptr);
    EXPECT_EQ(b.use_count(), 1u);
}

TEST(Week08SharedPtr, ResetCanDropOwnership) {
    Counter::destructions = 0;
    {
        course::SharedPtr<Counter> ptr(new Counter(9));
        ptr.reset();
        EXPECT_EQ(ptr.get(), nullptr);
        EXPECT_EQ(ptr.use_count(), 0u);
    }
    EXPECT_GE(Counter::destructions, 1);
}
