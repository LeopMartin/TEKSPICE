/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibault.avon
** File description:
** input.cpp
*/

#include "input.hpp"

input::input (nts::link t_link) {
    _state = nts::Tristate::Undefined;
    _next = nts::Tristate::Undefined;
    _link = t_link;
}

input::input (std::string name, std::size_t pin) {
    _link.pin_name = name;
    _link.pin = pin;
    _next = nts::Tristate::Undefined;
    _state = nts::Tristate::Undefined;
}

true_input::true_input (std::string name, std::size_t pin) {
    _link.pin_name = name;
    _link.pin = pin;
}

false_input::false_input (std::string name, std::size_t pin) {
    _link.pin_name = name;
    _link.pin = pin;
}

cl::cl (std::string name, std::size_t pin) {
    _state = nts::Tristate::Undefined;
    _next = nts::Tristate::Undefined;
    _link.pin_name = name;
    _link.pin = pin;
}
