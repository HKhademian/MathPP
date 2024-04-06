#pragma once
#include "DigitalV.hpp"
#include <iostream>

namespace CircuitPP
{
    std::ostream &operator<<(std::ostream &os, DigitalV const &rhs)
    {
        if (rhs == DigitalV::V0)
            os << "V0";
        else if (rhs == DigitalV::V1)
            os << "V1";
        return os;
    }

    // std::ostream &operator<<(std::ostream &os, DigitalV const &&rhs)
    // {
    //     if (rhs == DigitalV::V0)
    //         os << "V0";
    //     else if (rhs == DigitalV::V1)
    //         os << "V1";
    //     return os;
    // }

}