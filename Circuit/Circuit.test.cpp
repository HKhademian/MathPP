/// clear && gcc -o ./Circuit/DigitalV.out ./Circuit/DigitalV.test.cpp -lstdc++ && echo "9 8 7 6 5 4 3 2 1" | ./Circuit/DigitalV.out | tee ./Circuit/DigitalV.test.out && rm ./Circuit/DigitalV.out

#include "Circuit.hpp"
#include "Circuit.iostream.hpp"
#include "DigitalV.hpp"
#include "DigitalV.iostream.hpp"
#include <iostream>

using namespace CircuitPP;

int main(void)
{
    std::cout << "START" << std::endl;

    for (unsigned char i = 10; i < 20; ++i)
    {
        auto v = busOf<DigitalV>(i);
        std::cout << (int)i << " = ";
        std::cout << v;
        std::cout << std::endl;
    }
    std::cout << std::endl;

    {
        auto a = Bus<5, DigitalV>(7);
        auto b = busOf<DigitalV, char>(12);
        auto s = adder_ripple(a, b, DigitalV::V0);
        std::cout << "A     =             " << a << std::endl;
        std::cout << "B     =    " << b << std::endl;
        std::cout << "(A+B) = " << s << std::endl;
        std::cout << std::endl;
    }

    {
        auto a = busOf<DigitalV>(char(7));
        auto b = busOf<DigitalV>(char(12));
        auto s = adder_ripple(a, b, DigitalV::V0);
        std::cout << "A     =    " << a << std::endl;
        std::cout << "B     =    " << b << std::endl;
        std::cout << "(A+B) = " << s << std::endl;
        std::cout << std::endl;
    }

    {
        auto a = busOf<DigitalV>((unsigned char)(141));
        auto b = busOf<DigitalV>((unsigned char)(145));
        auto s = adder_ripple(a, b, DigitalV::V0);
        std::cout << "A     =    " << a << std::endl;
        std::cout << "B     =    " << b << std::endl;
        std::cout << "(A+B) = " << s << std::endl;
        std::cout << std::endl;
    }

    std::cout << "FINISH" << std::endl;
    return 0;
}