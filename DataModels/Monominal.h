//
// Created by Максим Лейхнер on 15.11.2023.
//

#ifndef MONOMINAL_H
#define MONOMINAL_H

#include <utility>
#include <vector>
#include <ostream>

constexpr char superscript_numbers[10][4] = {"\u2070", "\u00B9", "\u00B2", "\u00B3", "\u2074", "\u2075", "\u2076", "\u2077", "\u2078", "\u2079"};
constexpr char subscript_nubers[10][4] = {"\u2080", "\u2081", "\u2082", "\u2083", "\u2084", "\u2085", "\u2086", "\u2087", "\u2088", "\u2089"};

class Monominal {
public:
    long double multiplier = 1.0;
    std::vector<int> x_indices;
    std::vector<int> x_powers;
    Monominal() = default;
    ~Monominal() = default;
    explicit Monominal(const long double multiplier) : multiplier(multiplier) { }
    Monominal(int x_index, int x_power);
    Monominal(int x_index, int x_power, long double multiplier);
    Monominal(std::vector<int> x_indices, std::vector<int> x_powers) : x_indices(std::move(x_indices)),
    x_powers(std::move(x_powers)) { }
    Monominal(std::vector<int> x_indices, std::vector<int> x_powers, const long double multiplier) : x_indices(std::move(x_indices)),
    x_powers(std::move(x_powers)), multiplier(multiplier) { }
    void add_x(int index, int power);
    int find_x(int index) const;
};

std::ostream& operator<<(std::ostream& os, const Monominal& obj);



#endif //MONOMINAL_H
