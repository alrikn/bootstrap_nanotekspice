/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** AComponent
*/

#include "AComponent.hpp"
#include "Circuit.hpp"
#include "HashMapCache.hpp"
#include "IComponent.hpp"
#include <cstddef>
#include <stdexcept>

// the logger may have to overwrite this
void nts::AComponent::simulate(size_t tick)
{
    for (std::pair<const unsigned long, nts::PinType> link_type : component_links) {
        if (link_type.second == InputType)
            getLink(link_type.first);
    }
}

//set da link
void nts::AComponent::setLink(size_t pin, nts::IComponent &other, size_t otherPin)
{
    //TODO: you should be able to connect may input pins to a single output
    //this means than an output may be linked to multiple inputs, but an input may only be linked to a single output.

    //if (get_type(pin) == InputType && other.get_type(otherPin) == InputType) { //this will throw an error (cus of the gates so the check has to be done in parser)
    PinType myType = get_type(pin);

    if (myType == UndefinedType)
        throw std::runtime_error("Attempting to link undefined pin type");

    auto &vec = _links[pin]; //list of links connected to pin

    if (myType == InputType) {
        //input can only have one source. howvere since how the gates work, if the same types tries to get added, we say okey
        if (!vec.empty()) { //input already connected to smth
            if (vec.front().component == &other && vec.front().pin == otherPin)
                return; //avoid connect same pin twice
            throw std::runtime_error("Input pin already connected");
        }
        vec.push_back({&other, otherPin});
        return;
    }


    if (myType == OutputType) {
        //since output can have many dest, we'll avoid duplicate entries
        for (const auto &l : vec)
            if (l.component == &other && l.pin == otherPin)
                return;
        vec.push_back({&other, otherPin});
        return;
    }
    //default behaviou
    for (const auto &l : vec)
        if (l.component == &other && l.pin == otherPin)
            return;
    vec.push_back({&other, otherPin});

}

nts::Tristate nts::AComponent::getLink(size_t pin)
{
    //theortically, getlink can only be called on input pins
    if (get_type(pin) != InputType) {
        throw std::runtime_error("Smth strange is goin on, you are requesting from an output");
        return Undefined;
    }
    auto it = _links.find(pin);
    if (it == _links.end() || it->second.empty())
        return Undefined; //check if list is emty

    const Link &da_link = it->second.front();
    if (da_link.component == nullptr)
        return Undefined;

    return compute_hashmap(da_link.component, da_link.pin); //compute takes as an input the supposed return pin
}

nts::PinType nts::AComponent::get_type(size_t pin)
{
    if (component_links.count(pin) == 0)
        return UndefinedType;
    return component_links[pin];
}

//this will be default behaviour
nts::Tristate nts::AComponent::compute(std::size_t pin)
{
    return getLink(pin);
}
