/*Zachary Wayne - 115649422
Code reads lines inputted by the user, and checks to see if each
line is less than 80 characters*/

#include <stdio.h>

int main(void){

  char curr;
  int end = 0;
  int start = 0;
  int line_count = 0;
  int line = 1;
  char string[100000];
  int char_count = 0;
  int forloop;
  int forloop2;

  /* reads input till control-D*/
  while (!feof(stdin)){
    scanf("%c", &curr);
    string[end] = curr;
    end++;
    /* counts lines by seeing where enter is hit*/
    if (curr == '\n')
      line_count++;
  }

  end = 0;

  /* runs until there are no lines left*/
  while (line_count > 1){

    start = end;
    /* counts characters in line */
    while (string[end] != '\n'){
      /* counts tabs correctly.*/
      if (string[end] == '\t')
	char_count += 8 - (char_count%8);
      else
      char_count++;
      end++;
    }

    end++;

    if (char_count <= 80)
      {
	printf(" %5d: ", line);
	line++;
	/* print line */
	while (start < end){
	  printf("%c", string[start]);
	  start++;
	}
	if (line_count == 1)
	  printf("\n");
      }
    else {
      printf("*%5d: ", line);
      line++;
      /* print line */
      while (start < end){
	printf("%c", string[start]);
	start++;
      }
      /* prints 88 blanks and then carrots for as many chars over 80 */
      for(forloop = 0; forloop < 88; forloop++)
	printf(" ");
      forloop2 = char_count - 80;
      while (forloop2 > 0){
	forloop2--;
	printf("^");
      }
      printf("\n");
    }

    line_count--;
    char_count = 0;
  }
  
  return 0;
  
}
	
