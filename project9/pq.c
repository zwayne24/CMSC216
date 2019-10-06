/*Zachary Wayne - 115649422
Code is for a Priority Queue, a queue that holds nodes, with a string and
a priority*/

#include "pq.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*initialize priority queue*/
void init(Priority_queue *const pq){
  pq -> head  = NULL;
  pq -> next = NULL;
}

/*add node to queue*/
int enqueue (Priority_queue * const pq, const char new_element[], int priority)
{
  Node *new_node, *curr, *temp;
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

      new_node = malloc (sizeof(Node));
      if (new_node != NULL)
	{

	  result = 1;
	  new_node->priority = priority;
	  new_node -> data = malloc((strlen(new_element)+1)*sizeof(char));
	  strcpy(new_node -> data, (char*) new_element);
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

/*checks if queue is empty*/
int is_empty(const Priority_queue pq){
  return (pq.head == NULL);
}

/*returns size of queue*/
int size(const Priority_queue pq){
  int count = 0;
  Node *curr = pq.head;
  while(curr != NULL){
    count++;
    curr = curr -> next;
  }
  return count;
}

/*removes and returns node with highest priority*/
char *dequeue(Priority_queue *const pq){
  char* result = NULL;
  if (pq != NULL && pq -> head != NULL){
    Node  *curr = pq -> head;
    while((curr -> next) != NULL){
      curr = curr -> next;
    }

    if (pq -> head -> next == NULL){
      result = malloc((strlen(curr->data)+1)*sizeof(char));
      if (result != NULL){
      strcpy(result,curr -> data);
      pq -> head = NULL;
      free(curr->data);
      free(curr);
    }
    }
    else{
      result = malloc((strlen(curr->data)+1)*sizeof(char));
      if (result != NULL){
      strcpy(result, curr -> data);
      (curr -> prev) ->  next = NULL;
      curr -> prev = NULL;
      free(curr -> data);
    free(curr);
      }
    }
  }
  return result;
}

/*clears queue, i.e removes all elements*/
void clear(Priority_queue *const pq){
  if (pq -> head != NULL){
  Node *curr = pq->head;
  
  while (curr-> next != NULL){
    curr = curr -> next;
    free(curr-> prev -> data);
    free(curr-> prev);
  }
  
  free(curr->data);
  free(curr);
  }
  init(pq);
}

/*returns arrays of all nodes' strings*/
char **get_all_elements(Priority_queue pq){  
  int count = 0;
  Node *curr = pq.head;
  char** elements = calloc(size(pq)+1, sizeof(char**));
  if (elements != NULL){
  if (curr != NULL){
    while (curr -> next != NULL)
	   curr = curr -> next;
  while (curr != NULL){
    elements[count] = malloc((strlen(curr->data)+1)*sizeof(char));
    if (elements[count] != NULL){
    strcpy(elements[count], (char*) curr->data);
    }
    count++;
    curr = curr->prev;
  }
  }
  elements[count] = NULL;
  }
  return elements;
}

/*removes elements in a given priority range*/
int remove_elements_between(Priority_queue *const pq, int low, int high){
  Node *curr = pq -> head, *lows, *highs;
  int result = 0;

  if (low > high)
    return result;
  
  while (curr != NULL && curr -> next -> priority < low)
    curr = curr -> next;

  if (curr == NULL)
    return result;
  else
    lows = curr;

  curr = pq->head;

  while (curr != NULL && curr -> priority <= high){
    curr = curr -> next;
  }

  if (curr == NULL)
    highs = NULL;
  else
    highs = curr;

  if (highs != NULL && lows != NULL){
    if (pq -> head -> priority > low){
      curr = pq -> head;
      while (curr != highs){
	curr = curr -> next;
	free(curr -> prev -> data);
	free(curr -> prev);
      }
      pq -> head = highs;
      highs -> prev = NULL;
    }
    else {
       curr = lows->next;
      while (curr != highs){
	curr = curr -> next;
	free(curr -> prev -> data);
	free(curr -> prev);
      }
      lows  -> next= highs;
      highs -> prev = lows;
    }
  }

  else if (lows != NULL && highs == NULL){
    if (pq -> head -> priority > low){
       curr = pq -> head;
      while (curr -> next != NULL){
	curr = curr -> next;
	free(curr -> prev -> data);
	free(curr -> prev);
      }
      free(curr->data);
      free(curr);
      pq -> head = NULL;
    }
    else{
	 curr = lows -> next;
      while (curr -> next != NULL){
	curr = curr -> next;
	free(curr -> prev -> data);
	free(curr -> prev);
      }
      free(curr->data);
      free(curr);
      lows -> next = NULL;
  }

  }
  
  return result;
}

/*returns string of node with highest priority*/
char *peek(Priority_queue pq){
  char* result = NULL;
  if (pq.head != NULL){
    Node  *curr = pq.head;
    while ((curr -> next) != NULL){
      curr = curr -> next;
    }
    result = malloc((strlen(curr->data)+1)*sizeof(char));
   if (result != NULL)
   strcpy(result, (char*) curr->data);
  }
  return result;
}
