#pragma once

#include <cstddef>

namespace course {

class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    void push_front(int value);
    bool contains(int value) const;
    std::size_t size() const noexcept;
    void clear() noexcept;

private:
    struct Node {
        int value;
        Node* next;
    };

    Node* head_;
    std::size_t size_;
};

}  // namespace course
