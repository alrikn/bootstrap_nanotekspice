/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Parser
** The parse only handles the file, not the cli
*/

#include "Parser.hpp"
#include <csignal>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <cctype>

nts::Parser::Parser(const std::string &file) : file_path(file), file_ptr(file)
{
    if (!file_ptr.is_open())
        throw std::runtime_error("Cloud not open file: " + file_path);
}

std::string nts::Parser::trim(const std::string &line)
{
}

bool nts::Parser::is_comment_or_empty(const std::string &line)
{

}

void nts::Parser::parse_chipset_line(const std::string &line)
{

}

void nts::Parser::parse_link_line(const std::string &line)
{

}

void nts::Parser::parse_chipsets()
{

}

void nts::Parser::parse_links()
{

}

void nts::Parser::run_parser()
{

}

nts::Circuit &nts::Parser::getCircuit()
{
    return circuit;
}