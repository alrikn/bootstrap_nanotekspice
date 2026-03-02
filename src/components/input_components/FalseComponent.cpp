/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** FalseComponent
*/

#include "FalseComponent.hpp"
#include "Circuit.hpp"

nts::FalseComponent::FalseComponent()
{
    component_links = {
        {1, OutputType},
    };
}

nts :: Tristate nts::FalseComponent::compute ( std :: size_t pin )
{
    if (pin != 1) //return pin
        return Undefined;
    return False;
}
