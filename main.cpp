#include <iostream>
#include <vector>

#include "DataModels/Function.h"
#include "DataModels/Monominal.h"

int main() {
    // Function myFunc();
    std::vector<Monominal> monominals;
    monominals.emplace_back(1,2,3);
    monominals.emplace_back(2,2,2);
    monominals.emplace_back(3,2,1);
    monominals.emplace_back(std::vector {1,2}, std::vector {1,1}, -1.0);
    monominals.emplace_back(std::vector {2,3}, std::vector {1,1}, 0.5);
    monominals.emplace_back(2,1,6);
    Function myFunc(monominals);

    myFunc.extremum();
//    auto dx1 = myFunc.partial_derivative(1);
//
    std::cout << myFunc << std::endl;
//    std::cout << dx1 << std::endl;
    //std::cout << myFunc.Calculate(std::vector<int> {1,2,3}) << std::endl;


    return 0;
}
