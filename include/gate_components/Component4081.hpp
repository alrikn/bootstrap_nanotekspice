/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Component4081
*/

#ifndef INCLUDED_COMPONENT4081_HPP
    #define INCLUDED_COMPONENT4081_HPP

#include "AComponent.hpp"
#include "AndComponent.hpp"


namespace nts {



class Component4081 : public virtual AComponent
{
    private:
    protected:
        AndComponent and1;
        AndComponent and2;
        AndComponent and3;
        AndComponent and4;
    public:
        Component4081();
        nts :: Tristate compute ( std :: size_t pin ) override;

};
}
#endif
