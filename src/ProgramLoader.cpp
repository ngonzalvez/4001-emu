#include <iostream>
#include <fstream>
#include <sstream>
#include "emu/ProgramLoader.hpp"
#include "emu/CPU.hpp"

using namespace std;


namespace emu {

    ProgramLoader::ProgramLoader(Memory* mem, byte offset)
        :
        m_counter(0),
        m_offset(offset),
        m_mem(mem)
    { }


    void ProgramLoader::loadFile(string path)
    {
        // Open and read the file.
        ifstream file;
        string line;
        file.open(path);

        if (file.is_open()) 
        {
            while (getline(file, line))
            {
                parse(line);
            }
        }
    }


    void ProgramLoader::parse(string line)
    {
        string op;

        if (line.length() < 4) 
        {
            load(stoi(line.substr(0, line.find(';'))));
            return;
        }

        op = line.substr(0, 3);
        string addr = line.substr(4, line.find(';'));

        if (op == "HAL") {
            load(HALT);
        }
        else if (op == "LD0") 
        {
            load(LOAD0);
            load(stoi(addr));
        }
        else if (op == "LD1")
        {
            load(LOAD1);
            load(stoi(addr));
        }
        else if (op == "ADD")
        {
            load(ADD);
        }
        else if (op == "BEL")
        {
            load(BEEP);
        }
        else if (op == "PRT")
        {
            load(PRINT);
            load(stoi(addr));
        }
        else if (op == "STR")
        {
            load(STORE);
            load(stoi(addr));
        }
        else if (op == "JMP")
        {
            load(JMP);
            load(stoi(addr));
        }
        else if (op == "JPE")
        {
            load(JMP_EQ);
            load(stoi(addr));
        }
        else if (op == "CL0")
        {
            load(CLEAR0);
        }
        else if (op == "CL1")
        {
            load(CLEAR1);
        }
        else if (op == "CP0")
        {
            load(COPY0);
        }
        else if (op == "CP1")
        {
            load(COPY1);
        }
    }


    void ProgramLoader::load(byte b) 
    {
        m_mem->write(m_offset + m_counter, b);
        m_counter++;
    }

}
