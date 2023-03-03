/*
** EPITECH PROJECT, 2022
** NanoTekSpace
** File description:
** main.cpp
*/

#include "shell.hpp"

int shell::prompt (std::string value) {

    if (value == "exit") exit(0);
    else if (value == "display") display();
    else if (value == "simulate")  simulate();
    else
        set_value(value);
    return 0;
}

int main(int ac, char **av)
{
    (void) av;

    std::string value;
    (void)av;
    if (ac != 2) return 84;
    //parser(av);

    class shell shell_s(av);

    while (std::cout << "> " && std::getline(std::cin, value)) {
        shell_s.prompt(value);
    }
    return 0;
}
