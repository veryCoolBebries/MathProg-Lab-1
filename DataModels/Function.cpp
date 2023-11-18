//
// Created by Максим Лейхнер on 15.11.2023.
//

#include "Function.h"
#include "math.h"
Function::Function(std::vector<Monominal> monominals) {
    this->monominals = std::move(monominals);
}

Function Function::partial_derivative(const int index) {
    // Новая функция
    std::vector<Monominal> new_function;

    // Итерация по одночленам
    for (auto monominal: this->monominals) {
        // Находим нужный X
        const auto x_index = monominal.find_x(index);
        if (x_index == -1) continue;
        auto new_monominal = Monominal();

        new_monominal.multiplier = monominal.multiplier * (float)monominal.x_powers[x_index];
        new_monominal.x_powers = monominal.x_powers;
        new_monominal.x_indices = monominal.x_indices;

        if (new_monominal.x_powers[x_index] > 1) new_monominal.x_powers[x_index] -= 1;
        else {
            new_monominal.x_powers.erase(new_monominal.x_powers.begin() + x_index);
            new_monominal.x_indices.erase(new_monominal.x_indices.begin() + x_index);
        }
        new_function.emplace_back(new_monominal);
    }
    return Function(new_function);
}

std::map<int, float> Function::Hauss() {
    int max_ind = 0;
    for (const auto& monominal : monominals) {
        for (const auto& index: monominal.x_indices) {
            if (index > max_ind) max_ind = index;
        }
    }

    std::vector<Function> derivatives;
    derivatives.reserve(max_ind);

    for (int i = 1; i < max_ind; i++) {
        derivatives.push_back(this->partial_derivative(i));
    }

    std::vector<std::vector<float>> matrix;

    matrix.reserve(max_ind - 1);
for (int i = 1; i < max_ind; i++) {
        auto line = derivatives[i - 1];
        matrix.emplace_back();
        for (int j = 1; j < max_ind; j++) {
            for (auto monominal : line.monominals) {
                if (monominal.find_x(j) != -1) {

                }
            }
        }
    }
}

double Function::Calculate(const std::vector<int> &x_values) {
    double result = 0;
    for(auto monominal : this->monominals) {
        double monominal_value = monominal.multiplier;
        for(auto index : monominal.x_indices) {
            monominal_value *= pow(x_values[index], monominal.x_powers[index]);
        }
        result += monominal_value;
    }
    return result;
}

std::ostream& operator<<(std::ostream& os, const Function& obj) {
    for (const auto& monominal: obj.monominals) {
        os << monominal;
    }
    return os;
}
