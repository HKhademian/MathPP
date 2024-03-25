#pragma once
#include <cstddef>
#include "Types.hpp"

#ifndef MATHPP_DEFAULT_DATA_TYPE
#define MATHPP_DEFAULT_DATA_TYPE float
#endif

/// define this to prevent shape matrices ops (+ or -)
// #define MATHPP_NO_DIFF_SHAPE_OP

#define MATHPP_LOOP(LAST, V) for (auto V = 0; V < LAST; ++V)
#define MATHPP_MAT_LOOP_ROW(MAT, R) MATHPP_LOOP(MAT.ROW_COUNT, R)
#define MATHPP_MAT_LOOP_COL(MAT, C) MATHPP_LOOP(MAT.COL_COUNT, C)
#define MATHPP_MAT_LOOP(MAT, R, C) \
    MATHPP_MAT_LOOP_ROW(MAT, R)    \
    MATHPP_MAT_LOOP_COL(MAT, C)

namespace MathPP
{
    /** Matrix */
    template <
        size_t _COLS,
        size_t _ROWS,
        typename _DATA_TYPE = MATHPP_DEFAULT_DATA_TYPE,
        size_t _COL_SKIP = 0,
        size_t _ROW_SKIP = 0
        //
        >
    struct Matrix;

    template <size_t _COLS, size_t _ROWS, typename _DATA_TYPE, size_t _COL_SKIP, size_t _ROW_SKIP>
    struct Matrix
    {
    public:
        using TYPE = _DATA_TYPE;
        constexpr static const auto COL_COUNT = _COLS;
        constexpr static const auto ROW_COUNT = _ROWS;
        constexpr static const auto COL_SKIP_SIZE = _COL_SKIP;
        constexpr static const auto ROW_SKIP_SIZE = _ROW_SKIP;
        using this_t = Matrix<COL_COUNT, ROW_COUNT, TYPE, COL_SKIP_SIZE, ROW_SKIP_SIZE>;

        constexpr static const bool isSquare = (COL_COUNT == ROW_COUNT);

    private:
        constexpr static const auto COL_SKIP_COUNT = COL_COUNT > 0 ? COL_COUNT - 1 : 0;
        constexpr static const auto ROW_SKIP_COUNT = ROW_COUNT > 0 ? ROW_COUNT - 1 : 0;
        constexpr static const auto COL_SIZE = 1;
        constexpr static const auto ROW_SIZE = COL_COUNT * COL_SIZE + COL_SKIP_COUNT * COL_SKIP_SIZE;
        constexpr static const auto COL_SKIP = COL_SIZE + COL_SKIP_SIZE;
        constexpr static const auto ROW_SKIP = ROW_SIZE + ROW_SKIP_SIZE;

    public:
        TYPE elements[(ROW_COUNT * ROW_SIZE) + (ROW_SKIP_COUNT * ROW_SKIP_SIZE)] = {TYPE(0)};

        /*
         * Instance
         */

        constexpr static auto ofAll(TYPE const &&value)
        {
            this_t ret;
            MATHPP_MAT_LOOP(ret, r, c) { ret.at(r, c) = value; }
            return ret;
        }

        constexpr static auto ofAll(TYPE const &value)
        {
            this_t ret;
            MATHPP_MAT_LOOP(ret, r, c) { ret.at(r, c) = value; }
            return ret;
        }

        constexpr static this_t zeros() { return ofAll(TYPE(0)); }
        constexpr static this_t ones() { return ofAll(TYPE(1)); }

        template <size_t C_COUNT = COL_COUNT>
        constexpr static typename std::enable_if<C_COUNT == COL_COUNT && C_COUNT == ROW_COUNT, this_t>::type
        identity(TYPE const &value = TYPE(1))
        {
            auto ret = zeros();
            MATHPP_MAT_LOOP_ROW(ret, rc) { ret.at(rc, rc) = value; }
            return ret;
        }

        /*
         * Access
         */

        constexpr TYPE const &at(size_t row, size_t col) const { return elements[row * ROW_SKIP + col * COL_SKIP]; }
        constexpr TYPE &at(size_t row, size_t col) { return elements[row * ROW_SKIP + col * COL_SKIP]; }

