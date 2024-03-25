#pragma once
#include "Matrix.hpp"
#include <iostream>

namespace MathPP
{
    template <size_t _COLS, size_t _ROWS, typename _DATA_TYPE, size_t _COL_SPACE, size_t _ROW_SPACE>
    constexpr std::ostream &operator<<(std::ostream &os, Matrix<_COLS, _ROWS, _DATA_TYPE, _COL_SPACE, _ROW_SPACE> const &rhs)
    {
        // os << "Matrix<"
        //    << "size=" << rhs.SIZE << ","
        //    << "STRIDE=" << rhs.STRIDE
        //    << "> ";
        os << "[";
        MATHPP_MAT_LOOP_ROW(rhs, r)
        {
            if (r)
                os << ", ";
            os << "[";
            MATHPP_MAT_LOOP_COL(rhs, c)
            {
                if (c)
                    os << ", ";
                os << rhs.at(r, c);
            }
            os << "]";
        }
        os << "]";
        return os;
    }

    template <size_t _COLS, size_t _ROWS, typename _DATA_TYPE, size_t _COL_SPACE, size_t _ROW_SPACE>
    constexpr std::istream &operator>>(std::istream &is, Matrix<_COLS, _ROWS, _DATA_TYPE, _COL_SPACE, _ROW_SPACE> &rhs)
    {
        MATHPP_MAT_LOOP(rhs, r, c)
        {
            is >> rhs.at(r, c);
        }
        return is;
    }
}