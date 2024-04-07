#pragma once
#include <cstddef>
#include "Types.hpp"

#define implicit
namespace TypePP
{
    // TODO : think about more optimized no-copy or less-copy version
    // or if even possible to implement
    // maybe no refrence impl is more desirable, or configurable to use in both mode

    template <typename ValueT>
    struct Optional
    {
    private:
        ValueT value;
        bool hasValue;

    public:
        implicit constexpr Optional(Optional const &&opt) : hasValue(opt.hasValue), value(std::move(opt.value)){};
        implicit constexpr Optional(Optional const &opt) : hasValue(opt.hasValue), value(opt.value){};
        implicit constexpr Optional(ValueT const &&value) : hasValue(true), value(std::move(value)){};
        implicit constexpr Optional(ValueT const &value) : hasValue(true), value(value){};
        implicit constexpr Optional() : hasValue(false), value(ValueT()){};

        /*
         * CHECK
         */

        constexpr inline bool has() const { return hasValue; }

        /*
         * READ
         */
        implicit constexpr inline ValueT const &operator*() const { return value; }
        implicit constexpr inline operator ValueT const &() const { return value; }

        /*
         * READ + WRITE via reference
         */
        implicit constexpr inline ValueT &operator*()
        {
            /*
             * NOTE: since Optional owns the mem of value,
             * we can safely assume that the value ref is valid
             * the user can write into this area, so it may have value
             */
            hasValue = true;
            return value;
        }
        // implicit constexpr inline operator ValueT &()
        // {
        //     hasValue = true;
        //     return value;
        // }

        /*
         * ASSIGN
         */

        constexpr inline Optional &operator=(Optional const &&opt)
        {
            hasValue = opt.hasValue;
            value = std::move(opt.value);
            return *this;
        }

        constexpr inline Optional &operator=(Optional const &opt)
        {
            hasValue = opt.hasValue;
            value = opt.value;
            return *this;
        }

        constexpr inline Optional &operator=(ValueT const &&newValue)
        {
            hasValue = true;
            value = std::move(newValue);
            return *this;
        }

        constexpr inline Optional &operator=(ValueT const &newValue)
        {
            hasValue = true;
            value = newValue;
            return *this;
        }

        constexpr inline Optional &operator=(ValueT const *newValue)
        {
            hasValue = (newValue != nullptr);
            if (hasValue)
                value = *newValue;
            return *this;
        }

        /*
         * COMPAIR
         */

        constexpr inline bool operator==(Optional const &rhs) const
        {
            return (hasValue == rhs.hasValue) && (value == rhs.value);
        }

        constexpr inline bool operator!=(Optional const &rhs) const
        {
            return !(*this == rhs);
        }
    };
}
#undef implicit
