#include "course/week06_linked_list.hpp"

namespace course {

LinkedList::LinkedList() : head_(nullptr), size_(0) {}

LinkedList::~LinkedList() = default;

void LinkedList::push_front(int value) {
    (void)value;
}

bool LinkedList::contains(int value) const {
    (void)value;
    return false;
}

std::size_t LinkedList::size() const noexcept {
    return size_;
}

void LinkedList::clear() noexcept {
}

}  // namespace course
