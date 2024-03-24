#pragma once
#include <cstddef>
#include "Types.hpp"

#ifndef MATHPP_DEFAULT_DATA_TYPE
#define MATHPP_DEFAULT_DATA_TYPE float
#endif

namespace MathPP
{
    /** Matrix */
    template <
        size_t _COLS,
        size_t _ROWS,
        typename _DATA_TYPE = MATHPP_DEFAULT_DATA_TYPE,
        size_t _COL_SPACE = 0,
        size_t _ROW_SPACE = 0
        //
        >
    struct Matrix;

    template <size_t _COLS, size_t _ROWS, typename _DATA_TYPE, size_t _COL_SPACE, size_t _ROW_SPACE>
    struct Matrix
    {
        using TYPE = _DATA_TYPE;
        constexpr static const auto COL_COUNT = _COLS;
        constexpr static const auto ROW_COUNT = _ROWS;
        constexpr static const auto COL_SPACE_SIZE = _COL_SPACE;
        constexpr static const auto ROW_SPACE_SIZE = _ROW_SPACE;
        using this_t = Matrix<COL_COUNT, ROW_COUNT, TYPE, COL_SPACE_SIZE, ROW_SPACE_SIZE>;

        constexpr static const auto COL_SPACE_COUNT = COL_COUNT > 0 ? COL_COUNT - 1 : 0;
        constexpr static const auto ROW_SPACE_COUNT = ROW_COUNT > 0 ? ROW_COUNT - 1 : 0;
        constexpr static const auto COL_SIZE = 1;
        constexpr static const auto ROW_SIZE = COL_COUNT * COL_SIZE + COL_SPACE_COUNT * COL_SPACE_SIZE;
        constexpr static const auto COL_SKIP = COL_SIZE + COL_SPACE_SIZE;
        constexpr static const auto ROW_SKIP = ROW_SIZE + ROW_SPACE_SIZE;

        _DATA_TYPE elements[ROW_COUNT * ROW_SIZE +
                            ROW_SPACE_COUNT * ROW_SPACE_SIZE] = {0};

        _DATA_TYPE const &at(size_t row, size_t col) const { return elements[row * ROW_SKIP + col * COL_SKIP]; }
        _DATA_TYPE &at(size_t row, size_t col) { return elements[row * ROW_SKIP + col * COL_SKIP]; }
    };

}