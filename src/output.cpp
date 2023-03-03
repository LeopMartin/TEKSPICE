/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibault.avon
** File description:
** output.cpp
*/

#include "output.hpp"

output::output (nts::link t_link) {
    _state = nts::Tristate::Undefined;
    _link = t_link;
}

nts::Tristate output::compute (std::size_t pin) {
    (void)pin;
    return link_s.at(0).other->compute(link_s.at(0).pin_card);
}
