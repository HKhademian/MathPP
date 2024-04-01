#pragma once
#include <cstddef>
#include "Types.hpp"

#define implicit
namespace CircuitPP
{

    using tick_t = unsigned short;

    enum DigitalV : bool
    {
        V0 = false,
        V1 = true
    };

    /**
     *
     */
    template <typename _ValueT>
    struct Wire
    {
        using ValueT = _ValueT;
        constexpr ValueT getValue(tick_t const &tick) { return ValueT(0); }
    };

    /**
     *
     */
    template <typename _ValueT>
    struct ConstantWire : public Wire<_ValueT>
    {
        using ValueT = _ValueT;

    private:
        ValueT value;

    public:
        ConstantWire(ValueT const &&value) : value(value){};
        ConstantWire(ValueT const &value) : value(value){};
        ConstantWire() : ConstantWire(ValueT(0)){};

        constexpr ValueT getValue(tick_t const &tick) { return ValueT(value); }
    };

    /**
     *
     */
    template <
        typename _ValueT,
        typename _InputT_A,
        typename std::enable_if<std::is_base_of<Wire<_ValueT>, _InputT_A>::value>::type * = nullptr>
    struct _single_input_gate : public Wire<_ValueT>
    {
        using ValueT = _ValueT;
        using InputT_A = _InputT_A;
        InputT_A &inputA;

    protected:
        constexpr _single_input_gate(InputT_A &inputA) : inputA(inputA){};
    };

    /**
     *
     */
    template <typename _ValueT, typename _InputT_A>
    struct NotGate : public _single_input_gate<_ValueT, _InputT_A>
    {
        using ValueT = _ValueT;
        using InputT_A = _InputT_A;
        constexpr NotGate(InputT_A &inputA) : _single_input_gate<_ValueT, _InputT_A>(inputA){};

        constexpr ValueT getValue(tick_t const &tick)
        {
            auto valueA = this->inputA.getValue(tick);
            auto value = ValueT(!valueA);
            // std::cout << "### NotGate:: "
            //           << " tick: " << tick
            //           << " value: " << value
            //           << " valueA: " << valueA
            //           << std::endl;
            return value;
        }
    };

    /**
     *
     */
    template <
        typename _ValueT,
        typename _InputT_A,
        typename _InputT_B,
        typename std::enable_if<std::is_base_of<Wire<_ValueT>, _InputT_A>::value>::type * = nullptr,
        typename std::enable_if<std::is_base_of<Wire<_ValueT>, _InputT_B>::value>::type * = nullptr>
    struct _double_input_gate : public Wire<_ValueT>
    {
        using ValueT = _ValueT;
        using InputT_A = _InputT_A;
        using InputT_B = _InputT_B;

    protected:
        // TODO std::array<std::reference_wrapper<Wire<ValueT>>, 256?> inputs;
        InputT_A &inputA;
        InputT_B &inputB;

        _double_input_gate(InputT_A &inputA, InputT_B &inputB) : inputA(inputA), inputB(inputB){};
        // _double_input_gate(Wire<ValueT> inputA, Wire<ValueT> &inputB) : inputA(inputA), inputB(inputB){};
        // _double_input_gate(Wire<ValueT> &inputA, Wire<ValueT> inputB) : inputA(inputA), inputB(inputB){};
        // _double_input_gate(Wire<ValueT> inputA, Wire<ValueT> inputB) : inputA(inputA), inputB(inputB){};
    };

    /**
     *
     */
    template <typename _ValueT, typename _InputT_A, typename _InputT_B>
    struct AndGate : public _double_input_gate<_ValueT, _InputT_A, _InputT_B>
    {
        using ValueT = _ValueT;
        using InputT_A = _InputT_A;
        using InputT_B = _InputT_B;

        AndGate(InputT_A &inputA, InputT_B &inputB) : _double_input_gate<_ValueT, _InputT_A, _InputT_B>(inputA, inputB){};

        ValueT getValue(tick_t const &tick)
        {
            auto valueA = this->inputA.getValue(tick);
            auto valueB = this->inputB.getValue(tick);
            auto value = ValueT(valueA & valueB);
            // std::cout << "### AndGate:: "
            //           << " tick: " << tick
            //           << " value: " << value
            //           << " valueA: " << valueA
            //           << " valueB: " << valueB
            //           << std::endl;
            return value;
        }
    };

    /**
     *
     */
    template <typename _ValueT, typename _InputT_A, typename _InputT_B>
    struct OrGate : public _double_input_gate<_ValueT, _InputT_A, _InputT_B>
    {
        using ValueT = _ValueT;
        using InputT_A = _InputT_A;
        using InputT_B = _InputT_B;

        OrGate(InputT_A &inputA, InputT_B &inputB) : _double_input_gate<_ValueT, _InputT_A, _InputT_B>(inputA, inputB){};

        ValueT getValue(tick_t const &tick)
        {
            auto valueA = this->inputA.getValue(tick);
            auto valueB = this->inputB.getValue(tick);
            auto value = ValueT(valueA | valueB);
            // std::cout << "### OrGate:: "
            //           << " tick: " << tick
            //           << " value: " << value
            //           << " valueA: " << valueA
            //           << " valueB: " << valueB
            //           << std::endl;
            return value;
        }
    };

    /**
     *
     */
    template <typename _ValueT, typename _InputT_A, typename _InputT_B>
    struct XorGate : public _double_input_gate<_ValueT, _InputT_A, _InputT_B>
    {
        using ValueT = _ValueT;
        using InputT_A = _InputT_A;
        using InputT_B = _InputT_B;

        XorGate(InputT_A &inputA, InputT_B &inputB) : _double_input_gate<_ValueT, _InputT_A, _InputT_B>(inputA, inputB){};

        ValueT getValue(tick_t const &tick)
        {
            auto valueA = this->inputA.getValue(tick);
            auto valueB = this->inputB.getValue(tick);
            auto value = ValueT(valueA ^ valueB);
            // std::cout << "### XorGate:: "
            //           << " tick: " << tick
            //           << " value: " << value
            //           << " valueA: " << valueA
            //           << " valueB: " << valueB
            //           << std::endl;
            return value;
        }
    };

    /*
     *
     */

    template <typename ValueT>
    constexpr inline auto &Constant(ValueT const &value) { return ConstantWire<ValueT>(value); }

    template <typename ValueT>
    constexpr inline auto Constant(ValueT const &&value) { return ConstantWire<ValueT>(value); }

    template <typename InputT_A>
    constexpr inline auto Not(InputT_A &inputA) { return NotGate<typename InputT_A::ValueT, InputT_A>(inputA); }

    template <typename InputT_A>
    constexpr inline auto Not(InputT_A &&inputA) { return NotGate<typename InputT_A::ValueT, InputT_A>(inputA); }

    template <typename InputT_A, typename InputT_B>
    constexpr inline auto And(InputT_A &inputA, InputT_B &inputB) { return AndGate<typename InputT_A::ValueT, InputT_A, InputT_B>(inputA, inputB); }

    template <typename InputT_A, typename InputT_B>
    constexpr inline auto Or(InputT_A &inputA, InputT_B &inputB) { return OrGate<typename InputT_A::ValueT, InputT_A, InputT_B>(inputA, inputB); }

    template <typename InputT_A, typename InputT_B>
    constexpr inline auto Xor(InputT_A &inputA, InputT_B &inputB) { return XorGate<typename InputT_A::ValueT, InputT_A, InputT_B>(inputA, inputB); }

}
#undef implicit
