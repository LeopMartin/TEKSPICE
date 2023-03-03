/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibault.avon
** File description:
** output.hpp
*/

#pragma once

#include "AComponent.hpp"

class output : public AComponent {
    public:
        output(nts::link t_link);
        output(std::string name, std::size_t pin) {_link.pin_name = name, _link.pin = pin; }
        ~output() {}
        nts::Tristate compute (std::size_t pin);
};
