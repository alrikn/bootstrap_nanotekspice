/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** ClockComponent
*/

#include "ClockComponent.hpp"
#include "Circuit.hpp"
#include "IComponent.hpp"


nts::ClockComponent::ClockComponent()
{
    component_links = {{1, OutputType}};
}

//Simulate overwrites the Acomponent simulate, and directly calls compute 1 on itself
//Noraml simulate just calls getlink on the input
//since we need the entire component to run and update itself for the display (this will be the same thing for Logger and possibly UserInput)
void nts::ClockComponent::simulate(size_t tick)
{
    if (tick == last_tick)
        return;

    last_tick = tick;

    //we update the one on previous tick
    display_value = real_value;

    //we toggle the value for the next tick, but if it was undefined we keep it undefined
    if (real_value != nts::Undefined) {
        real_value = (real_value == nts::True) ? nts::False : nts::True;
    }
}

nts :: Tristate nts::ClockComponent::compute(size_t pin)
{
    if (pin == 1)
        return display_value;
    return nts::Undefined;
}
