/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** OrComponent
*/

#ifndef INCLUDED_ORCOMPONENT_HPP
    #define INCLUDED_ORCOMPONENT_HPP

#include "AComponent.hpp"
#include <iostream>

namespace nts {



class OrComponent : public virtual AComponent
{
    private:
    protected:
    public:
        OrComponent();
        nts :: Tristate compute ( std :: size_t pin ) override;

};
}
#endif
