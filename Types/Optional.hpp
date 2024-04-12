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
        implicit constexpr Optional(Optional const &&opt) : value(std::move(opt.value)), hasValue(opt.hasValue){};
        implicit constexpr Optional(Optional const &opt) : value(opt.value), hasValue(opt.hasValue){};
        implicit constexpr Optional(ValueT const &&value) : value(std::move(value)), hasValue(true){};
        implicit constexpr Optional(ValueT const &value) : value(value), hasValue(true){};
        implicit constexpr Optional() : value(ValueT()), hasValue(false){};

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
