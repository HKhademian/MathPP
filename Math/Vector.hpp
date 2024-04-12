#pragma once
#include <cstddef>
#include "../Types/Types.hpp"

#ifndef MATHPP_DEFAULT_DATA_TYPE
#define MATHPP_DEFAULT_DATA_TYPE float
#endif

namespace MathPP
{

    /*
     * STRIDE
     * 99  98  97  96  95  94  93  92  91  90  89  88  87  86  85  84  83  82  81  80
     * 99      97      95      93      91      89      87      85      83      81
     * 99              95              91              87              83
     */

    template <std::size_t _SIZE, typename _DATA_TYPE = MATHPP_DEFAULT_DATA_TYPE, std::size_t _STRIDE = 0>
    struct Vektor
    {
    public:
        static constexpr const std::size_t SIZE = _SIZE;
        static constexpr const std::size_t STRIDE = _STRIDE;
        using DATA_TYPE = _DATA_TYPE;
        using MEM_TYPE = DATA_TYPE[SIZE * (STRIDE + 1)];
        using this_t = Vektor<SIZE, DATA_TYPE, STRIDE>;

    public:
        MEM_TYPE memory;

        /*
         * INSTANCE
         */

        constexpr inline static this_t const &from(DATA_TYPE const *memory) noexcept
        {
            return *(this_t const *)(void const *)memory;
        }
        constexpr inline static this_t &from(DATA_TYPE *memory) noexcept
        {
            return *(this_t *)(void *)memory;
        }

        constexpr inline static auto ofAll(DATA_TYPE const &value) noexcept
        {
            this_t ret;
            for (std::size_t i = 0; i < ret.SIZE; ++i)
            {
                ret.at(i) = value;
            }
            return ret;
        }

        constexpr inline static auto zeros() noexcept { return ofAll(0); }
        constexpr inline static auto ones() noexcept { return ofAll(1); }

        /*
         * access
         */

        constexpr inline DATA_TYPE const &at(size_t index) const noexcept
        {
            return memory[index * (STRIDE + 1)];
        }
        constexpr inline DATA_TYPE &at(size_t index) noexcept
        {
            return memory[index * (STRIDE + 1)];
        }

        /*
         * conversion
         */

        template <size_t __S, size_t __OFFSET = 0, size_t __STRIDE = 0>
        constexpr inline auto const &subvec() const noexcept
        {
            constexpr const auto stride = (STRIDE + 1) * (__STRIDE + 1) - 1;
            return Vektor<__S, DATA_TYPE, stride>::from(&at(__OFFSET));
        }

        template <size_t __S, size_t __OFFSET = 0, size_t __STRIDE = 0>
        constexpr inline auto subvec() noexcept
        {
            constexpr const auto stride = (STRIDE + 1) * (__STRIDE + 1) - 1;
            return Vektor<__S, DATA_TYPE, stride>::from(&at(__OFFSET));
        }

#define if_size_ge(___X, ___T)   \
    template <size_t __S = SIZE> \
    typename std::enable_if<(__S == SIZE) && (__S >= ___X), ___T>::type

#define if_size_in(___X, ___Y, ___T) \
    template <size_t __S = SIZE>     \
    typename std::enable_if<(__S == SIZE) && (__S >= ___X) && (__S < ___Y), ___T>::type

        if_size_ge(1, DATA_TYPE) constexpr inline const &v1() const noexcept { return at(0); }
        if_size_ge(1, DATA_TYPE) constexpr inline &v1() noexcept { return at(0); }
        if_size_ge(1, DATA_TYPE) constexpr inline const &x() const noexcept { return at(0); }
        if_size_ge(1, DATA_TYPE) constexpr inline &x() noexcept { return at(0); }
        if_size_ge(1, DATA_TYPE) constexpr inline const &width() const noexcept { return at(0); }
        if_size_ge(1, DATA_TYPE) constexpr inline &width() noexcept { return at(0); }

        if_size_ge(2, DATA_TYPE) constexpr inline const &v2() const noexcept { return at(1); }
        if_size_ge(2, DATA_TYPE) constexpr inline &v2() noexcept { return at(1); }
        if_size_ge(2, DATA_TYPE) constexpr inline const &y() const noexcept { return at(1); }
        if_size_ge(2, DATA_TYPE) constexpr inline &y() noexcept { return at(1); }
        if_size_ge(2, DATA_TYPE) constexpr inline const &height() const noexcept { return at(1); }
        if_size_ge(2, DATA_TYPE) constexpr inline &height() noexcept { return at(1); }

