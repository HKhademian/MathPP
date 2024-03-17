#pragma once
#include "Types.hpp"
#include <type_traits>
#include <ostream>

namespace MathPP
{
    using size_t = unsigned int;

    template <typename _T, size_t _S>
    struct Vektor;

    template <typename _T, size_t _S>
    struct Vektor
    {
        using this_t = Vektor<_T, _S>;
        using SIZE = std::integral_constant<size_t, _S>;
        using TYPE = _T;

        _T components[_S] = {0};

        template <size_t __S, size_t __OFF = 0>
        static typename std::enable_if<(_S >= __S - __OFF), this_t>::type const &
        from(Vektor<_T, __S> const &vek)
        {
            return *(this_t const *)(void const *)(&vek.components + __OFF);
        }
        template <size_t __S, size_t __OFF = 0>
        static typename std::enable_if<(_S >= __S - __OFF), this_t>::type &
        from(Vektor<_T, __S> &vek)
        {
            return *(this_t *)(void *)(&vek.components + __OFF);
        }

        static this_t const &from(_T const *components)
        {
            return *(this_t const *)(void const *)components;
        }
        static this_t &from(_T *components)
        {
            return *(this_t *)(void *)components;
        }

        static this_t zero()
        {
            return this_t{0};
        }

        static this_t one()
        {
            this_t ret;
            for (auto &v : ret.components)
                v = 1;
            return ret;
        }

#define if_size_ge(___X, ___T) \
    template <size_t __S = _S> \
    typename std::enable_if<(__S == _S) && (__S >= ___X), ___T>::type

#define if_size_in(___X, ___Y, ___T) \
    template <size_t __S = _S>       \
    typename std::enable_if<(__S == _S) && (__S >= ___X) && (__S < ___Y), ___T>::type

        if_size_ge(1, _T) const &v1() const { return components[0]; }
        if_size_ge(1, _T) & v1() { return components[0]; }
        if_size_ge(1, _T) const &x() const { return components[0]; }
        if_size_ge(1, _T) & x() { return components[0]; }
        if_size_ge(1, _T) const &width() const { return components[0]; }
        if_size_ge(1, _T) & width() { return components[0]; }

        if_size_ge(2, _T) const &v2() const { return components[1]; }
        if_size_ge(2, _T) & v2() { return components[1]; }
        if_size_ge(2, _T) const &y() const { return components[1]; }
        if_size_ge(2, _T) & y() { return components[1]; }
        if_size_ge(2, _T) const &height() const { return components[1]; }
        if_size_ge(2, _T) & height() { return components[1]; }

        if_size_ge(3, _T) const &v3() const { return components[2]; }
        if_size_ge(3, _T) & v3() { return components[2]; }
        if_size_ge(3, _T) const &z() const { return components[2]; }
        if_size_ge(3, _T) & z() { return components[2]; }
        if_size_ge(3, _T) const &depth() const { return components[2]; }
        if_size_ge(3, _T) & depth() { return components[2]; }

        if_size_ge(4, _T) const &v4() const { return components[3]; }
        if_size_ge(4, _T) & v4() { return components[3]; }
        if_size_ge(4, _T) const &w() const { return components[3]; }
        if_size_ge(4, _T) & w() { return components[3]; }
        if_size_ge(4, _T) const &layer() const { return components[3]; }
        if_size_ge(4, _T) & layer() { return components[3]; }

        /*
         * conversion
         */

        template <size_t __S, size_t __OFFSET = 0>
        typename std::enable_if<(_S >= __S + __OFFSET), Vektor<_T, __S>>::type const &subvec() const
        {
            return Vektor<_T, __S>::from((_T const *)(void const *)&components[__OFFSET]);
        }

        template <size_t __S, size_t __OFFSET = 0>
        typename std::enable_if<(_S >= __S + __OFFSET), Vektor<_T, __S>>::type &subvec()
        {
            return Vektor<_T, __S>::from((_T *)(void *)&components[__OFFSET]);
        }

        /*
         * 2D
         */

        using Vektor2 = Vektor<_T, 2>;

        if_size_in(3, 5, Vektor2) const &pos() const { return subvec<2>(); }
        if_size_in(3, 5, Vektor2) & pos() { return subvec<2>(); }

        if_size_in(3, 4, _T) const &size() const { return v3(); }
        if_size_in(3, 4, _T) & size() { return v3(); }

        if_size_in(4, 5, Vektor2) const &size() const { return subvec<2, 2>(); }
        if_size_in(4, 5, Vektor2) & size() { return subvec<2, 2>(); }

        /*
         * 3D
         */

        using Vektor3 = Vektor<_T, 3>;

