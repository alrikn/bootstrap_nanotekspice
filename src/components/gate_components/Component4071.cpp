/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Component4071
*/

/*
# OR logic gates (4071)
#
#           +---------4071---------+
# in_01  -1-|>-+---\       ignored-|-14-
#           |  | or |-+            |
# in_02  -2-|>-+---/  |     /---+-<|-13- in_13
#           |         |  +-| or |  |
# out_03 -3-|<--------+  |  \---+-<|-12- in_12
#           |            |         |
# out_04 -4-|<--------+  +-------->|-11- out_11
#           |         |            |
# in_05  -5-|>-+---\  |  +-------->|-10- out_10
#           |  | or |-+  |         |
# in_06  -6-|>-+---/     |  /---+-<|-9-  in_09
#           |            +-| or |  |
#        -7-|-ignored       \---+-<|-8-  in_08
#           +----------------------+

*/

#include "Component4071.hpp"
#include "Circuit.hpp"

nts::Component4071::Component4071()
{
    component_links = {
        //or1
        {1, InputType},
        {2, InputType},
        {3, OuputType},
        //or2
        {4, OuputType},
        {5, InputType},
        {6, InputType},
        //ignored
        {7,UndefinedType},
        //or3
        {8, InputType},
        {9, InputType},
        {10, OuputType},
        //or4
        {11, OuputType},
        {12, InputType},
        {13, InputType},
        //ignored
        {14,UndefinedType},
    };

    or1.setLink(1, *this, 1);
    or1.setLink(2, *this, 2);
    or1.setLink(3, *this, 3);

}

nts :: Tristate nts::Component4071::compute ( std :: size_t pin )
{
    if (pin != 3) //the return pin
        return Undefined;
    auto a = getLink(1);
    auto b = getLink(2);

    //most scuffed way of doing or statement, but can't think of anything better
    if (a == Undefined || b == Undefined)
        return Undefined;
    if (a == False && b == False)
        return False;
    return True;
}
