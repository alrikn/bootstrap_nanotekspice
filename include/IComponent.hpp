/*
** EPITECH PROJECT, 2026
** bootstrap_nanotekspice
** File description:
** Icomponent
** do not touch this file, it is already perfect
*/

#ifndef INCLUDED_ICOMPONENT_HPP
    #define INCLUDED_ICOMPONENT_HPP

#include <iostream>

namespace nts
{
enum Tristate {
    Undefined = (- true ) ,
    True = true ,
    False = false
};

enum PinType { //primes (cus if u add up any with each other or with itself its a unique val)
    InputType = 1, //can only be connected to a single output
    OuputType = 3, //can only be connect to one or more input
    LogOutputType = 5, //this is a special case and needs to be handled carefully
    UndefinedType = 7
};

class IComponent
{
    public :
        virtual ~IComponent () = default ;
        virtual void simulate ( std :: size_t tick ) = 0;
        virtual nts :: Tristate compute ( std :: size_t pin ) = 0;
        virtual void setLink ( std :: size_t pin , nts :: IComponent & other , std :: size_t otherPin ) = 0;
        virtual nts::PinType get_type(std::size_t pin) = 0; //necssary for the parser
};
}
#endif
