//
// Created by Максим Лейхнер on 15.11.2023.
//

#include "Function.h"
#include <cmath>
#include <iostream>
#include <iterator>

#define PRECISION 0.0001

std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<long double>>& obj) {
    for (const auto & i : obj) {
        os << "[\t";
        for (long double j : i) {
            if (fabs(j) < PRECISION) os << 0 << "\t\t";
            else os << j << "\t\t";
        }
        os << "]\n";
    }
    return os;
}

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

std::vector<long double> Function::extremum() {
    // Считаем количество иксов
    const int max_ind = x_count();

    // Вектор частных производных
    std::vector<Function> derivatives;
    derivatives.reserve(max_ind);

    // Находим частные производные по каждому иксу
    for (int i = 1; i <= max_ind; i++)
        derivatives.push_back(this->partial_derivative(i));

    // Матрица для решения системы
    std::vector<std::vector<long double>> matrix;
    matrix.reserve(max_ind);

    // Заполняем матрицу множителями перед иксами
    for (int i = 1; i <= max_ind; i++) {
        // Новая строка матрицы
        auto line = derivatives[i - 1];
        matrix.emplace_back();
        // Заполняем строки матрицы
        for (int j = 1; j <= max_ind; j++) {
            matrix.back().push_back(0);
            // Ищем одночлен с нужным индексом икса
            for (const auto& monominal : line.monominals) {
                if (monominal.find_x(j) == -1) continue;
                matrix.back().back() = monominal.multiplier;
                break;
            }
        }

        // Ищем свободный одночлен
        matrix.back().push_back(0);
        for (const auto& monominal : line.monominals) {
            if (!monominal.x_indices.empty()) continue;
            matrix.back().back() = -monominal.multiplier;
            break;
        }
    }

    std::cout << matrix << std::endl;

    //Приводим матрицу к треугольному виду
    for (int i = 0; i < matrix.size() - 1; i++) {
        for (int j = i + 1; j < matrix.size(); j++) {
            const long double multiplier = matrix[j][i] / matrix[i][i];
            for (int k = i; k < matrix[i].size(); k++) {
                matrix[j][k] -= matrix[i][k] *  multiplier;
            }
        }
        std::cout << matrix << std::endl;
    }

    std::vector<long double> result(matrix.size(), 0.0);
    static int last_index = static_cast<int>(matrix.size()) - 1;
    for (int i = last_index; i >= 0; i--) {
        long double known_sum = 0;
        for (int j = i; j < last_index; j++)
            known_sum += result[j] * matrix[i][j];
        result[i] = (matrix[i].back() - known_sum) / matrix[i][i];
        std::cout << result[i] << "\t";
    }

    return result;
}

long double Function::calculate(const std::vector<long double> & x_values) const {
    long double result = 0;
    for(auto monominal : this->monominals) {
        long double monominal_value = monominal.multiplier;
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
