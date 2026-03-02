/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Component4008
*/

#ifndef INCLUDED_COMPONENT4008_HPP
    #define INCLUDED_COMPONENT4008_HPP

#include "AComponent.hpp"
#include "IComponent.hpp"

namespace nts {


class Component4008 : public virtual AComponent
{
    private:
    protected:
    public:
        Component4008();
        nts :: Tristate compute ( std :: size_t pin ) override;

};
}
#endif
