#pragma once
#include <cstddef>
#include <functional>
#include "Types.hpp"

#define implicit
namespace CircuitPP
{

    using tick_t = unsigned short;

    enum DigitalV : bool
    {
        V0 = false,
        V1 = true
    };

    /*
     *
     */
    template <typename ValueT>
    using Logic = std::function<ValueT(tick_t const &)>;

    /*
     *
     */

    template <typename ValueT>
    constexpr inline Logic<ValueT> Wire(const ValueT &value)
    {
        return [value](tick_t const &tick) constexpr -> ValueT
        {
            return ValueT(value);
        };
    }

    template <typename ValueT>
    constexpr inline Logic<ValueT> Wire(const ValueT &&value)
    {
        return [value = value](tick_t const &tick) constexpr -> ValueT
        {
            return ValueT(value);
        };
    }

    template <typename ValueT>
    constexpr inline Logic<ValueT> Wire(const Logic<ValueT> &inputA)
    {
        return [inputA](tick_t const &tick) constexpr -> ValueT
        {
            return ValueT(inputA(tick));
        };
    }

    template <typename ValueT>
    constexpr inline Logic<ValueT> Wire(const Logic<ValueT> &&inputA)
    {
        return [inputA](tick_t const &tick) constexpr -> ValueT
        {
            return ValueT(inputA(tick));
        };
    }

    template <typename ValueT>
    constexpr inline Logic<ValueT> Not(const Logic<ValueT> &inputA)
    {
        return [inputA](tick_t const &tick) constexpr -> ValueT
        {
            return ValueT(!inputA(tick));
        };
    }

    template <typename ValueT>
    constexpr inline Logic<ValueT> Not(const Logic<ValueT> &&inputA)
    {
        return [inputA](tick_t const &tick) constexpr -> ValueT
        {
            return ValueT(!inputA(tick));
        };
    }

    template <typename ValueT>
    constexpr inline Logic<ValueT> And(const Logic<ValueT> &inputA, const Logic<ValueT> &inputB)
    {
        return [inputA, inputB](tick_t const &tick) constexpr -> ValueT
        {
            return ValueT(inputA(tick) & inputB(tick));
        };
    }

    template <typename ValueT>
    constexpr inline Logic<ValueT> Or(const Logic<ValueT> &inputA, const Logic<ValueT> &inputB)
    {
        return [inputA, inputB](tick_t const &tick) constexpr -> ValueT
        {
            return ValueT(inputA(tick) | inputB(tick));
        };
    }

    template <typename ValueT>
    constexpr inline Logic<ValueT> Xor(const Logic<ValueT> &inputA, const Logic<ValueT> &inputB)
    {
        return [inputA, inputB](tick_t const &tick) constexpr -> ValueT
        {
            return ValueT(inputA(tick) ^ inputB(tick));
        };
    }

}
#undef implicit
