 #if !defined(SSSDATASTRUCTURE_H)
#define SSSDATASTRUCTURE_H

typedef struct commands{
  struct node *compile;
  struct node *test;
} Commands;

typedef struct node{
  char *data;
  struct node *next;
} Node;

#endif
