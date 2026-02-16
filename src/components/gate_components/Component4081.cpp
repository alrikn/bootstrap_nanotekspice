/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Component4081
*/

/*
#           +---------4081---------+
# in_01  -1-|>-+---\       ignored-|-14-
#           |  | &  |-+            |
# in_02  -2-|>-+---/  |     /---+-<|-13- in_13
#           |         |  +-|  & |  |
# out_03 -3-|<--------+  |  \---+-<|-12- in_12
#           |            |         |
# out_04 -4-|<--------+  +-------->|-11- out_11
#           |         |            |
# in_05  -5-|>-+---\  |  +-------->|-10- out_10
#           |  | &  |-+  |         |
# in_06  -6-|>-+---/     |  /---+-<|-9-  in_09
#           |            +-|  & |  |
#        -7-|-ignored       \---+-<|-8-  in_08
#           +----------------------+
*/



#include "Component4081.hpp"
#include "Circuit.hpp"

nts::Component4081::Component4081()
{
    component_links = {
        //and1
        {1, InputType},{2, InputType},{3, OuputType},
        //and2
        {4, OuputType},{5, InputType},{6, InputType},
        //ignored
        {7,UndefinedType},
        //and3
        {8, InputType},{9, InputType},{10, OuputType},
        //and4
        {11, OuputType},{12, InputType},{13, InputType},
        //ignored
        {14,UndefinedType},
    };

    and1.setLink(1, *this, 1);
    and1.setLink(2, *this, 2);
    and1.setLink(3, *this, 3); //the outputs are technically useless

    //AND2 -> pins 5,6 -> 4
    and2.setLink(1, *this, 5);
    and2.setLink(2, *this, 6);
    and2.setLink(3, *this, 4);

    //AND3 -> pins 8,9 -> 10
    and3.setLink(1, *this, 8);
    and3.setLink(2, *this, 9);
    and3.setLink(3, *this, 10);

    //AND4 -> pins 12,13 -> 11
    and4.setLink(1, *this, 12);
    and4.setLink(2, *this, 13);
    and4.setLink(3, *this, 11);

}

nts :: Tristate nts::Component4081::compute ( std :: size_t pin )
{
    switch (pin) {
        case 3:
            return and1.compute(3);
        case 4:
            return and2.compute(3);
        case 10:
            return and3.compute(3);
        case 11:
            return and4.compute(3);
        default:
            return Undefined;
    }
}
