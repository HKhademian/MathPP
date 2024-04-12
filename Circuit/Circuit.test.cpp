/// clear && gcc -o ./Circuit/DigitalV.out ./Circuit/DigitalV.test.cpp -lstdc++ && echo "9 8 7 6 5 4 3 2 1" | ./Circuit/DigitalV.out | tee ./Circuit/DigitalV.test.out && rm ./Circuit/DigitalV.out

#include "DigitalV.hpp"
#include "DigitalV.iostream.hpp"
#include "Bus.hpp"
#include "Bus.ops.hpp"
#include "Bus.iostream.hpp"
#include "Circuit.hpp"
#include <iostream>

using namespace CircuitPP;

template <typename ValueT>
void test(std::string const &typeName)
{
    std::cout << "START " << typeName << std::endl;

    {
        auto a = busOf<ValueT, 5>(7);
        auto b = busOf<ValueT>(char(12));
        auto s = adder_ripple(a, b, ValueT(0));
        std::cout << "A     =             " << a << std::endl;
        std::cout << "B     =    " << b << std::endl;
        std::cout << "(A+B) = " << s << std::endl;
        std::cout << std::endl;
    }

    {
        auto a = busOf<ValueT, char>(7);
        auto b = busOf<ValueT, char>(12);
        auto s = adder_ripple(a, b, ValueT(0));
        std::cout << "A     =    " << a << std::endl;
        std::cout << "B     =    " << b << std::endl;
        std::cout << "(A+B) = " << s << std::endl;
        std::cout << std::endl;
    }

    {
        auto a = busOf<ValueT, unsigned char>(141);
        auto b = busOf<ValueT, unsigned char>(145);
        auto s = adder_ripple(a, b, ValueT(0));
        std::cout << "A     =    " << a << std::endl;
        std::cout << "B     =    " << b << std::endl;
        std::cout << "(A+B) = " << s << std::endl;
        std::cout << std::endl;
    }

    std::cout << "FINISH " << typeName << std::endl;
}

int main(void)
{
    test<DigitalV>("DigitalV");
    test<bool>("bool");
    test<int>("int");
    return 0;
}
