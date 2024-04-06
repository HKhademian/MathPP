#pragma once

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

    constexpr auto operator!(DigitalV const &value)
    {
        return DigitalV(!bool(value));
    }

    constexpr auto operator&(DigitalV const &lhs, DigitalV const &rhs)
    {
        return DigitalV(bool(lhs) & bool(rhs));
    }

    constexpr auto operator|(DigitalV const &lhs, DigitalV const &rhs)
    {
        return DigitalV(bool(lhs) | bool(rhs));
    }

    constexpr auto operator^(DigitalV const &lhs, DigitalV const &rhs)
    {
        return DigitalV(bool(lhs) ^ bool(rhs));
    }

    // constexpr auto operator==(DigitalV const &lhs, DigitalV const &rhs)
    // {
    //     return bool(lhs) == bool(rhs);
    // }

    // constexpr auto operator!=(DigitalV const &lhs, DigitalV const &rhs)
    // {
    //     return bool(lhs) != bool(rhs);
    // }
}
#undef implicit