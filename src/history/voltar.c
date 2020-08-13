#ifndef VOLTAR_BROWSER_HISTORY
#define VOLTAR_BROWSER_HISTORY

#include <stdio.h>

#include "../base/structs-definition.c"
#include "tools/verifica-history.c"

void VerificaHistory(history *h, int link);

void Voltar(gerenciador *g, history *h) {
  if (g->paginaAtual != NULL) {
    g->paginaAtual =
        (g->paginaAtual->ant == NULL ? g->paginaAtual : g->paginaAtual->ant);
    VerificaHistory(h, g->paginaAtual->dado.link);
  }
}

#endif
