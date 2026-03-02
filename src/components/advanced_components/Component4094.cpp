/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Component4094
*/

#include "Component4094.hpp"
#include "IComponent.hpp"

using namespace nts;

Component4094::Component4094()
{
    component_links = {
        {1, InputType},   // STROBE
        {2, InputType},   // DATA
        {3, InputType},   // CLOCK
        {4, OutputType},  // Q0
        {5, OutputType},  // Q1
        {6, OutputType},  // Q2
        {7, OutputType},  // Q3
        {8, UndefinedType},
        {9, OutputType},  // Qs
        {10, OutputType}, // Q'e
        {11, OutputType}, // Q7
        {12, OutputType}, // Q6
        {13, OutputType}, // Q5
        {14, OutputType}, // Q4
        {15, InputType},  // ENABLE
        {16, UndefinedType}
    };
}

void Component4094::simulate(size_t tick)
{
    Tristate clk = getLink(3);
    Tristate stb = getLink(1);
    Tristate data = getLink(2);
    Tristate enable = getLink(15);

    bool risingClock = (_lastClock == False && clk == True);
    bool fallingStrobe = (_lastStrobe == True && stb == False);
    bool fallingClock = (_lastClock == True && clk == False);

    // SHIFT REGISTER UPDATE (positive clock edge)
    if (risingClock) {
        _qs = _shift[7]; // serial output before shifting

        for (int i = 7; i > 0; i--)
            _shift[i] = _shift[i - 1];

        _shift[0] = data;
    }
    // LATCH UPDATE (negative strobe edge)
    if (fallingStrobe) {
        for (int i = 0; i < 8; i++)
            _latch[i] = _shift[i];
    }
    // Q'e update (negative clock edge)
    if (fallingClock)
        _qe = _shift[7];

    _lastClock = clk;
    _lastStrobe = stb;
}

Tristate Component4094::compute(size_t pin)
{
    Tristate enable = getLink(15);

    switch (pin) {
        case 4:  return enable ? _latch[0] : Undefined;
        case 5:  return enable ? _latch[1] : Undefined;
        case 6:  return enable ? _latch[2] : Undefined;
        case 7:  return enable ? _latch[3] : Undefined;
        case 14: return enable ? _latch[4] : Undefined;
        case 13: return enable ? _latch[5] : Undefined;
        case 12: return enable ? _latch[6] : Undefined;
        case 11: return enable ? _latch[7] : Undefined;

        case 9:  return _qs; // serial output
        case 10: return _qe; // latched serial output

        case 1: case 2: case 3: case 15:
            return getLink(pin);
    }

    return Undefined;
}
