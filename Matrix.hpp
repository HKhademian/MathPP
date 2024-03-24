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

        TYPE elements[ROW_COUNT * ROW_SIZE +
                      ROW_SPACE_COUNT * ROW_SPACE_SIZE] = {0};

        TYPE const &at(size_t row, size_t col) const { return elements[row * ROW_SKIP + col * COL_SKIP]; }
        TYPE &at(size_t row, size_t col) { return elements[row * ROW_SKIP + col * COL_SKIP]; }

        TYPE const &get(size_t row, size_t col, TYPE const &def = 0) const
        {
            return row < ROW_COUNT && col < COL_COUNT ? at(row, col) : def;
        }
        TYPE &get(size_t row, size_t col, TYPE &def = 0)
        {
            return row < ROW_COUNT && col < COL_COUNT ? at(row, col) : def;
        }

        /*
         * Transposition
         */

        using Transposition = Matrix<ROW_COUNT, COL_COUNT, TYPE, 0, 0>;

        auto trans() const
        {
            Transposition ret;
            for (auto r = 0; r < ROW_COUNT; ++r)
            {
                for (auto c = 0; c < COL_COUNT; ++c)
                {
                    ret.at(c, r) = at(r, c);
                }
            }
            return ret;
        }
    };

    template <
        size_t _COLS1, size_t _ROWS1, typename _DATA_TYPE1, size_t _COL_SPACE1, size_t _ROW_SPACE1,
        size_t _COLS2, size_t _ROWS2, typename _DATA_TYPE2, size_t _COL_SPACE2, size_t _ROW_SPACE2>
    auto operator+(
        Matrix<_COLS1, _ROWS1, _DATA_TYPE1, _COL_SPACE1, _ROW_SPACE1> const &lhs,
        Matrix<_COLS2, _ROWS2, _DATA_TYPE2, _COL_SPACE2, _ROW_SPACE2> const &rhs)
    {
        constexpr const auto COL_COUNT = _COLS1 > _COLS2 ? _COLS1 : _COLS2;
        constexpr const auto ROW_COUNT = _ROWS1 > _ROWS2 ? _ROWS1 : _ROWS2;
        typedef typename MathOp<_DATA_TYPE1, _DATA_TYPE2>::plus DATA_TYPE;

        Matrix<COL_COUNT, ROW_COUNT, DATA_TYPE, 0, 0> ret;
        for (auto r = 0; r < ret.ROW_COUNT; ++r)
        {
            for (auto c = 0; c < ret.COL_COUNT; ++c)
            {
                ret.at(r, c) = lhs.get(r, c) + rhs.get(r, c);
            }
        }
        return ret;
    }

    template <
        size_t _COLS1, size_t _ROWS1, typename _DATA_TYPE1, size_t _COL_SPACE1, size_t _ROW_SPACE1,
        size_t _COLS2, size_t _ROWS2, typename _DATA_TYPE2, size_t _COL_SPACE2, size_t _ROW_SPACE2>
    auto operator-(
        Matrix<_COLS1, _ROWS1, _DATA_TYPE1, _COL_SPACE1, _ROW_SPACE1> const &lhs,
        Matrix<_COLS2, _ROWS2, _DATA_TYPE2, _COL_SPACE2, _ROW_SPACE2> const &rhs)
    {
        constexpr const auto COL_COUNT = _COLS1 > _COLS2 ? _COLS1 : _COLS2;
        constexpr const auto ROW_COUNT = _ROWS1 > _ROWS2 ? _ROWS1 : _ROWS2;
        typedef typename MathOp<_DATA_TYPE1, _DATA_TYPE2>::minus DATA_TYPE;

        Matrix<COL_COUNT, ROW_COUNT, DATA_TYPE, 0, 0> ret;
        for (auto r = 0; r < ret.ROW_COUNT; ++r)
        {
            for (auto c = 0; c < ret.COL_COUNT; ++c)
            {
                ret.at(r, c) = lhs.get(r, c) - rhs.get(r, c);
            }
        }
        return ret;
    }

    template <
        typename _DATA_TYPE1,
        size_t _COLS2, size_t _ROWS2, typename _DATA_TYPE2, size_t _COL_SPACE2, size_t _ROW_SPACE2>
    auto operator*(
        _DATA_TYPE1 const &lhs,
        Matrix<_COLS2, _ROWS2, _DATA_TYPE2, _COL_SPACE2, _ROW_SPACE2> const &rhs)
    {
        constexpr const auto COL_COUNT = _COLS2;
        constexpr const auto ROW_COUNT = _ROWS2;
        typedef typename MathOp<_DATA_TYPE1, _DATA_TYPE2>::multiply DATA_TYPE;

        Matrix<COL_COUNT, ROW_COUNT, DATA_TYPE, 0, 0> ret;
        for (auto r = 0; r < ret.ROW_COUNT; ++r)
        {
            for (auto c = 0; c < ret.COL_COUNT; ++c)
            {
                ret.at(r, c) = lhs * rhs.get(r, c);
            }
        }
        return ret;
    }

    template <
        size_t _COLS1, size_t _ROWS1, typename _DATA_TYPE1, size_t _COL_SPACE1, size_t _ROW_SPACE1,
        typename _DATA_TYPE2>
    auto operator*(
        Matrix<_COLS1, _ROWS1, _DATA_TYPE1, _COL_SPACE1, _ROW_SPACE1> const &lhs,
        _DATA_TYPE2 const &rhs)
    {
        constexpr const auto COL_COUNT = _COLS1;
        constexpr const auto ROW_COUNT = _ROWS1;
        typedef typename MathOp<_DATA_TYPE1, _DATA_TYPE2>::multiply DATA_TYPE;

        Matrix<COL_COUNT, ROW_COUNT, DATA_TYPE, 0, 0> ret;
        for (auto r = 0; r < ret.ROW_COUNT; ++r)
        {
            for (auto c = 0; c < ret.COL_COUNT; ++c)
            {
                ret.at(r, c) = lhs.get(r, c) * rhs;
            }
        }
        return ret;
    }

    template <
        size_t _COLS1, size_t _ROWS1, typename _DATA_TYPE1, size_t _COL_SPACE1, size_t _ROW_SPACE1,
        typename _DATA_TYPE2>
    auto operator/(
        Matrix<_COLS1, _ROWS1, _DATA_TYPE1, _COL_SPACE1, _ROW_SPACE1> const &lhs,
        _DATA_TYPE2 const &rhs)
    {
        constexpr const auto COL_COUNT = _COLS1;
        constexpr const auto ROW_COUNT = _ROWS1;
        typedef typename MathOp<_DATA_TYPE1, _DATA_TYPE2>::division DATA_TYPE;

        Matrix<COL_COUNT, ROW_COUNT, DATA_TYPE, 0, 0> ret;
        for (auto r = 0; r < ret.ROW_COUNT; ++r)
        {
            for (auto c = 0; c < ret.COL_COUNT; ++c)
            {
                ret.at(r, c) = lhs.get(r, c) / rhs;
            }
        }
        return ret;
    }

    template <
        size_t _COLS1, size_t _ROWS1, typename _DATA_TYPE1, size_t _COL_SPACE1, size_t _ROW_SPACE1,
        size_t _COLS2, size_t _ROWS2, typename _DATA_TYPE2, size_t _COL_SPACE2, size_t _ROW_SPACE2>
    typename std::enable_if<_COLS1 == _ROWS2, Matrix<_COLS2, _ROWS1, typename MathOp<_DATA_TYPE1, _DATA_TYPE2>::multiply, 0, 0>>::type
    operator*(
        Matrix<_COLS1, _ROWS1, _DATA_TYPE1, _COL_SPACE1, _ROW_SPACE1> const &lhs,
        Matrix<_COLS2, _ROWS2, _DATA_TYPE2, _COL_SPACE2, _ROW_SPACE2> const &rhs)
    {
        constexpr const auto MID_SIZE = _COLS1; // _ROWS2
        Matrix<_COLS2, _ROWS1, typename MathOp<_DATA_TYPE1, _DATA_TYPE2>::multiply, 0, 0> ret;
        for (auto r = 0; r < ret.ROW_COUNT; ++r)
        {
            for (auto c = 0; c < ret.COL_COUNT; ++c)
            {
                typename decltype(ret)::TYPE v = 0;
                for (auto i = 0; i < MID_SIZE; ++i)
                {
                    v += lhs.at(r, i) * rhs.at(i, c);
                }
                ret.at(r, c) = v;
            }
        }
        return ret;
    }

}