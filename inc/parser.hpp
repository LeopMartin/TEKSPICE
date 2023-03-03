/*
** EPITECH PROJECT, 2022
** B3-AllProject
** File description:
** parser.hpp
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
#include <vector>
#include <list>
#include "shell.hpp"

typedef struct linker
{
    std::string pin_name_in;
    std::string pin_in;
    std::string pin_name_out;
    std::string pin_out;
} linker_t;

typedef struct infoParser
{
    std::list<std::string> _chipset;
    std::list<std::string> _name_chipset;
    std::list<std::string> _input;
    std::list<std::string> _output;
    std::list<linker_t> _links;
} infoParser_t;

infoParser_t parser (char **av);

