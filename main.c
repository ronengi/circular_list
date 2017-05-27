#include <stdio.h>

#include "circular_list.h"
#include "circular_list_2.h"

int main() {
  node_p head1 = NULL, head2 = NULL;

  head1 = add(head1, 5);
  /* head1 = add(head1, 11); */
  /* head1 = add(head1, 7); */
  /* head1 = add(head1, 9); */
  /* head1 = add(head1, 9); */
  /* head1 = add(head1, 3); */
  /* head1 = add(head1, 3); */
  /* head1 = add(head1, 13); */

  head2 = add(head2, 2);
  /* head2 = add(head2, 6); */
  /* head2 = add(head2, 1); */
  /* head2 = add(head2, 10); */
  /* head2 = add(head2, 1); */
  /* head2 = add(head2, 16); */
  /* head2 = add(head2, 1); */
  /* head2 = add(head2, 18); */
  /* head2 = add(head2, 4); */
  /* head2 = add(head2, 8); */
  /* head2 = add(head2, 8); */


  print_list(head1);
  print_list(head2);


  head1 = join(head1, head2);
  head2 = NULL;
  print_list(head1);


  destruct(head1);
  /* destruct(head2); */
  return 0;
}


