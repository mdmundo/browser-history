#ifndef MOSTRA_HISTORY_BROWSER_HISTORY
#define MOSTRA_HISTORY_BROWSER_HISTORY

#include <stdio.h>

#include "../base/structs-definition.c"
#include "mostra-history-recursiva.c"

void MostraHistory(history *h) {
  if (h->novo != NULL) {
    node *temp = h->antigo;
    MostraHistory_Recursiva(temp);
  }
}

#endif
