#pragma once

#include "Types.hpp"

#define implicit
namespace CircuitPP
{
    using tick_t = unsigned short;

    enum class LogicGate : unsigned char
    {
        CONST,
        WIRE,
        NOT,
        AND,
        OR,
        XOR,
        NAND,
        NOR,
        XNOR,
    };

    /*
     */
    template <typename ValueT>
    struct Logic
    {
        const LogicGate logic;
        ValueT const *value;
        Logic<ValueT> const *inputA;
        Logic<ValueT> const *inputB;

        static constexpr inline auto CONST(ValueT const &value)
        {
            return Logic<ValueT>{.logic = LogicGate::CONST, .value = &value};
        }

        static constexpr inline auto WIRE(Logic<ValueT> const &inputA)
        {
            return Logic<ValueT>{.logic = LogicGate::WIRE, .inputA = &inputA};
        }

        static constexpr inline auto NOT(Logic<ValueT> const &inputA)
        {
            return Logic<ValueT>{.logic = LogicGate::NOT, .inputA = &inputA};
        }

        static constexpr inline auto AND(Logic<ValueT> const &inputA, Logic<ValueT> const &inputB)
        {
            return Logic<ValueT>{.logic = LogicGate::AND, .inputA = &inputA, .inputB = &inputB};
        }

        static constexpr inline auto OR(Logic<ValueT> const &inputA, Logic<ValueT> const &inputB)
        {
            return Logic<ValueT>{.logic = LogicGate::OR, .inputA = &inputA, .inputB = &inputB};
        }

        static constexpr inline auto XOR(Logic<ValueT> const &inputA, Logic<ValueT> const &inputB)
        {
            return Logic<ValueT>{.logic = LogicGate::XOR, .inputA = &inputA, .inputB = &inputB};
        }

        static constexpr inline auto NAND(Logic<ValueT> const &inputA, Logic<ValueT> const &inputB)
        {
            return Logic<ValueT>{.logic = LogicGate::NAND, .inputA = &inputA, .inputB = &inputB};
        }

        static constexpr inline auto NOR(Logic<ValueT> const &inputA, Logic<ValueT> const &inputB)
        {
            return Logic<ValueT>{.logic = LogicGate::NOR, .inputA = &inputA, .inputB = &inputB};
        }

        static constexpr inline auto XNOR(Logic<ValueT> const &inputA, Logic<ValueT> const &inputB)
        {
            return Logic<ValueT>{.logic = LogicGate::XNOR, .inputA = &inputA, .inputB = &inputB};
        }

        constexpr inline ValueT operator()(tick_t const &tick) const
        {
            switch (logic)
            {
            case LogicGate::CONST:
            {
                // std::cout << "CONST"
                //           << " ptr: " << value
                //           << " val: " << *value
                //           << std::endl;
                return ValueT(*value);
            }
            case LogicGate::WIRE:
            {
                auto valueA = (*inputA)(tick);
                return ValueT(valueA);
            }
            case LogicGate::NOT:
            {
                auto valueA = (*inputA)(tick);
                return ValueT(!valueA);
            }
            case LogicGate::AND:
            {
                auto valueA = (*inputA)(tick);
                auto valueB = (*inputB)(tick);
                return ValueT((valueA & valueB));
            }
            case LogicGate::OR:
            {
                auto valueA = (*inputA)(tick);
                auto valueB = (*inputB)(tick);
                return ValueT((valueA | valueB));
            }
            case LogicGate::XOR:
            {
                auto valueA = (*inputA)(tick);
                auto valueB = (*inputB)(tick);
                return ValueT((valueA ^ valueB));
            }
            case LogicGate::NAND:
            {
                auto valueA = (*inputA)(tick);
                auto valueB = (*inputB)(tick);
                return ValueT(!(valueA & valueB));
            }
            case LogicGate::NOR:
            {
                auto valueA = (*inputA)(tick);
                auto valueB = (*inputB)(tick);
                return ValueT(!(valueA | valueB));
            }
            case LogicGate::XNOR:
            {
                auto valueA = (*inputA)(tick);
                auto valueB = (*inputB)(tick);
                return ValueT(!(valueA ^ valueB));
            }
            default:
                return ValueT(0);
            }
        }
    };

    /*
     */
    template <typename ValueT>
    constexpr inline auto Const(ValueT const &value) { return Logic<ValueT>::CONST(value); }

    /*
     */
    template <typename ValueT>
    constexpr inline auto Wire(Logic<ValueT> const &inputA) { return Logic<ValueT>::WIRE(inputA); }

    /*
     */
    template <typename ValueT>
    constexpr inline auto Not(Logic<ValueT> const &inputA) { return Logic<ValueT>::NOT(inputA); }

    /*
     */
    template <typename ValueT>
    constexpr inline auto And(Logic<ValueT> const &inputA, Logic<ValueT> const &inputB) { return Logic<ValueT>::AND(inputA, inputB); }

    /*
     */
    template <typename ValueT>
    constexpr inline auto Or(Logic<ValueT> const &inputA, Logic<ValueT> const &inputB) { return Logic<ValueT>::OR(inputA, inputB); }

    /*
     */
    template <typename ValueT>
    constexpr inline auto Xor(Logic<ValueT> const &inputA, Logic<ValueT> const &inputB) { return Logic<ValueT>::XOR(inputA, inputB); }
    /*
     */
    template <typename ValueT>
    constexpr inline auto Nand(Logic<ValueT> const &inputA, Logic<ValueT> const &inputB) { return Logic<ValueT>::NAND(inputA, inputB); }
    /*
     */
    template <typename ValueT>
    constexpr inline auto Nor(Logic<ValueT> const &inputA, Logic<ValueT> const &inputB) { return Logic<ValueT>::NOR(inputA, inputB); }

    /*
     */
    template <typename ValueT>
    constexpr inline auto Xnor(Logic<ValueT> const &inputA, Logic<ValueT> const &inputB) { return Logic<ValueT>::XNOR(inputA, inputB); }

    enum class DigitalV : bool
    {
        V0 = false,
        V1 = true
    };

    auto operator!(DigitalV const &value)
    {
        return DigitalV(!bool(value));
    }

    auto operator&(DigitalV const &lhs, DigitalV const &rhs)
    {
        return DigitalV(bool(lhs) & bool(rhs));
    }

    auto operator|(DigitalV const &lhs, DigitalV const &rhs)
    {
        return DigitalV(bool(lhs) | bool(rhs));
    }

    auto operator^(DigitalV const &lhs, DigitalV const &rhs)
    {
        return DigitalV(bool(lhs) ^ bool(rhs));
    }
}
#undef implicit
