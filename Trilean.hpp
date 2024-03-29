#pragma once
#include <cstddef>
#include "Types.hpp"

namespace MathPP
{
    struct Trilean;

    struct Trilean
    {
    private:
        sign_t value;

    public:
        constexpr Trilean() : Trilean(ZERO){};
        constexpr Trilean(sign_t value) : value(sign(value)){};
        constexpr Trilean(Trilean const &value) : Trilean(sign(value.value)){};
        constexpr Trilean(Trilean const &&value) : Trilean(sign(value.value)){};
        explicit constexpr Trilean(signed int value) : Trilean(sign(value)){};
        explicit constexpr Trilean(bool value) : Trilean(sign(value)){};
        explicit constexpr Trilean(char value) : Trilean(sign(value)){};
        explicit constexpr Trilean(signed char value) : Trilean(sign(value)){};
        explicit constexpr Trilean(signed short value) : Trilean(sign(value)){};
        explicit constexpr Trilean(signed long value) : Trilean(sign(value)){};
        explicit constexpr Trilean(signed long long value) : Trilean(sign(value)){};
        explicit constexpr Trilean(float value) : Trilean(sign(value)){};
        explicit constexpr Trilean(double value) : Trilean(sign(value)){};
        explicit constexpr Trilean(long double value) : Trilean(sign(value)){};

    public:
        constexpr inline bool operator==(Trilean rhs) const { return rhs.value == value; }
        constexpr inline bool operator!=(Trilean rhs) const { return rhs.value != value; }

        /*explicit*/ constexpr inline operator signed int() const { return value; }
        /** TODO: is this ok? */
        explicit constexpr inline operator bool() const { return value >= 0; }
        explicit constexpr inline operator char() const { return value; }
        explicit constexpr inline operator signed char() const { return value; }
        explicit constexpr inline operator signed short() const { return value; }
        explicit constexpr inline operator signed long() const { return value; }
        explicit constexpr inline operator signed long long() const { return value; }
        explicit constexpr inline operator float() const { return value; }
        explicit constexpr inline operator double() const { return value; }
        explicit constexpr inline operator long double() const { return value; }

    public:
        constexpr inline auto &operator=(Trilean const &rhs)
        {
            value = rhs.value;
            return *this;
        }
    };

    constexpr static const auto NEG = Trilean(-1);
    constexpr static const auto ZER = Trilean(0);
    constexpr static const auto POS = Trilean(+1);

    /*
     * Kleene and Priest logics
     * https://en.wikipedia.org/wiki/Three-valued_logic
     */

    constexpr inline Trilean operator!(Trilean const &rhs)
    {
        if (rhs == ZER)
            return ZER;
        if (rhs == POS)
            return NEG;
        return POS;
    }

    constexpr inline Trilean operator&(Trilean const &lhs, Trilean const &rhs)
    {
        if (lhs == NEG || rhs == NEG)
            return NEG;
        if (lhs == ZER || rhs == ZER)
            return ZER;
        return POS;
    }

    constexpr inline Trilean operator|(Trilean const &lhs, Trilean const &rhs)
    {
        if (lhs == POS || rhs == POS)
            return POS;
        if (lhs == ZER || rhs == ZER)
            return ZER;
        return NEG;
    }

    constexpr inline Trilean operator^(Trilean const &lhs, Trilean const &rhs)
    {
        if (lhs == ZER || rhs == ZER)
            return ZER;
        if (lhs == rhs)
            return NEG;
        return POS;
    }

    // constexpr inline auto operator+(Trilean const &lhs, Trilean const &rhs)
    // {
    //     return char(lhs) + char(rhs);
    // }
    //
    // constexpr inline auto operator-(Trilean const &lhs, Trilean const &rhs)
    // {
    //     return char(lhs) - char(rhs);
    // }

    constexpr inline Trilean operator*(Trilean const &lhs, Trilean const &rhs)
    {
        if (lhs == ZER || rhs == ZER)
            return ZER;
        if (lhs == rhs)
            return POS;
        return NEG;
    }

    // constexpr inline auto operator*(Trilean const &lhs, char const &rhs)
    // {
    //     return char(lhs) * rhs;
    // }
    //
    // constexpr inline auto operator*(char const &lhs, Trilean const &rhs)
    // {
    //     return lhs * char(rhs);
    // }

    constexpr inline auto operator/(Trilean const &lhs, Trilean const &rhs)
    {
        return lhs * rhs;
    }
}