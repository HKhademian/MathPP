#include "Mat.hpp"
#include <iostream>

using namespace MathPP;

int main()
{
    std::cout << sizeof(Vektor<0, int>) << std::endl;
    std::cout << sizeof(int) << ":" << sizeof(Vektor<2, int>) << std::endl;
    std::cout << sizeof(double) << ":" << sizeof(Vektor<2, double>) << std::endl;
    std::cout << sizeof(float) << ":" << sizeof(Vektor<3, float>) << std::endl;
    std::cout << "vek:: " << Vektor<10, int>::one() << Vektor2I::zero() << std::endl;
    std::cout << Vektor<10, float>::SIZE::value << std::endl;

    Vektor<4, int> vec;
    std::cin >> vec;
    std::cout << vec << std::endl;
    std::cout << vec.pos() << std::endl;
    std::cout << vec.size() << std::endl;
    Vektor<4, int> &vec2 = vec;
    auto &pos = vec2.pos();
    auto &width = vec2.size().width();
    pos.v1() *= 2;
    pos.v2() *= 3;
    width += 5;
    std::cout << vec.pos() << std::endl;
    std::cout << vec.size() << std::endl;
    std::cout << vec2.pos() << std::endl;
    std::cout << vec2.size() << std::endl;
    return 0;
}