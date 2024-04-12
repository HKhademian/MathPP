#pragma once

#include "./Bus.hpp"

#define implicit
namespace CircuitPP
{

    template <typename ValueT, std::size_t N, typename InputT = long long int>
    constexpr inline auto busOf(InputT v = InputT(0)) noexcept
    {
        auto result = Bus<ValueT, N>();
        for (auto i = 0; i < N; ++i)
        {
            result[i] = ValueT((v >> i) & 1);
        }
        return result;
    }

    template <typename ValueT, typename InputT = long long int, std::size_t N = (sizeof(InputT) * 8)>
    constexpr inline auto busOf(InputT v = InputT(0)) noexcept
    {
        return busOf<ValueT, N, InputT>(v);
    }

    template <std::size_t N = 0, typename ValueT = bool, typename InputT = long long int>
    constexpr inline auto busOf(InputT v = InputT(0)) noexcept
    {
        return busOf<ValueT, N, InputT>(v);
    }

    template <typename ValueT, std::size_t N>
    constexpr inline auto operator>>(Bus<ValueT, N> const &lhs, const std::size_t M) noexcept
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
    constexpr inline auto operator<<(Bus<ValueT, N> const &lhs, const std::size_t M) noexcept
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

    template <typename ValueT, std::size_t N>
    constexpr inline auto operator&(Bus<ValueT, N> const &lhs, Bus<ValueT, N> const &rhs) noexcept
    {
        auto result = Bus<ValueT, N>();
        for (auto i = 0; i < N; ++i)
        {
            result[i] = lhs[i] & rhs[i];
        }
        return result;
    }

    template <typename ValueT, std::size_t N>
    constexpr inline auto operator|(Bus<ValueT, N> const &lhs, Bus<ValueT, N> const &rhs) noexcept
    {
        auto result = Bus<ValueT, N>();
        for (auto i = 0; i < N; ++i)
        {
            result[i] = lhs[i] | rhs[i];
        }
        return result;
    }

    template <typename ValueT, std::size_t N>
    constexpr inline auto operator^(Bus<ValueT, N> const &lhs, Bus<ValueT, N> const &rhs) noexcept
    {
        auto result = Bus<ValueT, N>();
        for (auto i = 0; i < N; ++i)
        {
            result[i] = lhs[i] ^ rhs[i];
        }
        return result;
    }

    template <typename ValueT, std::size_t N>
    constexpr inline auto operator!(Bus<ValueT, N> const &rhs) noexcept
    {
        auto result = Bus<ValueT, N>();
        for (auto i = 0; i < N; ++i)
        {
            result[i] = !rhs[i];
        }
        return result;
    }

}
#undef implicit
