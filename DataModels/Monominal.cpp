//
// Created by Максим Лейхнер on 15.11.2023.
//

#include "Monominal.h"

void Monominal::add_x(const int index, const int power) {
    this->x_indices.push_back(index);
    this->x_powers.push_back(power);
}

int Monominal::find_x(int const index) const {
    for (int i = 0; i < this->x_indices.size(); i++) {
        if (this->x_indices[i] == index) return i;
    }
    return -1;
}


Monominal::Monominal(const int x_index, const int x_power) {
    this->add_x(x_index, x_power);
}

Monominal::Monominal(const int x_index, const int x_power, const double multiplier) : multiplier(multiplier){
    this->add_x(x_index, x_power);
}


std::ostream& operator<<(std::ostream& os, const Monominal& obj) {
    if (obj.multiplier > 0) {
        os << "+";
    }
    os << obj.multiplier;
    for (int i = 0; i < obj.x_indices.size(); i++) {
         os << "(x" << subscript_nubers[obj.x_indices[i]] << ")" << superscript_numbers[obj.x_powers[i]];
    }
    return os;
}
