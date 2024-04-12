#pragma once

#define implicit
namespace CircuitPP
{
    template <typename ValueT>
    struct EvalType
    {
        static constexpr inline auto eval(ValueT const &input, unsigned int tick)
        {
            return input;
        }
    };

    template <typename ValueT>
    constexpr inline auto eval(ValueT const &input, unsigned int tick)
    {
        return EvalType<ValueT>::eval(input, tick);
    }

    // template <typename ValueT>
    // auto eval(ValueT input, unsigned int tick)
    // {
    //     return EvalType<ValueT>::eval(input, tick);
    // }

}
#undef implicit
