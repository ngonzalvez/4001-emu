#include <iostream>
#include "emu/emu.hpp"

using namespace emu;
using namespace std;


int main(int argc, char* argv[])
{
    Memory *mem = new Memory();
    CPU *cpu = new CPU(mem);
    ProgramLoader programmer(mem, cpu->FIRST_ADDR);

    cout << "CPU & Memory initialized" << endl;

    if (argc == 2) 
    {
        programmer.loadFile(argv[1]);        
    }

    cpu->run();

    cout << "Computer shutdown" << endl;
}
