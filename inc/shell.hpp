/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibault.avon
** File description:
** shell.hpp
*/

#pragma once

#include "input.hpp"
#include "output.hpp"
#include "parser.hpp"

std::vector<std::string> split (const std::string &s, char delim);

class shell {
    public:
        shell(char **av);
        ~shell() {};
        int prompt (std::string value);
        void display();
        int set_value (std::string value);
        void simulate ();

        int get_tick () const { return _tick; }
        std::string get_value_display (nts::Tristate value);

    private:
        int _tick;
        std::vector <nts::IComponent *> _list_component;
};
