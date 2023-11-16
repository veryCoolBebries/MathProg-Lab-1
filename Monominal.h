//
// Created by Максим Лейхнер on 15.11.2023.
//

#ifndef MONOMINAL_H
#define MONOMINAL_H

#include <vector>
#include <ostream>

const char superscript_numbers[10][4] = {"\u2070", "\u00B9", "\u00B2", "\u00B3", "\u2074", "\u2075", "\u2076", "\u2077", "\u2078", "\u2079"};
const char subscript_nubers[10][4] = {"\u2080", "\u2081", "\u2082", "\u2083", "\u2084", "\u2085", "\u2086", "\u2087", "\u2088", "\u2089"};

class Monominal {
public:
    float multiplier;
    std::vector<int> x_indices;
    std::vector<int> x_powers;

    void add_x(int index, int power);
    int find_x(int index) const;
};

std::ostream& operator<<(std::ostream& os, const Monominal& obj);



#endif //MONOMINAL_H
