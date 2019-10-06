#include "check-string-arrays.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int check_string_arrays(char *names[], char *expected_names[]){
  int result = 0;
  int x = 0;
  while (names[x] != NULL && expected_names[x] != NULL &&
	 !strcmp((names[x]),(expected_names[x])))
    x++;
  if ((names[x]) == NULL &&  (expected_names[x]) == NULL)
    result = 1;
  return result;
}
