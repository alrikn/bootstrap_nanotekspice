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
    component_links = {{1, OuputType}};
}

//Simulate overwrites the Acomponent simulate, and directly calls compute 1 on itself
//Noraml simulate just calls getlink on the input
//since we need the entire component to run and update itself for the display (this will be the same thing for Logger and possibly UserInput)
void nts::ClockComponent::simulate(size_t tick)
{
    compute(1); //because on first call of sim ulate it must return the one it showed
    if (real_value != Undefined) {
        if (real_value == True)
            real_value = False;
        else
            real_value = True;
    }
}

nts :: Tristate nts::ClockComponent::compute(size_t pin)
{
    display_value = real_value;
    if (pin == 1)
        return real_value;
    return Undefined;
}
