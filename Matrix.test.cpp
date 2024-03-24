#include <iostream>
#include "Matrix.hpp"
#include "Matrix.iostream.hpp"

using namespace MathPP;

int main()
{
    Matrix<3, 4, int> mat1{101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112};
    Matrix<4, 3, float> mat2{201.1, 202.1, 203.1, 204.1, 205.1, 206.1, 207.1, 208.1, 209.1, 210.1, 211.1, 212.1};

    /*test1*/ {
        std::cout << "float size: " << sizeof(float) << std::endl;
        std::cout << "mat1 float 3x4 size: " << sizeof(mat1) << std::endl;
        std::cout << std::endl;
    }

    /*test2*/ {
        std::cout << "mat1 float 3x4: " << mat1 << std::endl;
        std::cout << "mat2 float 4x3: " << mat2 << std::endl;
        std::cout << std::endl;
    }

    /*test3*/ {
        auto mat = mat1 + mat2;
        std::cout << "mat1+mat2 : cols= " << mat.COL_COUNT << std::endl;
        std::cout << "mat1+mat2 : rows= " << mat.ROW_COUNT << std::endl;
        for (auto r = 0; r < mat.ROW_COUNT; ++r)
        {
            for (auto c = 0; c < mat.COL_COUNT; ++c)
            {
                std::cout << mat.at(r, c) << '\t';
            }
            std::cout << std::endl;
        }
        std::cout << "mat1+mat2 : " << mat << std::endl;
        std::cout << std::endl;
    }

    /*test4*/ {
        auto mat = mat2 - mat1;
        std::cout << "mat2-mat1 : cols= " << mat.COL_COUNT << std::endl;
        std::cout << "mat2-mat1 : rows= " << mat.ROW_COUNT << std::endl;
        for (auto r = 0; r < mat.ROW_COUNT; ++r)
        {
            for (auto c = 0; c < mat.COL_COUNT; ++c)
            {
                std::cout << mat.at(r, c) << '\t';
            }
            std::cout << std::endl;
        }
        std::cout << "mat2-mat1 : " << mat << std::endl;
        std::cout << std::endl;
    }

    /*test5*/ {
        auto mat = 3 * mat1;
        std::cout << "3 * mat1 : cols= " << mat.COL_COUNT << std::endl;
        std::cout << "3 * mat1 : rows= " << mat.ROW_COUNT << std::endl;
        std::cout << "3 * mat1 : " << mat << std::endl;
        std::cout << std::endl;
    }

    /*test6*/ {
        auto mat = mat1 * 2.5;
        std::cout << "mat1 * 2.5 : cols= " << mat.COL_COUNT << std::endl;
        std::cout << "mat1 * 2.5 : rows= " << mat.ROW_COUNT << std::endl;
        std::cout << "mat1 * 2.5 : " << mat << std::endl;
        std::cout << std::endl;
    }

    /*test7*/ {
        auto mat = mat1 / 7;
        std::cout << "mat1 / 7 : cols= " << mat.COL_COUNT << std::endl;
        std::cout << "mat1 / 7 : rows= " << mat.ROW_COUNT << std::endl;
        std::cout << "mat1 / 7 : " << mat << std::endl;
        std::cout << std::endl;
    }

    /*test8*/ {
        auto mat = mat1 / 1.1;
        std::cout << "mat1 / 1.1 : cols= " << mat.COL_COUNT << std::endl;
        std::cout << "mat1 / 1.1 : rows= " << mat.ROW_COUNT << std::endl;
        std::cout << "mat1 / 1.1 : " << mat << std::endl;
        std::cout << std::endl;
    }

    return 0;
}