/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** UserInputComponent
*/


#include "UserInputComponent.hpp"
#include "Circuit.hpp"
#include "IComponent.hpp"


nts::UserInputComponent::UserInputComponent()
{
    component_links = {{1, OutputType}};
}

//Simulate overwrites the Acomponent simulate, and directly calls compute 1 on itself
//Noraml simulate just calls getlink on the input
//since we need the entire component to run and update itself for the display (this will be the same thing for Logger and possibly UserInput)
void nts::UserInputComponent::simulate(size_t tick)
{
    compute(1);
}

nts :: Tristate nts::UserInputComponent::compute(size_t pin)
{
    display_value = real_value;
    if (pin == 1)
        return real_value;
    return Undefined;
}
