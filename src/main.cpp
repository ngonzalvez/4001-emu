#include <iostream>
#include "emu/emu.hpp"

using namespace emu;
using namespace std;


int main()
{
    Memory *mem = new Memory();
    CPU *cpu = new CPU(mem);
    byte code[11] = {
        LOAD0, 1,
        LOAD1, 2, 
        ADD,
        STORE, 12,
        PRINT, 12,
        BEEP,
        HALT
    };

    for (int i = 0; i < 11; i++)
    {
        mem->write(cpu->FIRST_ADDR + i, code[i]);
    }

    cpu->run();

    cout << "Computer shutdown" << endl;
}
