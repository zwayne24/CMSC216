#include "sss.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sysexits.h>
#include <err.h>
#include "safe-fork.h"
#include "split.h"
#include <sys/wait.h>

Commands read_commands(const char compile_cmds[], const char test_cmds[]){
  FILE *c = fopen(compile_cmds,"r");
  FILE *t = fopen(test_cmds,"r");

  char cinput[LINE_MAX];
  char tinput[LINE_MAX];

  Commands end;
  Node *curr;

  end.compile = NULL;
  end.test = NULL;

  if(c == NULL || t == NULL)
    exit(0);

  while(fgets(cinput, LINE_MAX, c)){
    Node *new = malloc(sizeof(Node));
    curr = end.compile;
    if (end.compile == NULL){
      end.compile = new;
      new -> data = calloc(LINE_MAX, sizeof(char));
      strcpy(new -> data, cinput);
      new -> next = NULL;
    }
    else{
      while(curr -> next != NULL)
	curr = curr-> next;
      curr -> next = new;
      new -> data = calloc(LINE_MAX, sizeof(char));
      strcpy(new->data, cinput);
      new -> next = NULL;
    }
  }

  while(fgets(tinput, LINE_MAX, t)){
    Node *newt = malloc(sizeof(Node));
    curr = end.test;
    if (end.test == NULL){
      end.test = newt;
      newt -> data = calloc(LINE_MAX, sizeof(char));
      strcpy(newt -> data, tinput);
      newt -> next = NULL;
    }
    else{
      while(curr -> next != NULL)
	curr = curr-> next;
      curr -> next = newt;
      newt -> data = calloc(LINE_MAX, sizeof(char));
      strcpy(newt->data, tinput);
      newt -> next = NULL;
    }
  }

  fclose(c);
  fclose(t);
  
  return end;  
   
}

void clear_commands(Commands *commands){
  struct node* tmp;
   
  while (commands -> compile != NULL)
    {
      tmp = commands -> compile;
      commands -> compile = commands -> compile -> next;
      free(tmp -> data);
      free(tmp);
    }

  while (commands -> test != NULL)
    {
      tmp = commands -> test;
      commands -> test = commands -> test -> next;
      free(tmp -> data);
      free(tmp);
    }
}

int compile_program(Commands commands){
  Node *curr = commands.compile;
  int x;
  pid_t pid;
  char** words;
  int status;
  while(curr != NULL){
    x = 0;
    status = 0;
    words = split(curr -> data);
      pid = safe_fork();
      if(pid > 0){
	wait(&status);
	if (WIFEXITED(status) == 0 || WEXITSTATUS(status) != 0)
	  return FAILED_COMPILATION;
      }
      else if (pid == 0)
	{
	  execvp(words[0], words);
	}
      else err(EX_OSERR, "No Bueno");

      while (words[x] != NULL){
	free(words[x]);
	x++;
      }
      free(words);
    curr = curr -> next;
  }
 
  
  return SUCCESSFUL_COMPILATION;
}


int test_program(Commands commands){
  Node *curr = commands.test;
  int x;
  pid_t pid;
  char** words;
  int status;
  int count = 0;
  while(curr != NULL){
    x = 0;
    status = 0;
    words = split(curr -> data);
      pid = safe_fork();
      if(pid > 0){
	wait(&status);
	if (WIFEXITED(status) != 0 && WEXITSTATUS(status) == 0)
	  count++;
      }
      else if (pid == 0)
	{
	  execvp(words[0], words);
	}
      else err(EX_OSERR, "No Bueno");

      while (words[x] != NULL){
	free(words[x]);
	x++;
      }
      free(words);
      curr = curr -> next;
  }

  return count;
}


