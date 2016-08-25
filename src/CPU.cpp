#include <iostream>
#include "emu/CPU.hpp"

using namespace std;


namespace emu {

    CPU::CPU(Memory* mem)
        :
        OP_ADDR(0),
        FIRST_ADDR(1),
        MAX_ADDR(253),
        m_mem(mem),
        m_counter(FIRST_ADDR),
        m_reg0(0),
        m_reg1(0),
        m_overflow(false),
        m_underflow(false),
        m_signed(false),
        m_halted(false)
    { 
        cout << "CPU initialized" << endl; 
    }


    CPU::~CPU()
    { 
        m_mem = nullptr; 
    }


    void CPU::reset()
    {
        m_counter = FIRST_ADDR;    
        m_overflow = false;
        m_underflow = false;
        m_signed = false;
        m_halted = false;
    }


    void CPU::run()
    {
        while (!m_halted) 
        {
            // Fetch the next operation code from the cache or memory,
            // and store it in the memory address reserved for the current
            // operation code.
            m_mem->write(OP_ADDR, fetch());

            // Process the op. code.
            decode(m_mem->read(OP_ADDR));
        }
    }


    byte CPU::fetch()
    {
        byte b = 0;
        b = m_mem->read(m_counter);
        m_counter += 1;

        return b;
    }


    void CPU::decode(const byte& code)
    {
        switch (code) 
        {
            case HALT:
                halt();
                break;

            case ADD:
                add();
                break;

            case LOAD0:
                m_reg0 = m_mem->read(m_counter);
                // cout << "Loading " << (int) m_reg0 << " into register 0" << endl;
                m_counter++;
                break;

            case LOAD1:
                m_reg1 = m_mem->read(m_counter);
                // cout << "Loading " << (int) m_reg1 << " into register 1" << endl;
                m_counter++;
                break;

            case BEEP:
                cout << "Beep" << endl;
                break;

            case PRINT:
                m_reg1 = m_mem->read(m_counter);
                m_reg0 = m_mem->read(m_reg1);
                cout << (int) m_reg0 << endl;
                m_counter++;
                break;

            case STORE:
                store();
                break;
        }
    }


    void CPU::add()
    {
        // cout << "Adding " << (int) m_reg0 << " and " << (int) m_reg1 << endl;
        m_reg0 = m_reg0 + m_reg1;
    }


    void CPU::halt() 
    {
        m_halted = true;
    }

 

    void CPU::store() 
    {
        m_reg1 = fetch();
        m_mem->write(m_reg1, m_reg0);
        // cout << "Storing value " << (int) m_reg0 << " into address " << (int) m_reg1 << endl;
    }

}

