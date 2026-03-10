#pragma once

#include <stdexcept>

namespace course {

template <typename T>
Vector<T>::Vector() : data_(nullptr), size_(0), capacity_(0) {}

template <typename T>
Vector<T>::~Vector() {
}

template <typename T>
Vector<T>::Vector(const Vector& other) : data_(nullptr), size_(0), capacity_(0) {
    (void)other;
    throw std::logic_error("Week 07 Vector copy constructor not implemented");
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
    (void)other;
    throw std::logic_error("Week 07 Vector copy assignment not implemented");
}

template <typename T>
Vector<T>::Vector(Vector&& other) noexcept : data_(nullptr), size_(0), capacity_(0) {
    (void)other;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& other) noexcept {
    (void)other;
    return *this;
}

template <typename T>
void Vector<T>::push_back(const T& value) {
    (void)value;
    throw std::logic_error("Week 07 Vector push_back(const T&) not implemented");
}

template <typename T>
void Vector<T>::push_back(T&& value) {
    (void)value;
    throw std::logic_error("Week 07 Vector push_back(T&&) not implemented");
}

template <typename T>
void Vector<T>::pop_back() {
    throw std::logic_error("Week 07 Vector pop_back() not implemented");
}

template <typename T>
void Vector<T>::reserve(std::size_t new_capacity) {
    (void)new_capacity;
    throw std::logic_error("Week 07 Vector reserve() not implemented");
}

template <typename T>
void Vector<T>::clear() noexcept {
}

template <typename T>
std::size_t Vector<T>::size() const noexcept {
    return size_;
}

template <typename T>
std::size_t Vector<T>::capacity() const noexcept {
    return capacity_;
}

template <typename T>
bool Vector<T>::empty() const noexcept {
    return size_ == 0;
}

template <typename T>
T& Vector<T>::operator[](std::size_t index) noexcept {
    return data_[index];
}

template <typename T>
const T& Vector<T>::operator[](std::size_t index) const noexcept {
    return data_[index];
}

template <typename T>
T& Vector<T>::at(std::size_t index) {
    if (index >= size_) {
        throw std::out_of_range("Vector index out of range");
    }
    return data_[index];
}

template <typename T>
const T& Vector<T>::at(std::size_t index) const {
    if (index >= size_) {
        throw std::out_of_range("Vector index out of range");
    }
    return data_[index];
}

template <typename T>
void Vector<T>::grow() {
    throw std::logic_error("Week 07 Vector grow() not implemented");
}

template <typename T>
void Vector<T>::destroy_elements() noexcept {
}

}  // namespace course
