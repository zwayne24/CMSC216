#include "pq.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void init(Priority_queue *const pq){
  pq -> head  = NULL;
}

int enqueue (Priority_queue * const pq, const char new_element[], int priority){
  Node *new_node, *curr, *temp;
  int result= 0;

  if (pq != NULL && priority > 0) {

    curr = pq -> head;
    while (curr != NULL && curr->priority <= priority){
      curr= curr->next;
      if (curr->priority == priority)
	return 0;
    }

    new_node= malloc(sizeof(*new_node));
    if (new_node != NULL) {

      result= 1;
      new_node->priority= priority;
      new_node->data = (char*) new_element;
      new_node->next= curr;    

      if (curr == NULL) {  
                               
        if (pq->head == NULL){             
          pq->head= new_node;
	  new_node -> prev = new_node -> next = NULL;
	}
        else{
	  temp = pq->head;
	  while (temp ->next != NULL)
	    temp= temp->next;
	   new_node -> prev = temp;
	  new_node->next = NULL;
	  temp -> next = new_node;	 
	}      

      } else {               
                            
        if (curr == pq->head){
	   new_node->next = curr;
	  new_node->prev = NULL;
	  pq->head= new_node;
	  curr -> prev = new_node;      
	}
        else {
	  new_node->next = curr;
	  new_node->prev = curr-> prev;
	    curr->prev->next= new_node;
	  curr -> prev = new_node;
	}
      }
    }

  }

  return result;
}


int is_empty(const Priority_queue pq){
  return (pq.head == NULL);
}

int size(const Priority_queue pq){
  int count = 0;
  Node *curr = pq.head;
  while(curr != NULL){
    count++;
    curr = curr -> next;
  }
  return count;
}

char *dequeue(Priority_queue *const pq){
  char* result = NULL;
  if (pq != NULL && pq -> head != NULL){
    Node  *curr = pq -> head;
    while((curr -> next) != NULL){
      curr = curr -> next;
    }

    if (pq -> head -> next == NULL){
      result = pq -> head -> data;
      pq -> head = NULL;
    }
    else{
      result = curr -> data;
      (curr -> prev) ->  next = NULL;
      curr -> prev = NULL;
    }
  }
  return result;
}

void clear(Priority_queue *const pq){
  pq->head = NULL;
}

char **get_all_elements(Priority_queue pq){  
  int count = 0;
  Node *curr = pq.head;
  char** elements = malloc(size(pq)+1);
  if (curr != NULL){
    while (curr -> next != NULL)
	   curr = curr -> next;
  while (curr != NULL){
    elements[count] = malloc(strlen(curr -> data));
    elements[count] = curr -> data;
    count++;
    curr = curr->prev;
  }
  }
  elements[count] = NULL;
  return elements;
}

int remove_elements_between(Priority_queue *const pq, int low, int high){
  Node *curr = pq -> head, *lows;
  int result = 0;
  while (curr -> priority < low)
    curr = curr -> next;
  lows = curr -> prev;
  while (curr -> priority < high)
    curr = curr -> next;
  if (curr != lows)
    result = 1;
  lows -> next = curr;
  curr -> prev = lows;
  return result;
}
