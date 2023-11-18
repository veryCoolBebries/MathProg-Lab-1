#include <iostream>
#include <vector>

#include "DataModels/Function.h"
#include "DataModels/Monominal.h"

int main() {
    // Function myFunc();
    std::vector<Monominal> monominals;
    monominals.emplace_back(1,2,-4);
    monominals.emplace_back(3,2,2);
    monominals.emplace_back(1,3,2);
    monominals.emplace_back(std::vector<int> {1,2}, std::vector<int> {2,1}, 2);
    monominals.emplace_back(std::vector<int> {1,3}, std::vector<int> {1,1}, 1);
    monominals.emplace_back(1,1,5);


    Function myFunc(monominals);
    auto dx1 = myFunc.partial_derivative(1);

    std::cout << myFunc << std::endl;
    std::cout << dx1 << std::endl;
    std::cout << myFunc.Calculate(std::vector<int> {1,2,3}) << std::endl;


    return 0;
}
