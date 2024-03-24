#include <iostream>
#include "Matrix.hpp"
#include "Matrix.iostream.hpp"

using namespace MathPP;

int main()
{
    /*test1*/ {
        Matrix<3, 4, float> mat{101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112};
        std::cout << "float size:" << sizeof(float) << std::endl;
        std::cout << "mat float 3x4 size:" << sizeof(mat) << std::endl;
        std::cout << "mat float 3x4:" << mat << std::endl;
        for (auto r = 0; r < mat.ROW_COUNT; ++r)
        {
            for (auto c = 0; c < mat.COL_COUNT; ++c)
            {
                std::cout << mat.at(r, c) << '\t';
            }
            std::cout << std::endl;
        }
    }

    return 0;
}