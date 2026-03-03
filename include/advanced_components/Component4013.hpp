/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Component4013
*/

#ifndef INCLUDED_COMPONENT4013_HPP
    #define INCLUDED_COMPONENT4013_HPP

#include "AComponent.hpp"
#include "FlipFlopComponent.hpp"

namespace nts {



class Component4013 : public virtual AComponent
{
    private:
    protected:
        FlipFlopComponent flipFlop1;
        FlipFlopComponent flipFlop2;
    public:
        Component4013();
        void simulate(size_t tick) override; //we need to overwrite simulate since we need to update the flipflops even if they aren't called by another component, since they need to update themselves on the rising edge of the clock
        nts :: Tristate compute ( std :: size_t pin ) override;

};
}
#endif
