#include <stdio.h>

#include "circular_list.h"

node_p join(node_p head1, node_p head2) {
    node_p cur1, next1, cur2, next2;

    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    if (head1->data > head2->data) {
        cur1 = head1;
        head1 = head2;
        head2 = cur1;
    }
    cur1 = head1;
    cur2 = head2;
    next1 = cur1->next;
    next2 = cur2->next;

    while (next1 != head1 && next2 != head2) {
        if (next1->data > cur2->data) {
            cur1->next = cur2;
            cur2->next = next1;
            cur1 = cur2;
            cur2 = next2;
            next2 = cur2->next;
        } else {
            cur1 = next1;
            next1 = cur1->next;
        }
    }

    if (next1 == head1) {
        cur1->next = cur2;
        while (next2 != head2) {
            cur2 = next2;
            next2 = cur2->next;
        }
        cur2->next = head1;
    } else {
        while (next1 != head1 && next1->data < cur2->data) {
            cur1 = next1;
            next1 = cur1->next;
        }
        cur1->next = cur2;
        cur2->next = next1;
    }

    return head1;
}
