/// clear && gcc -o ./Circuit/Logic.out ./Circuit/Logic.test.cpp -lstdc++ && echo "9 8 7 6 5 4 3 2 1" | ./Circuit/Logic.out | tee ./Circuit/Logic.test.out && rm ./Circuit/Logic.out

#include <iostream>
#include "Logic.hpp"
#include "DigitalV.hpp"
#include "DigitalV.iostream.hpp"

using namespace CircuitPP;

auto eval(const std::shared_ptr<LogicGate<DigitalV>> &gate)
{
    const auto TICK = 5;
    return (*(gate.get()))(TICK);
}

int main(void)
{
    std::cout << "START" << std::endl;

    std::cout << "V0: " << DigitalV::V0 << std::endl;
    std::cout << "V1: " << DigitalV::V1 << std::endl;
    std::cout << "Const(V0): " << eval(Const(DigitalV::V0)) << std::endl;
    std::cout << "Const(V1): " << eval(Const(DigitalV::V1)) << std::endl;
    std::cout << std::endl;

    const auto C0 = Const(DigitalV::V0);
    const auto C1 = Const(DigitalV::V1);

    std::cout << "C0: " << eval(C0) << std::endl;
    std::cout << "C1: " << eval(C1) << std::endl;
    std::cout << std::endl;

    const auto w0 = Wire(C0);
    const auto w1 = Wire(C1);
    std::cout << "+ C0: " << eval(w0) << std::endl;
    std::cout << "+ C1: " << eval(w1) << std::endl;
    std::cout << std::endl;

    std::cout << "! C0: " << eval(Not(C0)) << std::endl;
    std::cout << "! C1: " << eval(Not(C1)) << std::endl;
    std::cout << std::endl;

    std::cout << "C0 & C0: " << eval(And(Const(DigitalV::V0), Const(DigitalV::V0))) << std::endl;
    std::cout << "C0 & C1: " << eval(And(Const(DigitalV::V0), Const(DigitalV::V1))) << std::endl;
    std::cout << "C1 & C1: " << eval(And(Const(DigitalV::V1), Const(DigitalV::V1))) << std::endl;
    std::cout << "C0 & C1: " << eval(And(Const(DigitalV::V1), Const(DigitalV::V0))) << std::endl;
    std::cout << std::endl;

    std::cout << "C0 | C0: " << eval(Or(C0, C0)) << std::endl;
    std::cout << "C0 | C1: " << eval(Or(C0, C1)) << std::endl;
    std::cout << "C1 | C1: " << eval(Or(C1, C1)) << std::endl;
    std::cout << "C0 | C1: " << eval(Or(C1, C0)) << std::endl;
    std::cout << std::endl;

    std::cout << "C0 ^ C0: " << eval(Xor(C0, C0)) << std::endl;
    std::cout << "C0 ^ C1: " << eval(Xor(C0, C1)) << std::endl;
    std::cout << "C1 ^ C1: " << eval(Xor(C1, C1)) << std::endl;
    std::cout << "C0 ^ C1: " << eval(Xor(C1, C0)) << std::endl;
    std::cout << std::endl;

    {
        auto temp1 = !(!(!(C0 & C1)));
        std::cout << "temp1: " << eval(temp1) << " === " << eval(!(!(!(C0 & C1)))) << std::endl;
        auto temp2 = (!C0 ^ C1);
        std::cout << "temp2: " << eval(temp2) << " === " << eval(Xor(Not(C0), C1)) << std::endl;
        auto temp3 = (C1 & (!C0 ^ C1));
        std::cout << "temp3: " << eval(temp3) << " === " << eval(And(C1, Xor(Not(C0), C1))) << std::endl;
        auto temp4 = !(C1 & (!C0 ^ C1));
        std::cout << "temp4: " << eval(temp4) << " === " << eval(!And(C1, Xor(Not(C0), C1))) << std::endl;
        std::cout << std::endl;
    }

    {
        auto mod1 = Or(C0, C1);
        auto mod2 = And(C0, C1);
        auto mod3 = Xor(C0, C1);
        std::cout << "mod1: " << eval(mod1) << std::endl;
        std::cout << "mod2: " << eval(mod2) << std::endl;
        std::cout << "mod3: " << eval(mod3) << std::endl;
        std::cout << std::endl;

        std::cout << "mod7: " << eval(Xor(Or(mod1, mod2), And(mod1, mod2))) << std::endl;
        std::cout << "mod8: " << eval(Or(And(mod1, mod2), Xor(mod1, mod2))) << std::endl;
        std::cout << "mod9: " << eval(And(Or(mod1, mod2), Xor(mod1, mod2))) << std::endl;
        std::cout << std::endl;
    }

    std::cout << "Complex: " << eval(And(C1, Xor(Not(C0), C1))) << std::endl;
    std::cout << std::endl;

    std::cout << "FINISH" << std::endl;
    return 0;
}