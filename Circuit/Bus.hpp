#pragma once

#include <type_traits>
#include <array>

#include "./Eval.hpp"

#define implicit
namespace CircuitPP
{

    template <typename _ValueT, std::size_t _N>
    // using Bus = std::array<_ValueT, _N>;
    struct Bus : public std::array<_ValueT, _N>
    {
        using ValueT = _ValueT;
        static constexpr auto N = _N;
    };

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
