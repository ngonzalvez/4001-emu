#include <iostream>
#include "emu/emu.hpp"

using namespace emu;
using namespace std;


int main(void)
{
    Memory *mem = new Memory();
    CPU *cpu = new CPU(mem);

    cout << "CPU & Memory initialized" << endl;

    int codeLength = 20;
    byte code[codeLength] = {
        LOAD0, 20,  // Load the value in mem. address 20 in register 0.
        JMP, 15,    // Jump to memory address 16. 
        JMP_EQ, 14, // Jump to memory address 14 if both registers are equal.
        ADD,        // Add the numbers in the registers.
        STORE, 19,  // Store the result (register 0) in mem. address 15.
        PRINT, 19,  // Print the value on memory address 15.
        BEEP,       // Beep.
        HALT,       // Stop execution.
        LOAD1, 21,  // Load value in mem. address 21 into register 1.
        JMP, 8,     // Jump to memory address 8.
        0,          // Variable: result of the addition.
        1,          // Variable: First number in the sum.
        1           // Variable: Second number in the sum.
    };

    for (int i = 0; i < codeLength; i++)
    {
        mem->write(cpu->FIRST_ADDR + i, code[i]);
    }

    cout << "Default program loaded" << endl;

    cpu->run();

    cout << "Computer shutdown" << endl;
}
