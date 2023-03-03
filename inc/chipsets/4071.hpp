/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibault.avon
** File description:
** card.hpp
*/

#pragma once

#include "../AComponent.hpp"

class create_4071 : public AComponent {
    public:
        create_4071 (std::string name);

    private:
        std::vector <nts::IComponent> _card_pin;
};
