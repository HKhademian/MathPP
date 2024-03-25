/// clear && gcc -o MatrixTrilean.out MatrixTrilean.test.cpp -lstdc++ && echo "9 8 7 6 5 4 3 2 1" | ./MatrixTrilean.out | tee ./MatrixTrilean.test.out && rm ./MatrixTrilean.out

#include <iostream>
#include "Trilean.hpp"
#include "Trilean.iostream.hpp"
#include "Matrix.hpp"
#include "Matrix.iostream.hpp"

using namespace MathPP;

template <size_t C, size_t R>
using TriMatrix = Matrix<C, R, Trilean>;

template <size_t _COLS, size_t _ROWS, typename _DATA_TYPE, size_t _COL_SKIP, size_t _ROW_SKIP>
void printMat(Matrix<_COLS, _ROWS, _DATA_TYPE, _COL_SKIP, _ROW_SKIP> const &mat)
{
    MATHPP_MAT_LOOP_ROW(mat, r)
    {
        MATHPP_MAT_LOOP_COL(mat, c)
        {
            std::cout << mat.at(r, c) << '\t';
        }
        std::cout << std::endl;
    }
}

int main()
{
    TriMatrix<2, 3> mat1{NEG, POS, POS, ZER, POS, NEG};
    TriMatrix<3, 2> mat2{ZER, POS, ZER, NEG, NEG, POS};

    /*test1*/ {
        std::cout << "mat1 2x3: " << mat1 << std::endl;
        std::cout << "mat2 3x2: " << mat2 << std::endl;
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
        TriMatrix<2, 3> matA{NEG, ZER, POS, POS, NEG, ZER};
        TriMatrix<3, 2> matB{ZER, POS, NEG, NEG, ZER, POS};
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
        TriMatrix<2, 3> matA;
        TriMatrix<5, 3> matB;
        //// uncomment to get COMPILE TIME ERROR !
        // auto matAB = matA * matB;
        // auto matBA = matB * matA;
        std::cout << std::endl;
    }

    /*test13*/ {
        std::cout << "TriMatrix<2, 3>.zeros() = " << TriMatrix<2, 3>::zeros() << std::endl;
        std::cout << "TriMatrix<2, 3>.ones() = " << TriMatrix<2, 3>::ones() << std::endl;
        // std::cout << "TriMatrix<2, 3>.identity() = " << TriMatrix<2, 3>::identity() << std::endl;
        std::cout << "TriMatrix<3, 3>.identity() = " << TriMatrix<3, 3>::identity() << std::endl;
        std::cout << "TriMatrix<2, 2>.identity(NEG) = " << TriMatrix<2, 2>::identity(NEG) << std::endl;
        std::cout << "TriMatrix<5, 5>.identity(NEG).trans()*NEG = " << TriMatrix<5, 5>::identity(NEG).trans() * NEG << std::endl;
        std::cout << std::endl;
    }

    /*test14*/ {
        typedef typename MathOp<Trilean, Trilean>::multiply MULT_DATA_TYPE;
        typedef typename MathOp<Trilean, Trilean>::plus PLUS_DATA_TYPE;
        typedef typename MathOp<MULT_DATA_TYPE, MULT_DATA_TYPE>::plus PLUSMULT_DATA_TYPE;
        MULT_DATA_TYPE v1 = POS * NEG;
        PLUS_DATA_TYPE v2 = POS + NEG;
        PLUSMULT_DATA_TYPE v3 = (POS * NEG) + (NEG * POS);
        std::cout << "MULT_DATA_TYPE : " << v1 << std::endl;
        std::cout << "PLUS_DATA_TYPE : " << v2 << std::endl;
        std::cout << "PLUSMULT_DATA_TYPE : " << v3 << std::endl;
        std::cout << std::endl;
    }

    return 0;
}