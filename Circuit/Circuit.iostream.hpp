#pragma once
#include "Circuit.hpp"
#include <iostream>

namespace CircuitPP
{
    template <unsigned int n, typename ValueT>
    std::ostream &operator<<(std::ostream &os, Bus<n, ValueT> const &rhs)
    {
        os << "{";
        for (auto i = 0; i < n; ++i)
        {
            if (i > 0)
                os << ",";
            os << rhs[n - i - 1];
        }
        os << "}";
        return os;
    }
}