CC=gcc
# CC=clang

function testSubject
{
    name="$1"
    input=${2:-"4 3 2 1 0 -1 -2 -3 -4"}
    output="$1.test.out"
    exec="$1.test.o"
    #compile
    $CC -O3 -Wall $1.test.cpp -lstdc++ -o "$exec"
    #exec
    rm "$output"
    # echo "$input" | "$exec" | tee "$output"
    echo "$input" | "$exec" > "$output"
    #cleanup
    rm "$exec"
}

# clear
testSubject "./Types/TestClass"
testSubject "./Types/Optional"
testSubject "./Types/Trilean"
testSubject "./Math/Vector"
testSubject "./Math/Matrix"
testSubject "./Math/MatrixTrilean"
testSubject "./Circuit/DigitalV"
testSubject "./Circuit/Logic"
testSubject "./Circuit/Bus"
testSubject "./Circuit/Circuit"
