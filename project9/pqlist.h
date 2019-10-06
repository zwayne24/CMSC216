#if !defined(PQLIST_H)
#define PQLIST_H

/* (c) Larry Herman, 2018.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

#include "pq.h"
#include "pqlist-datastructure.h"

void init_queue_list(Priority_queue_list *const pqlist);
int add_queue(Priority_queue_list *const pqlist, const char new_queue_name[]);
int num_queues(Priority_queue_list pqlist);
int add_to_queue(Priority_queue_list *const pqlist, const char queue_name[],
                 const char new_element[], int priority);
char *remove_from_queue(Priority_queue_list *const pqlist,
                        const char queue_name[]);
void clear_queues(Priority_queue_list *const pqlist);

#endif