        if_size_ge(3, DATA_TYPE) constexpr inline const &v3() const noexcept { return at(2); }
        if_size_ge(3, DATA_TYPE) constexpr inline &v3() noexcept { return at(2); }
        if_size_ge(3, DATA_TYPE) constexpr inline const &z() const noexcept { return at(2); }
        if_size_ge(3, DATA_TYPE) constexpr inline &z() noexcept { return at(2); }
        if_size_ge(3, DATA_TYPE) constexpr inline const &depth() const noexcept { return at(2); }
        if_size_ge(3, DATA_TYPE) constexpr inline &depth() noexcept { return at(2); }

        if_size_ge(4, DATA_TYPE) constexpr inline const &v4() const noexcept { return at(3); }
        if_size_ge(4, DATA_TYPE) constexpr inline &v4() noexcept { return at(3); }
        if_size_ge(4, DATA_TYPE) constexpr inline const &w() const noexcept { return at(3); }
        if_size_ge(4, DATA_TYPE) constexpr inline &w() noexcept { return at(3); }
        if_size_ge(4, DATA_TYPE) constexpr inline const &layer() const noexcept { return at(3); }
        if_size_ge(4, DATA_TYPE) constexpr inline &layer() noexcept { return at(3); }

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

    template <typename T = MATHPP_DEFAULT_DATA_TYPE, size_t __STRIDE = 0>
    using Vektor2 = Vektor<2, T, __STRIDE>;

    template <typename T = MATHPP_DEFAULT_DATA_TYPE, size_t __STRIDE = 0>
    using Vektor3 = Vektor<3, T, __STRIDE>;

    template <typename T = MATHPP_DEFAULT_DATA_TYPE, size_t __STRIDE = 0>
    using Vektor4 = Vektor<4, T, __STRIDE>;

    template <size_t __STRIDE = 0>
    using Vektor2S = Vektor2<signed int, __STRIDE>;

    template <size_t __STRIDE = 0>
    using Vektor2I = Vektor2<unsigned int, __STRIDE>;

    /*
     * Operators
     */

    template <size_t __S1, typename __T1, size_t __STRIDE1, size_t __S2, typename __T2, size_t __STRIDE2>
    auto operator+(Vektor<__S1, __T1, __STRIDE1> const &lhs, Vektor<__S2, __T2, __STRIDE2> const &rhs)
    {
        constexpr const auto SIZE = __S1 <= __S2 ? __S1 : __S2;
        typedef typename MathOp<__T1, __T2>::plus type;

        Vektor<SIZE, type, 0> ret;
        for (std::size_t i = 0; i < ret.SIZE; ++i)
        {
            ret.at(i) = lhs.at(i) + rhs.at(i);
        }
        return ret;
    }

    template <size_t __S1, typename __T1, size_t __STRIDE1, size_t __S2, typename __T2, size_t __STRIDE2>
    constexpr auto operator-(Vektor<__S1, __T1, __STRIDE1> const &lhs, Vektor<__S2, __T2, __STRIDE2> const &rhs)
    {
        constexpr const auto SIZE = __S1 <= __S2 ? __S1 : __S2;
        typedef typename MathOp<__T1, __T2>::minus type;

        Vektor<SIZE, type, 0> ret;
        for (std::size_t i = 0; i < ret.SIZE; ++i)
        {
            ret.at(i) = lhs.at(i) - rhs.at(i);
        }
        return ret;
    }

    template <size_t __S1, typename __T1, size_t __STRIDE1, typename __V>
    constexpr auto operator*(__V v, Vektor<__S1, __T1, __STRIDE1> const &rhs)
    {
        typedef typename MathOp<__T1, __V>::multiply type;
        Vektor<__S1, type, 0> ret;
        for (std::size_t i = 0; i < ret.SIZE; ++i)
        {
            ret.at(i) = v * rhs.at(i);
        }
        return ret;
    }

    template <size_t __S1, typename __T1, size_t __STRIDE1, typename __V>
    constexpr auto operator*(Vektor<__S1, __T1, __STRIDE1> const &lhs, __V v)
    {
        typedef typename MathOp<__T1, __V>::multiply type;
        Vektor<__S1, type, 0> ret;
        for (std::size_t i = 0; i < ret.SIZE; ++i)
        {
            ret.at(i) = lhs.at(i) * v;
        }
        return ret;
    }

    template <size_t __S1, typename __T1, size_t __STRIDE1, typename __V>
    constexpr auto operator/(Vektor<__S1, __T1, __STRIDE1> const &lhs, __V v)
    {
        typedef typename MathOp<__T1, __V>::division type;
        Vektor<__S1, type, 0> ret;
        for (std::size_t i = 0; i < ret.SIZE; ++i)
        {
            ret.at(i) = lhs.at(i) / v;
        }
        return ret;
    }

}
