#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H


typedef struct node_st *node_p;
struct node_st {
  int data;
  node_p next;
};

void print_list(node_p);
void error(char *, ...);
void destruct(node_p);
node_p add(node_p, int);


#endif
