/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibault.avon
** File description:
** input.hpp
*/

#pragma once

#include "AComponent.hpp"

class input : public AComponent {
    public:
        input(nts::link t_link);
        input(std::string name, std::size_t pin);
        ~input() {}
        nts::Tristate compute ( std::size_t pin ) {(void)pin; return _state; }
};

class true_input : public AComponent {
    true_input (std::string name, std::size_t pin);
    ~true_input() {};
    nts::Tristate compute (std::size_t pin) {(void)pin; return nts::Tristate::True; }
};

class false_input : public AComponent {
    false_input (std::string name, std::size_t pin);
    ~false_input() {};
    nts::Tristate compute (std::size_t pin) {(void)pin; return nts::Tristate::False; }
};

class cl : public AComponent {
    public:
        cl(std::string name, std::size_t pin);
        ~cl() {};
};
