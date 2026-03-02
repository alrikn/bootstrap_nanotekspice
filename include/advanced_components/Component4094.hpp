/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Component4094
*/

#ifndef INCLUDED_COMPONENT4094_HPP
#define INCLUDED_COMPONENT4094_HPP

#include "AComponent.hpp"

namespace nts {

class Component4094 : public virtual AComponent {
private:
    Tristate _lastClock = False;
    Tristate _lastStrobe = False;

    Tristate _shift[8] = {Undefined};
    Tristate _latch[8] = {Undefined};

    Tristate _qs = Undefined;   // serial output
    Tristate _qe = Undefined;   // latched serial output

public:
    Component4094();
    void simulate(size_t tick) override;
    Tristate compute(size_t pin) override;
};

}

#endif
