//
// Created by Максим Лейхнер on 15.11.2023.
//

#ifndef FUNCTION_H
#define FUNCTION_H

#include <map>

#include "Monominal.h"
#include <vector>


class Function {
public:
    explicit Function(std::vector<Monominal> monominals);
    Function partial_derivative(int index);
    std::vector<Monominal> monominals;
    std::map<int, float> Hauss();
    double Calculate(const std::vector<int>& x_values) const;
};

std::ostream& operator<<(std::ostream& os, const Function& obj);

#endif //FUNCTION_H
