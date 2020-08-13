#ifndef MOSTRA_HISTORY_RECURSIVA_BROWSER_HISTORY
#define MOSTRA_HISTORY_RECURSIVA_BROWSER_HISTORY

#include <stdio.h>

#include "../base/structs-definition.c"

void MostraHistory_Recursiva(node *temp) {
  if (temp->prox != NULL) {
    MostraHistory_Recursiva(temp->prox);
  }
  puts("His-------");
  printf("link:%4d\n", temp->dado.link);
  puts("----------");
}

#endif
