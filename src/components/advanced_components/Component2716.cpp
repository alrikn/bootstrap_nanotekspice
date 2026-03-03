/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Component2716
*/

#include "Component2716.hpp"
#include "IComponent.hpp"
#include <fstream>

using namespace nts;

Component2716::Component2716()
{
    // Load ROM from file
    std::ifstream f("rom.bin", std::ios::binary);
    if (f.good())
        f.read(reinterpret_cast<char*>(_rom), 2048);
    else
        for (int i = 0; i < 2048; i++)
            _rom[i] = 0xFF; // erased EPROM = all 1s

    component_links = {
        {1, InputType},  // A7
        {2, InputType},  // A6
        {3, InputType},  // A5
        {4, InputType},  // A4
        {5, InputType},  // A3
        {6, InputType},  // A2
        {7, InputType},  // A1
        {8, InputType},  // A0
        {23, InputType}, // A8
        {22, InputType}, // A9
        {19, InputType}, // A10

        {18, InputType}, // CE
        {20, InputType}, // OE

        {9,  OutputType},
        {10, OutputType},
        {11, OutputType},
        {13, OutputType},
        {14, OutputType},
        {15, OutputType},
        {16, OutputType},
        {17, OutputType},
    };
}

int Component2716::computeAddress()
{
    Tristate a[11] = {
        getLink(8), getLink(7), getLink(6), getLink(5), getLink(4),
        getLink(3), getLink(2), getLink(1), getLink(23), getLink(22),
        getLink(19)
    };

    for (int i = 0; i < 11; i++)
        if (a[i] == Undefined)
            return -1;

    int addr = 0;
    for (int i = 0; i < 11; i++)
        if (a[i] == True)
            addr |= (1 << i);

    return addr;
}

void Component2716::simulate(size_t tick)
{
    // ROM is static, nothing to simulate
}

Tristate Component2716::compute(size_t pin)
{
    int bitIndex = -1;
    int pins[8] = {9,10,11,13,14,15,16,17};

    for (int i = 0; i < 8; i++)
        if (pin == pins[i])
            bitIndex = i;

    if (bitIndex == -1)
        return getLink(pin);

    Tristate CE = getLink(18);
    Tristate OE = getLink(20);

    if (CE == True || OE == True)
        return Undefined;

    int addr = computeAddress();
    if (addr < 0)
        return Undefined;

    uint8_t value = _rom[addr];
    return ((value >> bitIndex) & 1) ? True : False;
}
