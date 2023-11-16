#include <iostream>
#include <vector>

#include "Function.h"
#include "Monominal.h"

int main() {
    // Function myFunc();
    std::vector<Monominal> monominals;
    monominals.emplace_back();
    monominals[0].multiplier = -4;
    monominals[0].add_x(1, 2);

    monominals.emplace_back();
    monominals[1].multiplier = -3;
    monominals[1].add_x(2, 2);

    monominals.emplace_back();
    monominals[2].multiplier = -1;
    monominals[2].add_x(3, 2);

    monominals.emplace_back();
    monominals[3].multiplier = 2;
    monominals[3].add_x(1, 1);
    monominals[3].add_x(2, 1);

    monominals.emplace_back();
    monominals[4].multiplier = 1;
    monominals[4].add_x(1, 1);
    monominals[4].add_x(3, 1);

    monominals.emplace_back();
    monominals[5].multiplier = 5;
    monominals[5].add_x(1, 1);

    Function myFunc(monominals);
    auto dx1 = myFunc.partial_derivative(1);

    std::cout << myFunc << std::endl;
    std::cout << dx1 << std::endl;


    return 0;
}
