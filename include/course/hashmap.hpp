#pragma once

#include <cstddef>

namespace course {

template <typename K, typename V>
class HashMap {
public:
    HashMap() : size_(0) {}

    void insert(const K& key, const V& value) {
        (void)key;
        (void)value;
        // TODO(student): implement insert / overwrite policy.
    }

    bool contains(const K& key) const {
        (void)key;
        return false;
    }

    V* find(const K& key) {
        (void)key;
        return nullptr;
    }

    const V* find(const K& key) const {
        (void)key;
        return nullptr;
    }

    bool erase(const K& key) {
        (void)key;
        return false;
    }

    void rehash(std::size_t new_bucket_count) {
        (void)new_bucket_count;
        // TODO(student): reallocate bucket storage and reinsert existing entries.
    }

    [[nodiscard]] std::size_t size() const noexcept {
        return size_;
    }

    [[nodiscard]] bool empty() const noexcept {
        return size_ == 0;
    }

private:
    std::size_t size_;
    // TODO(student): choose chaining or open addressing and define storage.
};

}  // namespace course
