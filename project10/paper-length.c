#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sysexits.h>
#include <err.h>
#include "safe-fork.h"

int main(void){
  
int pfd[2];
pid_t pid;
int words;

pipe(pfd);
pid = safe_fork();

 if (pid > 0) { 
    dup2(pfd[0], STDIN_FILENO);
    scanf("%d", &words);
    if (words >= 200){
      printf("Long enough!\n");
      exit(0);
    }
    else{
      printf("Too short!\n");
      exit(1);
    }
  }
 else if (pid == 0) {  
      dup2(pfd[1], STDOUT_FILENO);
      execl("/usr/bin/wc", "wc", "-w", NULL);
      exit(0);
    }
 else err(EX_OSERR, "No Bueno");
 
}
