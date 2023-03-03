/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-tekspice-thibault.avon
** File description:
** shell.cpp
*/

#include "shell.hpp"
#include "chipsets.hpp"

std::size_t stringToSizet(std::string str) {
	std::stringstream sstream(str);
	size_t result;
	sstream >> result;
	return result;
}

nts::IComponent * searchLinks (std::vector <nts::IComponent *> _list, std::string _name) {
    for (nts::IComponent * elem : _list) {
        std::cout << elem->get_name() << " =|= " << _name << std::endl;
        if (elem->get_name() == _name) {
            return elem;
        }
    }
    return NULL;
}

shell::shell (char **av) {

    _tick = 0;
    infoParser_t info = parser(av);
    
    for (std::string elem : info._chipset) {
        if (elem == "and") {
            _list_component.push_back(new and_gate("gate"));
        }
    }

    for (std::string elem : info._input) {
        _list_component.push_back(new input(elem, 1));
    }

    for (std::string elem : info._output) {
        _list_component.push_back(new output(elem, 1));
    }

    for (nts::IComponent *jum : _list_component) {
        jum->show_link();
    }

    // input1->setLink(1, *gate, 1);
    // input2->setLink(1, *gate, 2);
    // out->setLink(1, *gate, 3);

    // gate->setLink(1, *input1, 1);
    // gate->setLink(2, *input2, 1);
    // gate->setLink(3, *out, 1);

    for (linker_t elem : info._links) {
        std::cout << "here" << std::endl;
        for (nts::IComponent *jum : _list_component) {
            std::cout << elem.pin_name_in << " == " << jum->get_name() << std::endl;
            if (elem.pin_name_in == jum->get_name()) {
                // std::cout << "pin out: " << elem.pin_out <<  std::endl;
                // std::cout << "pin in: " << elem.pin_in <<  std::endl;
                // std::cout << "pin name out: " << elem.pin_name_out <<  std::endl;
                // std::cout << "pin name in: " << elem.pin_name_in <<  std::endl;
                nts::IComponent *jul = searchLinks(_list_component, elem.pin_name_out);
                std::cout << jul << std::endl;
                jum->setLink(stringToSizet(elem.pin_in), *jul, stringToSizet(elem.pin_out));
                jul->setLink(stringToSizet(elem.pin_out), *jum, stringToSizet(elem.pin_in));
            }
        }
    }
    for (nts::IComponent *jum : _list_component) {
        jum->show_link();
    }
}

void shell::display () {

    std::cout << "ticks: " << _tick << std::endl;

    std::cout << "input(s):" << std::endl;
    for (int i = 0; i < (int)_list_component.size(); i++) {
        if (dynamic_cast<input*>(_list_component.at(i)) || dynamic_cast<cl*>(_list_component.at(i))) {
            std::cout << "  " << _list_component.at(i)->get_name() << ": ";
            std::cout << get_value_display(_list_component.at(i)->get_state()) << std::endl;
        }
    }

    std::cout << "output(s):" << std::endl;
    for (int j = 0; j < (int)_list_component.size(); j++) {
        if(dynamic_cast<output*>(_list_component.at(j))) {
            std::cout << "  " << _list_component.at(j)->get_name() << ": ";
            std::cout << get_value_display(_list_component.at(j)->compute(1)) << std::endl;
        }
    }
}

void shell::simulate () {
    _tick += 1;
    nts::Tristate state_cl;
    nts::Tristate state_in;
    for (int i = 0; i < (int)_list_component.size(); i++) {
        if (dynamic_cast<cl*>(_list_component.at(i))) {
            state_cl = _list_component.at(i)->get_state();
            if (state_cl == nts::Tristate::Undefined)
                _list_component.at(i)->set_state("0");
            else if (state_cl == nts::Tristate::False)
                _list_component.at(i)->set_state("1");
            else
                _list_component.at(i)->set_state("0");
        }
        else if (dynamic_cast<input*>(_list_component.at(i))) {
            state_in = _list_component.at(i)->get_next();
            if (state_in == nts::Tristate::False)
                _list_component.at(i)->set_state("0");
            if (state_in == nts::Tristate::True)
                _list_component.at(i)->set_state("1");
            if (state_in == nts::Tristate::Undefined)
                _list_component.at(i)->set_state("U");
        }
    }
}

std::string shell::get_value_display(nts::Tristate value) {
    if (value == nts::Tristate::True)
        return "1";
    else if (value == nts::Tristate::False)
        return "0";
    else
        return "U";
}

int shell::set_value (std::string value) {

    std::vector <std::string> list = split(value, '=');

    if (list.size() != 2) {
        std::cout << "\"" << value << "\": bad command." << std::endl;
        return 0;
    }
    if (list[1] == "1" || list[1] == "0" || list[1] == "U") {
        for (int i = 0; i < (int)_list_component.size(); i++) {
            if (_list_component.at(i)->get_name() == list[0]) {
                if(dynamic_cast<input*>(_list_component.at(i))) {
                    _list_component.at(i)->set_next(list[1]);
                // std::cout << "value to next: " << list[1]  << " " << _list_component.at(i)->get_name();
                // std::cout << " next = " << _list_component.at(i)->get_next() << std::endl;
                return 0;
                }
            }
        }
    }

    std::cout << "\"" << value << "\": bad command." << std::endl;
    return 0;
}

std::vector<std::string> split (const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss (s);
    std::string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}
