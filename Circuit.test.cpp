/// clear && gcc -o Circuit.out Circuit.test.cpp -lstdc++ && echo "9 8 7 6 5 4 3 2 1" | ./Circuit.out | tee ./Circuit.test.out && rm ./Circuit.out

#include <iostream>
#include "Circuit.hpp"

using namespace CircuitPP;

int main(void)
{
    // bool test{1};
    auto C0 = Constant(DigitalV::V0);
    auto C1 = Constant(DigitalV::V1);

    std::cout << C0.getValue(1) << std::endl;
    std::cout << C0.getValue(2) << std::endl;
    std::cout << C0.getValue(3) << std::endl;
    std::cout << C0.getValue(4) << std::endl;
    std::cout << C0.getValue(5) << std::endl;

    std::cout << C1.getValue(1) << std::endl;
    std::cout << C1.getValue(5) << std::endl;

    auto not0 = Not(C0);
    std::cout << not0.getValue(5) << std::endl;

    auto and1 = And(C1, not0);
    std::cout << and1.getValue(5) << std::endl;
    std::cout << std::endl;

    std::cout << "C0: " << (C0).getValue(5) << std::endl;
    std::cout << "C1: " << (C1).getValue(5) << std::endl;
    std::cout << std::endl;
   
    std::cout << "! C0: " << (Not(C0)).getValue(5) << std::endl;
    std::cout << "! C1: " << (Not(C1)).getValue(5) << std::endl;
    std::cout << std::endl;
   
    std::cout << "C0 & C0: " << (And(C0, C0)).getValue(5) << std::endl;
    std::cout << "C0 & C1: " << (And(C0, C1)).getValue(5) << std::endl;
    std::cout << "C1 & C1: " << (And(C1, C1)).getValue(5) << std::endl;
    std::cout << "C0 & C1: " << (And(C1, C0)).getValue(5) << std::endl;
    std::cout << std::endl;

    std::cout << "C0 | C0: " << (Or(C0, C0)).getValue(5) << std::endl;
    std::cout << "C0 | C1: " << (Or(C0, C1)).getValue(5) << std::endl;
    std::cout << "C1 | C1: " << (Or(C1, C1)).getValue(5) << std::endl;
    std::cout << "C0 | C1: " << (Or(C1, C0)).getValue(5) << std::endl;
    std::cout << std::endl;

    std::cout << "C0 ^ C0: " << (Xor(C0, C0)).getValue(5) << std::endl;
    std::cout << "C0 ^ C1: " << (Xor(C0, C1)).getValue(5) << std::endl;
    std::cout << "C1 ^ C1: " << (Xor(C1, C1)).getValue(5) << std::endl;
    std::cout << "C0 ^ C1: " << (Xor(C1, C0)).getValue(5) << std::endl;
    std::cout << std::endl;

    return 0;
}