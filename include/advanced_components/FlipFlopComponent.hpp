/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** FlipFlopComponent
*/

#ifndef INCLUDED_FLIPFLOPCOMPONENT_HPP
    #define INCLUDED_FLIPFLOPCOMPONENT_HPP

#include "AComponent.hpp"
#include "IComponent.hpp"

namespace nts {


class FlipFlopComponent : public virtual AComponent
{
    private:
        //should this start as undef? TODO: figure out
        Tristate _lastClock = False; //to detect rising edge
        Tristate _Q = Undefined; //initial value of Q
    protected:
    public:
        //the FLIPFLOP component should always be updated, even if it isn't aclled by another component, since it needs to update itself on the rising edge of the clock, so we need to overwrite simulate as well
        void simulate(size_t tick) override;
        FlipFlopComponent();
        nts :: Tristate compute ( std :: size_t pin ) override;

};
}
#endif
