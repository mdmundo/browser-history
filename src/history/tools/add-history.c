#ifndef ADD_HISTORY_BROWSER_HISTORY
#define ADD_HISTORY_BROWSER_HISTORY

#include <stdio.h>
#include <stdlib.h>

#include "../../base/structs-definition.c"

void AddHistory(history *h, int link) {
  node *temp = (node *)malloc(sizeof(node));
  temp->dado.link = link;
  temp->prox = NULL;
  if (h->antigo == NULL) {
    h->novo = h->antigo = temp;
    h->cnt++;
  } else {
    h->novo->prox = temp;
    h->novo = temp;
    h->cnt++;
  }
}

#endif
