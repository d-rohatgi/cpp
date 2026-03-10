#pragma once

#include <cstddef>

namespace course {

template <typename T>
class SharedPtr {
public:
    SharedPtr() noexcept : ptr_(nullptr), count_(nullptr) {}
    explicit SharedPtr(T* ptr) : ptr_(ptr), count_(ptr ? new std::size_t(1) : nullptr) {}

    ~SharedPtr() {
        // TODO(student): decrement count and delete exactly once.
    }

    SharedPtr(const SharedPtr& other) noexcept : ptr_(other.ptr_), count_(other.count_) {
        // TODO(student): increment reference count when non-null.
    }

    SharedPtr& operator=(const SharedPtr& other) noexcept {
        if (this != &other) {
            // TODO(student): release current, then share ownership.
            ptr_ = other.ptr_;
            count_ = other.count_;
        }
        return *this;
    }

    SharedPtr(SharedPtr&& other) noexcept : ptr_(other.ptr_), count_(other.count_) {
        other.ptr_ = nullptr;
        other.count_ = nullptr;
    }

    SharedPtr& operator=(SharedPtr&& other) noexcept {
        if (this != &other) {
            // TODO(student): release current, steal ownership.
            ptr_ = other.ptr_;
            count_ = other.count_;
            other.ptr_ = nullptr;
            other.count_ = nullptr;
        }
        return *this;
    }

    T* get() const noexcept { return ptr_; }
    std::size_t use_count() const noexcept { return count_ ? *count_ : 0; }

    void reset(T* ptr = nullptr) {
        // TODO(student): release current object and reset to new ownership.
        ptr_ = ptr;
        count_ = ptr ? new std::size_t(1) : nullptr;
    }

    T& operator*() const noexcept { return *ptr_; }
    T* operator->() const noexcept { return ptr_; }

private:
    T* ptr_;
    std::size_t* count_;
};

}  // namespace course
