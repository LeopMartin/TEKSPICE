/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibault.avon
** File description:
** and.hpp
*/

#pragma once

#include "AComponent.hpp"

class and_gate : public AComponent {
    public:
        and_gate(std::string name) {_link.pin_name = name; }
        ~and_gate() {};
        nts::Tristate compute ( std::size_t pin );
};

class or_gate : public AComponent {
    public:
        or_gate(std::string name) {_link.card_name = name; }
        ~or_gate() {};
        nts::Tristate compute (std::size_t pin);
};

class not_gate : public AComponent {
    public:
        not_gate(std::string name) {_link.card_name = name; }
        ~not_gate() {};
        nts::Tristate compute (std::size_t pin);
};

class xor_gate : public AComponent {
    public:
        xor_gate (std::string name) {_link.card_name = name;}
        ~xor_gate () {};
        nts::Tristate compute (std::size_t pin);
};
