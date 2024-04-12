#pragma once

#include "./Eval.hpp"

#define implicit
namespace CircuitPP
{
    /*
     *
     * DIGITAL_VALUE
     *
     */

    enum class DigitalV : bool
    {
        V0 = false,
        V1 = true
    };

    template <>
    struct EvalType<DigitalV>
    {
        using inputT = DigitalV;
        using outputT = DigitalV;

        static outputT eval(inputT input, tick_t tick)
        {
            return input;
        }
    };

    constexpr inline auto operator!(DigitalV const &value) noexcept
    {
        return DigitalV(!bool(value));
    }

    constexpr inline auto operator&(DigitalV const &lhs, DigitalV const &rhs) noexcept
    {
        return DigitalV(bool(lhs) & bool(rhs));
    }

    constexpr inline auto operator|(DigitalV const &lhs, DigitalV const &rhs) noexcept
    {
        return DigitalV(bool(lhs) | bool(rhs));
    }

    constexpr inline auto operator^(DigitalV const &lhs, DigitalV const &rhs) noexcept
    {
        return DigitalV(bool(lhs) ^ bool(rhs));
    }

    // constexpr inline auto operator==(DigitalV const &lhs, DigitalV const &rhs) noexcept
    // {
    //     return bool(lhs) == bool(rhs);
    // }

    // constexpr inline auto operator!=(DigitalV const &lhs, DigitalV const &rhs) noexcept
    // {
    //     return bool(lhs) != bool(rhs);
    // }
}
#undef implicit
