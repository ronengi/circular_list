#include <stdio.h>
#include <stdlib.h>

typedef struct node_st *nodep;
struct node_st {
  int data;
  nodep next;
};



nodep unite(nodep h1, nodep h2) {
  nodep h, p, p1, p2;

  if (!h1)    return h2;
  if (!h2)    return h1;

  p1 = h1;
  p2 = h2;

  if (h1->data < h2->data) {
    p = h = h1;
    p1 = p1->next != h1 ? p1->next : NULL;
  }
  else {
    p = h = h2;
    p2 = p2->next != h2 ? p2->next : NULL;
  }

  while (p1  &&  p2) {
    if (p1->data < p2->data) {
      p = p->next = p1;
      p1 = p1->next != h1 ? p1->next : NULL;
    }
    else {
      p = p->next = p2;
      p2 = p2->next != h2 ? p2->next : NULL;
    }
  }

  while (p1) {
    p = p->next = p1;
    p1 = p1->next != h1 ? p1->next : NULL;
  }

  while (p2) {
    p = p->next = p2;
    p2 = p2->next != h2 ? p2->next : NULL;
  }

  return p->next = h;
}


void print(nodep h) {
  nodep p;
  if (!h) {
    printf("empty list!\n");
    return;
  }
  p = h;
  do {
    printf("[%d]%s", p->data, p->next == h ? "\t@\n\n" : "-> ");
  } while ((p = p->next) != h);
}


void destruct(nodep h) {
  nodep p, f;
  if (!h)
    return;
  p = f = h;
  do {
    p = p->next;
    free(f);
    f = p;
  } while (f != h);
}


int main() {
  nodep h1 = NULL, h2 = NULL, p = NULL;

  h1 = (nodep)calloc(1, sizeof(struct node_st));
  p = h1;
  p->data = 2;

  p->next = (nodep)calloc(1, sizeof(struct node_st));
  p = p->next;
  p->data = 4;

  p->next = (nodep)calloc(1, sizeof(struct node_st));
  p = p->next;
  p->data = 6;

  p->next = (nodep)calloc(1, sizeof(struct node_st));
  p = p->next;
  p->data = 8;

  p->next = (nodep)calloc(1, sizeof(struct node_st));
  p = p->next;
  p->data = 10;

  p->next = h1;




  h2 = (nodep)calloc(1, sizeof(struct node_st));
  p = h2;
  p->data = 1;

  p = p->next = (nodep)calloc(1, sizeof(struct node_st));
  p->data = 3;

  p = p->next = (nodep)calloc(1, sizeof(struct node_st));
  p->data = 5;

  p = p->next = (nodep)calloc(1, sizeof(struct node_st));
  p->data = 7;

  p = p->next = (nodep)calloc(1, sizeof(struct node_st));
  p->data = 9;

  p->next = h2;




  print(h1);
  print(h2);


  h1 = unite(h1, h2);

  print(h1);


  destruct(h1);
  /* destruct(h2); */

  return 0;
}
