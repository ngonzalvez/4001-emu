#ifndef _EMU86_CPU_HPP_
#define _EMU86_CPU_HPP_

#include "emu/Memory.hpp"


namespace emu {

    enum OP {
        HALT,
        LOAD0,
        LOAD1,
        ADD,
        BEEP,
        PRINT,
        STORE,
        JMP,
        JMP_EQ,
        CLEAR0,
        CLEAR1,
        COPY0,
        COPY1
    };

    class CPU
    {
        public:
            const byte OP_ADDR;
            const byte JMP_ADDR;
            const byte FIRST_ADDR;
            const byte MAX_ADDR;

        private:
            emu::Memory* m_mem;

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
            CPU(emu::Memory* mem);

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
             * Load the given address into register 0.
             */
            void load0();

            /**
             * Load the given address into register 1.
             */
            void load1();

            /**
             * Stop the execution of the code in memory.
             */
            void halt();

            /**
             * Store the value in register 0 in the memory address stored in 
             * register 1.
             */
            void store();

            /**
             * Jump to the address stored in the reserved memory address JMP_ADDR.
             */
            void jump();

            /**
             * Jump if register 0 and register 1 have the same value.
             */
            void jumpEqual();

            /**
             * Clear register 0.
             */
            void clear0();

            /**
             * Clear register 1.
             */
            void clear1();

            /**
             * Copy register 0 to register 1.
             */
            void copy0();

            /**
             * Copy register 1 to register 0.
             */
            void copy1();
    };
     
}

#endif
