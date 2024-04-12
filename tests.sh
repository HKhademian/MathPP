CC=gcc
# CC=clang

clear

$CC ./Types/TestClass.test.cpp -lstdc++ -o ./Types/TestClass.test.o 
echo "4 3 2 1 0 -1 -2 -3 -4" | ./Types/TestClass.test.o | tee ./Types/TestClass.test.out && rm ./Types/TestClass.test.o

$CC ./Types/Types.test.cpp -lstdc++ -o ./Types/Types.test.o
echo "4 3 2 1 0 -1 -2 -3 -4" | ./Types/Types.test.o | tee ./Types/Types.test.out && rm ./Types/Types.test.o

$CC ./Types/Optional.test.cpp -lstdc++ -o ./Types/Optional.test.o 
echo "4 3 2 1 0 -1 -2 -3 -4" | ./Types/Optional.test.o | tee ./Types/Optional.test.out && rm ./Types/Optional.test.o

$CC ./Types/Trilean.test.cpp -lstdc++ -o ./Types/Trilean.test.o 
echo "4 3 2 1 0 -1 -2 -3 -4" | ./Types/Trilean.test.o | tee ./Types/Trilean.test.out && rm ./Types/Trilean.test.o

$CC ./Math/Vector.test.cpp -lstdc++ -o ./Math/Vector.test.o
echo "4 3 2 1 0 -1 -2 -3 -4" | ./Math/Vector.test.o | tee ./Math/Vector.test.out && rm ./Math/Vector.test.o

$CC ./Math/Matrix.test.cpp -lstdc++ -o ./Math/Matrix.test.o
echo "4 3 2 1 0 -1 -2 -3 -4" | ./Math/Matrix.test.o | tee ./Math/Matrix.test.out && rm ./Math/Matrix.test.o

$CC ./Math/MatrixTrilean.test.cpp -lstdc++ -o ./Math/MatrixTrilean.test.o
echo "4 3 2 1 0 -1 -2 -3 -4" | ./Math/MatrixTrilean.test.o | tee ./Math/MatrixTrilean.test.out && rm ./Math/MatrixTrilean.test.o

$CC ./Circuit/DigitalV.test.cpp -lstdc++ -o ./Circuit/DigitalV.test.o
echo "4 3 2 1 0 -1 -2 -3 -4" | ./Circuit/DigitalV.test.o | tee ./Circuit/DigitalV.test.out && rm ./Circuit/DigitalV.test.o

$CC ./Circuit/Logic.test.cpp -lstdc++ -o ./Circuit/Logic.test.o
echo "4 3 2 1 0 -1 -2 -3 -4" | ./Circuit/Logic.test.o | tee ./Circuit/Logic.test.out && rm ./Circuit/Logic.test.o

$CC ./Circuit/Bus.test.cpp -lstdc++ -o ./Circuit/Bus.test.o
echo "4 3 2 1 0 -1 -2 -3 -4" | ./Circuit/Bus.test.o | tee ./Circuit/Bus.test.out && rm ./Circuit/Bus.test.o

$CC ./Circuit/Circuit.test.cpp -lstdc++ -o ./Circuit/Circuit.test.o
echo "4 3 2 1 0 -1 -2 -3 -4" | ./Circuit/Circuit.test.o | tee ./Circuit/Circuit.test.out && rm ./Circuit/Circuit.test.o
