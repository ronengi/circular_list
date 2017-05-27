#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "circular_list.h"

node_p add(node_p head, int data) {
    node_p cur, ind;
    if ((cur = (node_p) malloc(sizeof (struct node_st))) == NULL) error("Unable to allocate memory!\n");
    cur->data = data;

    if (head == NULL) {
        head = cur;
        head->next = head;
    } else {


        if (head->data > cur->data) {
            for (ind = head; ind->next != head; ind = ind->next)
                ;
            head = cur;
        } else
            for (ind = head; ind->next != head && ind->next->data <= cur->data; ind = ind->next)
                ;

        cur->next = ind->next;
        ind->next = cur;
    }

    return head;
}

void print_list(node_p head) {
    node_p ind;

    if (!head) {
        printf("Empty!\n");
        return;
    }

    for (ind = head; ind->next != head; ind = ind->next)
        printf("%d -> ", ind->data);
    printf("%d  -> (loop)%d\n", ind->data, head->data);
}

void destruct(node_p head) {
    node_p cur, next;
    if (head == NULL)
        return;

    cur = head;
    do {
        next = cur->next;
        free(cur);
        cur = next;
    } while (cur != head);
}

void error(char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    exit(EXIT_FAILURE);
}
