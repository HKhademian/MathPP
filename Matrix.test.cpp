#include <iostream>
#include "Matrix.hpp"
#include "Matrix.iostream.hpp"

using namespace MathPP;

template <size_t _COLS, size_t _ROWS, typename _DATA_TYPE, size_t _COL_SPACE, size_t _ROW_SPACE>
void printMat(Matrix<_COLS, _ROWS, _DATA_TYPE, _COL_SPACE, _ROW_SPACE> const &mat)
{
    for (auto r = 0; r < mat.ROW_COUNT; ++r)
    {
        for (auto c = 0; c < mat.COL_COUNT; ++c)
        {
            std::cout << mat.at(r, c) << '\t';
        }
        std::cout << std::endl;
    }
}

int main()
{
    Matrix<3, 4, int> mat1{101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112};
    Matrix<4, 3, float> mat2{201.1, 202.1, 203.1, 204.1, 205.1, 206.1, 207.1, 208.1, 209.1, 210.1, 211.1, 212.1};

    /*test1*/ {
        std::cout << "float size: " << sizeof(float) << std::endl;
        std::cout << "mat1 float 3x4 size: " << sizeof(mat1) << std::endl;
        printMat(mat1);
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
        std::cout << "mat1+mat2 : " << mat << std::endl;
        printMat(mat);
        std::cout << std::endl;
    }

    /*test4*/ {
        auto mat = mat2 - mat1;
        std::cout << "mat2-mat1 : cols= " << mat.COL_COUNT << std::endl;
        std::cout << "mat2-mat1 : rows= " << mat.ROW_COUNT << std::endl;
        printMat(mat);
        std::cout << "mat2-mat1 : " << mat << std::endl;
        std::cout << std::endl;
    }

    /*test5*/ {
        auto mat = 3 * mat1;
        std::cout << "3 * mat1 : cols= " << mat.COL_COUNT << std::endl;
        std::cout << "3 * mat1 : rows= " << mat.ROW_COUNT << std::endl;
        std::cout << "3 * mat1 : " << mat << std::endl;
        printMat(mat);
        std::cout << std::endl;
    }

    /*test6*/ {
        auto mat = mat1 * 2.5;
        std::cout << "mat1 * 2.5 : cols= " << mat.COL_COUNT << std::endl;
        std::cout << "mat1 * 2.5 : rows= " << mat.ROW_COUNT << std::endl;
        std::cout << "mat1 * 2.5 : " << mat << std::endl;
        printMat(mat);
        std::cout << std::endl;
    }

    /*test7*/ {
        auto mat = mat1 / 7;
        std::cout << "mat1 / 7 : cols= " << mat.COL_COUNT << std::endl;
        std::cout << "mat1 / 7 : rows= " << mat.ROW_COUNT << std::endl;
        std::cout << "mat1 / 7 : " << mat << std::endl;
        printMat(mat);
        std::cout << std::endl;
    }

    /*test8*/ {
        auto mat = mat1 / 1.1;
        std::cout << "mat1 / 1.1 : cols= " << mat.COL_COUNT << std::endl;
        std::cout << "mat1 / 1.1 : rows= " << mat.ROW_COUNT << std::endl;
        std::cout << "mat1 / 1.1 : " << mat << std::endl;
        printMat(mat);
        std::cout << std::endl;
    }

    auto mat1trans = mat1.trans();
    /*test9*/ {
        auto &mat = mat1trans;
        std::cout << "mat1 trans : cols= " << mat.COL_COUNT << std::endl;
        std::cout << "mat1 trans : rows= " << mat.ROW_COUNT << std::endl;
        std::cout << "mat1 trans : " << mat << std::endl;
        printMat(mat);
        std::cout << "mat1       : " << mat1 << std::endl;
        printMat(mat1);
        std::cout << std::endl;
    }

    /*test10*/ {
        auto mat = mat1 * mat1trans;
        std::cout << "mat1 * trans : cols= " << mat.COL_COUNT << std::endl;
        std::cout << "mat1 * trans : rows= " << mat.ROW_COUNT << std::endl;
        std::cout << "mat1 * trans : " << mat << std::endl;
        printMat(mat);
        std::cout << std::endl;
    }

    /*test11*/ {
        Matrix<2, 3> matA{10, 20, 30, 40, 50, 60};
        Matrix<3, 2> matB{1, 2, 3, 4, 5, 6};
        auto matAB = matA * matB;
        auto matBA = matB * matA;
        std::cout << "matA : " << matA << std::endl;
        printMat(matA);
        std::cout << "matB : " << matB << std::endl;
        printMat(matB);
        std::cout << "matAB : cols= " << matAB.COL_COUNT << std::endl;
        std::cout << "matAB : rows= " << matAB.ROW_COUNT << std::endl;
        std::cout << "matAB : " << matAB << std::endl;
        printMat(matAB);
        std::cout << "matBA : cols= " << matBA.COL_COUNT << std::endl;
        std::cout << "matBA : rows= " << matBA.ROW_COUNT << std::endl;
        std::cout << "matBA : " << matBA << std::endl;
        printMat(matBA);
        std::cout << std::endl;
    }

    /*test12*/ {
        Matrix<2, 3> matA;
        Matrix<5, 3> matB;
        //// uncomment to get COMPILE TIME ERROR !
        // auto matAB = matA * matB;
        // auto matBA = matB * matA;
        std::cout << std::endl;
    }

    return 0;
}