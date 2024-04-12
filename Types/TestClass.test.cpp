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

    auto operator==(Student const &other) const
    {
        std::cout << "Student:: operator==" << std::endl;
        return id == other.id;
    }
};
typedef TestClass<Student> TestStudent;

int main()
{

    /*test1*/ {
        Student student1, student2;

        std::cout << "--- test 11 ---" << std::endl;
        TestStudent x11;
        (void)x11;
        std::cout << std::endl;

        std::cout << "--- test 12 ---" << std::endl;
        TestStudent x12(student1);
        (void)x12;
        std::cout << std::endl;

        std::cout << "--- test 13 ---" << std::endl;
        TestStudent x13(std::move(student1));
        (void)x13;
        std::cout << std::endl;

        std::cout << "--- test 14 ---" << std::endl;
        const TestStudent x14 = student2;
        (void)x14;
        std::cout << std::endl;

        std::cout << "--- test 15 ---" << std::endl;
        TestStudent x15 = std::move(student2);
        (void)x15;
        std::cout << std::endl;

        std::cout << "--- test 16 ---" << std::endl;
        TestStudent x16(x15);
        (void)x16;
        std::cout << std::endl;

        std::cout << "--- test 17 ---" << std::endl;
        TestStudent x17 = x16;
        (void)x17;
        std::cout << std::endl;

        std::cout << "--- test 18 ---" << std::endl;
        auto x18 = x17;
        (void)x18;
        std::cout << std::endl;

        std::cout << "--- test 19 ---" << std::endl;
        auto x19 = std::move(x18);
        (void)x19;
        std::cout << std::endl;

        std::cout << "--- test 20 ---" << std::endl;
        auto const &x20 = x19;
        (void)x20;
        std::cout << std::endl;

        std::cout << "--- test 21 ---" << std::endl;
        auto &x21 = x19;
        (void)x21;
        std::cout << std::endl;

        std::cout << "--- test 22 ---" << std::endl;
        auto &&x22 = x19;
        (void)x22;
        std::cout << std::endl;

        std::cout << "--- test 23 ---" << std::endl;
        auto const &&x23 = std::move(x11);
        (void)x23;
        std::cout << std::endl;

        std::cout << "--- test 24 ---" << std::endl;
        auto x24 = x20;
        (void)x24;
        std::cout << std::endl;

        std::cout << "--- test 25 ---" << std::endl;
        auto x25 = x23;
        (void)x25;
        std::cout << std::endl;

        std::cout << "--- test 26 ---" << std::endl;
        auto std26 = (Student)x25;
        (void)std26;
        std::cout << std::endl;

        std::cout << "--- test 27 ---" << std::endl;
        auto std27 = (Student const)x25;
        (void)std27;
        std::cout << std::endl;

        std::cout << "--- test 28 ---" << std::endl;
        auto std28 = (Student &&)x25;
        (void)std28;
        std::cout << std::endl;

        std::cout << "--- test 29 ---" << std::endl;
        auto std29 = (Student const &&)x25;
        (void)std29;
        std::cout << std::endl;

        std::cout << "--- test 30 ---" << std::endl;
        auto std30 = (Student &)x25;
        (void)std30;
        std::cout << std::endl;

        std::cout << "--- test 31 ---" << std::endl;
        auto std31 = (Student const &)(const TestStudent &)x25;
        (void)std31;
        std::cout << std::endl;

        std::cout << "--- test 32 ---" << std::endl;
        Student std32 = x25;
        (void)std32;
        std::cout << std::endl;

        std::cout << "--- test 33 ---" << std::endl;
        Student &std33 = x25;
        (void)std33;
        std::cout << std::endl;

        std::cout << "--- test 34 ---" << std::endl;
        Student const &std34 = x25;
        (void)std34;
        std::cout << std::endl;

        // std::cout << "--- test 35 ---" << std::endl;
        // Student &&std35 = std::move(x25);
        // (void)std35;
        // std::cout << std::endl;

        // std::cout << "--- test 36 ---" << std::endl;
        // Student const &&std36 = std::move(x25);
        // (void)std36;
        // std::cout << std::endl;

        std::cout << "--- test 37 ---" << std::endl;
        Student std37 = std::move(x25);
        (void)std37;
        std::cout << std::endl;

        std::cout << "--- test 38 ---" << std::endl;
        auto res38 = (student1 == student2);
        (void)res38;
        std::cout << std::endl;

        std::cout << "--- test 39 ---" << std::endl;
        auto res39 = (x11 == student1);
        (void)res39;
        std::cout << std::endl;

        std::cout << "--- test 40 ---" << std::endl;
        auto res40 = (student1 == x11);
        (void)res40;
        std::cout << std::endl;

        std::cout << "--- test 41 ---" << std::endl;
        auto res41 = (x11 == x12);
        (void)res41;
        std::cout << std::endl;
    }

    return 0;
}