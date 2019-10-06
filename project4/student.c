#include "student.h"
#include <stdio.h>
#include <string.h>

Student new_student(const char name[], unsigned int id, float shoe_size){
  Student new_person;
  
  if(name){
    strcpy(new_person.name, name);
  }
  else
    strcpy(new_person.name, "");
  
  new_person.id = id;
  new_person.shoe_size = shoe_size;

  return new_person;
}

void init_student(Student *const student, const char name[], unsigned int id,
                  float shoe_size){
  if (student != NULL){
    student->id = id;
  student->shoe_size = shoe_size;
  if(name)
    strcpy(student->name, name);
  else
    strcpy(student->name, "");
  }
}


unsigned int has_id(Student student, unsigned int id){
  return student.id == id;
}

int has_name(Student student, const char name[]){
  int ans = 0;
   if(name == NULL)
     ans = 0;
   else if (strcmp(student.name, name) == 0)
     ans = 1;
   
   return ans;
}

unsigned int get_id(Student student){
  return student.id;
}
float get_shoe_size(Student student){
  return student.shoe_size;
}
Student change_shoe_size(Student student, float new_shoe_size){
  student.shoe_size = new_shoe_size;
  return student;
}

void change_name(Student *const student, const char new_name[]){
  if(student){
    if(new_name)
      strcpy(student->name, new_name);
    else
      strcpy(student->name,"");
  }
  
}
