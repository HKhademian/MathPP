#pragma once

#include <memory>
#include "../Types/Types.hpp"

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
     * OPAERATORS
     *
     */

    template <typename ValueT>
    constexpr inline logic_ptr<ValueT> operator+(const ValueT input)
    {
        struct ConstGate : public LogicGate<ValueT>
        {
            const ValueT input;

            constexpr inline explicit ConstGate(const ValueT input) : input(input) {}

            ValueT operator()(tick_t tick) const override
            {
                return ValueT(input);
            }
        };

        return std::make_shared<ConstGate>(input);
    }

    template <typename ValueT>
    constexpr inline logic_ptr<ValueT> operator+(const logic_ptr<ValueT> input)
    {
        struct WireGate : public LogicGate<ValueT>
        {
            const logic_ptr<ValueT> input;

            constexpr inline explicit WireGate(const logic_ptr<ValueT> input) : input(input) {}

            ValueT operator()(tick_t tick) const override
            {
                return ValueT(((*input)(tick)));
            }
        };

        return std::make_shared<WireGate>(input);
    }

    template <typename ValueT>
    constexpr inline logic_ptr<ValueT> operator!(const logic_ptr<ValueT> input)
    {
        struct NotGate : public LogicGate<ValueT>
        {
            const logic_ptr<ValueT> input;

            constexpr inline explicit NotGate(const logic_ptr<ValueT> input) : input(input) {}

            ValueT operator()(tick_t tick) const override
            {
                return ValueT(!((*input)(tick)));
            }
        };

        return std::make_shared<NotGate>(input);
    }

    template <typename ValueT>
    constexpr inline logic_ptr<ValueT> operator~(const logic_ptr<ValueT> input)
    {
        return !input;
    }

    template <typename ValueT>
    constexpr inline logic_ptr<ValueT> operator&(const logic_ptr<ValueT> inputA, const logic_ptr<ValueT> inputB)
    {
        struct AndGate : public LogicGate<ValueT>
        {
            const logic_ptr<ValueT> inputA;
            const logic_ptr<ValueT> inputB;

            constexpr inline explicit AndGate(
                const logic_ptr<ValueT> inputA,
                const logic_ptr<ValueT> inputB)
                : inputA(inputA), inputB(inputB) {}

            ValueT operator()(tick_t tick) const override
            {
                return ValueT(((*inputA)(tick)) & ((*inputB)(tick)));
            }
        };

        return std::make_shared<AndGate>(inputA, inputB);
    }

    template <typename ValueT>
    constexpr inline logic_ptr<ValueT> operator|(const logic_ptr<ValueT> inputA, const logic_ptr<ValueT> inputB)
    {
        struct OrGate : public LogicGate<ValueT>
        {
            const logic_ptr<ValueT> inputA;
            const logic_ptr<ValueT> inputB;

            constexpr inline explicit OrGate(const logic_ptr<ValueT> inputA, const logic_ptr<ValueT> inputB) : inputA(inputA), inputB(inputB) {}

            ValueT operator()(tick_t tick) const override
            {
                return ValueT(((*inputA)(tick)) | ((*inputB)(tick)));
            }
        };

        return std::make_shared<OrGate>(inputA, inputB);
    }

    template <typename ValueT>
    constexpr inline logic_ptr<ValueT> operator^(const logic_ptr<ValueT> inputA, const logic_ptr<ValueT> inputB)
    {
        struct XorGate : public LogicGate<ValueT>
        {
            const logic_ptr<ValueT> inputA;
            const logic_ptr<ValueT> inputB;

            constexpr inline explicit XorGate(const logic_ptr<ValueT> inputA, const logic_ptr<ValueT> inputB) : inputA(inputA), inputB(inputB) {}

            ValueT operator()(tick_t tick) const override
            {
                return ValueT(((*inputA)(tick)) ^ ((*inputB)(tick)));
            }
        };

        return std::make_shared<XorGate>(inputA, inputB);
    }

    template <typename ValueT>
    constexpr inline logic_ptr<ValueT> operator==(const logic_ptr<ValueT> inputA, const logic_ptr<ValueT> inputB)
    {
        return !(inputA ^ inputB);
    }

    template <typename ValueT>
    constexpr inline logic_ptr<ValueT> operator!=(const logic_ptr<ValueT> inputA, const logic_ptr<ValueT> inputB)
    {
        return (inputA ^ inputB);
    }

    /*
     *
     * GATES
     *
     */

    /*
     */
    template <typename ValueT>
    constexpr inline logic_ptr<ValueT> Const(const ValueT input)
    {
        return (+input);
    }

    /*
     */
    template <typename ValueT>
    constexpr inline logic_ptr<ValueT> Wire(const logic_ptr<ValueT> input)
    {
        return (+input);
    }

    /*
     */
    template <typename ValueT>
    constexpr inline logic_ptr<ValueT> Not(const logic_ptr<ValueT> input)
    {
        return (!input);
    }

    /*
     */
    template <typename ValueT>
    constexpr inline logic_ptr<ValueT> And(const logic_ptr<ValueT> inputA, const logic_ptr<ValueT> inputB)
    {
        return (inputA & inputB);
    }

    /*
     */
    template <typename ValueT>
    constexpr inline logic_ptr<ValueT> Or(const logic_ptr<ValueT> inputA, const logic_ptr<ValueT> inputB)
    {
        return (inputA | inputB);
    }

    /*
     */
    template <typename ValueT>
    constexpr inline logic_ptr<ValueT> Xor(const logic_ptr<ValueT> inputA, const logic_ptr<ValueT> inputB)
    {
        return (inputA ^ inputB);
    }

    /*
     */
    template <typename ValueT>
    constexpr inline auto Nand(const logic_ptr<ValueT> inputA, const logic_ptr<ValueT> inputB)
    {
        return !(inputA & inputB);
    }

    /*
     */
    template <typename ValueT>
    constexpr inline auto Nor(const logic_ptr<ValueT> inputA, const logic_ptr<ValueT> inputB)
    {
        return !(inputA | inputB);
    }

    /*
     */
    template <typename ValueT>
    constexpr inline auto Xnor(const logic_ptr<ValueT> inputA, logic_ptr<ValueT> inputB)
    {
        return !(inputA ^ inputB);
    }

}
#undef implicit
