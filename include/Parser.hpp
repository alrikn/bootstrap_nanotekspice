/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Parser
*/

#ifndef INCLUDED_PARSER_HPP
    #define INCLUDED_PARSER_HPP

#include "Circuit.hpp"
#include <fstream>
#include <sstream>
#include <string>
namespace nts {

class Parser
{
    private:
    protected:
        Circuit circuit;

        bool found_links = false;
        bool found_chipsets = false;

        std::string file_path;
        std::ifstream file_ptr;

        std::string trim(const std::string &line);
        bool is_comment_or_empty(const std::string &line);

        // parse lines
        void parse_chipset_line(const std::string &line);
        void parse_link_line(const std::string &line);

        // sections
        void parse_chipsets();
        void parse_links();


    public:
        Parser(const std::string& file);
        void run_parser();

        //built circuit
        Circuit &getCircuit();

        ~Parser() = default;

};
}

#endif