        constexpr TYPE const &get(size_t row, size_t col, TYPE const &def = TYPE(0)) const
        {
            return row < ROW_COUNT && col < COL_COUNT ? at(row, col) : def;
        }
        constexpr TYPE &get(size_t row, size_t col, TYPE &def = TYPE(0))
        {
            return row < ROW_COUNT && col < COL_COUNT ? at(row, col) : def;
        }

        /*
         * Transposition
         */

        using Transposition = Matrix<ROW_COUNT, COL_COUNT, TYPE, 0, 0>;

        constexpr auto trans() const
        {
            Transposition ret;
            MATHPP_MAT_LOOP(ret, r, c) { ret.at(r, c) = at(c, r); }
            return ret;
        }
    };

    template <
        size_t _COLS1, size_t _ROWS1, typename _DATA_TYPE1, size_t _COL_SKIP1, size_t _ROW_SKIP1,
        size_t _COLS2, size_t _ROWS2, typename _DATA_TYPE2, size_t _COL_SKIP2, size_t _ROW_SKIP2>
    constexpr
#ifdef MATHPP_NO_DIFF_SHAPE_OP
        typename std::enable_if<_COLS1 == _COLS2 && _ROWS1 == _ROWS2, Matrix<_COLS1, _ROWS1, typename MathOp<_DATA_TYPE1, _DATA_TYPE2>::plus, 0, 0>>::type
#else
        auto
#endif
        operator+(
            Matrix<_COLS1, _ROWS1, _DATA_TYPE1, _COL_SKIP1, _ROW_SKIP1> const &lhs,
            Matrix<_COLS2, _ROWS2, _DATA_TYPE2, _COL_SKIP2, _ROW_SKIP2> const &rhs)
    {
        constexpr const auto COL_COUNT = _COLS1 > _COLS2 ? _COLS1 : _COLS2;
        constexpr const auto ROW_COUNT = _ROWS1 > _ROWS2 ? _ROWS1 : _ROWS2;
        typedef typename MathOp<_DATA_TYPE1, _DATA_TYPE2>::plus DATA_TYPE;

        Matrix<COL_COUNT, ROW_COUNT, DATA_TYPE, 0, 0> ret;
        MATHPP_MAT_LOOP(ret, r, c)
        {
            ret.at(r, c) = lhs.get(r, c) + rhs.get(r, c);
        }
        return ret;
    }

    template <
        size_t _COLS1, size_t _ROWS1, typename _DATA_TYPE1, size_t _COL_SKIP1, size_t _ROW_SKIP1,
        size_t _COLS2, size_t _ROWS2, typename _DATA_TYPE2, size_t _COL_SKIP2, size_t _ROW_SKIP2>
    constexpr
#ifdef MATHPP_NO_DIFF_SHAPE_OP
        typename std::enable_if<_COLS1 == _COLS2 && _ROWS1 == _ROWS2, Matrix<_COLS1, _ROWS1, typename MathOp<_DATA_TYPE1, _DATA_TYPE2>::plus, 0, 0>>::type
#else
        auto
#endif
        operator-(
            Matrix<_COLS1, _ROWS1, _DATA_TYPE1, _COL_SKIP1, _ROW_SKIP1> const &lhs,
            Matrix<_COLS2, _ROWS2, _DATA_TYPE2, _COL_SKIP2, _ROW_SKIP2> const &rhs)
    {
        constexpr const auto COL_COUNT = _COLS1 > _COLS2 ? _COLS1 : _COLS2;
        constexpr const auto ROW_COUNT = _ROWS1 > _ROWS2 ? _ROWS1 : _ROWS2;
        typedef typename MathOp<_DATA_TYPE1, _DATA_TYPE2>::minus DATA_TYPE;

        Matrix<COL_COUNT, ROW_COUNT, DATA_TYPE, 0, 0> ret;
        MATHPP_MAT_LOOP(ret, r, c)
        {
            ret.at(r, c) = lhs.get(r, c) - rhs.get(r, c);
        }
        return ret;
    }

