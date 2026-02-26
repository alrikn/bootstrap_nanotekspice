/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** CLI_interface
*/

#ifndef INCLUDED_CLI_INTERFACE_HPP
    #define INCLUDED_CLI_INTERFACE_HPP

#include "Circuit.hpp"

enum CmdType {
    Exit,
    Simulate,
    Display,
    Assignment,
    Unknown
};


class CLI_interface
{
    private:
        long long tick = 0;
    protected:
    public:

        nts::Circuit *_circuit = nullptr;
        CLI_interface() = default;

        ~CLI_interface() = default;

        CmdType type = CmdType::Unknown;
        std::string lhs; // for assignment: name
        std::string rhs; // for assignment: value

        void parse_command(const std::string &raw_line);
        int run_loop(nts::Circuit &circuit);

        bool handle_display();
        bool handle_simulate();
        bool handle_assignment();
        bool handle_exit();

};


#endif
