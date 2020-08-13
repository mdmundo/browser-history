#ifndef VERIFICA_HISTORY_BROWSER_HISTORY
#define VERIFICA_HISTORY_BROWSER_HISTORY

#include <stdio.h>
#include <stdlib.h>

#include "../../base/structs-definition.c"
#include "add-history.c"

void VerificaHistory(history *h, int link) {
  if (h->antigo != NULL) {
    if (h->novo->dado.link == link) return;
    if (h->antigo->dado.link == link) {
      h->novo->prox = h->antigo;
      h->novo = h->antigo;
      h->antigo = h->antigo->prox;
      h->novo->prox = NULL;
      return;
    }
    node *temp_0 = h->antigo;
    while (temp_0->prox != NULL) {
      if (temp_0->prox->dado.link == link) {
        h->novo->prox = temp_0->prox;
        h->novo = temp_0->prox;
        temp_0->prox = temp_0->prox->prox;
        h->novo->prox = NULL;
        return;
      }
      temp_0 = temp_0->prox;
    }
    if (h->cnt >= 5) {
      temp_0 = h->antigo;
      h->antigo = h->antigo->prox;
      free(temp_0);
      h->cnt--;
      AddHistory(h, link);
      return;
    }
  }
  AddHistory(h, link);
}

#endif
