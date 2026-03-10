#pragma once

namespace course {

template <typename T>
SharedPtr<T>::~SharedPtr() {
}

template <typename T>
SharedPtr<T>::SharedPtr(const SharedPtr& other) noexcept : ptr_(other.ptr_), count_(other.count_) {
}

template <typename T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr& other) noexcept {
    if (this != &other) {
        ptr_ = other.ptr_;
        count_ = other.count_;
    }
    return *this;
}

template <typename T>
SharedPtr<T>::SharedPtr(SharedPtr&& other) noexcept : ptr_(other.ptr_), count_(other.count_) {
    other.ptr_ = nullptr;
    other.count_ = nullptr;
}

template <typename T>
SharedPtr<T>& SharedPtr<T>::operator=(SharedPtr&& other) noexcept {
    if (this != &other) {
        ptr_ = other.ptr_;
        count_ = other.count_;
        other.ptr_ = nullptr;
        other.count_ = nullptr;
    }
    return *this;
}

template <typename T>
void SharedPtr<T>::reset(T* ptr) {
    ptr_ = ptr;
    count_ = ptr ? new std::size_t(1) : nullptr;
}

}  // namespace course
