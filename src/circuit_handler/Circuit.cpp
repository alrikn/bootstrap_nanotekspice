/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Circuit
*/

#include "Circuit.hpp"
#include "HashMapCache.hpp"

namespace nts {



void Circuit::addComponent(std::string name, std::unique_ptr<IComponent> c, Class_type type)
{
    if (components.count(name) >= 1)
        throw std::runtime_error("Component already exists");
    components[name] = {std::move(c), type}; //uniqueptr can only be moved not copied
}

std::unique_ptr<IComponent> &Circuit::getComponent(std::string const &name)
{
    if (components.count(name) == 0)
        raise(3); //placeholder until we find real error
    return components[name].component;
}

void Circuit::simulate(std::size_t tick) { // there should probably be an order of execution
    g_current_tick = tick;
    for (auto &c : components)
        c.second.component->simulate(tick);
}

Class_type Circuit::getType(const std::string& name)
{
    return components.at(name).type;
}


    }
