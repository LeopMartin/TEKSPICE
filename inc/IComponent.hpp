/*
** EPITECH PROJECT, 2022
** NanoTekSpace
** File description:
** IComponent.hpp
*/

#pragma once

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <dirent.h>
#include <exception>
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

namespace nts
{
    enum Tristate {
        Undefined = -1 ,
        True = true ,
        False = false
    };

    enum Card {
        nor_4001,
        adder_4008,
        nand_4011,
        flipflop_4013,
        johnson_4017,
        xor_4030,
        counter_4040,
        not_4069,
        or_4071,
        and_4081,
        shift_4094,
        selector_4512,
        decoder_4514,
        ram_4801,
        nothing
    };

    class IComponent {
        public :
            virtual ~IComponent () = default;
            virtual std::string get_name () const = 0;
            virtual nts::Tristate get_state () const = 0;
            virtual std::size_t get_pin () const = 0;

            virtual void set_state (std::string value) = 0;
            virtual nts::Tristate compute ( std::size_t pin ) = 0;
            virtual void set_next (std::string value) = 0;
            virtual void simu () = 0;
            virtual nts::Tristate get_next () const = 0;
            virtual void setLink (std::size_t pin, nts::IComponent &other,
                                  std::size_t otherPin) = 0;
            virtual void show_link() = 0;
    }; 

    typedef struct link {
            link () {};
            std::size_t pin;            // numéro de pin
            std::string pin_name;       // nom du composant
            std::string card_name;      // nom de la carte
            std::size_t pin_card;       // numéro de la pin sur la carte
            nts::IComponent * other; // pointe vers une autre componant
    }link_t;
}
