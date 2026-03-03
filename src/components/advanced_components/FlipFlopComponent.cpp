/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** FlipFlopComponent
*/

#include "FlipFlopComponent.hpp"
#include "IComponent.hpp"

/*
FLIP-FLOP Component (4514)
# 2 outputs 4 inputs

input 1 = Set
input 2 = Data
input 3 = Reset
input 4 = Clock
output 5 = Q
output 6 = Q̅

*/

nts::FlipFlopComponent::FlipFlopComponent()
{
    component_links = {
        {1, InputType}, //set
        {2, InputType}, //data
        {3, InputType}, //reset
        {4, InputType}, //clock
        {5, OutputType}, //Q
        {6, OutputType} //Q̅
    };
}

void nts::FlipFlopComponent::simulate(size_t tick)
{
    compute(5); //we compute Q, which will update the value of Q and Q̅
}

/*
| CL (Clock)       | D | R | S | Q (next)      | Q̅ (next)      |
| ---------------- | - | - | - | ------------- | -------------- |
| ↑ (rising edge)  | 0 | 0 | 0 | 0             | 1              |
| ↑ (rising edge)  | 1 | 0 | 0 | 1             | 0              |
| ↓ (falling edge) | X | 0 | 0 | Q (no change) | Q̅ (no change) |
| X (no edge)      | X | 1 | 0 | 0             | 1              |
| X (no edge)      | X | 0 | 1 | 1             | 0              |
| X (no edge)      | X | 1 | 1 | 1             | 1              |

*/
nts :: Tristate nts::FlipFlopComponent::compute ( std :: size_t pin )
{
    Tristate clock = getLink(4);
    Tristate set = getLink(1);
    Tristate data = getLink(2);
    Tristate reset = getLink(3);
    bool risingEdge = (_lastClock == nts::False && clock == nts::True);


    if (set == Undefined || reset == Undefined)
        return Undefined;

    if (reset == True && set == True) {
        if (pin == 5 || pin == 6) //does this also mean that i have to set Q?
            return True;
        return Undefined; //otherwise just return Undefined since it's an invalid state
    }
    if (reset == True) {
        _Q = False;
        goto end;
    }
    if (set == True) {
        _Q = True;
        goto end;
    }
    //if any of the inputs are undefined, the output is undefined
    if (clock == Undefined || data == Undefined)
        return Undefined;

    _lastClock = clock;

    
    if (!risingEdge) //so falling edge
        goto end; //if it's not a rising edge, we don't change the value of Q

    if (data == True)
        _Q = True;
    else
        _Q = False;

end:
    if (pin == 5)
        return _Q;
    if (pin == 6)
        return !_Q; //Q̅ is the opposite of Q
    return Undefined;
}
