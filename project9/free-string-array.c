/*Zachary Wayne - 115649422
frees all strings in an array*/
#include "free-string-array.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void free_string_array(char *names[]){
  int x = 0;

  while (names[x] != NULL){
    free(names[x]);
    x++;
  }

  free(names);
}
