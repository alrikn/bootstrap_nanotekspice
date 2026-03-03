/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Component4013
*/

/*
# Dual D-Type Flip-Flop (4013)
#
#     cl_1_clock  -3-+
#                    |
#                +---v---+
#                |   |   |
#                | +-v-+ |
#                | |   | |
# in_1_data   -5->-> L | |
#                | | A >->-1-  out_1_q
# in_1_set    -6->-> T | |
#                | | C >->-2-  out_1_qb
# in_1_reset  -4->-> H | |
#                | |   | |
#                | +---+ |
#                |       |
#                | +---+ |
#                | |   | |
# in_2_data   -9->-> L | |
#                | | A >->-13- out_2_q
# in_2_set    -8->-> T | |
#                | | C >->-12- out_2_qb
# in_2_reset -10->-> H | |
#                | |   | |
#                | +-^-+ |
#                |   |   |
#                +---^---+
#                    |
#     cl_2_clock -11-+

*/

#include "Component4013.hpp"
#include "Circuit.hpp"
#include "IComponent.hpp"

nts::Component4013::Component4013()
{
    component_links = {
        {1, OutputType}, //out_1_q
        {2, OutputType}, //out_1_qb
        {3, InputType}, //cl_1_clock
        {4, InputType}, //in_1_reset
        {5, InputType}, //in_1_data
        {6, InputType}, //in_1_set

        {7, UndefinedType}, //ignored

        {8, InputType}, //in_2_set
        {9, InputType}, //in_2_data
        {10, InputType}, //in_2_reset
        {11, InputType}, //cl_2_clock
        {12, OutputType}, //out_2_qb
        {13, OutputType}, //out_2_q
        {14, UndefinedType} //ignored
    };

    /* this is the interior of a flip flop
        {1, InputType}, //set
        {2, InputType}, //data
        {3, InputType}, //reset
        {4, InputType}, //clock
        {5, OutputType}, //Q
        {6, OutputType} //Q̅
    */

    flipFlop1.setLink(1, *this, 6); //set is linked to in_1_set
    flipFlop1.setLink(2, *this, 5); //data is linked to in_1_data
    flipFlop1.setLink(3, *this, 4); //reset is linked to in_1_reset
    flipFlop1.setLink(4, *this, 3); //clock is linked to cl_1_clock
    flipFlop1.setLink(5, *this, 1); //Q is linked to out_1_q
    flipFlop1.setLink(6, *this, 2); //Qb is linked to out_1_qb

    //OR2 -> pins 5,6 -> 4
    flipFlop2.setLink(1, *this, 8);//set is linked to in_2_set
    flipFlop2.setLink(2, *this, 9);//data is linked to in_2_data
    flipFlop2.setLink(3, *this, 10);//reset is linked to in_2_reset
    flipFlop2.setLink(4, *this, 11);//clock is linked to cl_2_clock
    flipFlop2.setLink(5, *this, 13);//Q is linked to out_2_q
    flipFlop2.setLink(6, *this, 12);//Qb is linked to out_2_qb


}

void nts::Component4013::simulate(size_t tick)
{
    flipFlop1.simulate(tick);
    flipFlop2.simulate(tick);
}

nts :: Tristate nts::Component4013::compute ( std :: size_t pin )
{
    switch (pin) {
        //because we are linking the child components together, as they are asking us for intel, on all the inputs, which we provide
        case 3: case 4: case 5: case 6: case 8: case 9: case 10: case 11:
            return getLink(pin);
        case 1:
            return flipFlop1.compute(5); //Q of flip flop 1
        case 2:
            return flipFlop1.compute(6); //Qb of flip flop 1
        case 12:
            return flipFlop2.compute(6); //Qb of flip flop 2
        case 13:
            return flipFlop2.compute(5); //Q of flip flop 2
        default:
            return Undefined;
    }
}
