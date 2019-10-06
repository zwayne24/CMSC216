#include "pq.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void init(Priority_queue *const pq){
  pq -> head  = NULL;
}

int enqueue (Priority_queue * const pq, const char new_element[], int priority)
{
  Node *new_node, *curr, *temp;
  char *ex;
  int result = 0;

  if (pq != NULL && priority > 0 && new_element != NULL)
    {

      curr = pq->head;
      while (curr != NULL && priority >= curr->priority)
	{
	  if (curr->priority == priority)
	    return 0;
	  curr = curr->next;
	}

      new_node = malloc (sizeof (*new_node));
      if (new_node != NULL)
	{

	  result = 1;
	  new_node->priority = priority;
	  ex = malloc(strlen(new_element));
	  strcpy(ex, (char*) new_element);
	  new_node-> data = ex;
	  new_node->next = curr;

	  if (curr == NULL)
	    {

	      if (pq->head == NULL)
		{
		  pq->head = new_node;
		  new_node->prev = new_node->next = NULL;
		}
	      else
		{
		  temp = pq->head;
		  while (temp->next != NULL)
		    temp = temp->next;
		  temp->next = new_node;
		  new_node->prev = temp;
		  new_node->next = NULL;
		}

	    }
	  else
	    {

	      if (curr == pq->head)
		{
		  new_node->next = curr;
		  new_node->prev = NULL;
		  pq->head = new_node;
		  curr->prev = new_node;
		}
	      else
		{
		  new_node->next = curr;
		  new_node->prev = curr->prev;
                  curr->prev->next = new_node;
		  curr->prev = new_node;
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
  char* ex;
  char** elements = calloc(size(pq), sizeof(char**));
  if (curr != NULL){
    while (curr -> next != NULL)
	   curr = curr -> next;
  while (curr != NULL){
    ex = malloc(strlen(curr->data));
    strcpy(ex, (char*) curr->data);
    elements[count] = ex;
    count++;
    curr = curr->prev;
  }
  }
  elements[count] = NULL;
  return elements;
}

int remove_elements_between(Priority_queue *const pq, int low, int high){
  Node *curr = pq -> head, *lows, *highs;
  int result = 0;

  if (low > high)
    return result;
  
  while (curr != NULL && curr -> priority < low)
    curr = curr -> next;

  if (curr == NULL)
    return result;
  else
    lows = curr;

  curr = pq->head;

  while (curr != NULL && curr -> priority <= high)
    curr = curr -> next;

  if (curr == NULL)
    highs = NULL;
  else
    highs = curr;

  if (highs != NULL && lows != NULL){
    if (lows == pq -> head){
      pq -> head = highs;
      lows -> next = NULL;
      highs -> prev = NULL;
    }
    else {
      lows -> prev -> next= highs;
      highs -> prev = lows -> prev;
    }
  }

  else if (lows != NULL && highs == NULL){
    if (lows == pq -> head)
      pq -> head = NULL;
    else
      lows -> prev -> next = NULL;
  }
  
  return result;
}

char *peek(Priority_queue pq){
  char* result = NULL;
  if (pq.head != NULL){
    Node  *curr = pq.head;
    while ((curr -> next) != NULL){
      curr = curr -> next;
    }
   result = malloc(strlen(curr->data));
   strcpy(result, (char*) curr->data);
  }
  return result;
}
