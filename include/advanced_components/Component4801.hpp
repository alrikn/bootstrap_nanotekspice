/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Component4801
*/

#ifndef INCLUDED_COMPONENT4801_HPP
#define INCLUDED_COMPONENT4801_HPP

#include "AComponent.hpp"
#include <cstdint>

namespace nts {

class Component4801 : public virtual AComponent {
private:
    uint8_t _memory[1024];
    int computeAddress();
    Tristate readBit(int addr, int bit);

public:
    Component4801();
    void simulate(size_t tick) override;
    Tristate compute(size_t pin) override;
};

}

#endif
