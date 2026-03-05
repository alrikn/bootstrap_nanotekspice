/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Factory
*/

#ifndef INCLUDED_FACTORY_HPP
    #define INCLUDED_FACTORY_HPP

#include "Circuit.hpp"
#include "IComponent.hpp"
#include <functional>
#include <unordered_map>

//input components
#include "TrueComponent.hpp"
#include "FalseComponent.hpp"
#include "UserInputComponent.hpp"
#include "UserOutputComponent.hpp"
#include "ClockComponent.hpp"

//elementary components
#include "AndComponent.hpp"
#include "LoggerComponent.hpp"
#include "XorComponent.hpp"
#include "NotComponent.hpp"


//gate components

#include "Component4001.hpp"
#include "Component4011.hpp"
#include "Component4030.hpp"
#include "Component4069.hpp"
#include "Component4071.hpp"
#include "Component4081.hpp"

//advanced
#include "Component4008.hpp"
#include "Component4512.hpp"
#include "Component4013.hpp"
#include "FlipFlopComponent.hpp"
#include "Component4040.hpp"
#include "Component2716.hpp"


namespace nts {
class Factory
{
    private:

        // 'using' -> alias for complex type
    using Pair = std::pair<std::unique_ptr<nts::IComponent>, nts::ClassType>;

    //FILL W/ REST OF COMPONENTS!!!!
    //TODO put all of this in a hpp file, there is no good reason that this should come clutter our code
    static inline const std::unordered_map<std::string, std::function<Pair()>> factory = {
        //inputs
        {"input", []() { return Pair(std::unique_ptr<nts::IComponent>(new nts::UserInputComponent()), nts::InDisplayComponent); }},
        {"output", []() { return Pair(std::unique_ptr<nts::IComponent>(new nts::UserOutputComponent()), nts::OutDisplayComponent); }},
        {"true", []() { return Pair(std::unique_ptr<nts::IComponent>(new nts::TrueComponent()), nts::InDisplayComponent); }},
        {"false", []() { return Pair(std::unique_ptr<nts::IComponent>(new nts::FalseComponent()), nts::InDisplayComponent); }},
        {"clock", []() { return Pair(std::unique_ptr<nts::IComponent>(new nts::ClockComponent()), nts::InDisplayComponent); }},

        //elementary components
        {"and", []() { return Pair(std::unique_ptr<nts::IComponent>(new nts::AndComponent()), nts::NormalComponent); }},
        {"or", []() { return Pair(std::unique_ptr<nts::IComponent>(new nts::OrComponent()), nts::NormalComponent); }},
        {"xor", []() { return Pair(std::unique_ptr<nts::IComponent>(new nts::XorComponent()), nts::NormalComponent); }},
        {"not", []() { return Pair(std::unique_ptr<nts::IComponent>(new nts::NotComponent()), nts::NormalComponent); }},
        {"logger", []() { return Pair(std::unique_ptr<nts::IComponent>(new nts::LoggerComponent()), nts::NormalComponent); }},
        //gate components
        {"4001", []() { return Pair(std::unique_ptr<nts::IComponent>(new nts::Component4001()), nts::NormalComponent); }},
        {"4011", []() { return Pair(std::unique_ptr<nts::IComponent>(new nts::Component4011()), nts::NormalComponent); }},
        {"4030", []() { return Pair(std::unique_ptr<nts::IComponent>(new nts::Component4030()), nts::NormalComponent); }},
        {"4069", []() { return Pair(std::unique_ptr<nts::IComponent>(new nts::Component4069()), nts::NormalComponent); }},
        {"4071", []() { return Pair(std::unique_ptr<nts::IComponent>(new nts::Component4071()), nts::NormalComponent); }},
        {"4081", []() { return Pair(std::unique_ptr<nts::IComponent>(new nts::Component4081()), nts::NormalComponent); }},
        //advanced components
        {"4008", []() { return Pair(std::unique_ptr<nts::IComponent>(new nts::Component4008()), nts::NormalComponent); }},
        {"4512", []() { return Pair(std::unique_ptr<nts::IComponent>(new nts::Component4512()), nts::NormalComponent); }},
        {"4013", []() { return Pair(std::unique_ptr<nts::IComponent>(new nts::Component4013()), nts::NormalComponent); }},
        {"flipflop", []() { return Pair(std::unique_ptr<nts::IComponent>(new nts::FlipFlopComponent()), nts::NormalComponent); }}, //tchnically not an obligatory component but since its used in 4013, might as well add it to the factory
        {"4040", []() { return Pair(std::unique_ptr<nts::IComponent>(new nts::Component4040()), nts::NormalComponent); }},
        {"2716", []() { return Pair(std::unique_ptr<nts::IComponent>(new nts::Component2716()), nts::NormalComponent); }},
    };
    public:
    static Pair create(const std::string &type)
    {
        auto it = factory.find(type);

        if (it == factory.end())
            throw std::runtime_error("Unknown component type '" + type + "'");

        return it->second();
    }
};
}


#endif
