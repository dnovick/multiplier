#pragma once

#include <vector>
#include <span>
#include <type_traits>

namespace Multiplier {

    //TODO: Reuse std iterator concepts or redo this to use concepts syntax.

    //https://stackoverflow.com/questions/13830158/check-if-a-variable-type-is-iterable
    template <typename T, typename = void>
    struct is_iterable : std::false_type {};

    // this gets used only when we can call std::begin() and std::end() on that type
    template <typename T>
    struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<T&>())),
                                    decltype(std::end(std::declval<T&>()))
                                    >
                    > : std::true_type {};

    // Here is a helper:
    template <typename T>
    constexpr bool is_iterable_v = is_iterable<T>::value;



    template<typename InColl, typename OutColl = InColl>
    inline auto multiplyElement(const InColl& coll, size_t count) -> OutColl {
        
        static_assert(is_iterable_v<InColl>);

        OutColl prod;

        for(auto i = 0U; i < count; i++)
        {
            prod.insert(prod.end(), coll.begin(), coll.end());
        }

        return prod;

    }

    template<typename InColl, typename OutColl = InColl>
    inline auto operator*(const InColl& coll, size_t count) -> OutColl {
        
        return multiplyElement(coll, count);
    }

} //namespace multiplier