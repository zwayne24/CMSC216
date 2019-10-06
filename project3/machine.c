/*Zach Wayne 115649422
Contains functions that immitate a fiction computer Commqual.
Assembles and disassembles hex code and commands*/
#include "machine.h"
#include <stdio.h>

/*Takes 6 fields in the form of numbers and stores them into word
as one hex command*/
int assemble (unsigned short opcode, unsigned short reg1, unsigned short reg2,
	  unsigned short reg3, unsigned short extension,
	  unsigned int addr_constant, Machine_word * const word)
{
  /*checks if word is null */
  if (!word)
    return 0;
  *word = (addr_constant << 0 | extension << 12 | reg3 << 15 | reg2 << 19
	   | reg1 << 23 | opcode << 27);

  return *word;
}

/*takes a hex instruction and prints out the command in readable terms*/
int print_instruction (Machine_word instruction)
{
  Opcode op = (instruction >> 27);
  const char *opcode[] = { "sys", "add", "sub", "mul", "div", "rem", "shl",
    "shr", "neg", "cmp", "br", "and", "or", "not", "li",
    "lw", "sw", "mov "
  };
  /*prints opcode instruction */
  printf ("%s ", opcode[op]);
  /*prints extension if necessary */
  if (op == 0 || op == 9)
    printf ("%d ", (instruction >> 12) & 7);
  else
    printf ("  ");
  /*prints registers as necessary */
  if (op != 10)
    printf ("R%d ", (instruction >> 23) & 15);
  if (op != 0 && op != 10 && op != 14 && op != 15 && op != 16)
    printf ("R%d ", (instruction >> 19) & 15);
  if ((op > 0 && op < 8) || op == 11 || op == 12)
    printf ("R%d ", (instruction >> 15) & 15);
  /*prints memory address as necessary. special case for li */
  if (op == 14 && instruction & 32767)
    printf ("%d", instruction & 32767);
  else if (op == 10 || op == 15 || op == 16)
    printf ("%05d", instruction & 4095);
  return 0;
}


/*turns hex code commands to english*/
int disassemble (const Machine_word program[], unsigned int program_size,
	     unsigned int data_segment_size)
{
  int i;
  int r = 1;
  if (program_size < 0 || data_segment_size >= program_size)
    r = 0;
  if (r)
    {
      for (i = 0; i < program_size; i++)
	{
	  if (valid_instruction (program[i]) &&
	      (program_size - i) > data_segment_size)
	    {
	      print_instruction (program[i]);
	      printf ("\n");
	    }
	  else if ((program_size - i) <= data_segment_size)
	    {
	      printf ("%08x", program[i]);
	      printf ("\n");
	    }
	  else
	    {
	      r = 0;
	      i = program_size;
	    }
	}
    }

  return r;
}

/*checks if a hex code command is valid*/
int valid_instruction (Machine_word word)
{
  int opcode = word >> 27;
  int reg1 = word >> 23 & 15;
  int reg2 = word >> 19 & 15;
  int reg3 = word >> 15 & 15;
  int ext = word >> 12 & 7;
  int mem = word & 4095;
  int check = 0;

/*checks that the first registry is not 0 for cases where it can't be*/
  if (reg1 != 0 || (opcode == 16 || opcode == 9 ||
		    (opcode == 1 && ext != 2) || opcode == 10))
    check = 1;
/*checks that the extension is in check when it needs to be*/
  if ((opcode == 0 && ext >= 3) || (opcode == 9 && ext >= 6))
    check = 0;

/*checks the rest*/
  return (opcode < 18) && (reg1 < 12) && (reg2 < 12) && (reg3 < 12)
    && ((opcode == 14) || (mem % 4 == 0)) && check;
}

