/*
** EPITECH PROJECT, 2026
** bootstrap_nanotekspice
** File description:
** Circuit
*/

#ifndef INCLUDED_CIRCUIT_HPP
    #define INCLUDED_CIRCUIT_HPP

#include <csignal>
#include <memory>
#include "IComponent.hpp"
#include <map>


namespace nts {

enum Class_type { //primes (cus if u add up any with each other or with itself its a unique val)
    InputType = 1, //can only be connected to output or clock
    OuputType = 3, //can only be connect to any input and UserOutputTypes
    UserOutputType = 5, //user outputs that will be shown on display (so the output keyword)
    UserInputType = 7, //the special inputs that require no connection like clock or the special input but still require cli intervention
    PureInputType = 11, //False and True, who bothe require no connection and are always set specifically
    UndefinedType = 13
};

const auto possible_combinations = { //there is probably a better way but it is late and i am tired
    OuputType + InputType, //normal input + normal output
    OuputType + UserOutputType, //normal output + user output
    UserInputType + InputType,
    UserInputType + UserOutputType,
    PureInputType + InputType,
    PureInputType + UserOutputType,

};

struct ComponentEntry {
    std::unique_ptr<IComponent> component;
    Class_type type;
};

class Circuit {
    private:
        std::map<std::string, ComponentEntry> components;
    public:
        void addComponent(std::string name, std::unique_ptr<IComponent> c, Class_type type);
        std::unique_ptr<IComponent> &getComponent(std::string const &name);

        void simulate(std::size_t tick);

        Class_type getType(const std::string& name);


        //void display();

};
}

#endif
