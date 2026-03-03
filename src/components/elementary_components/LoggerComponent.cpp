/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Logger
*/

/*
# Byte Logger Component
#
#           +-Logger-+
#           |        |
# in_001 -1->        |
#           |        |
# in_002 -2->        |
#           |        |
# in_004 -3->        |
#           |        |
# in_008 -4->        |
#           |        |
# in_016 -5->        |
#           |        |
# in_032 -6->        |
#           |        |
# in_064 -7->        |
#           |        |
# in_128 -8->        |
#           |        |
#           +-^----^-+
#             |    |
#    clock -9-+    +-10- inhibit

.chipsets:
input in_001
input in_002
input in_004
input in_008
input in_016
input in_032
input in_064
input in_128
clock clock
input inhibit
logger logger

.links:
in_001:1 logger:1
in_002:1 logger:2
in_004:1 logger:3
in_008:1 logger:4
in_016:1 logger:5
in_032:1 logger:6
in_064:1 logger:7
in_128:1 logger:8
clock:1 logger:9
inhibit:1 logger:10
*/



#include "LoggerComponent.hpp"
#include "IComponent.hpp"

#include <fstream> // for std::ofstream used in compute()

//You must also implement the logger component. It appends the character computed from its inputs to the
//file ./log.bin on the positive-going edge of the clock when inhibit is false. More details in the provided NTS
//files.
nts::LoggerComponent::LoggerComponent()
{
    component_links = {
        {1, InputType},
        {2, InputType},
        {3, InputType},
        {4, InputType},
        {5, InputType},
        {6, InputType},
        {7, InputType},
        {8, InputType},
        {9, InputType},
        {10, InputType},
    };
}


void nts::LoggerComponent::simulate(size_t tick)
{
    compute(0);
}

//rising edge means that prevoius was false and now its true
nts :: Tristate nts::LoggerComponent::compute(size_t pin)
{
    if (pin != 0) //it means smth is not right and it isn't our simulate thats calling us
        return Undefined;

    nts::Tristate clock = getLink(9);
    nts::Tristate inhibit = getLink(10);

    //if last was false and now its true the rising edfe
    bool risingEdge = (_lastClock == nts::False && clock == nts::True);
    _lastClock = clock;

    if (!risingEdge || inhibit == nts::True) //if it's not a rising edge or if inhibit is true, we do nothing
        return Undefined;

    //data inputs () to avoid huge if statement detecting if each and everyone of them has an undefined
    nts::Tristate inputs[8] = {
        getLink(1), getLink(2), getLink(3), getLink(4),
        getLink(5), getLink(6), getLink(7), getLink(8)
    };
    //check for undefined
    for (auto v : inputs) {
        if (v == nts::Undefined)
            return Undefined;
    }

    //build the byte
    unsigned char value = 0;
    for (int i = 0; i < 8; i++) {
        if (inputs[i] == nts::True)
            value |= (1 << i);
    }

    //we append to file ()no idea how it works, but this works
    std::ofstream file("./log.bin", std::ios::binary | std::ios::app);
    file.write(reinterpret_cast<char*>(&value), 1);
    return Undefined; //because our output is in a file, we don't care about the actual return value
}

