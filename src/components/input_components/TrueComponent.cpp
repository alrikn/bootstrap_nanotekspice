/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** TrueComponent
*/

#include "TrueComponent.hpp"

nts::TrueComponent::TrueComponent()
{
    component_links = {
        {1, OutputType},
    };
}

nts :: Tristate nts::TrueComponent::compute ( std :: size_t pin )
{
    if (pin != 1) //return pin
        return Undefined;
    return True;
}