#include "course/lru_cache.hpp"

#include <gtest/gtest.h>
#include <string>

TEST(LruCachePublicTest, BasicPutGetWorks) {
    course::LruCache<int, std::string> cache(2);
    cache.put(1, "one");

    auto value = cache.get(1);
    ASSERT_TRUE(value.has_value());
    EXPECT_EQ(*value, "one");
}

TEST(LruCachePublicTest, EvictsLeastRecentlyUsedEntry) {
    course::LruCache<int, std::string> cache(2);
    cache.put(1, "one");
    cache.put(2, "two");
    (void)cache.get(1);  // make 2 the least recently used
    cache.put(3, "three");

    EXPECT_TRUE(cache.get(1).has_value());
    EXPECT_FALSE(cache.get(2).has_value());
    EXPECT_TRUE(cache.get(3).has_value());
}

TEST(LruCachePublicTest, UpdatingExistingKeyDoesNotIncreaseLogicalSizePastCapacity) {
    course::LruCache<int, std::string> cache(2);
    cache.put(1, "one");
    cache.put(1, "ONE");
    EXPECT_LE(cache.size(), cache.capacity());

    auto value = cache.get(1);
    ASSERT_TRUE(value.has_value());
    EXPECT_EQ(*value, "ONE");
}

// TODO(student):
// Add capacity-1 and capacity-0 edge cases.
// Add exact recency-order scenario tests.
// Add long random sequences checked against a reference model.
