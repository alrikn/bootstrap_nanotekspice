/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** XxorComponent
*/

#ifndef INCLUDED_XORCOMPONENT_HPP
    #define INCLUDED_XORCOMPONENT_HPP

#include "AComponent.hpp"
#include <iostream>

namespace nts {



class XorComponent : public virtual AComponent
{
    private:
    protected:
    public:
        XorComponent();
        nts :: Tristate compute ( std :: size_t pin ) override;

};
}

#endif
