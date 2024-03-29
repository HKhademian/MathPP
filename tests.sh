CC=clang # gcc

clear

$CC -o Types.out Types.test.cpp -lstdc++
echo "4 3 2 1 0 -1 -2 -3 -4" | ./Types.out | tee ./Types.test.out && rm ./Types.out

$CC -o Trilean.out Trilean.test.cpp -lstdc++
echo "4 3 2 1 0 -1 -2 -3 -4" | ./Trilean.out | tee ./Trilean.test.out && rm ./Trilean.out

$CC -o Vector.out Vector.test.cpp -lstdc++
echo "4 3 2 1 0 -1 -2 -3 -4" | ./Vector.out | tee ./Vector.test.out && rm ./Vector.out

$CC -o Matrix.out Matrix.test.cpp -lstdc++
echo "4 3 2 1 0 -1 -2 -3 -4" | ./Matrix.out | tee ./Matrix.test.out && rm ./Matrix.out

$CC -o MatrixTrilean.out MatrixTrilean.test.cpp -lstdc++
echo "4 3 2 1 0 -1 -2 -3 -4" | ./MatrixTrilean.out | tee ./MatrixTrilean.test.out && rm ./MatrixTrilean.out
