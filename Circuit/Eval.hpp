#pragma once

#define implicit
namespace CircuitPP
{
    using tick_t = unsigned int;

    template <typename ValueT>
    struct EvalType
    {
        using outputT = ValueT;

        static constexpr inline outputT eval(ValueT const &input, tick_t tick) noexcept
        {
            return input;
        }
    };

    template <typename ValueT>
    using EvalOutT = typename EvalType<ValueT>::outputT;

    template <typename ValueT>
    constexpr inline auto eval(ValueT const &input, tick_t tick) noexcept
    {
        return EvalType<ValueT>::eval(input, tick);
    }

    // template <typename ValueT>
    // auto eval(ValueT input, tick_t tick)
    // {
    //     return EvalType<ValueT>::eval(input, tick);
    // }

}
#undef implicit
