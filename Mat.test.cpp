#include "Mat.hpp"
#include <iostream>

using namespace MathPP;

int main()
{
    std::cout << sizeof(Vektor<0, int>) << std::endl;
    std::cout << sizeof(int) << ":" << sizeof(Vektor<2, int>) << std::endl;
    std::cout << sizeof(double) << ":" << sizeof(Vektor<2, double>) << std::endl;
    std::cout << sizeof(float) << ":" << sizeof(Vektor<3, float>) << std::endl;
    std::cout << "vek:: " << Vektor<10, int>::one() << Vector2I::zero() << std::endl;
    std::cout << Vektor<10, float>::SIZE::value << std::endl;

    Vektor<5, int> vec5;
    std::cin >> vec5;
    std::cout << vec5 << std::endl;
    return 0;
}