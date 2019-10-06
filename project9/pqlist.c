/*Zachary Wayne - 115649422
  Code is for a Priority Queue List, a queue that holds Priority queues*/
#include "pqlist.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*initializes pqlist*/
void init_queue_list(Priority_queue_list *const pqlist){
   pqlist -> head  = NULL;
}

/*adds priority queue to the list*/
int add_queue(Priority_queue_list *const pqlist, const char new_queue_name[]){
  Priority_queue *curr = pqlist -> head;
  Priority_queue *new_node;
  Priority_queue *previous = NULL;
  
  char *ex;

  while (curr != NULL){
    if (strcmp(curr -> name, (char*) new_queue_name) == 0)
      return 0;
    previous = curr;
    curr = curr -> next;
  }

  new_node = malloc(sizeof(Priority_queue));
  if (new_node != NULL){
  ex = malloc((strlen(new_queue_name)+1)*sizeof(char));
  if (ex != NULL){
  strcpy(ex, (char*)new_queue_name);
  new_node -> name = ex;
  new_node -> next = NULL;
  init(new_node);
  if (pqlist -> head != NULL)
    previous -> next = new_node;
  else
    pqlist -> head = new_node;

  return 1;
  }
  }

  return 0;
}

/*returns the numbers of pq's in the list*/
int num_queues(Priority_queue_list pqlist){
  int result = 0;
  Priority_queue *curr = pqlist.head;

  while (curr != NULL){
    curr = curr -> next;
    result++;
  }

  return result;
}

/*adds a node to the pq with the given name*/
int add_to_queue(Priority_queue_list *const pqlist, const char queue_name[],
                 const char new_element[], int priority){
  int result = 0;
  Priority_queue *curr = pqlist -> head;

  while (curr != NULL){
    if (strcmp(curr -> name,(char*) queue_name) == 0)
      result = enqueue(curr, new_element, priority);
    curr = curr -> next;
  }

  return result;
}

/*removes node from pq with the given name*/
char *remove_from_queue(Priority_queue_list *const pqlist,
                        const char queue_name[]){
  char* result = NULL;
  Priority_queue *curr = pqlist -> head;

  while (curr != NULL){
    if (strcmp(curr -> name,(char*) queue_name) == 0)
      result = dequeue(curr);
    curr = curr -> next;
  }

  return result;
}

/*clears pqlist, i.e. removes all pqs*/
void clear_queues(Priority_queue_list *const pqlist){
  Priority_queue *curr = pqlist -> head, *temp;

  while (curr-> next != NULL){
    temp = curr;
    curr = curr -> next;
    clear(temp);
    free(temp -> name);
    free(temp);
  }

  clear(curr);
  free(curr -> name);
  free(curr);

  init_queue_list(pqlist);
}
