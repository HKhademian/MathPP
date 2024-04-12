#pragma once

#include <type_traits>
#include "./Eval.hpp"

#define implicit
namespace CircuitPP
{
    template <typename _ValueT, unsigned int _N>
    struct Bus
    {
        using ValueT = _ValueT;
        static constexpr auto size = _N;
        ValueT value[size] = {ValueT(0)};

        Bus() = default;
        Bus(Bus const &) = default;
        Bus(Bus &&) = default;

        template <typename T, typename = typename std::enable_if_t<std::is_integral_v<T>>>
        explicit Bus(T const &v)
        {
            for (auto i = 0; i < size; ++i)
            {
                value[i] = ValueT((v >> i) & 1);
            }
        }

        template <typename T>
        Bus &operator=(T const &v)
        {
            for (auto i = 0; i < size; ++i)
            {
                value[i] = v[i];
            }
            return *this;
        }

        constexpr inline ValueT const &operator[](unsigned int i) const { return value[i]; }
        constexpr inline ValueT &operator[](unsigned int i) { return value[i]; }
    };

    template <typename ValueT, typename T>
    constexpr inline auto busOf(T const &v)
    {
        constexpr unsigned int size = sizeof(T) * 8;
        return Bus<ValueT, size>(v);
    }

    template <typename ValueT, unsigned int N>
    struct EvalType<Bus<ValueT, N>>
    {
        static constexpr inline auto eval(Bus<ValueT, N> const &input, unsigned int tick)
        {
            return input; //(*input)(tick);
        }
    };

}
#undef implicit
