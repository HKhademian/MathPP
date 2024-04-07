/// clear && gcc -o Optional.out Optional.test.cpp -lstdc++ && echo "9 8 7 6 5 4 3 2 1" | ./Optional.out | tee ./Optional.test.out && rm ./Optional.out

#include <iostream>
#include "Optional.hpp"
// #include "Optional.iostream.hpp"

using namespace TypePP;

int main()
{

    /*test1*/ {
        Optional<int> x1;
        Optional<int> x2(10);
        Optional<int> x3(x2);
        Optional<int> x4;
        Optional<int> x5(std::move(x4));
        Optional<int> x6 = x5;
        Optional<int> x7 = std::move(x6);
        auto x8 = Optional(x2);
        auto x9 = std::move(x3);
        auto &x10 = x2;

        std::cout << "x1: " << x1.has() << " " << x1 << std::endl;
        std::cout << "x2: " << x2.has() << " " << x2 << std::endl;
        std::cout << "x3: " << x3.has() << " " << x3 << std::endl;
        std::cout << "x4: " << x4.has() << " " << x4 << std::endl;
        std::cout << "x5: " << x5.has() << " " << x5 << std::endl;
        std::cout << "x6: " << x6.has() << " " << x6 << std::endl;
        std::cout << "x7: " << x7.has() << " " << x7 << std::endl;
        std::cout << "x8: " << x8.has() << " " << x8 << std::endl;
        std::cout << "x9: " << x9.has() << " " << x9 << std::endl;
        std::cout << "x10: " << x10.has() << std::endl;
        if (x1.has())
            std::cout << "if x1: reached " << *x1 << std::endl;
        if (x2.has())
            std::cout << "if x2: reached " << (int)x2 << std::endl;
        if (x3.has())
            std::cout << "if x3: reached " << (int)x3 << std::endl;
        std::cout << std::endl;

        x2 = nullptr;
        int const &x4ref = *x4;
        x4 = 8;

        std::cout << "x1: " << x1.has() << " " << x1 << std::endl;
        std::cout << "x2: " << x2.has() << " " << x2 << std::endl;
        std::cout << "x3: " << x3.has() << " " << x3 << std::endl;
        std::cout << "x4: " << x4.has() << " " << x4 << " " << x4ref << std::endl;
        std::cout << "x5: " << x5.has() << std::endl;
        std::cout << "x6: " << x6.has() << std::endl;
        std::cout << "x7: " << x7.has() << std::endl;
        std::cout << "x8: " << x8.has() << std::endl;
        std::cout << "x9: " << x9.has() << std::endl;
        std::cout << "x10: " << x10.has() << std::endl;
        if (x1.has())
            std::cout << "if x1: reached " << *x1 << std::endl;
        if (x2.has())
            std::cout << "if x2: reached " << (int)x2 << std::endl;
        if (x3.has())
            std::cout << "if x3: reached " << (int)x3 << std::endl;
        std::cout << std::endl;
    }

    return 0;
}