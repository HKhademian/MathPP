#pragma once
#include <type_traits>

namespace Types
{
    using size_t = unsigned int;

    template <typename T, typename U>
    struct Plus
    {
    private:
        static T t;
        static U u;
        static typeof(t + u) v;

    public:
        typedef typeof(v) V;
    };

    template <typename T, typename U>
    struct Minus
    {
    private:
        static T t;
        static U u;
        static typeof(t - u) v;

    public:
        typedef typeof(v) V;
    };

    template <typename T, typename U>
    struct Multiply
    {
    private:
        static T t;
        static U u;
        static typeof(t * u) v;

    public:
        typedef typeof(v) V;
    };

    template <typename T, typename U>
    struct Division
    {
    private:
        static T t;
        static U u;
        static typeof(t / u) v;

    public:
        using V = typeof(v);
        // typedef typeof(v) V;
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
