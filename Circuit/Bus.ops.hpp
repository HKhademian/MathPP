#pragma once

#include "./Bus.hpp"

#define implicit
namespace CircuitPP
{

    template <typename ValueT, std::size_t size, typename T = int>
    constexpr auto busOf(T const &v = T(0)) noexcept
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

    template <typename ValueT, std::size_t N>
    constexpr auto operator>>(Bus<ValueT, N> const &lhs, const std::size_t M) noexcept
    {
        auto result = Bus<ValueT, N>();
        const auto size = N > M ? N - M : 0;

        for (auto i = 0; i < size; ++i)
        {
            result[i] = lhs[i + M];
        }
        // rest (right) is zero (default)

        return result;
    }

    template <typename ValueT, std::size_t N>
    constexpr auto operator<<(Bus<ValueT, N> const &lhs, const std::size_t M) noexcept
    {
        auto result = Bus<ValueT, N>();
        const auto size = N > M ? N - M : 0;

        // rest (left) is zero (default)
        for (auto i = 0; i < size; ++i)
        {
            result[i + M] = lhs[i];
        }

        return result;
    }

}
#undef implicit
