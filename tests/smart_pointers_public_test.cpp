#include "course/shared_ptr.hpp"
#include "course/unique_ptr.hpp"

#include <gtest/gtest.h>

namespace {
struct Counter {
    static inline int destructions = 0;
    int value = 0;

    explicit Counter(int v = 0) : value(v) {}
    ~Counter() { ++destructions; }
};
}  // namespace

TEST(UniquePtrPublicTest, OwnsRawPointer) {
    auto* raw = new Counter(7);
    course::UniquePtr<Counter> ptr(raw);

    ASSERT_NE(ptr.get(), nullptr);
    EXPECT_EQ(ptr->value, 7);
}

TEST(UniquePtrPublicTest, ReleaseReturnsRawPointerAndNullsOwner) {
    course::UniquePtr<Counter> ptr(new Counter(3));
    Counter* raw = ptr.release();

    ASSERT_NE(raw, nullptr);
    EXPECT_EQ(ptr.get(), nullptr);
    delete raw;
}

TEST(SharedPtrPublicTest, StartsWithUseCountOne) {
    course::SharedPtr<Counter> ptr(new Counter(11));
    EXPECT_EQ(ptr.use_count(), 1u);
    EXPECT_EQ(ptr->value, 11);
}

TEST(SharedPtrPublicTest, CopyIncrementsUseCount) {
    course::SharedPtr<Counter> a(new Counter(1));
    course::SharedPtr<Counter> b(a);

    EXPECT_EQ(a.use_count(), 2u);
    EXPECT_EQ(b.use_count(), 2u);
}

TEST(SharedPtrPublicTest, ResetCanDropOwnership) {
    Counter::destructions = 0;
    {
        course::SharedPtr<Counter> ptr(new Counter(9));
        ptr.reset();
        EXPECT_EQ(ptr.get(), nullptr);
        EXPECT_EQ(ptr.use_count(), 0u);
    }
    EXPECT_GE(Counter::destructions, 1);
}

// TODO(student):
// Add move-assignment tests.
// Add nested-scope tests that check exact destruction count.
// Add reset-after-copy interaction tests.
