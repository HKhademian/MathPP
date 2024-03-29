#pragma once
#include <cstddef>
#include "Types.hpp"

#define implicit
namespace MathPP
{
    /** Tri-State Value */
    struct Trilean;

    struct Trilean
    {
    private:
        sign_t value;

    public:
        /* ******* CTORS ******* */
        implicit constexpr Trilean(sign_t value) : value(sign(value)){};
        implicit constexpr Trilean();
        implicit constexpr Trilean(Trilean const &value);
        implicit constexpr Trilean(Trilean const &&value);
        explicit constexpr Trilean(signed int value);
        explicit constexpr Trilean(bool value);
        explicit constexpr Trilean(char value);
        explicit constexpr Trilean(signed char value);
        explicit constexpr Trilean(signed short value);
        explicit constexpr Trilean(signed long value);
        explicit constexpr Trilean(signed long long value);
        explicit constexpr Trilean(float value);
        explicit constexpr Trilean(double value);
        explicit constexpr Trilean(long double value);
        /* ******* operators ******* */
        constexpr inline Trilean &operator=(Trilean const &rhs);
        constexpr inline bool operator==(Trilean rhs) const;
        constexpr inline bool operator!=(Trilean rhs) const;
        /* ******* cast operators ******* */
        implicit constexpr inline operator signed int() const;
        explicit constexpr inline operator bool() const;
        explicit constexpr inline operator char() const;
        explicit constexpr inline operator signed char() const;
        explicit constexpr inline operator signed short() const;
        explicit constexpr inline operator signed long() const;
        explicit constexpr inline operator signed long long() const;
        explicit constexpr inline operator float() const;
        explicit constexpr inline operator double() const;
        explicit constexpr inline operator long double() const;
    };
    /* ******* ENUM like values ******* */
    constexpr static const auto NEG = Trilean(NEGATIVE);
    constexpr static const auto ZER = Trilean(ZERO);
    constexpr static const auto POS = Trilean(POSITIVE);
    /* ******* logic operators ******* */
    constexpr inline Trilean operator!(Trilean const &rhs);
    constexpr inline Trilean operator&(Trilean const &lhs, Trilean const &rhs);
    constexpr inline Trilean operator|(Trilean const &lhs, Trilean const &rhs);
    constexpr inline Trilean operator^(Trilean const &lhs, Trilean const &rhs);
    /* ******* math operators ******* */
    constexpr inline Trilean operator*(Trilean const &lhs, Trilean const &rhs);
    // constexpr inline Trilean operator/(Trilean const &lhs, Trilean const &rhs);
    // constexpr inline signed char operator+(Trilean const &lhs, Trilean const &rhs);
    // constexpr inline signed char operator-(Trilean const &lhs, Trilean const &rhs);
    // constexpr inline signed char operator*(Trilean const &lhs, char const &rhs);
    // constexpr inline signed char operator/(Trilean const &lhs, char const &rhs);

    /*
     *
     *  IMPL
     *
     */

    constexpr Trilean::Trilean() : Trilean(ZERO){};
    constexpr Trilean::Trilean(Trilean const &value) : Trilean(sign(value.value)){};
    constexpr Trilean::Trilean(Trilean const &&value) : Trilean(sign(value.value)){};
    constexpr Trilean::Trilean(signed int value) : Trilean(sign(value)){};
    constexpr Trilean::Trilean(bool value) : Trilean(sign(value)){};
    constexpr Trilean::Trilean(char value) : Trilean(sign(value)){};
    constexpr Trilean::Trilean(signed char value) : Trilean(sign(value)){};
    constexpr Trilean::Trilean(signed short value) : Trilean(sign(value)){};
    constexpr Trilean::Trilean(signed long value) : Trilean(sign(value)){};
    constexpr Trilean::Trilean(signed long long value) : Trilean(sign(value)){};
    constexpr Trilean::Trilean(float value) : Trilean(sign(value)){};
    constexpr Trilean::Trilean(double value) : Trilean(sign(value)){};
    constexpr Trilean::Trilean(long double value) : Trilean(sign(value)){};

    constexpr Trilean &Trilean::operator=(Trilean const &rhs) { return (value = rhs.value), *this; }

    constexpr bool Trilean::operator==(Trilean rhs) const { return rhs.value == value; }
    constexpr bool Trilean::operator!=(Trilean rhs) const { return rhs.value != value; }

    constexpr Trilean::operator signed int() const { return value; }
    constexpr Trilean::operator bool() const { return value >= 0; }
    constexpr Trilean::operator char() const { return value; }
    constexpr Trilean::operator signed char() const { return value; }
    constexpr Trilean::operator signed short() const { return value; }
    constexpr Trilean::operator signed long() const { return value; }
    constexpr Trilean::operator signed long long() const { return value; }
    constexpr Trilean::operator float() const { return value; }
    constexpr Trilean::operator double() const { return value; }
    constexpr Trilean::operator long double() const { return value; }

    /*
     * Kleene and Priest logics
     * https://en.wikipedia.org/wiki/Three-valued_logic
     */

    constexpr Trilean operator!(Trilean const &rhs)
    {
        if (rhs == ZER)
            return ZER;
        if (rhs == POS)
            return NEG;
        return POS;
    }

    constexpr Trilean operator&(Trilean const &lhs, Trilean const &rhs)
    {
        if (lhs == NEG || rhs == NEG)
            return NEG;
        if (lhs == ZER || rhs == ZER)
            return ZER;
        return POS;
    }

    constexpr Trilean operator|(Trilean const &lhs, Trilean const &rhs)
    {
        if (lhs == POS || rhs == POS)
            return POS;
        if (lhs == ZER || rhs == ZER)
            return ZER;
        return NEG;
    }

    constexpr Trilean operator^(Trilean const &lhs, Trilean const &rhs)
    {
        if (lhs == ZER || rhs == ZER)
            return ZER;
        if (lhs == rhs)
            return NEG;
        return POS;
    }

    constexpr Trilean operator*(Trilean const &lhs, Trilean const &rhs)
    {
        if (lhs == ZER || rhs == ZER)
            return ZER;
        if (lhs == rhs)
            return POS;
        return NEG;
    }

    // constexpr auto operator+(Trilean const &lhs, Trilean const &rhs)
    // {
    //     return char(lhs) + char(rhs);
    // }
    //
    // constexpr auto operator-(Trilean const &lhs, Trilean const &rhs)
    // {
    //     return char(lhs) - char(rhs);
    // }
    //
    // constexpr auto operator*(Trilean const &lhs, char const &rhs)
    // {
    //     return char(lhs) * rhs;
    // }
    //
    // constexpr auto operator*(char const &lhs, Trilean const &rhs)
    // {
    //     return lhs * char(rhs);
    // }
    //
    // constexpr auto operator/(Trilean const &lhs, Trilean const &rhs)
    // {
    //     return lhs * rhs;
    // }
}
#undef implicit
