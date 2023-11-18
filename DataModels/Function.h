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
    Function partial_derivative(int index) const;
    std::vector<Monominal> monominals;

    std::vector<long double> extremum();
    long double calculate(const std::vector<long double>&x_values) const;
    int x_count() const;
};

std::ostream& operator<<(std::ostream& os, const Function& obj);
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<long double>>& obj);

#endif //FUNCTION_H
