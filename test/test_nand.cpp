#include "systemc11/std/nand.h"

using sc::Module;
using sc::In1;
using sc::Out1;
using sc::Out;

SC_MODULE(NandDriver)
{
    Out1 out1, out2;
    Out<sc_bv<2>> out;

    SC_CTOR(NandDriver)
    {
        SC_THREAD(drive);
    }

    void drive()
    {
        sc_uint<2> pattern{0};

        while (true) {
            out1 = pattern[0];
            out2 = pattern[1];
            out.write(pattern);
            wait(1, SC_NS);
            ++pattern;
        }
    }
};

SC_MODULE(NandMonitor)
{
    In1 in1, in2, out, gout;

    SC_CTOR(NandMonitor)
    {
        SC_METHOD(monitor);
        sensitive << /*in1 << in2 <<*/ out;
        dont_initialize();
    }

    void monitor()
    {
        std::cout << "At time " << sc_time_stamp() << "::"
        << "(a,b): " << in1 << in2
        << " (out):" << out
        << " (gout):" << gout << std::endl;

        sc_assert(out == !(in1 && in2));
        sc_assert(gout == out);
    }
};

int sc_main(int /*argc*/, char* /*argv*/[])
{
    sc_signal<bool> in1, in2, out, gout;
    sc_signal<sc_bv<2>> in;

    sc::std::Nand2 nand("nand");
    nand(in1, in2, out);

    sc::std::Nand<2> gnand("gnand");
    gnand(in, gout);

    NandDriver driver("driver");
    driver(in1, in2, in);

    NandMonitor monitor("monitor");
    monitor(in1, in2, out, gout);

    sc_start(10, SC_NS);

    return 0;
}
