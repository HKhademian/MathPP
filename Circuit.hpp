#pragma once

#include <memory>
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
    struct LogicGate
    {
        virtual ValueT operator()(tick_t tick) const = 0;
    };

    template <typename ValueT>
    using logic_ptr = std::shared_ptr<LogicGate<ValueT>>;

    /*
     *
     * GATES
     *
     */

    /*
     */
    template <typename ValueT>
    constexpr inline logic_ptr<ValueT> Const(const ValueT value)
    {
        struct ConstGate : public LogicGate<ValueT>
        {
            const ValueT value;

            constexpr inline explicit ConstGate(const ValueT value) : value(value) {}

            ValueT operator()(tick_t tick) const override { return ValueT(value); }
        };

        return std::make_shared<ConstGate>(value);
    }

    /*
     */
    template <typename ValueT>
    constexpr inline logic_ptr<ValueT> Wire(const logic_ptr<ValueT> input)
    {
        struct WireGate : public LogicGate<ValueT>
        {
            const logic_ptr<ValueT> input;

            constexpr inline explicit WireGate(const logic_ptr<ValueT> input) : input(input) {}

            ValueT operator()(tick_t tick) const override { return ValueT(((*input.get())(tick))); }
        };

        return std::make_shared<WireGate>(input);
    }

    /*
     */
    template <typename ValueT>
    constexpr inline logic_ptr<ValueT> Not(const logic_ptr<ValueT> input)
    {
        struct NotGate : public LogicGate<ValueT>
        {
            const logic_ptr<ValueT> input;

            constexpr inline explicit NotGate(const logic_ptr<ValueT> input) : input(input) {}

            ValueT operator()(tick_t tick) const override { return ValueT(!((*input.get())(tick))); }
        };

        return std::make_shared<NotGate>(input);
    }

    /*
     */
    template <typename ValueT>
    constexpr inline logic_ptr<ValueT> And(const logic_ptr<ValueT> inputA, const logic_ptr<ValueT> inputB)
    {
        struct AndGate : public LogicGate<ValueT>
        {
            const logic_ptr<ValueT> inputA;
            const logic_ptr<ValueT> inputB;

            constexpr inline explicit AndGate(
                const logic_ptr<ValueT> inputA,
                const logic_ptr<ValueT> inputB)
                : inputA(inputA), inputB(inputB) {}

            ValueT operator()(tick_t tick) const override { return ValueT(((*inputA.get())(tick)) & ((*inputB.get())(tick))); }
        };

        return std::make_shared<AndGate>(inputA, inputB);
    }

    /*
     */
    template <typename ValueT>
    constexpr inline logic_ptr<ValueT> Or(const logic_ptr<ValueT> inputA, const logic_ptr<ValueT> inputB)
    {
        struct OrGate : public LogicGate<ValueT>
        {
            const logic_ptr<ValueT> inputA;
            const logic_ptr<ValueT> inputB;

            constexpr inline explicit OrGate(const logic_ptr<ValueT> inputA, const logic_ptr<ValueT> inputB) : inputA(inputA), inputB(inputB) {}

            ValueT operator()(tick_t tick) const override { return ValueT(((*inputA.get())(tick)) | ((*inputB.get())(tick))); }
        };

        return std::make_shared<OrGate>(inputA, inputB);
    }

    /*
     */
    template <typename ValueT>
    constexpr inline logic_ptr<ValueT> Xor(const logic_ptr<ValueT> inputA, const logic_ptr<ValueT> inputB)
    {
        struct XorGate : public LogicGate<ValueT>
        {
            const logic_ptr<ValueT> inputA;
            const logic_ptr<ValueT> inputB;

            constexpr inline explicit XorGate(const logic_ptr<ValueT> inputA, const logic_ptr<ValueT> inputB) : inputA(inputA), inputB(inputB) {}

            ValueT operator()(tick_t tick) const override { return ValueT(((*inputA.get())(tick)) ^ ((*inputB.get())(tick))); }
        };

        return std::make_shared<XorGate>(inputA, inputB);
    }

    /*
     */
    template <typename ValueT>
    constexpr inline auto Nand(const logic_ptr<ValueT> inputA, const logic_ptr<ValueT> inputB)
    {
        return Not(And(inputA, inputB));
    }

    /*
     */
    template <typename ValueT>
    constexpr inline auto Nor(const logic_ptr<ValueT> inputA, const logic_ptr<ValueT> inputB)
    {
        return Not(Or(inputA, inputB));
    }

    /*
     */
    template <typename ValueT>
    constexpr inline auto Xnor(const logic_ptr<ValueT> inputA, const logic_ptr<ValueT> inputB)
    {
        return Not(Xor(inputA, inputB));
    }

    /*
     *
     * OPAERATORS
     *
     */

    template <typename ValueT>
    constexpr inline auto operator!(const logic_ptr<ValueT> input)
    {
        return Not(input);
    }

    template <typename ValueT>
    constexpr inline auto operator&(const logic_ptr<ValueT> inputA, const logic_ptr<ValueT> inputB)
    {
        return And(inputA, inputB);
    }

    template <typename ValueT>
    constexpr inline auto operator|(const logic_ptr<ValueT> inputA, const logic_ptr<ValueT> inputB)
    {
        return Or(inputA, inputB);
    }

    template <typename ValueT>
    constexpr inline auto operator^(const logic_ptr<ValueT> inputA, const logic_ptr<ValueT> inputB)
    {
        return Xor(inputA, inputB);
    }

    template <typename ValueT>
    constexpr inline auto operator==(const logic_ptr<ValueT> inputA, const logic_ptr<ValueT> inputB)
    {
        return Xnor(inputA, inputB);
    }

    template <typename ValueT>
    constexpr inline auto operator!=(const logic_ptr<ValueT> inputA, const logic_ptr<ValueT> inputB)
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
