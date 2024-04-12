/// clear && gcc -o ./Math/Vector.out ./Math/Vector.test.cpp -lstdc++ && echo "9 8 7 6 5 4 3 2 1" | ./Math/Vector.out | tee ./Math/Vector.test.out && rm ./Math/Vector.out

#include <iostream>
#include "Vector.hpp"
#include "Vector.iostream.hpp"

using namespace MathPP;

int main()
{
    std::cout << sizeof(int) << ":" << sizeof(Vektor<0, int>) << std::endl;
    std::cout << sizeof(int) << ":" << sizeof(Vektor<1, int>) << std::endl;
    std::cout << sizeof(int) << ":" << sizeof(Vektor<10, int>) << std::endl;
    std::cout << sizeof(double) << ":" << sizeof(Vektor<20, double>) << std::endl;
    std::cout << sizeof(float) << ":" << sizeof(Vektor<30, float>) << std::endl;
    std::cout << std::endl;

    std::cout << "vek 10I ones  :: " << Vektor<10, int>::ones() << std::endl;
    std::cout << "vek  2I zeros :: " << Vektor2I<>::zeros() << std::endl;
    std::cout << "vek 10F size  :: " << Vektor<10, float>::SIZE << std::endl;
    std::cout << std::endl;

    auto vecA = Vektor<2, int>::from(new int[100]);
    (void)vecA;
    std::cin >> vecA;
    std::cout << "vecA 2I from input : " << vecA << std::endl;
    std::cout << std::endl;

    Vektor<4, int> vec;
    (void)vec;
    std::cin >> vec;
    std::cout << "vec 4I from input : " << vec << std::endl;
    std::cout << std::endl;

    Vektor<4, int> &vecB = vec;
    (void)vecB;
    std::cout << "mul: " << vecB * 2 << "    " << sizeof(vecB * 2) << std::endl;
    std::cout << "mul: " << vecB * 2 << "    " << sizeof(vecB * 2L) << std::endl;
    std::cout << "mul: " << vecB * 2.1f << "    " << sizeof(vecB * 2.1f) << std::endl;
    std::cout << "mul: " << vecB * 2.1 << "    " << sizeof(vecB * 2.1) << std::endl;
    std::cout << std::endl;

    std::cout << "div: " << vecB / 2 << std::endl;
    std::cout << "div: " << vecB / 3.1f << std::endl;
    std::cout << "div: " << vecB / 3.1 << std::endl;
    std::cout << std::endl;

    std::cout << "vecB: " << vecB << std::endl;
    std::cout << "minus: " << vecB - Vektor<4, int>{1, 2, 3, 4} << std::endl
              << std::endl;

    std::cout << "vecB: " << vecB << std::endl
              << "plus: " << vecB - Vektor<4, double>{1.1, 2.5, 3.9, 4} << std::endl
              << std::endl;

    std::cout << "vecB: " << vecB << std::endl
              << "plus: " << vecB + Vektor<10, short>{3, 5, 7, 9, 1, 2, 3, 4, 5, 6} << std::endl
              << std::endl;

    Vektor<30, int> vec30{
        29, 28, 27, 26, 25, 24, 23, 22, 21, 20,
        19, 18, 17, 16, 15, 14, 13, 12, 11, 10,
        9, 8, 7, 6, 5, 4, 3, 2, 1, 0,
        //
    };
    (void)vec30;

    std::cout << std::endl;
    {
        auto vec10 = vec30.subvec<10, 5>();
        std::cout << "vec30       : " << vec30 << std::endl;
        std::cout << "vec10       : " << vec10 << std::endl;
        std::cout << "subvec 10   : " << vec10.subvec<10>() << std::endl;
        std::cout << "subvec 1    : " << vec10.subvec<1>() << std::endl;
        std::cout << "subvec 2    : " << vec10.subvec<2>() << std::endl;
        std::cout << "subvec 2 1  : " << vec10.subvec<2, 1>() << std::endl;
        std::cout << "subvec 9 1  : " << vec10.subvec<9, 1>() << std::endl;
        std::cout << "subvec 3 0  : " << vec10.subvec<3, 0>() << std::endl;
        std::cout << "subvec 3 1  : " << vec10.subvec<3, 1>() << std::endl;
        std::cout << "subvec 3 2  : " << vec10.subvec<3, 2>() << std::endl;
        std::cout << "subvec 4 1  : " << vec10.subvec<4, 1>() << std::endl;
        std::cout << "subvec 0    : " << vec10.subvec<0>() << std::endl;
        std::cout << std::endl;
    }

    {
        auto vec15 = vec30.subvec<15, 0, 1>();
        (void)vec15;
        std::cout << "vec30         : " << vec30 << std::endl;
        std::cout << "vec15         : " << vec15 << std::endl;

        std::cout << "subvec 4 0 1  : " << vec15.subvec<4, 0, 1>() << std::endl;

        std::cout << "vec15         : " << vec15 << std::endl;
        std::cout << "subvec 4 0 2  : " << vec15.subvec<4, 0, 2>() << std::endl;

        std::cout << "vec15         : " << vec15 << std::endl;
        std::cout << "subvec 4 0 3  : " << vec15.subvec<4, 0, 3>() << std::endl;

        std::cout << "vec15         : " << vec15 << std::endl;
        std::cout << "subvec 4 1 1  : " << vec15.subvec<4, 1, 1>() << std::endl;

        std::cout << "vec15         : " << vec15 << std::endl;
        std::cout << "subvec 4 1 2  : " << vec15.subvec<4, 1, 2>() << std::endl;

        std::cout << "vec15         : " << vec15 << std::endl;
        std::cout << "subvec 4 1 3  : " << vec15.subvec<4, 1, 3>() << std::endl;

        std::cout << "vec15         : " << vec15 << std::endl;
        std::cout << "subvec 4 1 1  : " << vec15.subvec<4, 1, 1>() << std::endl;

        std::cout << "vec15         : " << vec15 << std::endl;
        std::cout << "subvec 4 2 1  : " << vec15.subvec<4, 2, 1>() << std::endl;

        std::cout << "vec15         : " << vec15 << std::endl;
        std::cout << "subvec 4 3 1  : " << vec15.subvec<4, 3, 1>() << std::endl;

        std::cout << "vec15         : " << vec15 << std::endl;
        std::cout << "subvec 4 3 2  : " << vec15.subvec<4, 3, 2>() << std::endl;

        std::cout << "vec15         : " << vec15 << std::endl;
        std::cout << "subvec 3 3 3  : " << vec15.subvec<3, 3, 3>() << std::endl;
        std::cout << std::endl;
    }

    {
        Vektor<10, int> vec10{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
        (void)vec10;
        std::cout << "vec10 offset 1: " << vec10 << std::endl;
        std::cout << "subvec 3 0    : " << vec10.subvec<3, 0>() << std::endl;
        std::cout << "subvec 3 1    : " << vec10.subvec<3, 1>() << std::endl;
        std::cout << "subvec 3 2    : " << vec10.subvec<3, 2>() << std::endl;
        std::cout << "subvec 4 1    : " << vec10.subvec<4, 1>() << std::endl;
        std::cout << std::endl;
    }

    const auto &vecConst = vec;
    (void)vecConst;
    std::cout << "vecConst 4I from input : " << vecConst << std::endl;
    // std::cout << "vecConst 4I pos() : " << vecConst.pos() << std::endl;
    // std::cout << "vecConst 4I size() : " << vecConst.size() << std::endl;
    std::cout << std::endl;

    // auto &pos = vecB.pos();
    // auto &width = vecB.size().width();
    // pos.v1() *= 2;
    // pos.v2() *= 3;
    // width += 5;
    // std::cout << vec.pos() << std::endl;
    // std::cout << vec.size() << std::endl;
    // std::cout << vecB.pos() << std::endl;
    // std::cout << vecB.size() << std::endl;
    // std::cout << "vecB: " << vecB << std::endl;
    // std::cout << "subvec: " << vecB.subvec<3, 1>() << std::endl;
    // std::cout << std::endl;

    return 0;
}