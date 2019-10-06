#if !defined(SSS_H)
#define SSS_H

/* (c) Larry Herman, 2018.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

#include "sss-datastructure.h"

#define LINE_MAX 255
#define SUCCESSFUL_COMPILATION 1
#define FAILED_COMPILATION 0

Commands read_commands(const char compile_cmds[], const char test_cmds[]);
void clear_commands(Commands *commands);
int compile_program(Commands commands);
int test_program(Commands commands);

#endif
