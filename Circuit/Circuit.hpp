#pragma once

#include <type_traits>

#define implicit
namespace CircuitPP
{

    template <unsigned int n, typename ValueT>
    struct Bus
    {
        using type = ValueT;
        static constexpr auto size = n;
        ValueT value[n] = {ValueT(0)};

        Bus() = default;
        Bus(Bus const &) = default;
        Bus(Bus &&) = default;

        template <typename T, typename = typename std::enable_if_t<std::is_integral_v<T>>>
        explicit Bus(T const &v)
        {
            for (auto i = 0; i < n; ++i)
            {
                value[i] = ValueT((v >> i) & 1);
            }
        }

        template <typename T>
        Bus &operator=(T const &v)
        {
            for (auto i = 0; i < n; ++i)
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
        return Bus<size, ValueT>(v);
    }

    /*
     *
     * ADDER
     * 
     */

    template <typename ValueT>
    constexpr inline auto adder_half(const ValueT a, const ValueT b)
    {
        Bus<2, ValueT> result;
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
    constexpr inline auto adder_full(const ValueT a, const ValueT b, const ValueT c_in)
    {
        Bus<2, ValueT> result;
        result[0] = a ^ b ^ c_in;
        result[1] = (a & b) | (a & c_in) | (b & c_in);
        return result;
    }

    template <unsigned int n, typename ValueT>
    constexpr inline auto adder_ripple(const Bus<n, ValueT> &a, const Bus<n, ValueT> &b, const ValueT c_in)
    {
        Bus<n + 1, ValueT> result;
        ValueT carry = c_in;
        for (auto i = 0; i < n; ++i)
        {
            auto res = adder_full(a[i], b[i], carry);
            result[i] = res[0];
            carry = res[1];
        }
        result[n] = carry;
        return result;
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
        Bus<3, ValueT> result;
        result[0] /*s*/ = (a ^ b) ^ c_in;
        result[1] /*p*/ = (a | b);
        result[2] /*g*/ = (a & b);
        return result;
    }

    template <unsigned int n, typename ValueT>
    constexpr inline auto adder_lookahead(const Bus<n, ValueT> &a, const Bus<n, ValueT> &b, const ValueT c_in)
    {
        Bus<n + 1, ValueT> result;
        ValueT carry = c_in;
        for (auto i = 0; i < n; ++i)
        {
            auto res = adder_full(a[i], b[i], carry);
            result[i] = res[0];
            carry = res[1];
        }
        result[n] = carry;
        return result;
    }
}
#undef implicit
