#pragma once
#include <cstddef>
#include "Types.hpp"

namespace MathPP
{

    enum Trilean
    {
        NEG = -1,
        ZER = 0,
        POS = 1,
    };

    /*
     * Kleene and Priest logics
     * https://en.wikipedia.org/wiki/Three-valued_logic
     */

    Trilean operator!(Trilean const &&rhs)
    {
        if (rhs == ZER)
            return ZER;
        if (rhs == POS)
            return NEG;
        return POS;
    }

    constexpr inline Trilean operator&(Trilean const &&lhs, Trilean const &&rhs)
    {
        if (lhs == NEG || rhs == NEG)
            return NEG;
        if (lhs == ZER || rhs == ZER)
            return ZER;
        return POS;
    }

    constexpr inline Trilean operator|(Trilean const &&lhs, Trilean const &&rhs)
    {
        if (lhs == POS || rhs == POS)
            return POS;
        if (lhs == ZER || rhs == ZER)
            return ZER;
        return NEG;
    }

    constexpr inline Trilean operator^(Trilean const &&lhs, Trilean const &&rhs)
    {
        if (lhs == ZER || rhs == ZER)
            return ZER;
        if (lhs == rhs)
            return NEG;
        return POS;
    }

    constexpr inline Trilean operator*(Trilean const &&lhs, Trilean const &&rhs)
    {
        if (lhs == ZER || rhs == ZER)
            return ZER;
        if (lhs == rhs)
            return POS;
        return NEG;
    }
}