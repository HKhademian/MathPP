CC=clang # gcc

clear

$CC Types.test.cpp -lstdc++ -o Types.out
echo "4 3 2 1 0 -1 -2 -3 -4" | ./Types.out | tee ./Types.test.out && rm ./Types.out

$CC Trilean.test.cpp -lstdc++ -o Trilean.out 
echo "4 3 2 1 0 -1 -2 -3 -4" | ./Trilean.out | tee ./Trilean.test.out && rm ./Trilean.out

$CC Vector.test.cpp -lstdc++ -o Vector.out
echo "4 3 2 1 0 -1 -2 -3 -4" | ./Vector.out | tee ./Vector.test.out && rm ./Vector.out

$CC Matrix.test.cpp -lstdc++ -o Matrix.out
echo "4 3 2 1 0 -1 -2 -3 -4" | ./Matrix.out | tee ./Matrix.test.out && rm ./Matrix.out

$CC MatrixTrilean.test.cpp -lstdc++ -o MatrixTrilean.out
echo "4 3 2 1 0 -1 -2 -3 -4" | ./MatrixTrilean.out | tee ./MatrixTrilean.test.out && rm ./MatrixTrilean.out

$CC Circuit.test.cpp -lstdc++ -o Circuit.out
echo "4 3 2 1 0 -1 -2 -3 -4" | ./Circuit.out | tee ./Circuit.test.out && rm ./Circuit.out
