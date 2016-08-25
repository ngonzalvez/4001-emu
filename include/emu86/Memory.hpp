#ifndef _EMU86_MEMORY_HPP_
#define _EMU86_MEMORY_HPP_

namespace emu86 {

    typedef unsigned char byte;

    class Memory
    {
        public:
            const byte MAX_ADDRESS;

        private:
            byte* m_storage;

        public:
            /**
             * Memory constructor. 
             */
            Memory();

            /**
             * Memory destructor.
             */
            ~Memory();

            /**
             * Clear the memory.
             */
            void clear();

            /**
             * Read a value from the memory.
             */
            const byte& read(const byte& addr);

            /**
             * Write a value in the memory.
             */
            void write(const byte& addr, const byte& val);
    };

}

#endif
