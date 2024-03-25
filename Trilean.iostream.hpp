#pragma once
#include "Trilean.hpp"
#include <iostream>
#include <iomanip>

namespace MathPP
{
    std::ostream &operator<<(std::ostream &os, Trilean const &&rhs)
    {
        os << std::right << std::setw(2) << (int)rhs;
        return os;
    }

    std::istream &operator>>(std::istream &is, Trilean &rhs)
    {
        is >> *(int *)(void *)&rhs;
        if (rhs > 0)
            rhs = POS;
        else if (rhs < 0)
            rhs = NEG;
        return is;
    }
}