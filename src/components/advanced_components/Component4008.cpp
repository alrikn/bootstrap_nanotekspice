/*
** EPITECH PROJECT, 2026
** nanotekspice
** File description:
** Component4008
*/

#include "Component4008.hpp"
#include "IComponent.hpp"

/*
# 4-bits Adder (4008)
#
#                  +-14- out_c
#                  |
#           +-4008-^------+
#           |      |      |
# in_b4 -15->---+--^--+   |
#           |   | sum |--->-13- out_3
# in_a4  -1->---+--+--+   |
#           |      |   C4 |
# in_b3  -2->---+--^--+   |
#           |   | sum |--->-12- out_2
# in_a3  -3->---+--+--+   |
#           |      |   C3 |
# in_b2  -4->---+--^--+   |
#           |   | sum |--->-11- out_1
# in_a2  -5->---+--+--+   |
#           |      |   C2 |
# in_b1  -6->---+--^--+   |
#           |   | sum |--->-10- out_0
# in_a1  -7->---+--+--+   |
#           |      |      |
# in_c   -9->------+  C1    |
#           |             |
#        -8-+- ign   ign -+-16-
#           |             |
#           +-------------+
*/

nts::Component4008::Component4008()
{
    component_links = {
        {1, InputType},//a4
        {2, InputType},//b3
        {3, InputType},//a3
        {4, InputType},//b2
        {5, InputType},//a2
        {6, InputType},//b1
        {7, InputType},//a1
        {8, UndefinedType}, //ignored
        {9, InputType},//carry in (whatever that means)
        {10, OutputType}, //s1
        {11, OutputType}, //s2
        {12, OutputType}, //s3
        {13, OutputType}, //s4
        {14, OutputType},//C0
        {15, InputType},//b4
        {16, UndefinedType}, //ignored


    };
}

/*
# 4-bits Adder (4008)
    Ai  |   Bi  |   Ci  |   C0  |   SUM
    0   |   0   |   0   |   0   |   0
    1   |   0   |   0   |   0   |   1
    0   |   1   |   0   |   0   |   1
    1   |   1   |   0   |   1   |   0
    0   |   0   |   1   |   0   |   1
    1   |   0   |   1   |   1   |   0
    0   |   1   |   1   |   1   |   0
    1   |   1   |   1   |   1   |   1

    //an addition in binary works like this:
    //0 + 0 = 0
    //0 + 1 = 1
    //1 + 0 = 1
    //1 + 1 = 0 with a carry of 1 to the next bit

    howver in practice we also have to take into account the carry in of the prevoius op.
    a + b + carry in = sum with a carry out to the next operation

    0 + 0 + 0 = 0 with a carry of 0
    0 + 0 + 1 = 1 with a carry of 0
    0 + 1 + 0 = 1 with a carry of 0
    0 + 1 + 1 = 0 with a carry of 1
    1 + 0 + 0 = 1 with a carry of 0
    1 + 0 + 1 = 0 with a carry of 1
    1 + 1 + 0 = 0 with a carry of 1
    1 + 1 + 1 = 1 with a carry of 1
*/
nts :: Tristate nts::Component4008::compute ( std :: size_t pin )
{
    if (pin < 10 || pin > 14) //if not return pin exit with undefined
        return Undefined;
    Tristate A1 = getLink(7);
    Tristate B1 = getLink(6);
    Tristate A2 = getLink(5);
    Tristate B2 = getLink(4);
    Tristate A3 = getLink(3);
    Tristate B3 = getLink(2);
    Tristate A4 = getLink(1);
    Tristate B4 = getLink(15);
    Tristate Cin = getLink(9);
    //TODO: find a way to check if one of the inputs is undefined without doing a huge if statement
    if (A1 == Undefined || B1 == Undefined ||
        A2 == Undefined || B2 == Undefined ||
        A3 == Undefined || B3 == Undefined ||
        A4 == Undefined || B4 == Undefined || Cin == Undefined)
        return Undefined;

    bool a1 = (A1 == True); //to make operations easier
    bool b1 = (B1 == True); //to make operations easier
    bool a2 = (A2 == True); //to make operations easier
    bool b2 = (B2 == True); //to make operations easier
    bool a3 = (A3 == True); //to make operations easier
    bool b3 = (B3 == True); //to make operations easier
    bool a4 = (A4 == True); //to make operations easier
    bool b4 = (B4 == True); //to make operations easier
    bool cin = (Cin == True); //to make operations easier

    bool carry = cin;

    int total;

    total = a1 + b1 + carry;
    bool s1 = total % 2;
    carry = total / 2;

    total = a2 + b2 + carry;
    bool s2 = total % 2;
    carry = total / 2;

    total = a3 + b3 + carry;
    bool s3 = total % 2;
    carry = total / 2;

    total = a4 + b4 + carry;
    bool s4 = total % 2;
    bool cout = total / 2;

    switch (pin) {
        case 10: return s1 ? True : False;
        case 11: return s2 ? True : False;
        case 12: return s3 ? True : False;
        case 13: return s4 ? True : False;
        case 14: return cout ? True : False;
    }
    return Undefined;
}
