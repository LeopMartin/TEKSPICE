/*
** EPITECH PROJECT, 2022
** NanoTekSpace
** File description:
** Component.hpp
*/

#pragma once

#include "IComponent.hpp"

class AComponent : public nts::IComponent {

    public:

        AComponent () {};
        ~AComponent () {};

        void set_card (nts::Card card) { _link.card_name = card; }

        std::string get_name () const { return _link.pin_name; }
        nts::Tristate get_state () const { return _state; }
        std::size_t get_pin () const { return _link.pin ; }
        nts::Tristate compute (std::size_t pin);
        void setLink (std::size_t pin, nts::IComponent &other,
                                  std::size_t otherPin);

        void set_state (std::string value);
        void set_next (std::string value);
        void simu () { _state = _next; }
        nts::Tristate get_next () const { return _next; }

        nts::Tristate and_function (nts::Tristate a, nts::Tristate b);
        nts::Tristate or_function (nts::Tristate a, nts::Tristate b);
        nts::Tristate xor_function (nts::Tristate a, nts::Tristate b);
        nts::Tristate not_function (nts::Tristate a);
        void show_link();
    protected:
        nts::link _link;
        std::vector<nts::link> link_s;
        nts::Tristate _state;
        nts::Tristate _next;
};
