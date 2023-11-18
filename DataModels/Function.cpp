//
// Created by Максим Лейхнер on 15.11.2023.
//

#include "Function.h"
#include <cmath>
#include <iterator>

Function::Function(std::vector<Monominal> monominals) {
    this->monominals = std::move(monominals);
}

Function Function::partial_derivative(const int index) const {
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

std::map<int, float> Function::hauss() {
    // Считаем количество иксов
    const int max_ind = x_count();

    // Вектор частных производных
    std::vector<Function> derivatives;
    derivatives.reserve(max_ind);

    // Находим частные производные по каждому иксу
    for (int i = 1; i <= max_ind; i++)
        derivatives.push_back(this->partial_derivative(i));

    // Матрица для решения системы
    std::vector<std::vector<float>> matrix;
    matrix.reserve(max_ind);

    for (int i = 1; i <= max_ind; i++) {
        auto line = derivatives[i - 1];
        matrix.emplace_back();
        for (int j = 1; j <= max_ind; j++) {
            for (auto monominal : line.monominals) {
                if (monominal.find_x(j) != -1) {

                }
            }
        }
    }
}

double Function::calculate(const std::vector<double> & x_values) const {
    double result = 0;
    for(auto monominal : this->monominals) {
        double monominal_value = monominal.multiplier;
        for(const auto index : monominal.x_indices) {
            monominal_value *= pow(x_values[index], monominal.x_powers[index]);
        }
        result += monominal_value;
    }
    return result;
}

int Function::x_count() const {
    int max_int = 0;
    for (const auto& monominal: monominals)
        for (auto index: monominal.x_indices)
            max_int = std::max(max_int, index);
    return max_int;
}

std::ostream& operator<<(std::ostream& os, const Function& obj) {
    for (const auto& monominal: obj.monominals) {
        os << monominal;
    }
    return os;
}
