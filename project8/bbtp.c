#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pq.h"

/* (c) Larry Herman, 2018.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

static void test1(void);
static void test2(void);
static void test3(void);
static void test4(void);
static void test5(void);
static void test6(void);
static void test7(void);
static void test8(void);
static void test9(void);

static void test1(void) {
  Priority_queue pq;

  init(&pq);

  if (size(pq) != 0)
    exit(FOUND_BUG);

  clear(&pq);
}

static void test2(void) {
  Priority_queue pq;
  char *element;

  init(&pq);

  enqueue(&pq, "Rocky Racoon", 90);
  enqueue(&pq, "Wally Walrus", 40);
  enqueue(&pq, "Aaron Aardvark", 60);
  enqueue(&pq, "Ginny Giraffe", 20);
  enqueue(&pq, "Manny Manatee", 30);
  enqueue(&pq, "Donny Donkey", 50);

  element= dequeue(&pq);
  if (element == NULL || strcmp(element, "Rocky Racoon") != 0) {
    printf("Bug found- dequeue() was wrong!\n");
    exit(FOUND_BUG);
  } else clear(&pq);
}

static void test3(void){
  Priority_queue pq;
  char *element;

  init(&pq);
  
  enqueue(&pq, "Rocky Racoon", 90);

   element= dequeue(&pq);
  if (element == NULL || strcmp(element, "Rocky Racoon") != 0)
    exit(FOUND_BUG);

  enqueue(&pq, "Rocky Racoon", 90);
  enqueue(&pq, "Rocky Balboa", 91);

   element= dequeue(&pq);
  if (element == NULL || strcmp(element, "Rocky Balboa") != 0)
    exit(FOUND_BUG);

   enqueue(&pq, "Rocky Road", 89);
   
   element= dequeue(&pq);
  if (element == NULL || strcmp(element, "Rocky Racoon") != 0)
    exit(FOUND_BUG);
}

static void test4(void){
  char *element = "Whoop";
  Priority_queue pq;

  init(&pq);
  
  enqueue(&pq, element, 90);
  element = "Whomp";
  if (strcmp(dequeue(&pq), "Whoop") != 0)
    exit(FOUND_BUG);
}

static void test5(void){
  Priority_queue pq;

  init(&pq);

  if (!is_empty(pq))
    exit(FOUND_BUG);

  enqueue(&pq, "Bob", 10);

  if (is_empty(pq))
    exit(FOUND_BUG);

  dequeue(&pq);

  if (!is_empty(pq))
    exit(FOUND_BUG);
}

static void test6(void){
  Priority_queue pq;
  int x = 6;

  init(&pq);

  enqueue(&pq, "Rocky Racoon", 90);
  enqueue(&pq, "Wally Walrus", 40);
  enqueue(&pq, "Aaron Aardvark", 60);
  enqueue(&pq, "Ginny Giraffe", 20);
  enqueue(&pq, "Manny Manatee", 30);
  enqueue(&pq, "Donny Donkey", 50);

  while(x != 0){
    if (size(pq) != x)
      exit(FOUND_BUG);
    dequeue(&pq);
    x--;
  }

  if (dequeue(&pq) != NULL)
    exit(FOUND_BUG);
}

static void test7(void){
  Priority_queue pq;

  init(&pq);

  enqueue(&pq, "Bloop", 5);
  clear(&pq);

  if (size(pq) != 0 || !is_empty(pq))
    exit(FOUND_BUG);

  enqueue(&pq, "Bloop", 5);
  enqueue(&pq, "Blop", 5);
  clear(&pq);

  if (size(pq) != 0 || !is_empty(pq))
   exit(FOUND_BUG);
}

static void test8(void){
  Priority_queue pq;

  init(&pq);

  enqueue(&pq, "Bloop", 5);
  enqueue(&pq, "Bloop", 7);
  enqueue(&pq, "Bloop", 6);
  enqueue(&pq, "Bloop", 4);
  enqueue(&pq, "Bloop", 8);
  enqueue(&pq, "Bloop", 9);
  enqueue(&pq, "Bloop", 3);

  remove_elements_between(&pq, 4, 8);

  if (size(pq) != 2)
    exit(FOUND_BUG);

  clear(&pq);

  enqueue(&pq, "Bloop", 5);
  enqueue(&pq, "Bloop", 7);
  enqueue(&pq, "Bloop", 6);
  enqueue(&pq, "Bloop", 4);
  enqueue(&pq, "Bloop", 8);
  enqueue(&pq, "Bloop", 9);
  enqueue(&pq, "Bloop", 3);

  remove_elements_between(&pq, 4, 11);

  if (size(pq) != 1)
    exit(FOUND_BUG);

  clear(&pq);

  enqueue(&pq, "Bloop", 5);
  enqueue(&pq, "Bloop", 7);
  enqueue(&pq, "Bloop", 6);
  enqueue(&pq, "Bloop", 4);
  enqueue(&pq, "Bloop", 8);
  enqueue(&pq, "Bloop", 9);
  enqueue(&pq, "Bloop", 3);

  remove_elements_between(&pq, 11, 12);

  if (size(pq) != 7)
    exit(FOUND_BUG);
}

static void test9(void){
  Priority_queue pq;
  char* element;

  init(&pq);

   enqueue(&pq, "Hello", 9);
   enqueue(&pq, "Goodbye", 9);
   enqueue(&pq, "Aloha", 5);
   enqueue(&pq, "Howdy", 6);

   if (size(pq) != 3)
     exit(FOUND_BUG);

   element = peek(pq);
   
   if(strcmp(element, "Hello") != 0 || size(pq) != 3)
     exit(FOUND_BUG);

   
}

int main() {
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  test7();
  test8();
  test9();
  
  printf("No bugs were detected!\n");

  return CORRECT;
}


