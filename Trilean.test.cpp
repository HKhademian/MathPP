/// clear && gcc -o Trilean.out Trilean.test.cpp -lstdc++ && echo "9 8 7 6 5 4 3 2 1" | ./Trilean.out | tee ./Trilean.test.out && rm ./Trilean.out

#include <iostream>
#include "Trilean.hpp"
#include "Trilean.iostream.hpp"

using namespace MathPP;

int main()
{

    /*test1*/ {
        std::cout << "NEG: " << NEG << std::endl;
        std::cout << "ZER: " << ZER << std::endl;
        std::cout << "POS: " << POS << std::endl;
        std::cout << std::endl;
    }

    /*test2: not*/ {
        std::cout << "! NEG: " << !NEG << std::endl;
        std::cout << "! ZER: " << !ZER << std::endl;
        std::cout << "! POS: " << !POS << std::endl;
        std::cout << std::endl;
    }

    /*test3: eq*/ {
        std::cout << "NEG == NEG: " << (NEG == NEG) << std::endl;
        std::cout << "NEG == ZER: " << (NEG == ZER) << std::endl;
        std::cout << "NEG == POS: " << (NEG == POS) << std::endl;
        std::cout << "ZER == NEG: " << (ZER == NEG) << std::endl;
        std::cout << "ZER == ZER: " << (ZER == ZER) << std::endl;
        std::cout << "ZER == POS: " << (ZER == POS) << std::endl;
        std::cout << "POS == NEG: " << (POS == NEG) << std::endl;
        std::cout << "POS == ZER: " << (POS == ZER) << std::endl;
        std::cout << "POS == POS: " << (POS == POS) << std::endl;
        std::cout << std::endl;
    }

    /*test3: neq*/ {
        std::cout << "NEG != NEG: " << (NEG != NEG) << std::endl;
        std::cout << "NEG != ZER: " << (NEG != ZER) << std::endl;
        std::cout << "NEG != POS: " << (NEG != POS) << std::endl;
        std::cout << "ZER != NEG: " << (ZER != NEG) << std::endl;
        std::cout << "ZER != ZER: " << (ZER != ZER) << std::endl;
        std::cout << "ZER != POS: " << (ZER != POS) << std::endl;
        std::cout << "POS != NEG: " << (POS != NEG) << std::endl;
        std::cout << "POS != ZER: " << (POS != ZER) << std::endl;
        std::cout << "POS != POS: " << (POS != POS) << std::endl;
        std::cout << std::endl;
    }

    /*test3: and*/ {
        std::cout << "NEG & NEG: " << (NEG & NEG) << std::endl;
        std::cout << "NEG & ZER: " << (NEG & ZER) << std::endl;
        std::cout << "NEG & POS: " << (NEG & POS) << std::endl;
        std::cout << "ZER & NEG: " << (ZER & NEG) << std::endl;
        std::cout << "ZER & ZER: " << (ZER & ZER) << std::endl;
        std::cout << "ZER & POS: " << (ZER & POS) << std::endl;
        std::cout << "POS & NEG: " << (POS & NEG) << std::endl;
        std::cout << "POS & ZER: " << (POS & ZER) << std::endl;
        std::cout << "POS & POS: " << (POS & POS) << std::endl;
        std::cout << std::endl;
    }

    /*test3: or*/ {
        std::cout << "NEG | NEG: " << (NEG | NEG) << std::endl;
        std::cout << "NEG | ZER: " << (NEG | ZER) << std::endl;
        std::cout << "NEG | POS: " << (NEG | POS) << std::endl;
        std::cout << "ZER | NEG: " << (ZER | NEG) << std::endl;
        std::cout << "ZER | ZER: " << (ZER | ZER) << std::endl;
        std::cout << "ZER | POS: " << (ZER | POS) << std::endl;
        std::cout << "POS | NEG: " << (POS | NEG) << std::endl;
        std::cout << "POS | ZER: " << (POS | ZER) << std::endl;
        std::cout << "POS | POS: " << (POS | POS) << std::endl;
        std::cout << std::endl;
    }

    /*test3: xor*/ {
        std::cout << "NEG ^ NEG: " << (NEG ^ NEG) << std::endl;
        std::cout << "NEG ^ ZER: " << (NEG ^ ZER) << std::endl;
        std::cout << "NEG ^ POS: " << (NEG ^ POS) << std::endl;
        std::cout << "ZER ^ NEG: " << (ZER ^ NEG) << std::endl;
        std::cout << "ZER ^ ZER: " << (ZER ^ ZER) << std::endl;
        std::cout << "ZER ^ POS: " << (ZER ^ POS) << std::endl;
        std::cout << "POS ^ NEG: " << (POS ^ NEG) << std::endl;
        std::cout << "POS ^ ZER: " << (POS ^ ZER) << std::endl;
        std::cout << "POS ^ POS: " << (POS ^ POS) << std::endl;
        std::cout << std::endl;
    }

    /*test3: mult*/ {
        std::cout << "NEG * NEG: " << (NEG * NEG) << std::endl;
        std::cout << "NEG * ZER: " << (NEG * ZER) << std::endl;
        std::cout << "NEG * POS: " << (NEG * POS) << std::endl;
        std::cout << "ZER * NEG: " << (ZER * NEG) << std::endl;
        std::cout << "ZER * ZER: " << (ZER * ZER) << std::endl;
        std::cout << "ZER * POS: " << (ZER * POS) << std::endl;
        std::cout << "POS * NEG: " << (POS * NEG) << std::endl;
        std::cout << "POS * ZER: " << (POS * ZER) << std::endl;
        std::cout << "POS * POS: " << (POS * POS) << std::endl;
        std::cout << std::endl;
    }

    /*test3: plus*/ {
        std::cout << "NEG + NEG: " << (NEG + NEG) << std::endl;
        std::cout << "NEG + ZER: " << (NEG + ZER) << std::endl;
        std::cout << "NEG + POS: " << (NEG + POS) << std::endl;
        std::cout << "ZER + NEG: " << (ZER + NEG) << std::endl;
        std::cout << "ZER + ZER: " << (ZER + ZER) << std::endl;
        std::cout << "ZER + POS: " << (ZER + POS) << std::endl;
        std::cout << "POS + NEG: " << (POS + NEG) << std::endl;
        std::cout << "POS + ZER: " << (POS + ZER) << std::endl;
        std::cout << "POS + POS: " << (POS + POS) << std::endl;
        std::cout << std::endl;
    }

    /*test3: minus*/ {
        std::cout << "NEG - NEG: " << (NEG - NEG) << std::endl;
        std::cout << "NEG - ZER: " << (NEG - ZER) << std::endl;
        std::cout << "NEG - POS: " << (NEG - POS) << std::endl;
        std::cout << "ZER - NEG: " << (ZER - NEG) << std::endl;
        std::cout << "ZER - ZER: " << (ZER - ZER) << std::endl;
        std::cout << "ZER - POS: " << (ZER - POS) << std::endl;
        std::cout << "POS - NEG: " << (POS - NEG) << std::endl;
        std::cout << "POS - ZER: " << (POS - ZER) << std::endl;
        std::cout << "POS - POS: " << (POS - POS) << std::endl;
        std::cout << std::endl;
    }

    return 0;
}