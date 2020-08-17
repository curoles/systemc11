/**@file
 * @brief     NAND gate.
 * @authors   Igor Lesik 2020
 * @copyright Igor Lesik  2020
 *
 *
 */
#pragma once

#include "systemc11/systemc11.h"

namespace sc::std {


class Nand2 : public Module
{
    typedef Nand2 SC_CURRENT_USER_MODULE;

    In1 in1, in2;
    Out1 out;

    void nand2()
    {
        out = !(in1 && in2);
    }

public:
    Nand2(const sc_module_name& name):Module(name)
    {
        SC_METHOD(nand2);
        sensitive << in1 << in2;
    }
};

template <unsigned int SIZE>
class Nand : public Module
{
    typedef Nand SC_CURRENT_USER_MODULE;

    In<sc_bv<SIZE>> in;
    Out1 out;

    void nand()
    {
        auto inval = in.read();
        out = !inval.and_reduce();
    }

public:

    Nand(const sc_module_name& name):Module(name)
    {
        SC_METHOD(nand);
        sensitive << in;
    }
};

} // namespace sc::std
