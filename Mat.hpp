#pragma once
#include "Types.hpp"
#include <ostream>

namespace MathPP
{
    template <typename _DATA_TYPE, size_t _SIZE, size_t _STRIDE = 0>
    struct Vektor
    {
        static constexpr const auto SIZE = _SIZE;
        static constexpr const auto STRIDE = _STRIDE;
        using DATA_TYPE = _DATA_TYPE;
        using MEM_TYPE = DATA_TYPE[SIZE * (STRIDE + 1)];

    private:
        using this_t = Vektor<DATA_TYPE, SIZE, STRIDE>;

    public:
        MEM_TYPE memory;

        constexpr static this_t const &from(DATA_TYPE const *memory)
        {
            return *(this_t const *)(void const *)memory;
        }
        constexpr static this_t &from(DATA_TYPE *memory)
        {
            return *(this_t *)(void *)memory;
        }

        constexpr static auto ofAll(DATA_TYPE const &value)
        {
            this_t ret;
            for (auto i = 0; i < ret.SIZE; ++i)
            {
                ret.at(i) = value;
            }
            return ret;
        }

        constexpr static auto zero()
        {
            return ofAll(0);
        }

        constexpr static auto one()
        {
            return ofAll(1);
        }

        /*
         * access
         */

        constexpr const DATA_TYPE &at(size_t index) const
        {
            return memory[index * (STRIDE + 1)];
        }
        constexpr DATA_TYPE &at(size_t index)
        {
            return memory[index * (STRIDE + 1)];
        }

        /*
         * conversion
         */

        /*
        99  98  97  96  95  94  93  92  91  90  89  88  87  86  85  84  83  82  81  80
        99      97      95      93      91      89      87      85      83      81
        99              95              91              87              83
        */

        template <size_t __S, size_t __OFFSET = 0, size_t __STRIDE = 0>
        constexpr auto const &subvec() const
        {
            constexpr const auto stride = (STRIDE + 1) * (__STRIDE + 1) - 1;
            return Vektor<DATA_TYPE, __S, STRIDE>::from(&at(__OFFSET));
        }

        template <size_t __S, size_t __OFFSET = 0, size_t __STRIDE = 0>
        constexpr auto subvec()
        {
            constexpr const auto stride = (STRIDE + 1) * (__STRIDE + 1) - 1;
            return Vektor<DATA_TYPE, __S, STRIDE>::from(&at(__OFFSET));
        }

#define if_size_ge(___X, ___T)   \
    template <size_t __S = SIZE> \
    typename std::enable_if<(__S == SIZE) && (__S >= ___X), ___T>::type

#define if_size_in(___X, ___Y, ___T) \
    template <size_t __S = SIZE>     \
    typename std::enable_if<(__S == SIZE) && (__S >= ___X) && (__S < ___Y), ___T>::type

        if_size_ge(1, DATA_TYPE) constexpr const &v1() const { return at(0); }
        if_size_ge(1, DATA_TYPE) constexpr &v1() { return at(0); }
        if_size_ge(1, DATA_TYPE) constexpr const &x() const { return at(0); }
        if_size_ge(1, DATA_TYPE) constexpr &x() { return at(0); }
        if_size_ge(1, DATA_TYPE) constexpr const &width() const { return at(0); }
        if_size_ge(1, DATA_TYPE) constexpr &width() { return at(0); }

        if_size_ge(2, DATA_TYPE) constexpr const &v2() const { return at(1); }
        if_size_ge(2, DATA_TYPE) constexpr &v2() { return at(1); }
        if_size_ge(2, DATA_TYPE) constexpr const &y() const { return at(1); }
        if_size_ge(2, DATA_TYPE) constexpr &y() { return at(1); }
        if_size_ge(2, DATA_TYPE) constexpr const &height() const { return at(1); }
        if_size_ge(2, DATA_TYPE) constexpr &height() { return at(1); }

        if_size_ge(3, DATA_TYPE) constexpr const &v3() const { return at(2); }
        if_size_ge(3, DATA_TYPE) constexpr &v3() { return at(2); }
        if_size_ge(3, DATA_TYPE) constexpr const &z() const { return at(2); }
        if_size_ge(3, DATA_TYPE) constexpr &z() { return at(2); }
        if_size_ge(3, DATA_TYPE) constexpr const &depth() const { return at(2); }
        if_size_ge(3, DATA_TYPE) constexpr &depth() { return at(2); }

        if_size_ge(4, DATA_TYPE) constexpr const &v4() const { return at(3); }
        if_size_ge(4, DATA_TYPE) constexpr &v4() { return at(3); }
        if_size_ge(4, DATA_TYPE) constexpr const &w() const { return at(3); }
        if_size_ge(4, DATA_TYPE) constexpr &w() { return at(3); }
        if_size_ge(4, DATA_TYPE) constexpr const &layer() const { return at(3); }
        if_size_ge(4, DATA_TYPE) constexpr &layer() { return at(3); }

