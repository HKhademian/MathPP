#pragma once

#include "Types.hpp"

#define implicit
namespace CircuitPP
{
    using tick_t = unsigned short const &;

    /*
     *
     * LOGIC GATES
     *
     */

    template <typename ValueT>
    struct LogicGate;

    template <typename ValueT>
    struct LogicGate
    {
        virtual ValueT operator()(tick_t tick) const = 0;
    };

    namespace
    {
        template <typename ValueT>
        struct ConstGate : public LogicGate<ValueT>
        {
            const ValueT &value;

            constexpr inline explicit ConstGate(const ValueT &value) : value(value) {}

            ValueT operator()(tick_t tick) const override { return ValueT(value); }
        };

        template <typename ValueT>
        struct WireGate : public LogicGate<ValueT>
        {
            const LogicGate<ValueT> &input;

            constexpr inline explicit WireGate(const LogicGate<ValueT> &input) : input(input) {}

            ValueT operator()(tick_t tick) const override { return ValueT(input(tick)); }
        };

        template <typename ValueT>
        struct NotGate : public LogicGate<ValueT>
        {
            const LogicGate<ValueT> &input;

            constexpr inline explicit NotGate(const LogicGate<ValueT> &input) : input(input) {}

            ValueT operator()(tick_t tick) const override { return ValueT(!input(tick)); }
        };

        template <typename ValueT>
        struct AndGate : public LogicGate<ValueT>
        {
            const LogicGate<ValueT> &inputA;
            const LogicGate<ValueT> &inputB;

            constexpr inline explicit AndGate(const LogicGate<ValueT> &inputA, const LogicGate<ValueT> &inputB) : inputA(inputA), inputB(inputB) {}

            ValueT operator()(tick_t tick) const override { return ValueT(inputA(tick) & inputB(tick)); }
        };

        template <typename ValueT>
        struct OrGate : public LogicGate<ValueT>
        {
            const LogicGate<ValueT> &inputA;
            const LogicGate<ValueT> &inputB;

            constexpr inline explicit OrGate(const LogicGate<ValueT> &inputA, const LogicGate<ValueT> &inputB) : inputA(inputA), inputB(inputB) {}

            ValueT operator()(tick_t tick) const override { return ValueT(inputA(tick) | inputB(tick)); }
        };

        template <typename ValueT>
        struct XorGate : public LogicGate<ValueT>
        {
            const LogicGate<ValueT> &inputA;
            const LogicGate<ValueT> &inputB;

            constexpr inline explicit XorGate(const LogicGate<ValueT> &inputA, const LogicGate<ValueT> &inputB) : inputA(inputA), inputB(inputB) {}

            ValueT operator()(tick_t tick) const override { return ValueT(inputA(tick) ^ inputB(tick)); }
        };
    }

    /*
     *
     * GATES
     *
     */

    /*
     */
    template <typename ValueT>
    constexpr inline auto Const(const ValueT &value)
    {
        return ConstGate<ValueT>(value);
    }

    /*
     */
    template <typename ValueT>
    constexpr inline auto Wire(const LogicGate<ValueT> &input)
    {
        return WireGate<ValueT>(input);
    }

    /*
     */
    template <typename ValueT>
    constexpr inline auto Not(const LogicGate<ValueT> &input)
    {
        return NotGate<ValueT>(input);
    }

    /*
     */
    template <typename ValueT>
    constexpr inline auto And(const LogicGate<ValueT> &inputA, const LogicGate<ValueT> &inputB)
    {
        return AndGate<ValueT>(inputA, inputB);
    }

    /*
     */
    template <typename ValueT>
    constexpr inline auto Or(const LogicGate<ValueT> &inputA, const LogicGate<ValueT> &inputB)
    {
        return OrGate<ValueT>(inputA, inputB);
    }

    /*
     */
    template <typename ValueT>
    constexpr inline auto Xor(const LogicGate<ValueT> &inputA, const LogicGate<ValueT> &inputB)
    {
        return XorGate<ValueT>(inputA, inputB);
    }

    /*
     */
    template <typename ValueT>
    constexpr inline auto Nand(const LogicGate<ValueT> &inputA, const LogicGate<ValueT> &inputB)
    {
        return Not(And(inputA, inputB));
    }

    /*
     */
    template <typename ValueT>
    constexpr inline auto Nor(const LogicGate<ValueT> &inputA, const LogicGate<ValueT> &inputB)
    {
        return Not(Or(inputA, inputB));
    }

    /*
     */
    template <typename ValueT>
    constexpr inline auto Xnor(const LogicGate<ValueT> &inputA, const LogicGate<ValueT> &inputB)
    {
        return Not(Xor(inputA, inputB));
    }

    /*
     *
     * OPAERATORS
     *
     */

    template <typename ValueT>
    constexpr inline auto operator!(const LogicGate<ValueT> &input)
    {
        return Not(input);
    }

    template <typename ValueT>
    constexpr inline auto operator&(const LogicGate<ValueT> &inputA, const LogicGate<ValueT> &inputB)
    {
        return And(inputA, inputB);
    }

    template <typename ValueT>
    constexpr inline auto operator|(const LogicGate<ValueT> &inputA, const LogicGate<ValueT> &inputB)
    {
        return Or(inputA, inputB);
    }

    template <typename ValueT>
    constexpr inline auto operator^(const LogicGate<ValueT> &inputA, const LogicGate<ValueT> &inputB)
    {
        return Xor(inputA, inputB);
    }

    template <typename ValueT>
    constexpr inline auto operator==(const LogicGate<ValueT> &inputA, const LogicGate<ValueT> &inputB)
    {
        return Xnor(inputA, inputB);
    }

    template <typename ValueT>
    constexpr inline auto operator!=(const LogicGate<ValueT> &inputA, const LogicGate<ValueT> &inputB)
    {
        return Xor(inputA, inputB);
    }

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
