#pragma once

#include <vector>
#include <span>

namespace Multiplier {


using IntVector = std::vector<int>;

template<typename T>
inline auto multiplyElement(const T& elem, size_t count) -> T {
    T prod;

    for(auto i = 0U; i < count; i++)
    {
        prod += elem;
    }

    return prod;
}

template<>
inline auto multiplyElement(const IntVector& elem, size_t count) ->  IntVector {
    IntVector prod;

    for(auto i = 0U; i < count; i++)
    {
        prod.insert(prod.end(), elem.begin(), elem.end());
    }

    return prod;
}

} //namespace Nultiplier