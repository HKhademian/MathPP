#pragma once
#include <type_traits>

namespace MathPP
{

    enum sign_t : signed char
    {
        NEGATIVE = -1,
        ZERO = 0,
        POSITIVE = +1,
    };

    template <typename T>
    constexpr inline sign_t sign(T value)
    {
        if (value > 0)
            return POSITIVE;
        if (value < 0)
            return NEGATIVE;
        return ZERO;
    };

    template <>
    constexpr inline sign_t sign<bool>(bool value)
    {
        if (value)
            return POSITIVE;
        return ZERO;
    };

    template <typename T, typename U>
    struct MathOp
    {
    private:
        static T t1, t2;
        static U u1, u2;

    public:
        using plus = typeof(t1 + u1);
        using minus = typeof(t1 - u1);
        using multiply = typeof(t1 * u1);
        using division = typeof(t1 / u1);
        using plus_mult = typeof((t1 * u1) + (t2 * u2));
        using mult_plus = typeof((t1 + u1) * (t2 + u2));
        // typedef typeof(t % u) mod;
        // typedef typeof(t ^ u) Xor;
        // typedef typeof(t | u) Or;
        // typedef typeof(t & u) And;
    };

    template <typename T, T V1, T V2, typename = void>
    struct NumberCmp
    {
    };

    template <typename T, T V1, T V2>
    struct NumberCmp<T, V1, V2, typename std::enable_if<(V1 >= V2)>::type>
    {
        static constexpr T minValue = V2;
        static constexpr T maxValue = V1;
        static constexpr bool isEqual = false;
        using min = std::integral_constant<T, minValue>;
        using max = std::integral_constant<T, maxValue>;
        using eq = std::integral_constant<bool, isEqual>;
    };

    template <typename T, T V1, T V2>
    struct NumberCmp<T, V1, V2, typename std::enable_if<(V2 > V1)>::type>
    {
        static constexpr T minValue = V1;
        static constexpr T maxValue = V2;
        static constexpr bool isEqual = false;
        using min = std::integral_constant<T, minValue>;
        using max = std::integral_constant<T, maxValue>;
        using eq = std::integral_constant<bool, isEqual>;
    };

    template <typename T, T V1, T V2>
    struct NumberCmp<T, V1, V2, typename std::enable_if<(V2 == V1)>::type>
    {
        static constexpr T minValue = V1;
        static constexpr T maxValue = V1;
        static constexpr bool isEqual = true;
        using min = std::integral_constant<T, minValue>;
        using max = std::integral_constant<T, maxValue>;
        using eq = std::integral_constant<bool, isEqual>;
    };

    template <bool cond, typename TypeIF, typename TypeElse>
    struct Conditional
    {
    };
    template <typename TypeIF, typename TypeElse>
    struct Conditional<true, TypeIF, TypeElse>
    {
        using type = TypeIF;
    };
    template <typename TypeIF, typename TypeElse>
    struct Conditional<false, TypeIF, TypeElse>
    {
        using type = TypeElse;
    };

    /*
     * number type
     */

    template <typename T>
    struct Number
    {
        constexpr static bool isNumber = false;
        constexpr static bool isFloatingPoint = false;
    };

    template <>
    struct Number<char>
    {
        constexpr static bool isNumber = true;
        constexpr static bool isFloatingPoint = false;
        using type = char;
    };

    template <>
    struct Number<short>
    {
        constexpr static bool isNumber = true;
        constexpr static bool isFloatingPoint = false;
        using type = short;
    };

    template <>
    struct Number<long>
    {
        constexpr static bool isNumber = true;
        constexpr static bool isFloatingPoint = false;
        using type = long;
    };

    template <>
    struct Number<long long>
    {
        constexpr static bool isNumber = true;
        constexpr static bool isFloatingPoint = false;
        using type = long long;
    };

    template <>
    struct Number<float>
    {
        constexpr static bool isNumber = true;
        constexpr static bool isFloatingPoint = true;
        using type = float;
    };

    template <>
    struct Number<double>
    {
        constexpr static bool isNumber = true;
        constexpr static bool isFloatingPoint = true;
        using type = double;
    };

    template <>
    struct Number<long double>
    {
        constexpr static bool isNumber = true;
        constexpr static bool isFloatingPoint = true;
        using type = long double;
    };

}