        if_size_in(5, 7, Vektor3) const &pos() const { return subvec<3>(); }
        if_size_in(5, 7, Vektor3) & pos() { return subvec<3>(); }

        if_size_in(6, 7, Vektor3) const &size() const { return subvec<3, 3>(); }
        if_size_in(6, 7, Vektor3) & size() { return subvec<3, 3>(); }

#undef if_size_ge
#undef if_size_in
    };

    template <typename T>
    using Vektor2 = Vektor<T, 2>;

    template <typename T>
    using Vektor3 = Vektor<T, 3>;

    template <typename T>
    using Vektor4 = Vektor<T, 4>;

    using Vektor2S = Vektor<signed int, 2>;
    using Vektor2I = Vektor<unsigned int, 2>;

    /*
     * Operators
     */

    template <typename T, typename U, size_t S>
    auto operator+(Vektor<T, S> const &lhs, Vektor<U, S> const &rhs)
    {
        Vektor<typename Types::Plus<T, U>::V, S> ret;
        for (auto i = 0; i < S; ++i)
        {
            ret.components[i] = lhs.components[i] + rhs.components[i];
        }
        return ret;
    }

    template <typename T, typename U, size_t S>
    auto operator-(Vektor<T, S> const &lhs, Vektor<U, S> const &rhs)
    {
        Vektor<typename Types::Minus<T, U>::V, S> ret;
        for (auto i = 0; i < S; ++i)
        {
            ret.components[i] = lhs.components[i] - rhs.components[i];
        }
        return ret;
    }

    template <typename T, typename V, size_t S>
    auto operator*(V v, Vektor<T, S> const &rhs)
    {
        Vektor<typename Types::Multiply<V, T>::V, S> ret;
        for (auto i = 0; i < S; ++i)
        {
            ret.components[i] = v * rhs.components[i];
        }
        return ret;
    }

    template <typename T, typename V, size_t S>
    auto operator*(Vektor<T, S> const &lhs, V v)
    {
        Vektor<typename Types::Multiply<T, V>::V, S> ret;
        for (auto i = 0; i < S; ++i)
        {
            ret.components[i] = lhs.components[i] * v;
        }
        return ret;
    }

    template <typename T, typename V, size_t S>
    auto operator/(Vektor<T, S> const &lhs, V v)
    {
        Vektor<typename Types::Division<T, V>::V, S> ret;
        for (auto i = 0; i < S; ++i)
        {
            ret.components[i] = lhs.components[i] / v;
        }
        return ret;
    }

    // NOTE: ...YET... error: function template partial specialization is not allowed

    // template <typename T>
    // Vektor<1, T> operator+ <1, T>(const Vektor<1, T> &lhs, const Vektor<1, T> &rhs)
    // {
    //     Vektor<1, T> ret;
    //     ret.v1 = lhs.v1 + rhs.v1;
    //     return ret;
    // }
    //
    // template <typename T>
    // Vektor<2, T> operator+ <2>(const Vektor<2, T> &lhs, const Vektor<2, T> &rhs)
    // {
    //     Vektor<2, T> ret;
    //     ret.v1 = lhs.v1 + rhs.v1;
    //     ret.v2 = lhs.v2 + rhs.v2;
    //     return ret;
    // }
    //
    // template <typename T>
    // Vektor<3, T> operator+ <3>(const Vektor<3, T> &lhs, const Vektor<3, T> &rhs)
    // {
    //     Vektor<3, T> ret;
    //     ret.v1 = lhs.v1 + rhs.v1;
    //     ret.v2 = lhs.v2 + rhs.v2;
    //     ret.v3 = lhs.v3 + rhs.v3;
    //     return ret;
    // }
    //
    // template <typename T>
    // Vektor<4, T> operator+ <4>(const Vektor<4, T> &lhs, const Vektor<4, T> &rhs)
    // {
    //     Vektor<4, T> ret;
    //     ret.v1 = lhs.v1 + rhs.v1;
    //     ret.v2 = lhs.v2 + rhs.v2;
    //     ret.v3 = lhs.v3 + rhs.v3;
    //     ret.v4 = lhs.v4 + rhs.v4;
    //     return ret;
    // }

    template <typename T, size_t S>
    std::ostream &operator<<(std::ostream &os, Vektor<T, S> const &vek)
    {
        bool first = true;
        for (auto const &v : vek.components)
        {
            if (first)
            {
                first = false;
            }
            else
            {
                os << " ";
            }
            os << v;
        }
        return os;
    }

    template <typename T, size_t S>
    std::istream &operator>>(std::istream &is, Vektor<T, S> &vek)
    {
        for (auto &v : vek.components)
        {
            is >> v;
        }
        return is;
    }
}
