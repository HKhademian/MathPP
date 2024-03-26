/// clear && gcc -o Types.out Types.test.cpp -lstdc++ && echo "9 8 7 6 5 4 3 2 1" | ./Types.out | tee ./Types.test.out && rm ./Types.out

#include <iostream>
#include "Types.hpp"

using namespace MathPP;

// typedef unsigned int size_t;
template <size_t size, bool isStatic = true>
struct Test
{
    using ListType = typename Conditional<isStatic, int[size], int *>::type;

    ListType elements;

    void print() const
    {
        for (auto i = 0; i < size; ++i)
        {
            // do something
            int x = elements[i] * 2;
        }
    }
};

using ttt = typename Conditional<true, char[25], int>::type;

int main()
{
    Test<5> test1{9, 8, 7, 6, 5};
    std::cout << sizeof(test1) / sizeof(test1.elements[0]) << std::endl;

    Test<5, false> test2;
    std::cout << sizeof(test2) / sizeof(test2.elements[0]) << std::endl;

    ttt val = "Holla";
}