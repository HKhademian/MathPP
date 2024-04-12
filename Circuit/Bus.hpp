#pragma once

#include <type_traits>
#include <array>

#include "./Eval.hpp"

#define implicit
namespace CircuitPP
{

    template <typename _ValueT, std::size_t _size>
    using Bus = std::array<_ValueT, _size>;

    template <typename ValueT, std::size_t size, typename T>
    constexpr auto busOf(T const &v) noexcept
    {
        auto result = Bus<ValueT, size>();
        for (auto i = 0; i < size; ++i)
        {
            result[i] = ValueT((v >> i) & 1);
        }
        return result;
    }

    template <typename ValueT, typename T>
    constexpr auto busOf(T const &v) noexcept
    {
        constexpr std::size_t size = sizeof(T) * 8;
        return busOf<ValueT, size, T>(v);
    }

    /** eval for Bus<V,N> */
    template <typename ValueT, std::size_t N>
    struct EvalType<Bus<ValueT, N>>
    {
        using outputT = Bus<EvalOutT<ValueT>, N>;

        static constexpr Bus<EvalOutT<ValueT>, N> eval(Bus<ValueT, N> const &input, std::size_t tick)
        {
            Bus<EvalOutT<ValueT>, N> result;
            for (auto i = 0; i < N; ++i)
            {
                auto v = input[i];
                result[i] = EvalType<ValueT>::eval(v, tick);
            }
            return result;
        }
    };

}
#undef implicit
