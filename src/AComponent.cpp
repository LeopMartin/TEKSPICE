/*
** EPITECH PROJECT, 2022
** NanoTekSpace
** File description:
** Component.cpp
*/

#include "AComponent.hpp"

void AComponent::set_state (std::string value) {
    if (value == "0") _state = nts::Tristate::False;
    else if (value == "1") _state = nts::Tristate::True;
    else _state = nts::Tristate::Undefined;
}

nts::Tristate AComponent::compute (std::size_t pin) {
    (void) pin;
    return _link.other->compute(_link.pin_card);
}

void AComponent::setLink (std::size_t pin, nts::IComponent &other,std::size_t otherPin) {
    nts::link add_link;

    add_link.pin = pin;
    add_link.other = &other;
    add_link.pin_card = otherPin;
    link_s.push_back(add_link);
}

void AComponent::set_next(std::string value) {
    if (value == "0") _next = nts::Tristate::False;
    else if (value == "1") _next = nts::Tristate::True;
    else if (value == "U") _next = nts::Tristate::Undefined;
}

nts::Tristate AComponent::and_function (nts::Tristate a, nts::Tristate b) {
    if ((a != nts::Tristate::Undefined) && (b != nts::Tristate::Undefined)) {
        if (a == nts::Tristate::True && b == nts::Tristate::True)
            return nts::Tristate::True;
        if (a == nts::Tristate::False || b == nts::Tristate::False)
            return nts::Tristate::False;
    } else if (a == nts::Tristate::False || b == nts::Tristate::False)
        return nts::Tristate::False;
    return nts::Tristate::Undefined;
}

nts::Tristate AComponent::or_function (nts::Tristate a, nts::Tristate b) {
    if (a != nts::Tristate::Undefined && b != nts::Tristate::Undefined) {
        if (a == nts::Tristate::True || b == nts::Tristate::True)
            return nts::Tristate::True;
        else
            return nts::Tristate::False;
    }
    if (a == nts::Tristate::True || b == nts::Tristate::True)
        return nts::Tristate::True;
    return nts::Tristate::Undefined;
}

nts::Tristate AComponent::xor_function (nts::Tristate a, nts::Tristate b) {
    if (a == nts::Tristate::Undefined || b == nts::Tristate::Undefined)
        return nts::Tristate::Undefined;
    if ((a == nts::Tristate::True && b == nts::Tristate::True) ||
        (a == nts::Tristate::False && b == nts::Tristate::False))
        return nts::Tristate::False;
    return nts::Tristate::True;
}

nts::Tristate AComponent::not_function (nts::Tristate a) {
    if (a == nts::Tristate::Undefined)
        return nts::Tristate::Undefined;
    else if (a == nts::Tristate::False)
        return nts::Tristate::True;
    else
        return nts::Tristate::False;
}

void AComponent::show_link(void) {
    std::cout << "nbr of links: " << link_s.size() << std::endl;
    for (long unsigned int i = 0; i < link_s.size(); i++)
        std::cout << i+1 << " " << link_s[i].other << std::endl;
}