        //         /*
        //          * 2D
        //          */
        //
        //     private:
        //         using Vektor2Dynamic = Vektor<DATA_TYPE, 2, _STRIDE, false>;
        //
        //     public:
        //         if_size_in(3, 5, Vektor2Dynamic) const &pos() const
        //         {
        //             return subvec<2>();
        //         }
        //         if_size_in(3, 5, Vektor2Dynamic) & pos()
        //         {
        //             return subvec<2>();
        //         }
        //
        //         if_size_in(3, 4, DATA_TYPE) const &size() const
        //         {
        //             return v3();
        //         }
        //         if_size_in(3, 4, DATA_TYPE) & size()
        //         {
        //             return v3();
        //         }
        //
        //         if_size_in(4, 5, Vektor2Dynamic) const &size() const
        //         {
        //             return subvec<2, 2>();
        //         }
        //         if_size_in(4, 5, Vektor2Dynamic) & size()
        //         {
        //             return subvec<2, 2>();
        //         }
        //
        //         /*
        //          * 3D
        //          */
        //
        //     private:
        //         using Vektor3Dynamic = Vektor<DATA_TYPE, 3, _STRIDE, false>;
        //
        //     public:
        //         if_size_in(5, 7, Vektor3Dynamic) const &pos() const
        //         {
        //             return subvec<3>();
        //         }
        //         if_size_in(5, 7, Vektor3Dynamic) & pos()
        //         {
        //             return subvec<3>();
        //         }
        //
        //         if_size_in(6, 7, Vektor3Dynamic) const &size() const
        //         {
        //             return subvec<3, 3>();
        //         }
        //         if_size_in(6, 7, Vektor3Dynamic) & size()
        //         {
        //             return subvec<3, 3>();
        //         }

#undef if_size_ge
#undef if_size_in
    };

    template <typename T, size_t __STRIDE = 0>
    using Vektor2 = Vektor<T, 2, __STRIDE>;

    template <typename T, size_t __STRIDE = 0>
    using Vektor3 = Vektor<T, 3, __STRIDE>;

    template <typename T, size_t __STRIDE = 0>
    using Vektor4 = Vektor<T, 4, __STRIDE>;

    template <size_t __STRIDE = 0>
    using Vektor2S = Vektor<signed int, 2, __STRIDE>;

    template <size_t __STRIDE = 0>
    using Vektor2I = Vektor<unsigned int, 2, __STRIDE>;

    /*
     * Operators
     */

    template <typename __T1, size_t __S1, size_t __STRIDE1, typename __T2, size_t __S2, size_t __STRIDE2>
    auto operator+(Vektor<__T1, __S1, __STRIDE1> const &lhs, Vektor<__T2, __S2, __STRIDE2> const &rhs)
    {
        constexpr const auto S = __S1 > __S2 ? __S2 : __S1;
        Vektor<typename Types::MathOp<__T1, __T2>::plus, S, 0> ret;
        for (auto i = 0; i < ret.SIZE; ++i)
        {
            ret.at(i) = lhs.at(i) + rhs.at(i);
        }
        return ret;
    }

    template <typename __T1, size_t __S1, size_t __STRIDE1, typename __T2, size_t __S2, size_t __STRIDE2>
    auto operator-(Vektor<__T1, __S1, __STRIDE1> const &lhs, Vektor<__T2, __S2, __STRIDE2> const &rhs)
    {
        constexpr const auto S = __S1 > __S2 ? __S2 : __S1;
        Vektor<typename Types::MathOp<__T1, __T2>::minus, S, 0> ret;
        for (auto i = 0; i < ret.SIZE; ++i)
        {
            ret.at(i) = lhs.at(i) - rhs.at(i);
        }
        return ret;
    }

    template <typename __T1, size_t __S1, size_t __STRIDE1, typename __V>
    auto operator*(__V v, Vektor<__T1, __S1, __STRIDE1> const &rhs)
    {
        Vektor<typename Types::MathOp<__T1, __V>::multiply, __S1, 0> ret;
        for (auto i = 0; i < ret.SIZE; ++i)
        {
            ret.at(i) = v * rhs.at(i);
        }
        return ret;
    }

    template <typename __T1, size_t __S1, size_t __STRIDE1, typename __V>
    auto operator*(Vektor<__T1, __S1, __STRIDE1> const &lhs, __V v)
    {
        Vektor<typename Types::MathOp<__T1, __V>::multiply, __S1, 0> ret;
        for (auto i = 0; i < ret.SIZE; ++i)
        {
            ret.at(i) = lhs.at(i) * v;
        }
        return ret;
    }

    template <typename __T1, size_t __S1, size_t __STRIDE1, typename __V>
    auto operator/(Vektor<__T1, __S1, __STRIDE1> const &lhs, __V v)
    {
        Vektor<typename Types::MathOp<__T1, __V>::division, __S1, 0> ret;
        for (auto i = 0; i < ret.SIZE; ++i)
        {
            ret.at(i) = lhs.at(i) / v;
        }
        return ret;
    }

    template <typename __T1, size_t __S1, size_t __STRIDE1>
    std::ostream &operator<<(std::ostream &os, Vektor<__T1, __S1, __STRIDE1> const &rhs)
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

    template <typename __T, size_t __S, size_t __STRIDE>
    std::istream &operator>>(std::istream &is, Vektor<__T, __S, __STRIDE> &rhs)
    {
        for (auto i = 0; i < rhs.SIZE; ++i)
        {
            is >> rhs.at(i);
        }
        return is;
    }

}

namespace MathPP
{

    template <typename _DATA_TYPE, size_t _R, size_t _C, size_t _STRIDE>
    struct Matrix;

    template <typename _DATA_TYPE, size_t _R, size_t _C, size_t _STRIDE>
    struct Matrix
    {
        // TODO apply _STRIDE
        _DATA_TYPE elements[_R * _C] = {0};

        using this_t = Matrix<_DATA_TYPE, _R, _C, _STRIDE>;
        using ROW_SIZE = std::integral_constant<size_t, _R>;
        using COL_SIZE = std::integral_constant<size_t, _C>;
        using SIZE = std::integral_constant<size_t, _R * _C>;
        using TYPE = _DATA_TYPE;

        _DATA_TYPE const &at(size_t row, size_t col) const { return elements[row * _C + col]; }
        _DATA_TYPE &at(size_t row, size_t col) { return elements[row * _C + col]; }
    };

}