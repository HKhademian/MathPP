/// clear && gcc -o ./Circuit/DigitalV.out ./Circuit/DigitalV.test.cpp -lstdc++ && echo "9 8 7 6 5 4 3 2 1" | ./Circuit/DigitalV.out | tee ./Circuit/DigitalV.test.out && rm ./Circuit/DigitalV.out

#include "DigitalV.hpp"
#include "DigitalV.iostream.hpp"
#include <iostream>

using namespace CircuitPP;

const auto V0 = DigitalV::V0;
const auto V1 = DigitalV::V1;

int main(void)
{
    std::cout << "START" << std::endl;

    std::cout << "V0: " << DigitalV::V0 << std::endl;
    std::cout << "V1: " << DigitalV::V1 << std::endl;
    std::cout << std::endl;

    std::cout << "eval V0: " << eval(DigitalV::V0, 0) << std::endl;
    std::cout << "eval V1: " << eval(DigitalV::V1, 0) << std::endl;
    std::cout << std::endl;

    std::cout << "! V0: " << !V0 << std::endl;
    std::cout << "! V1: " << !V1 << std::endl;
    std::cout << std::endl;

    std::cout << "V0 & V0: " << (V0 & V0) << std::endl;
    std::cout << "V0 & V1: " << (V0 & V1) << std::endl;
    std::cout << "V1 & V1: " << (V1 & V1) << std::endl;
    std::cout << "V0 & V1: " << (V0 & V1) << std::endl;
    std::cout << std::endl;

    std::cout << "V0 | V0: " << (V0 | V0) << std::endl;
    std::cout << "V0 | V1: " << (V0 | V1) << std::endl;
    std::cout << "V1 | V1: " << (V1 | V1) << std::endl;
    std::cout << "V0 | V1: " << (V0 | V1) << std::endl;
    std::cout << std::endl;

    std::cout << "V0 ^ V0: " << (V0 ^ V0) << std::endl;
    std::cout << "V0 ^ V1: " << (V0 ^ V1) << std::endl;
    std::cout << "V1 ^ V1: " << (V1 ^ V1) << std::endl;
    std::cout << "V0 ^ V1: " << (V0 ^ V1) << std::endl;
    std::cout << std::endl;

    {
        std::cout << "Complex1: (!(!(!(V0 & V1)))) === " << (!(!(!(V0 & V1)))) << std::endl;
        std::cout << "Complex2: (!V0 ^ V1) === " << (!V0 ^ V1) << std::endl;
        std::cout << "Complex3: ((V1 & !V0) ^ V1) === " << ((V1 & !V0) ^ V1) << std::endl;
        std::cout << "Complex4: (!((V1 & !V0) ^ V1)) === " << (!((V1 & !V0) ^ V1)) << std::endl;
        std::cout << "Complex4: eval(!((V1 & !V0) ^ V1)) === " << eval(!((V1 & !V0) ^ V1), 0) << std::endl;
        std::cout << std::endl;
    }

    std::cout << "FINISH" << std::endl;
    return 0;
}