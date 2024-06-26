/// clear && gcc -o ./Circuit/Bus.out ./Circuit/Bus.test.cpp -lstdc++ && echo "9 8 7 6 5 4 3 2 1" | ./Circuit/Bus.out | tee ./Circuit/Bus.test.out && rm ./Circuit/Bus.out

#include "Bus.hpp"
#include "Bus.ops.hpp"
#include "Bus.iostream.hpp"
#include "DigitalV.hpp"
#include "DigitalV.iostream.hpp"
#include <iostream>

using namespace CircuitPP;

template <typename ValueT>
void test(std::string const &typeName)
{
    std::cout << "START " << typeName << std::endl;

    for (unsigned char i = 10; i < 20; ++i)
    {
        auto v = busOf<ValueT>(i);
        std::cout << "     " << (int)i << " = ";
        std::cout << v;
        std::cout << std::endl;
        std::cout << "eval " << (int)i << " = ";
        std::cout << eval(v, 0);
        std::cout << std::endl;
    }

    std::cout << "FINISH " << typeName << std::endl;
    std::cout << std::endl;
}

int main(void)
{
    std::cout << "START " << std::endl;

    test<DigitalV>("DigitalV");
    test<bool>("bool");
    test<int>("int");

    auto test = busOf<unsigned short, 8>();
    for (std::size_t i = 0; i < test.size(); ++i)
    {
        test[i] = 1 + i;
    }
    std::cout << std::endl;

    std::cout << "test " << test << std::endl;
    std::cout << "<< 2 " << (test << 2) << std::endl;
    std::cout << ">> 2 " << (test >> 2) << std::endl;
    std::cout << "eval " << eval(test, 0) << std::endl;
    std::cout << std::endl;

    std::cout << "  busOf<8>(7)  " << busOf<8>(7) << std::endl;
    std::cout << "  busOf<8>(12) " << busOf<8>(12) << std::endl;
    std::cout << "! busOf<8>(12) " << !busOf<8>(12) << std::endl;
    std::cout << "busOf<8>(12) & busOf<8>(7) " << (busOf<8>(12) & busOf<8>(7)) << std::endl;
    std::cout << "busOf<8>(12) | busOf<8>(7) " << (busOf<8>(12) | busOf<8>(7)) << std::endl;
    std::cout << "busOf<8>(12) ^ busOf<8>(7) " << (busOf<8>(12) ^ busOf<8>(7)) << std::endl;
    std::cout << std::endl;

    std::cout << "FINISH " << std::endl;
    return 0;
}
