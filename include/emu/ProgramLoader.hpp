#ifndef _EMU_PROGRAM_LOADER_HPP_
#define _EMU_PROGRAM_LOADER_HPP_

#include <string>
#include "Memory.hpp"


namespace emu {
    
    class ProgramLoader
    {
        private:
            byte m_counter;
            byte m_offset;
            Memory *m_mem;

        public:
            /**
             * Constructor.
             */
            ProgramLoader(Memory* mem, byte offset);

            /**
             * Read the program in the file and load it into the memory.
             */
            void loadFile(std::string path);


        private:
            /**
             * Parse the code string and return an array of bytes.
             */
            void parse(std::string code);

            /**
             * Load the given bytes into the memory.
             */
            void load(byte b);
    };

}

#endif 

