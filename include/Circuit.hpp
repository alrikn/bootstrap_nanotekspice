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


const int valid_pin_combination = OutputType + InputType; //normal input + normal output


enum ClassType {
    NormalComponent,
    ClockComponentDisplay, //i am not sure this one has good reason to be here? we might need to remove it.
    InDisplayComponent, //what we show on the display, no special treatement needed
    OutDisplayComponent, //what we show on the display, it needs special tretement, (class needs to overwrite simulate)
};

struct ComponentEntry {
    std::unique_ptr<IComponent> component;
    ClassType type;
};

class Circuit {
    private:
        std::map<std::string, ComponentEntry> components;
    public:
        Circuit() = default;
        ~Circuit() = default;
        void addComponent(std::string name, std::unique_ptr<IComponent> c, ClassType type);
        std::unique_ptr<IComponent> &getComponent(std::string const &name);

        void simulate(std::size_t tick);

        ClassType getType(const std::string& name);


        void display();

};
}

#endif