    template <
        typename _DATA_TYPE1,
        size_t _COLS2, size_t _ROWS2, typename _DATA_TYPE2, size_t _COL_SKIP2, size_t _ROW_SKIP2>
    constexpr auto operator*(
        _DATA_TYPE1 const &lhs,
        Matrix<_COLS2, _ROWS2, _DATA_TYPE2, _COL_SKIP2, _ROW_SKIP2> const &rhs)
    {
        constexpr const auto COL_COUNT = _COLS2;
        constexpr const auto ROW_COUNT = _ROWS2;
        typedef typename MathOp<_DATA_TYPE1, _DATA_TYPE2>::multiply DATA_TYPE;

        Matrix<COL_COUNT, ROW_COUNT, DATA_TYPE, 0, 0> ret;
        MATHPP_MAT_LOOP(ret, r, c)
        {
            ret.at(r, c) = lhs * rhs.get(r, c);
        }
        return ret;
    }

    template <
        size_t _COLS1, size_t _ROWS1, typename _DATA_TYPE1, size_t _COL_SKIP1, size_t _ROW_SKIP1,
        typename _DATA_TYPE2>
    constexpr auto operator*(
        Matrix<_COLS1, _ROWS1, _DATA_TYPE1, _COL_SKIP1, _ROW_SKIP1> const &lhs,
        _DATA_TYPE2 const &rhs)
    {
        constexpr const auto COL_COUNT = _COLS1;
        constexpr const auto ROW_COUNT = _ROWS1;
        typedef typename MathOp<_DATA_TYPE1, _DATA_TYPE2>::multiply DATA_TYPE;

        Matrix<COL_COUNT, ROW_COUNT, DATA_TYPE, 0, 0> ret;
        MATHPP_MAT_LOOP(ret, r, c)
        {
            ret.at(r, c) = lhs.get(r, c) * rhs;
        }
        return ret;
    }

    template <
        size_t _COLS1, size_t _ROWS1, typename _DATA_TYPE1, size_t _COL_SKIP1, size_t _ROW_SKIP1,
        typename _DATA_TYPE2>
    constexpr auto operator/(
        Matrix<_COLS1, _ROWS1, _DATA_TYPE1, _COL_SKIP1, _ROW_SKIP1> const &lhs,
        _DATA_TYPE2 const &rhs)
    {
        constexpr const auto COL_COUNT = _COLS1;
        constexpr const auto ROW_COUNT = _ROWS1;
        typedef typename MathOp<_DATA_TYPE1, _DATA_TYPE2>::division DATA_TYPE;

        Matrix<COL_COUNT, ROW_COUNT, DATA_TYPE, 0, 0> ret;
        MATHPP_MAT_LOOP(ret, r, c)
        {
            ret.at(r, c) = lhs.get(r, c) / rhs;
        }
        return ret;
    }

    template <
        size_t _COLS1, size_t _ROWS1, typename _DATA_TYPE1, size_t _COL_SKIP1, size_t _ROW_SKIP1,
        size_t _COLS2, size_t _ROWS2, typename _DATA_TYPE2, size_t _COL_SKIP2, size_t _ROW_SKIP2>
    constexpr typename std::enable_if<_COLS1 == _ROWS2,
                                      Matrix<_COLS2, _ROWS1,
                                             typename MathOp<
                                                 typename MathOp<_DATA_TYPE1, _DATA_TYPE2>::multiply,
                                                 typename MathOp<_DATA_TYPE1, _DATA_TYPE2>::multiply>::plus,
                                             0, 0>>::type
    operator*(
        Matrix<_COLS1, _ROWS1, _DATA_TYPE1, _COL_SKIP1, _ROW_SKIP1> const &lhs,
        Matrix<_COLS2, _ROWS2, _DATA_TYPE2, _COL_SKIP2, _ROW_SKIP2> const &rhs)
    {
        typedef typename MathOp<_DATA_TYPE1, _DATA_TYPE2>::multiply MULT_DATA_TYPE;
        typedef typename MathOp<MULT_DATA_TYPE, MULT_DATA_TYPE>::plus RET_DATA_TYPE;
        constexpr const auto MID_SIZE = _COLS1; // _ROWS2
        Matrix<_COLS2, _ROWS1, RET_DATA_TYPE, 0, 0> ret;
        MATHPP_MAT_LOOP(ret, r, c)
        {
            typename decltype(ret)::TYPE v = RET_DATA_TYPE(0);
            MATHPP_LOOP(MID_SIZE, i)
            {
                v = v + RET_DATA_TYPE(lhs.at(r, i) * rhs.at(i, c));
            }
            ret.at(r, c) = v;
        }
        return ret;
    }

}