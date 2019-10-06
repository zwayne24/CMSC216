typedef struct priority_queue{
  struct node *head;
} Priority_queue;

typedef struct node{
  int priority;
  char *data;
  struct node *prev;
  struct node *next;
} Node;
