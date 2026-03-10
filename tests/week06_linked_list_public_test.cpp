#include "course/week06_linked_list.hpp"

#include <gtest/gtest.h>

TEST(Week06LinkedList, StartsEmpty) {
    course::LinkedList list;
    EXPECT_EQ(list.size(), 0u);
    EXPECT_FALSE(list.contains(1));
}

TEST(Week06LinkedList, PushFrontAddsElements) {
    course::LinkedList list;
    list.push_front(10);
    list.push_front(20);

    EXPECT_EQ(list.size(), 2u);
    EXPECT_TRUE(list.contains(10));
    EXPECT_TRUE(list.contains(20));
}

TEST(Week06LinkedList, ContainsReturnsFalseForMissingValue) {
    course::LinkedList list;
    list.push_front(10);
    EXPECT_FALSE(list.contains(99));
}

TEST(Week06LinkedList, ClearRemovesAllElements) {
    course::LinkedList list;
    list.push_front(1);
    list.push_front(2);
    list.clear();

    EXPECT_EQ(list.size(), 0u);
    EXPECT_FALSE(list.contains(1));
}

TEST(Week06LinkedList, RepeatedClearIsSafe) {
    course::LinkedList list;
    list.clear();
    list.clear();
    EXPECT_EQ(list.size(), 0u);
}
