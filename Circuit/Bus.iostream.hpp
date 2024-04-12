#pragma once
#include "Circuit.hpp"
#include <iostream>

namespace CircuitPP
{
    template <typename ValueT, std::size_t N>
    std::ostream &operator<<(std::ostream &os, Bus<ValueT, N> const &rhs)
    {
        os << "{";
        for (auto i = 0; i < rhs.size(); ++i)
        {
            if (i > 0)
                os << ",";
            os << rhs[rhs.size() - i - 1];
        }
        os << "}";
        return os;
    }
}