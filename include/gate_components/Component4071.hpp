/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Component4071
*/

#ifndef INCLUDED_COMPONENT4071_HPP
    #define INCLUDED_COMPONENT4071_HPP


#include "AComponent.hpp"
#include "OrComponent.hpp"
#include <iostream>

namespace nts {



class Component4071 : public virtual AComponent
{
    private:
    protected:
        OrComponent or1;
        OrComponent or2;
        OrComponent or3;
        OrComponent or4;
    public:
        Component4071();
        nts :: Tristate compute ( std :: size_t pin ) override;

};
}
#endif
