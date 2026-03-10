#include "course/hashmap.hpp"

#include <gtest/gtest.h>
#include <string>

TEST(HashMapPublicTest, InsertAndFindBasicKey) {
    course::HashMap<std::string, int> m;
    m.insert("a", 1);

    EXPECT_TRUE(m.contains("a"));
    auto* value = m.find("a");
    ASSERT_NE(value, nullptr);
    EXPECT_EQ(*value, 1);
}

TEST(HashMapPublicTest, MissingKeyReturnsNull) {
    course::HashMap<int, int> m;
    EXPECT_FALSE(m.contains(42));
    EXPECT_EQ(m.find(42), nullptr);
}

TEST(HashMapPublicTest, EraseRemovesPresentKey) {
    course::HashMap<int, int> m;
    m.insert(5, 50);
    EXPECT_TRUE(m.erase(5));
    EXPECT_FALSE(m.contains(5));
}

TEST(HashMapPublicTest, DuplicateInsertUsesConsistentPolicy) {
    course::HashMap<int, int> m;
    m.insert(1, 10);
    m.insert(1, 99);

    auto* value = m.find(1);
    ASSERT_NE(value, nullptr);
    // Accept overwrite semantics for the public suite.
    EXPECT_EQ(*value, 99);
}

// TODO(student):
// Add collision-heavy tests with adversarial keys.
// Add randomized model-based tests against std::unordered_map.
// Add explicit rehash correctness tests.
