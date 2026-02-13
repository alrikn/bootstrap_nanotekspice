/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** TrueComponent
*/

#include "TrueComponent.hpp"



nts :: Tristate nts::TrueComponent::compute ( std :: size_t pin )
{
    if (pin != 1) //return pin
        return Undefined;
    return True;
}