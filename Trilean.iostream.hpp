#pragma once
#include "Trilean.hpp"
#include <iostream>
#include <iomanip>

namespace MathPP
{
    std::ostream &operator<<(std::ostream &os, Trilean const &rhs)
    {
        os << std::right << std::setw(2) << int(rhs);
        return os;
    }

    std::istream &operator>>(std::istream &is, Trilean &rhs)
    {
        int v;
        is >> v;
        rhs = Trilean(v);
        return is;
    }
}