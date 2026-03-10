#pragma once

#include <cstddef>

namespace course {

template <typename T>
class SharedPtr {
public:
    SharedPtr() noexcept : ptr_(nullptr), count_(nullptr) {}
    explicit SharedPtr(T* ptr) : ptr_(ptr), count_(ptr ? new std::size_t(1) : nullptr) {}

    ~SharedPtr();

    SharedPtr(const SharedPtr& other) noexcept;
    SharedPtr& operator=(const SharedPtr& other) noexcept;

    SharedPtr(SharedPtr&& other) noexcept;
    SharedPtr& operator=(SharedPtr&& other) noexcept;

    T* get() const noexcept { return ptr_; }
    std::size_t use_count() const noexcept { return count_ ? *count_ : 0; }

    void reset(T* ptr = nullptr);

    T& operator*() const noexcept { return *ptr_; }
    T* operator->() const noexcept { return ptr_; }

private:
    T* ptr_;
    std::size_t* count_;
};

}  // namespace course

#include "week08_shared_ptr.tpp"
