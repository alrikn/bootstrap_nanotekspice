/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** ClockComponent
*/

#ifndef INCLUDED_CLOCKCOMPONENT_HPP
    #define INCLUDED_CLOCKCOMPONENT_HPP

#include "AComponent.hpp"
#include "ASpecialComponent.hpp"
#include "IComponent.hpp"


namespace nts {

class ClockComponent  : public virtual ASpecialComponent
{
    private:
    protected:
    public:
        //ClockComponent();
        //~ClockComponent() = default;
        void simulate(size_t tick) override;
        ClockComponent();
        nts :: Tristate compute ( std :: size_t pin ) override;

};
}
#endif
