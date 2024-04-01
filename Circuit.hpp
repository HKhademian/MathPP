#pragma once
#include <cstddef>
#include "Types.hpp"

#include <iostream>

#define implicit
namespace CircuitPP
{

    using tick_t = unsigned short;

    /**
     *
     */
    template <typename ValueT = bool>
    struct Wire
    {
        virtual ValueT const &getValue(tick_t tick);
    };

    /**
     *
     */
    template <typename ValueT = bool>
    struct Constant : Wire<ValueT>
    {
    private:
        ValueT value = ValueT(0);

    public:
        Constant(ValueT value) : value(ValueT(value)){};
        Constant() : Constant(ValueT(0)){};

        ValueT const &getValue(tick_t tick) override { return value; }
    };

    /**
     *
     */
    template <typename ValueT = bool>
    struct NotGate : Wire<ValueT>
    {
    private:
        tick_t lastTick = tick_t(0);
        ValueT values[1000] = {0};

    public:
        Wire<ValueT> *input = nullptr;

        ValueT const &getValue(tick_t tick) override
        {
            std::cout << "NOT at " << tick;
            if (tick <= lastTick)
            {
                std::cout << " from cache: " << values[tick] << std::endl;
                return values[tick];
            }
            std::cout << " START" << std::endl;

            if (input != nullptr)
            {
                values[tick] = !input->getValue(tick - 1);
            }

            std::cout << "NOT at " << tick << " CALC: " << values[tick] << std::endl;
            lastTick = tick;
            return values[tick];
        }
    };

    /**
     *
     */
    template <typename ValueT = bool>
    struct AndGate : Wire<ValueT>
    {
    private:
        tick_t lastTick = tick_t(0);
        ValueT values[1000] = {0};

    public:
        Wire<ValueT> *inputs[256] = {0};

        ValueT const &getValue(tick_t tick) override
        {
            std::cout << "AND at " << tick;
            if (tick <= lastTick)
            {
                std::cout << " from cache: " << values[tick] << std::endl;
                return values[tick];
            }
            std::cout << " START" << std::endl;

            values[tick] = ValueT(1);
            for (auto i = 0; i < 256 && inputs[i] != nullptr; ++i)
            {
                values[tick] = values[tick] & inputs[i]->getValue(tick - 1);
            }

            std::cout << "AND at " << tick << " CALC: " << values[tick] << std::endl;
            lastTick = tick;
            return values[tick];
        }
    };

    /**
     *
     */
    template <typename ValueT = bool>
    struct OrGate : Wire<ValueT>
    {
    private:
        tick_t lastTick = tick_t(0);
        ValueT values[1000] = {0};

    public:
        Wire<ValueT> *inputs[256] = {0};

        ValueT const &getValue(tick_t tick) override
        {
            if (tick <= lastTick)
            {
                return values[tick];
            }

            values[tick] = ValueT(0);
            for (auto i = 0; i < 256 && inputs[i] != nullptr; ++i)
            {
                values[tick] = values[tick] | inputs[i]->getValue(tick - 1);
            }

            lastTick = tick;
            return values[tick];
        }
    };

    /**
     *
     */
    template <typename ValueT = bool>
    struct XorGate : Wire<ValueT>
    {
    private:
        tick_t lastTick = tick_t(0);
        ValueT values[1000] = {0};

    public:
        Wire<ValueT> *inputs[256] = {0};

        ValueT const &getValue(tick_t tick) override
        {
            if (tick <= lastTick)
            {
                return values[tick];
            }

            values[tick] = ValueT(0);
            for (auto i = 0; i < 256 && inputs[i] != nullptr; ++i)
            {
                values[tick] = values[tick] ^ inputs[i]->getValue(tick - 1);
            }

            lastTick = tick;
            return values[tick];
        }
    };

}
#undef implicit
