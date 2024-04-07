#pragma once
#include <cstddef>
#include "Types.hpp"

#define implicit
#define LOG(x) std::cout << "TestClass:: " << x << std::endl
namespace TypePP
{
    template <typename _ValueT>
    struct TestClass
    {
        using ValueT = _ValueT;

    private:
        ValueT value;

    public:
        implicit constexpr TestClass(TestClass const &&other) : value(std::move(other.value))
        {
            LOG("ctor move");
        };
        implicit constexpr TestClass(TestClass const &other) : value(other.value)
        {
            LOG("ctor copy");
        };
        implicit constexpr TestClass(ValueT const &&value) : value(std::move(value))
        {
            LOG("ctor value move");
        };
        implicit constexpr TestClass(ValueT const &value) : value(value)
        {
            LOG("ctor value copy");
        };
        implicit constexpr TestClass()
        {
            LOG("ctor default");
        };

        implicit constexpr inline operator ValueT const &() const
        {
            LOG("operator cast ValueT const&");
            return value;
        }

        implicit constexpr inline operator ValueT &()
        {
            LOG("operator cast ValueT &");
            return value;
        }

        implicit constexpr inline operator ValueT() const
        {
            LOG("operator cast ValueT");
            return value;
        }

        implicit constexpr inline TestClass &operator=(TestClass const &&opt)
        {
            LOG("operator= move");
            return *this;
        }

        implicit constexpr inline TestClass &operator=(TestClass const &opt)
        {
            LOG("operator= copy");
            return *this;
        }

        implicit constexpr inline bool operator==(TestClass const &rhs) const
        {
            LOG("operator==");
            return (value == rhs.value);
        }

        implicit constexpr inline bool operator!=(TestClass const &rhs) const
        {
            LOG("operator!=");
            return !(value == rhs.value);
        }
    };
}
#undef LOG
#undef implicit
