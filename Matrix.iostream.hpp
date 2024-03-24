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
        for (auto r = 0; r < rhs.ROW_COUNT; ++r)
        {
            if (r)
                os << ", ";
            os << "[";
            for (auto c = 0; c < rhs.COL_COUNT; ++c)
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
        // for (auto i = 0; i < rhs.SIZE; ++i)
        // {
        //     is >> rhs.at(i);
        // }
        return is;
    }
}