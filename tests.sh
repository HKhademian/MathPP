clear
gcc -o Trilean.out Trilean.test.cpp -lstdc++
echo "9 8 7 6 5 4 3 2 1" | ./Trilean.out | tee ./Trilean.test.out && rm ./Trilean.out

gcc -o Vector.out Vector.test.cpp -lstdc++
echo "9 8 7 6 5 4 3 2 1" | ./Vector.out | tee ./Vector.test.out && rm ./Vector.out

gcc -o Matrix.out Matrix.test.cpp -lstdc++
echo "9 8 7 6 5 4 3 2 1" | ./Matrix.out | tee ./Matrix.test.out && rm ./Matrix.out

gcc -o MatrixTrilean.out MatrixTrilean.test.cpp -lstdc++
echo "9 8 7 6 5 4 3 2 1" | ./MatrixTrilean.out | tee ./MatrixTrilean.test.out && rm ./MatrixTrilean.out
