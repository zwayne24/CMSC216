#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>

/* (c) Larry Herman, 2018.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define LINE_SZ 256

static void* grepit(void *arg);

typedef struct{
  char* word;
  char* file;
} Args;

static void* grepit(void *arg){
  FILE *fp;
  char line[LINE_SZ], *string_to_search_for;
  Args *args = arg;
  int total = 0;
  int* returner = malloc(sizeof(*returner));
  
  string_to_search_for= args -> word;

      fp= fopen(args -> file, "r");

      /* silently ignore nonexistent files, or ones that there was an error
         trying to open */
      if (fp != NULL)
        while (fgets(line, LINE_SZ, fp) != NULL)
          if (strstr(line, string_to_search_for) != NULL)
            (total)++;

      *returner = total;

      fclose(fp);

      return returner;
}

int main(int argc, char *argv[]) {
  pthread_t tids[1];
  Args args;
  int loop;
  int total = 0;
  void* indiv;
  int indivint =  0;
  args.word = argv[1];
  for(loop = 2; loop < argc; loop++)
    {
       args.file = argv[loop];
       pthread_create(&tids[0], NULL, grepit, (void *)&args);
       pthread_join(tids[0],&indiv);
       indivint = * (int *)indiv;
       free(indiv);
       (total) +=  (indivint);
    }
    
  printf("%d\n", total);
  
  return 0;
}
