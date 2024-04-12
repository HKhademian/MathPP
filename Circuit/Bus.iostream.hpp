#pragma once
#include "Circuit.hpp"
#include <iostream>

namespace CircuitPP
{
    template <typename ValueT, std::size_t N>
    std::ostream &operator<<(std::ostream &os, Bus<ValueT, N> const &rhs)
    {
        os << "{";
        for (std::size_t i = 0; i < rhs.N; ++i)
        {
            if (i > 0)
                os << ",";
            os << rhs[rhs.N - i - 1];
        }
        os << "}";
        return os;
    }
}