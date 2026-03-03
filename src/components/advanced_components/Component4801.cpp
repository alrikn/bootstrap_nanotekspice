/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Component4801
*/

#include "Component4801.hpp"
#include "IComponent.hpp"

using namespace nts;

Component4801::Component4801()
{
    for (int i = 0; i < 1024; i++)
        _memory[i] = 0;

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

        {18, InputType}, // CE
        {21, InputType}, // WE
        {20, InputType}, // OE

        // InputType so that we can use getLink()
        {9,  InputType},
        {10, InputType},
        {11, InputType},
        {13, InputType},
        {14, InputType},
        {15, InputType},
        {16, InputType},
        {17, InputType},
    };
}

int Component4801::computeAddress()
{
    Tristate a[10] = {
        getLink(8), getLink(7), getLink(6), getLink(5), getLink(4),
        getLink(3), getLink(2), getLink(1), getLink(23), getLink(22)
    };

    for (int i = 0; i < 10; i++)
        if (a[i] == Undefined)
            return -1;

    int addr = 0;
    for (int i = 0; i < 10; i++)
        if (a[i] == True)
            addr |= (1 << i);

    return addr;
}

void Component4801::simulate(size_t tick)
{
    Tristate CE = getLink(18);
    Tristate WE = getLink(21);

    if (CE == True || WE == True)
        return;

    int addr = computeAddress();
    if (addr < 0)
        return;

    uint8_t value = 0;
    int pins[8] = {9,10,11,13,14,15,16,17};

    for (int i = 0; i < 8; i++) {
        Tristate b = getLink(pins[i]);
        if (b == Undefined)
            return;
        if (b == True)
            value |= (1 << i);
    }

    _memory[addr] = value;
}

Tristate Component4801::compute(size_t pin)
{
    int bitIndex = -1;
    int pins[8] = {9,10,11,13,14,15,16,17};

    for (int i = 0; i < 8; i++)
        if (pin == pins[i])
            bitIndex = i;

    if (bitIndex == -1)
        return getLink(pin);

    Tristate CE = getLink(18);
    Tristate WE = getLink(21);
    Tristate OE = getLink(20);

    if (CE == True || WE == False || OE == True)
        return Undefined;

    int addr = computeAddress();
    if (addr < 0)
        return Undefined;

    return ((_memory[addr] >> bitIndex) & 1) ? True : False;
}
