/*
** EPITECH PROJECT, 2022
** B3-AllProject
** File description:
** parser.cpp
*/

#include "parser.hpp"

std::string doc;

std::list<std::string> list_chipset;
std::list<std::string> list_name_chipset;
std::list<std::string> list_input;
std::list<std::string> list_output;
std::list <linker_t> list_links;

void open(const std::string& path) {
    std::ifstream ifs(path);
    if (ifs.is_open()) {
        std::ostringstream ss;
        ss << ifs.rdbuf();
        doc = ss.str();
    } else {
        // std::cout << path << " is not a directory" << std::endl;
        exit (84);
    }
}

bool isInList (std::list<std::string> _list, std::string _str) { // retrun 1 si oui
    for (std::string elem : _list)
        if (strcmp(elem.c_str(), _str.c_str()) == 0)
            return 1;
    return 0;
}

void goodValueOfSpace (std::string _text) {
    int x = 0;
    for (char i : _text)
        if (i == ' ')
            x++;
    if (x != 2) {
        // std::cout << "ERROR TEST 3\n";
        exit (84);
    }
}

void printList(std::list <std::string> _list) {
    std::cout << "|";
    for (std::string elem : _list) {
        std::cout << elem <<" |";
    }
    std::cout << "\n";
}

void printVector(std::vector<std::string> _vec) {
    for (std::string elem : _vec) {
            std::cout << '\"' << elem << "\"\n";
            std::cout << '\"';
    }
}

std::vector<std::string> parser_etp1(const std::string &s) {
    // découpe du fichier
    std::vector<std::string> result;
    std::vector<std::string> nocom;
    std::istringstream ss (s);
    std::string item;

    while (getline (ss, item, '\n')) {
        result.push_back (item);
    }

    // suppr les coms
    for (std::string item : result) {
        size_t found = item.find('\t');
    
        if (found != std::string::npos) {
            item.erase(found, 1);
        }
        
        if (strstr(item.c_str(), "#") != NULL) {
            item = item.substr(0, item.find('#'));
        }
        // std::cout << item << "|";
        nocom.push_back(item);
    }

    // if (strstr(item.c_str(), "#") != NULL) {
    //     std::cout << "error: probleme freinage" << std::endl;
    // }

    // boucle de la longeur de mon vector
    std::vector<std::string> propre;
    for (std::string item : nocom) {
        std::istringstream nss (item);
        std::string final;

        while (nss >> final) {
            propre.push_back(final);
            propre.push_back(" ");
        }
        propre.push_back("\n");
    }
    return propre;
}

void verifName () {
    int x = 0;
    std::list<std::string> _list;
    _list.insert(_list.end(), list_input.begin(), list_input.end());
    _list.insert(_list.end(), list_output.begin(), list_output.end());
    _list.insert(_list.end(), list_name_chipset.begin(), list_name_chipset.end());
    
    // std::cout << "list :\n";
    // printList(_list);

    for (std::string src : _list) {
        for (std::string dest : _list) {
            if (src == dest)
                x++;
        }
        if (x >= 2) {
            // std::cout << "ERROR 4: " << src << std::endl;
            exit (84);
        }
        x = 0;
    }
}

void multipleDeclarationVerif (std::string _text) {
    if (_text.find(".chipsets:") != _text.rfind(".chipsets:")) {
        exit (84);
    }
    if (_text.find(".links:") != _text.rfind(".links:")) {
        exit (84);
    }
    // std::cout << "PASSED : TEST 1\n";
}

void noDataInDeclaration (std::vector<std::string> _vec) {
    bool ischip = false;
    int x = 0;
    for (std::string elem : _vec) {
        if (elem == ".chipsets:") {
            ischip = true;
            x++;
        } else if (elem == ".links:" && x == 4) {
            exit (84);
        } else if (ischip == true) {
            x++;
        }
    }
    x = 0;
    ischip = false;
    for (std::string elem : _vec) {
        if (elem == ".links:") {
            ischip = true;
            x++;
        } else if (ischip == true && elem != "\n") {
            x++;
        }
    }
    if (x == 2)
        exit (84);
    // std::cout << "PASSED : TEST 2\n";
}

