/// clear && gcc -o Circuit.out Circuit.test.cpp -lstdc++ && echo "9 8 7 6 5 4 3 2 1" | ./Circuit.out | tee ./Circuit.test.out && rm ./Circuit.out

#include <iostream>
#include "Circuit.hpp"
#include "Circuit.iostream.hpp"

using namespace CircuitPP;

int main(void)
{
    const auto TICK = 5;
    auto V0 = DigitalV::V0;
    auto V1 = DigitalV::V1;

    std::cout << "V0: " << V0 << std::endl;
    std::cout << "V1: " << V1 << std::endl;
    std::cout << std::endl;

    auto C0 = Const(V0);
    auto C1 = Const(V1);

    std::cout << "C0: " << (C0)(TICK) << std::endl;
    std::cout << "C1: " << (C1)(TICK) << std::endl;
    std::cout << std::endl;

    auto w0 = Wire(C0);
    auto w1 = Wire(C1);
    std::cout << "!! C0: " << w0(TICK) << std::endl;
    std::cout << "!! C1: " << w1(TICK) << std::endl;
    std::cout << std::endl;

    std::cout << "! C0: " << (Not(C0))(TICK) << std::endl;
    std::cout << "! C1: " << (Not(C1))(TICK) << std::endl;
    std::cout << std::endl;

    std::cout << "C0 & C0: " << (And(C0, C0))(TICK) << std::endl;
    std::cout << "C0 & C1: " << (And(C0, C1))(TICK) << std::endl;
    std::cout << "C1 & C1: " << (And(C1, C1))(TICK) << std::endl;
    std::cout << "C0 & C1: " << (And(C1, C0))(TICK) << std::endl;
    std::cout << std::endl;

    std::cout << "C0 | C0: " << (Or(C0, C0))(TICK) << std::endl;
    std::cout << "C0 | C1: " << (Or(C0, C1))(TICK) << std::endl;
    std::cout << "C1 | C1: " << (Or(C1, C1))(TICK) << std::endl;
    std::cout << "C0 | C1: " << (Or(C1, C0))(TICK) << std::endl;
    std::cout << std::endl;

    std::cout << "C0 ^ C0: " << (Xor(C0, C0))(TICK) << std::endl;
    std::cout << "C0 ^ C1: " << (Xor(C0, C1))(TICK) << std::endl;
    std::cout << "C1 ^ C1: " << (Xor(C1, C1))(TICK) << std::endl;
    std::cout << "C0 ^ C1: " << (Xor(C1, C0))(TICK) << std::endl;
    std::cout << std::endl;

    std::cout << "C0: " << (C0)(TICK) << std::endl;
    std::cout << "C1: " << (C1)(TICK) << std::endl;
    std::cout << std::endl;

    auto cmplx = And(C1, Xor(Not(C0), C1));
    std::cout << "Complex: " << cmplx(TICK) << std::endl;
    std::cout << std::endl;

    return 0;
}