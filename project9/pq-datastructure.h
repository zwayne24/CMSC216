/*Zachary Wayne - 115649422
Code contains structs for priority queue*/
#if !defined(PQDATASTRUCTURE_H)
#define PQDATASTRUCTURE_H

typedef struct priority_queue{
  struct  node *head;
  struct priority_queue *next;
  char *name;
} Priority_queue;

typedef struct node{
  int priority;
  char *data;
  struct node *prev;
  struct node *next;
} Node;

#endif
