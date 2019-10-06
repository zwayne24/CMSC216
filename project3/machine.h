/* (c) Larry Herman, 2018.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

#define NUM_BYTES 4096
#define BYTES_PER_WORD 4
#define NUM_WORDS (NUM_BYTES / BYTES_PER_WORD)
#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define R4 4
#define R5 5
#define R6 6
#define R7 7
#define R8 8
#define R9 9
#define R10 10
#define R11 11

typedef unsigned int Machine_word;

typedef enum { SYS, ADD, SUB, MUL, DIV, REM, SHL, SHR, NEG, CMP, BR,
               AND, OR, NOT, LI, LW, SW, MOV } Opcode;

int assemble(unsigned short opcode, unsigned short reg1, unsigned short reg2,
             unsigned short reg3, unsigned short extension,
             unsigned int addr_constant, Machine_word *const word);
int print_instruction(Machine_word instruction);
int disassemble(const Machine_word program[], unsigned int program_size,
                unsigned int data_segment_size);
int valid_instruction(Machine_word word);
