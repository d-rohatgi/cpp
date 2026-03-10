#pragma once

namespace course {

template <typename It, typename T>
It find(It first, It last, const T& value) {
    // TODO(student): implement generic linear search.
    (void)value;
    return last;
}

template <typename It, typename T>
T accumulate(It first, It last, T init) {
    // TODO(student): implement generic accumulation.
    return init;
}

template <typename InIt, typename OutIt, typename Pred>
OutIt copy_if(InIt first, InIt last, OutIt dest, Pred pred) {
    // TODO(student): copy matching elements to output iterator.
    (void)pred;
    return dest;
}

template <typename It, typename T, typename Compare>
It lower_bound(It first, It last, const T& value, Compare comp) {
    // TODO(student): implement lower_bound for sorted ranges.
    (void)value;
    (void)comp;
    return last;
}

template <typename It, typename T>
It lower_bound(It first, It last, const T& value) {
    return course::lower_bound(first, last, value, [](const auto& a, const auto& b) {
        return a < b;
    });
}

}  // namespace course
