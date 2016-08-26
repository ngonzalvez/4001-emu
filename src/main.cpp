#include <iostream>
#include "emu/emu.hpp"

using namespace emu;
using namespace std;


int main(void)
{
    Memory *mem = new Memory();
    CPU *cpu = new CPU(mem);

    cout << "CPU & Memory initialized" << endl;

    int codeLength = 18;
    byte code[codeLength] = {
        LOAD0, 1,   // 2 
        JMP, 16,    // 4 
        JMP_EQ, 15, // 6
        ADD,        // 8
        STORE, 15,  // 9
        PRINT, 15,  // 11
        BEEP,       // 13
        HALT,       // 14
        0,          // 15
        LOAD1, 1,   // 16
        JMP, 8      // 18
    };

    for (int i = 0; i < codeLength; i++)
    {
        mem->write(cpu->FIRST_ADDR + i, code[i]);
    }

    cout << "Default program loaded" << endl;

    cpu->run();

    cout << "Computer shutdown" << endl;
}
