#pragma once

#include <cstddef>
#include <new>
#include <stdexcept>
#include <utility>

namespace course {

template <typename T>
class Vector {
public:
    Vector();
    ~Vector();

    Vector(const Vector& other);
    Vector& operator=(const Vector& other);

    Vector(Vector&& other) noexcept;
    Vector& operator=(Vector&& other) noexcept;

    void push_back(const T& value);
    void push_back(T&& value);
    void pop_back();

    void reserve(std::size_t new_capacity);
    void clear() noexcept;

    [[nodiscard]] std::size_t size() const noexcept;
    [[nodiscard]] std::size_t capacity() const noexcept;
    [[nodiscard]] bool empty() const noexcept;

    T& operator[](std::size_t index) noexcept;
    const T& operator[](std::size_t index) const noexcept;

    T& at(std::size_t index);
    const T& at(std::size_t index) const;

private:
    T* data_;
    std::size_t size_;
    std::size_t capacity_;

    void grow();
    void destroy_elements() noexcept;
};

}  // namespace course

#include "vector.tpp"
