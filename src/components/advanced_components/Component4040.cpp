/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Component4040
*/

#include "Component4040.hpp"
#include "IComponent.hpp"

/*
# 12-bits Binary Counter (4040)
#
#      cl_clock -10-+     +-11- in_reset
#                   |     |
#    +------4040----v-----v--------------+
# -8-|-ign   12-bit Binary Counter   ign-|-16-
#    +------v-v-v-v-v-v-v-v-v-v-v-v------+
#           | | | | | | | | | | | |
# out_00 -9-+ | | | | | | | | | | +-1- out_11
#   out_01 -7-+ | | | | | | | | +-15- out_10
#     out_02 -6-+ | | | | | | +-14- out_09
#       out_03 -5-+ | | | | +-12- out_08
#         out_04 -3-+ | | +-13- out_07
#           out_05 -2-+ +-4- out_06

*/

nts::Component4040::Component4040()
{
    component_links = {
        {1, OutputType}, //out_11
        {2, OutputType}, //out_05
        {3, OutputType}, //out_04
        {4, OutputType}, //out_06
        {5, OutputType}, //out_03
        {6, OutputType}, //out_02
        {7, OutputType}, //out_01
        {8, UndefinedType}, //ignored
        {9, OutputType}, //out_00
        {10, InputType}, //cl_clock
        {11, InputType}, //in_reset
        {12, InputType},//out_08
        {13, InputType}, //out_07
        {14, InputType}, //out_09
        {15, InputType}, //out_10
        {16, UndefinedType} //ignored
    };
}

void nts::Component4040::simulate(size_t tick)
{
    //we need to update the counter on the rising edge of the clock, but we also need to update the outputs on every tick since they depend on the counter value
    compute(1); //this will update the outputs based on the current counter value
}


nts::Tristate nts::Component4040::compute(size_t pin)
{
    nts::Tristate clock = compute(10);
    nts::Tristate reset = compute(11);

    if (reset == nts::Tristate::True) {
        counter = 0;
    } else if (clock == nts::Tristate::True && last_clock == nts::Tristate::False) {
        counter = (counter + 1) % 4096; // 12 bits counter
        last_clock = clock;
    }
    //now we calculate the output based on the counter value
    if (pin >= 1 && pin <= 11) {
        //what is goin on here is we find the bit that we need to return (11 - pin) we shit a bit by that number of positions on the counter, and the we do bin and to get a bollean out of that
        return (counter & (1 << (11 - pin))) ? nts::Tristate::True : nts::Tristate::False; //this is a bit hacky but it works, we check if the bit at the position of the pin is 1 or 0 and return true or false accordingly
    } else
        return nts::Tristate::Undefined;
}