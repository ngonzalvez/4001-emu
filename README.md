This is a simple implementation of a 2-register processor emulator with a 255 bytes RAM. Note that this is a WIP. Also, this is heavily based on the 4001 processor by Richard Buckland at UNSW.

## 4001 CPU Architecture
The CPU consists of:

- One counter.
- Two 1-byte registers.
- One underflow flag.
- One overflow flag.
- One "signed" flag (for negative numbers).


## Operations
This is a list of available operations.

Operation Code | Description
---------------|--------------------------------------------------------------
LD0 `<addr>`   | Load the value in the given memory address into register 0.
LD1 `<addr>`   | Load the value in the given memory address into register 1.
ADD            | Add both registers and store the result in register 0.
STR `<addr>`   | Store the value in register 0 in the given memory address.
PRT `<addr>`   | Print the value in the given memory address.
JMP `<addr>`   | Jump to the given memory address.
JPE `<addr>`   | Jump to the given memory address if both registers are equal.
CL0            | Set the register 0 to zero.
CL1            | Set the register 1 to zero.
CP0            | Copy the value in register 0 into register 1.
CP1            | Copy the value in register 1 into register 0.
BEL            | Make the computer "beep".
HAL            | Stop execution. 