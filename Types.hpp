#pragma once
#include <type_traits>

namespace MathPP
{
    // using size_t = unsigned int;

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
        static T t;
        static U u;

    public:
        using plus = typeof(t + u);
        using minus = typeof(t - u);
        using multiply = typeof(t * u);
        using division = typeof(t / u);
        // typedef typeof(t % u) mod;
        // typedef typeof(t ^ u) Xor;
        // typedef typeof(t | u) Or;
        // typedef typeof(t & u) And;
    };

    template <typename T, T V1, T V2, typename = void>
    struct Number
    {
    };

    template <typename T, T V1, T V2>
    struct Number<T, V1, V2, typename std::enable_if<(V1 >= V2)>::type>
    {
        using min = std::integral_constant<T, V2>;
        using max = std::integral_constant<T, V1>;
        using eq = std::integral_constant<bool, false>;
        static constexpr T minValue = min::value;
        static constexpr T maxValue = max::value;
        static constexpr bool isEqual = eq::value;
    };

    template <typename T, T V1, T V2>
    struct Number<T, V1, V2, typename std::enable_if<(V2 > V1)>::type>
    {
        using min = std::integral_constant<T, V1>;
        using max = std::integral_constant<T, V2>;
        using eq = std::integral_constant<bool, false>;
        static constexpr T minValue = min::value;
        static constexpr T maxValue = max::value;
        static constexpr bool isEqual = eq::value;
    };

    template <typename T, T V1, T V2>
    struct Number<T, V1, V2, typename std::enable_if<(V2 == V1)>::type>
    {
        using min = std::integral_constant<T, V1>;
        using max = std::integral_constant<T, V1>;
        using eq = std::integral_constant<bool, true>;
        static constexpr T minValue = min::value;
        static constexpr T maxValue = max::value;
        static constexpr bool isEqual = eq::value;
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

}
