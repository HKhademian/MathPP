/// clear && gcc -o TestClass.out TestClass.test.cpp -lstdc++ && echo "9 8 7 6 5 4 3 2 1" | ./TestClass.out | tee ./TestClass.test.out && rm ./TestClass.out

#include <iostream>
#include "TestClass.hpp"
// #include "TestClass.iostream.hpp"

using namespace TypePP;

struct Student
{
    int id;
    struct
    {
        int year;
        int month;
        int day;
    } birth;
    int age;
    int height;
    int weight;
    int grade;
    int score;
    int rank;
};

int main()
{

    /*test1*/ {
        Student student1, student2;

        std::cout << "--- test 11 ---" << std::endl;
        TestClass<Student> x11;
        std::cout << std::endl;

        std::cout << "--- test 12 ---" << std::endl;
        TestClass<Student> x12(student1);
        std::cout << std::endl;

        std::cout << "--- test 13 ---" << std::endl;
        TestClass<Student> x13(std::move(student1));
        std::cout << std::endl;

        std::cout << "--- test 14 ---" << std::endl;
        const TestClass<Student> x14 = student2;
        std::cout << std::endl;

        std::cout << "--- test 15 ---" << std::endl;
        TestClass<Student> x15 = std::move(student2);
        std::cout << std::endl;

        std::cout << "--- test 16 ---" << std::endl;
        TestClass<Student> x16(x15);
        std::cout << std::endl;

        std::cout << "--- test 17 ---" << std::endl;
        TestClass<Student> x17 = x16;
        std::cout << std::endl;

        std::cout << "--- test 18 ---" << std::endl;
        auto x18 = x17;
        std::cout << std::endl;

        std::cout << "--- test 19 ---" << std::endl;
        auto x19 = std::move(x18);
        std::cout << std::endl;

        std::cout << "--- test 20 ---" << std::endl;
        auto const &x20 = x19;
        std::cout << std::endl;

        std::cout << "--- test 21 ---" << std::endl;
        auto &x21 = x19;
        std::cout << std::endl;

        std::cout << "--- test 22 ---" << std::endl;
        auto &&x22 = x19;
        std::cout << std::endl;

        std::cout << "--- test 23 ---" << std::endl;
        auto const &&x23 = std::move(x11);
        std::cout << std::endl;

        std::cout << "--- test 24 ---" << std::endl;
        auto x24 = x20;
        std::cout << std::endl;

        std::cout << "--- test 25 ---" << std::endl;
        auto x25 = x23;
        std::cout << std::endl;

        std::cout << "--- test 26 ---" << std::endl;
        auto std26 = (Student)x25;
        std::cout << std::endl;

        std::cout << "--- test 27 ---" << std::endl;
        auto std27 = (Student const)x25;
        std::cout << std::endl;

        std::cout << "--- test 28 ---" << std::endl;
        auto std28 = (Student &&)x25;
        std::cout << std::endl;

        std::cout << "--- test 29 ---" << std::endl;
        auto std29 = (Student const &&)x25;
        std::cout << std::endl;

        std::cout << "--- test 30 ---" << std::endl;
        auto std30 = (Student &)x25;
        std::cout << std::endl;

        std::cout << "--- test 31 ---" << std::endl;
        auto std31 = (Student const &)(const TestClass<Student> &)x25;
        std::cout << std::endl;

        std::cout << "--- test 32 ---" << std::endl;
        Student std32 = x25;
        std::cout << std::endl;

        std::cout << "--- test 33 ---" << std::endl;
        Student &std33 = x25;
        std::cout << std::endl;

        std::cout << "--- test 34 ---" << std::endl;
        Student const &std34 = x25;
        std::cout << std::endl;

        // std::cout << "--- test 35 ---" << std::endl;
        // Student &&std35 = std::move(x25);
        // std::cout << std::endl;

        // std::cout << "--- test 36 ---" << std::endl;
        // Student const &&std36 = std::move(x25);
        // std::cout << std::endl;

        std::cout << "--- test 37 ---" << std::endl;
        Student std37 = std::move(x25);
        std::cout << std::endl;
    }

    return 0;
}