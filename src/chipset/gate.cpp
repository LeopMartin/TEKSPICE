/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibault.avon
** File description:
** and.cpp
*/

#include "chipsets.hpp"

nts::Tristate and_gate::compute (std::size_t pin) {
    (void)pin;
    nts::Tristate result;
    result = and_function(link_s.at(0).other->get_state(),
                            link_s.at(1).other->get_state());
    return result;
}

nts::Tristate or_gate::compute (std::size_t pin) {
    (void)pin;
    nts::Tristate result;
    result = or_function(link_s.at(0).other->get_state(),
                        link_s.at(1).other->get_state());
    return result;
}

nts::Tristate not_gate::compute (std::size_t pin) {
    (void)pin;
    return not_function(link_s.at(0).other->get_state());
}

nts::Tristate xor_gate::compute (std::size_t pin) {
    (void)pin;
    nts::Tristate result;
    result = xor_function(link_s.at(0).other->get_state(),
                            link_s.at(1).other->get_state());
    return result;
}
