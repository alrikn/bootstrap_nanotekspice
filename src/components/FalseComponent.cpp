/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** FalseComponent
*/

#include "FalseComponent.hpp"


nts :: Tristate nts::FalseComponent::compute ( std :: size_t pin )
{
    if (pin != 1) //return pin
        return Undefined;
    return False;
}