void catAnalyse (std::string _text) {
    std::string result;
    std::stringstream final (_text);

    while (std::getline (final, result, '\n') && result != ".links: ") { // ajouter clock
        int douppoint = result.rfind(' ') - 1;
        if (result.substr(0, 6) == "input ") {
            goodValueOfSpace(result);
            list_input.push_back(result.substr(6, douppoint - 5));
            // std::cout << "INPUT: \"" << result.substr(6, douppoint - 5) << "\"" << std::endl;
        } else if (result.substr(0, 7) == "output ") {
            goodValueOfSpace(result);
            list_output.push_back(result.substr(7, douppoint - 6));
            // std::cout << "OUTPUT: " << "\"" << result.substr(7, douppoint - 6) << "\"" << std::endl;
        } else if (result == ".chipsets: " || result == "\0") {
            continue;
        } else if (result[0] == '#') {
            continue;
        } else {
            goodValueOfSpace(result);
            // std::cout << "OTHERS PART 1: " << "\"" << result.substr(0, result.find(' ')) << "\"" << std::endl;
            list_chipset.push_back(result.substr(0, result.find(' ')));
            //////
            // std::cout << "OTHERS PART 2: " << "\"" << result.substr(result.find(' ') + 1, douppoint - result.find(' ')) << "\"" << std::endl;
            list_name_chipset.push_back(result.substr(result.find(' ') + 1, douppoint - result.find(' ')));
        }
    }
    
    while (std::getline (final, result, '\n')) {
        if (result[0] == '#') {
            // std::cout << "com detected" << std::endl;
            continue;
        } else {
            goodValueOfSpace(result);

            int dpoint = result.find(':') + 1;
            int espace = result.find(' ') + 1;
            int lpoint = result.rfind(':') + 1;
            int gpoint = result.rfind(' ');

            ////////////////////////////////////////////////////
            // printList(list_chipset);
            // printList(list_input);
            // printList(list_output);
            std::string nameObj1 = result.substr(0, dpoint - 1);
            std::string nameObj2 = result.substr(espace, lpoint - espace - 1);

            ////////////////////////////////////////////////////
            // std::cout << "In the obj \"" << result.substr(0, dpoint - 1) << "\"";
            // std::cout << ", push value: \"" << result.substr(dpoint, espace - dpoint - 1) << "\"";
            // std::cout << " and in the obj: \"" << result.substr(espace, lpoint - espace - 1) << "\"";
            // std::cout << " push value: \"" << result.substr(lpoint, gpoint - lpoint) << "\"" << std::endl;

            std::string pin_in = result.substr(dpoint, espace - dpoint - 1);
            std::string pin_name_in = result.substr(0, dpoint - 1);
            std::string pin_out = result.substr(lpoint, gpoint - lpoint);
            std::string pin_name_out = result.substr(espace, lpoint - espace - 1);

            if (pin_in == "" || pin_name_in == "" || pin_out == "" || pin_name_out == "")
                exit(84);

            linker_t lister;
            lister.pin_in = pin_in;
            lister.pin_name_in = pin_name_in;
            lister.pin_out = pin_out;
            lister.pin_name_out = pin_name_out;
            list_links.push_back(lister);

            if (isInList(list_input, nameObj1) == 0 && isInList(list_output, nameObj1) == 0 && isInList(list_name_chipset, nameObj1) == 0) {
                std::cout << "Unknow component name \'" << nameObj1 << "\'." << std::endl;
                exit (84);
            }
            if (isInList(list_input, nameObj2) == 0 && isInList(list_output, nameObj2) == 0 && isInList(list_name_chipset, nameObj2) == 0) {
                std::cout << "Unknow name \'" << nameObj2 << "\'." << std::endl;
                exit (84);
            }
        }
    }
    verifName();
}

infoParser_t parser (char **av) {

    open(av[1]); // ouverture du fichier
    infoParser_t info;
    std::string s;
    std::vector<std::string> part = parser_etp1(doc); // plus de tab, d'espace et de commentaire.
    for (const auto &piece : part) s += piece;
    multipleDeclarationVerif(s); // verification : plusieur declaration chipset/input
    noDataInDeclaration(part); // verification : si chipset vide ? / si input vide ?
    //////////////////////////////////////////////////////////////////
    // verification : si les compo on le bon nombre de pin
    // verifier les chipset name
    //////////////////////////////////////////////////////////////////
    // verifier la validiter des liens
    //////////////////////////////////////////////////////////////////
    // verification : 2 compo on le meme nom OK
    // verification : plus de 2 mot par ligne OK
    // verification : si les input, output nom pas de nom OK
    // verification : si compo existe pas (pas le bon nom) OK
    //////////////////////////////////////////////////////////////////
    catAnalyse(s);

    info._chipset = list_chipset;
    info._name_chipset = list_name_chipset;
    info._input = list_input;
    info._output = list_output;
    info._links = list_links;

    return info;
}
