#include "course/week06_linked_list.hpp"

#include <stdexcept>

namespace course {

LinkedList::LinkedList() : head_(nullptr), size_(0) {}

LinkedList::~LinkedList() = default;

void LinkedList::push_front(int value) {
    (void)value;
    throw std::logic_error("Week 06 push_front() not implemented");
}

bool LinkedList::contains(int value) const {
    (void)value;
    throw std::logic_error("Week 06 contains() not implemented");
}

std::size_t LinkedList::size() const noexcept {
    return size_;
}

void LinkedList::clear() noexcept {
}

}  // namespace course
