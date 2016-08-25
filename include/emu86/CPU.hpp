#ifndef _EMU86_CPU_HPP_
#define _EMU86_CPU_HPP_

#include "emu86/Memory.hpp"


namespace emu86 {

    enum OPERATIONS {
        HALT,
        LOAD0,
        LOAD1,
        ADD,
        BEEP,
        PRINT,
        STORE
    };

    class CPU
    {
        private:
            const byte OP_ADDR;
            const byte FIRST_ADDR;
            const byte MAX_ADDR;

            emu86::Memory* m_mem;

            byte m_counter;
            byte m_reg0;
            byte m_reg1;

            bool m_overflow;
            bool m_underflow;
            bool m_signed;
            bool m_halted;

        public:
            /**
             * Constructor.
             */
            CPU(emu86::Memory* mem);

            /**
             * Destructor.
             */
            ~CPU();

            /**
             * Reset the processor.
             */
            void reset();

            /**
             * Start the procesor.
             */
            void run();

            /**
             * Fetch the next op. code from memory or cache.
             */
            byte fetch();

            /**
             * Decode the byte in register 0.
             */
            void decode(const byte&);

            /**
             * Add the registers and store the result in register 0.
             */
            void add();

            /**
             * Stop the execution of the code in memory.
             */
            void halt();

            /**
             * Store the value in register 0 in the memory address stored in 
             * register 1.
             */
            void store();
    };
     
}

#endif
