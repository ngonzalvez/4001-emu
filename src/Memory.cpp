#include <iostream>
#include "emu86/Memory.hpp"

using namespace std;


namespace emu86 {

    Memory::Memory()
        : 
        MAX_ADDRESS(255),
        m_storage(new byte[MAX_ADDRESS])
    {
        clear();
        cout << "Memory initialized" << endl;
    }


    Memory::~Memory()
    {
        if (m_storage != nullptr)
        {
            delete[] m_storage;
            m_storage = nullptr;
        }
    }
          

    void Memory::clear()
    {
        for (byte i = 0; i < MAX_ADDRESS; i++)
        {
            m_storage[i] = 0;
        }
    }


    const byte& Memory::read(const byte& addr) 
    {
        return m_storage[addr]; 
    }

    
    void Memory::write(const byte& addr, const byte& val)
    {
        m_storage[addr] = val;
    }
}
