#pragma once
#include <cstddef>
#include "Types.hpp"

namespace MathPP
{
    struct Trilean;

    struct Trilean
    {
    private:
        signed char value;

    public:
        constexpr static inline auto NEG()
        {
            return Trilean(sign(-1));
        }

        constexpr static inline auto ZER()
        {
            return Trilean(sign(0));
        }

        constexpr static inline auto POS()
        {
            return Trilean(sign(+1));
        }

    public:
        constexpr Trilean() : value(0){};
        constexpr Trilean(Trilean const &value) : value(value.value){};
        explicit constexpr Trilean(bool value) : value(sign(value)){};
        explicit constexpr Trilean(char value) : value(sign(value)){};
        explicit constexpr Trilean(signed char value) : value(sign(value)){};
        explicit constexpr Trilean(signed short value) : value(sign(value)){};
        explicit constexpr Trilean(signed int value) : value(sign(value)){};
        explicit constexpr Trilean(signed long value) : value(sign(value)){};
        explicit constexpr Trilean(signed long long value) : value(sign(value)){};
        explicit constexpr Trilean(float value) : value(sign(value)){};
        explicit constexpr Trilean(double value) : value(sign(value)){};
        explicit constexpr Trilean(long double value) : value(sign(value)){};

    public:
        constexpr inline bool operator==(Trilean rhs) const { return rhs.value == value; }
        constexpr inline bool operator!=(Trilean rhs) const { return rhs.value != value; }

        /** TODO: is this ok? */
        explicit constexpr inline operator bool() const { return value >= 0; }
        explicit constexpr inline operator char() const { return value; }
        explicit constexpr inline operator signed char() const { return value; }
        explicit constexpr inline operator signed short() const { return value; }
        /*explicit*/ constexpr inline operator signed int() const { return value; }
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

    constexpr static const auto NEG = Trilean::NEG();
    constexpr static const auto ZER = Trilean::ZER();
    constexpr static const auto POS = Trilean::POS();

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