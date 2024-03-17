#pragma once
#include <type_traits>
#include <typeinfo>
#include <ostream>

namespace MathPP
{
    using size_t = unsigned int;

#define if_size_ge(X, T)       \
    template <size_t SIZE = S> \
    typename std::enable_if<(S == SIZE) && (SIZE >= X), T>::type

#define if_size_in(X, Y, T)    \
    template <size_t SIZE = S> \
    typename std::enable_if<(S == SIZE) && (S >= X) && (S < Y), T>::type

    template <size_t S, typename T>
    struct Vektor;

    template <size_t S, typename T>
    struct Vektor
    {
    private:
    public:
        using this_t = Vektor<S, T>;
        using SIZE = std::integral_constant<size_t, S>;
        using TYPE = T;

        T components[SIZE::value] = {0};

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

        if_size_ge(1, T) const &v1() const { return components[0]; }
        if_size_ge(1, T) & v1() { return components[0]; }
        if_size_ge(1, T) const &x() const { return components[0]; }
        if_size_ge(1, T) & x() { return components[0]; }
        if_size_ge(1, T) const &width() const { return components[0]; }
        if_size_ge(1, T) & width() { return components[0]; }

        if_size_ge(2, T) const &v2() const { return components[1]; }
        if_size_ge(2, T) & v2() { return components[1]; }
        if_size_ge(2, T) const &y() const { return components[1]; }
        if_size_ge(2, T) & y() { return components[1]; }
        if_size_ge(2, T) const &height() const { return components[1]; }
        if_size_ge(2, T) & height() { return components[1]; }

        if_size_ge(3, T) const &v3() const { return components[2]; }
        if_size_ge(3, T) & v3() { return components[2]; }
        if_size_ge(3, T) const &z() const { return components[2]; }
        if_size_ge(3, T) & z() { return components[2]; }
        if_size_ge(3, T) const &depth() const { return components[2]; }
        if_size_ge(3, T) & depth() { return components[2]; }

        if_size_ge(4, T) const &v4() const { return components[3]; }
        if_size_ge(4, T) & v4() { return components[3]; }
        if_size_ge(4, T) const &w() const { return components[3]; }
        if_size_ge(4, T) & w() { return components[3]; }
        if_size_ge(4, T) const &layer() const { return components[3]; }
        if_size_ge(4, T) & layer() { return components[3]; }

        using Vektor2 = Vektor<2, T>;
        if_size_in(3, 5, Vektor2) pos() const
        {
            return Vektor2{{v1(), v2()}};
        }

        if_size_in(4, 5, Vektor2) size() const
        {
            return Vektor2{{v3(), v4()}};
        }
    };
#undef if_size_ge

    template <typename T>
    using Vektor2 = Vektor<2, T>;

    template <typename T>
    using Vektor3 = Vektor<3, T>;

    template <typename T>
    using Vektor4 = Vektor<4, T>;

    using Vektor2S = Vektor<2, signed int>;
    using Vektor2I = Vektor<2, unsigned int>;

    template <size_t S, typename T>
    Vektor<S, T> operator+(const Vektor<S, T> &lhs, const Vektor<S, T> &rhs)
    {
        Vektor<S, T> ret;
        for (auto &v : ret.components)
            v = 1;
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

    template <size_t S, typename T>
    std::ostream &operator<<(std::ostream &os, const Vektor<S, T> &vek)
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

    template <size_t S, typename T>
    std::istream &operator>>(std::istream &is, Vektor<S, T> &vek)
    {
        for (auto &v : vek.components)
        {
            is >> v;
        }
        return is;
    }

}
