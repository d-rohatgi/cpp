#pragma once

#include <cstddef>
#include <optional>

namespace course {

template <typename K, typename V>
class LruCache {
public:
    explicit LruCache(std::size_t capacity) : capacity_(capacity), size_(0) {}

    std::optional<V> get(const K& key) {
        (void)key;
        return std::nullopt;
    }

    void put(const K& key, const V& value) {
        (void)key;
        (void)value;
        // TODO(student): insert/update and maintain recency ordering.
    }

    [[nodiscard]] std::size_t size() const noexcept {
        return size_;
    }

    [[nodiscard]] std::size_t capacity() const noexcept {
        return capacity_;
    }

private:
    std::size_t capacity_;
    std::size_t size_;
    // TODO(student): combine hashmap with a doubly linked list or equivalent.
};

}  // namespace course
