#pragma once

#include <type_traits>
#include <algorithm>

#define implicit
namespace CircuitPP
{

    template <typename ValueT, unsigned int _N>
    struct Bus
    {
        using type = ValueT;
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
        constexpr auto size = sizeof(T) * 8;
        return Bus<ValueT, size>(v);
    }

    /*
     *
     * ADDER
     *
     */

    template <typename ValueT>
    constexpr inline auto adder_half(const ValueT a, const ValueT b)
    {
        Bus<ValueT, 2> result;
        result[0] = a ^ b;
        result[1] = a & b;
        return result;
    }

    /**
     * sum of a, b, and c_in
     * will calculate carry and sum signals
     * https://en.wikipedia.org/wiki/Adder_(electronics)#Ripple-carry_adder
     */
    template <typename ValueT>
    constexpr inline auto adder_full(
        const ValueT a, const ValueT b, const ValueT c_in,
        ValueT &s, ValueT &c_out)
    {
        auto c = c_in;
        s = a ^ b ^ c;
        c_out = (a & b) | (a & c) | (b & c);
    }

    template <unsigned int n, unsigned int m, typename ValueT>
    constexpr inline auto adder_ripple(
        const Bus<ValueT, n> &a,
        const Bus<ValueT, m> &b,
        const ValueT c_in,
        Bus<ValueT, std::max(n, m) + 1> &s)
    {
        ValueT carry = c_in;
        for (auto i = 0; i < std::max(n, m); ++i)
        {
            adder_full(
                i < n ? a[i] : ValueT(0),
                i < m ? b[i] : ValueT(0),
                carry,
                s[i], carry);
        }
        s[s.size - 1] = carry;
    }

    template <unsigned int n, unsigned int m, typename ValueT>
    constexpr inline auto adder_ripple(
        const Bus<ValueT, n> &a,
        const Bus<ValueT, m> &b,
        const ValueT c_in)
    {
        Bus<ValueT, std::max(n, m) + 1> s;
        adder_ripple(a, b, c_in, s);
        return s;
    }

    /**
     * sum of a, b, and c_in
     * will calculate Propagate and Generate signals
     * https://en.wikipedia.org/wiki/Adder_(electronics)#Carry-lookahead_adder
     * https://en.wikipedia.org/wiki/Carry-lookahead_adder
     */
    template <typename ValueT>
    constexpr inline auto adder_pg(const ValueT a, const ValueT b, const ValueT c_in)
    {
        Bus<ValueT, 3> result;
        result[0] /*s*/ = (a ^ b) ^ c_in;
        result[1] /*p*/ = (a | b);
        result[2] /*g*/ = (a & b);
        return result;
    }

    // template <unsigned int n, typename ValueT>
    // constexpr inline auto adder_lookahead(const Bus<n, ValueT> &a, const Bus<n, ValueT> &b, const ValueT c_in)
    // {
    //     Bus<n + 1, ValueT> result;
    //     ValueT carry = c_in;
    //     for (auto i = 0; i < n; ++i)
    //     {
    //         auto res = adder_full(a[i], b[i], carry);
    //         result[i] = res[0];
    //         carry = res[1];
    //     }
    //     result[n] = carry;
    //     return result;
    // }
}
#undef implicit
