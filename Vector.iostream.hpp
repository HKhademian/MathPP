#pragma once
#include "Vector.hpp"
#include <iostream>

namespace MathPP
{
    template <size_t __S1, typename __T1, size_t __STRIDE1>
    constexpr std::ostream &operator<<(std::ostream &os, Vektor<__S1, __T1, __STRIDE1> const &rhs)
    {
        // os << "Vector<"
        //    << "size=" << rhs.SIZE << ","
        //    << "STRIDE=" << rhs.STRIDE
        //    << "> ";
        os << "[";
        for (auto i = 0; i < rhs.SIZE; ++i)
        {
            if (i)
                os << ", ";
            os << rhs.at(i);
        }
        os << "]";
        return os;
    }

    template <size_t __S, typename __T, size_t __STRIDE>
    constexpr std::istream &operator>>(std::istream &is, Vektor<__S, __T, __STRIDE> &rhs)
    {
        for (auto i = 0; i < rhs.SIZE; ++i)
        {
            is >> rhs.at(i);
        }
        return is;
    }
}
