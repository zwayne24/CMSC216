#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Student *new_student(const char name[], unsigned int id, float shoe_size){
  Student *ns;
  int i = sizeof(id);
  int ss = sizeof(shoe_size);
  int na;

  if(name)
    na = strlen(name)+1;
  else
    na = 1;
  
  ns = malloc((na + i +ss));
  ns -> id = id;
  ns -> shoe_size = shoe_size;
  if(name)
    ns -> name =  (char*) name;
  else
    ns -> name =  (char*) "";

  return ns;
}

unsigned int has_id(Student *const student, unsigned int id){
  int ans = 0;

  if(student && student -> id && id)
    ans = (student -> id == id);

   return ans;
}

int has_name(Student *const student, const char name[]){
  int ans = 0;

  if(student && name)
    ans = !(strcmp(student -> name, name));

  return ans;
}

unsigned int get_id(Student *const student){
  unsigned int ans = 0;
  
  if (student)
    ans = student -> id;

  return ans;
}

float get_shoe_size(Student *const student){
   float ans = 0;
  
  if (student)
    ans = student -> shoe_size;

  return ans;
}

void change_shoe_size(Student *const student, float new_shoe_size){
    if (student)
      student -> shoe_size = new_shoe_size;
}

void change_name(Student *const student, const char new_name[]){
   char *n;
  if(new_name && student){
    n = (char*) malloc(strlen(new_name)+1);
    strcpy(n, new_name);
      student -> name = n;
  }
  else if (student){
     n = malloc(strlen("")+1);
     strcpy(n, "");
      student -> name = n;
  }
}

void copy_student(Student *student1, Student *const student2){
   char *n;
  if(student1 && student2){
    n = (char*) malloc(strlen(student2 -> name));
     strcpy(n, student2 -> name);
  student1 -> id = student2 -> id;
  student1 -> shoe_size = student2 -> shoe_size;
  student1 -> name = n;
  }
}
