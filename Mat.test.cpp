#include "Mat.hpp"
#include <iostream>

using namespace MathPP;

int main()
{
    std::cout << sizeof(Vektor<int, 0>) << std::endl;
    std::cout << sizeof(int) << ":" << sizeof(Vektor<int, 2>) << std::endl;
    std::cout << sizeof(double) << ":" << sizeof(Vektor<double, 2>) << std::endl;
    std::cout << sizeof(float) << ":" << sizeof(Vektor<float, 3>) << std::endl;
    std::cout << "vek:: " << Vektor<int, 10>::one() << Vektor2I::zero() << std::endl;
    std::cout << Vektor<float, 10>::SIZE::value << std::endl;

    Vektor<int, 4> vec;
    std::cin >> vec;
    std::cout << vec << std::endl;
    std::cout << vec.pos() << std::endl;
    // std::cout << vec.size() << std::endl;
    Vektor<int, 4> &vecB = vec;
    auto &pos = vecB.pos();
    auto &width = vecB.size().width();
    pos.v1() *= 2;
    pos.v2() *= 3;
    width += 5;
    std::cout << vec.pos() << std::endl;
    std::cout << vec.size() << std::endl;
    std::cout << vecB.pos() << std::endl;
    std::cout << vecB.size() << std::endl;
    std::cout << "vecB: " << vecB << std::endl;
    std::cout << "subvec: " << vecB.subvec<3, 1>() << std::endl;
    std::cout << "mul: " << vecB * 2 << "    " << sizeof(vecB * 2) << std::endl;
    std::cout << "mul: " << vecB * 2 << "    " << sizeof(vecB * 2L) << std::endl;
    std::cout << "mul: " << vecB * 2.1f << "    " << sizeof(vecB * 2.1f) << std::endl;
    std::cout << "mul: " << vecB * 2.1 << "    " << sizeof(vecB * 2.1) << std::endl;
    std::cout << "div: " << vecB / 3 << std::endl;
    std::cout << "div: " << vecB / 3.1f << std::endl;
    std::cout << "div: " << vecB / 3.1 << std::endl;
    std::cout << "vecB: " << vecB << std::endl;
    std::cout << "minus: " << vecB - Vektor<int, 4>{1, 2, 3, 4} << std::endl;
    return 0;
}