#ifndef AVANCAR_BROWSER_HISTORY
#define AVANCAR_BROWSER_HISTORY

#include <stdio.h>

#include "../base/structs-definition.c"
#include "tools/verifica-history.c"

void VerificaHistory(history *h, int link);

void Avancar(gerenciador *g, history *h) {
  if (g->paginaAtual != NULL) {
    g->paginaAtual =
        (g->paginaAtual->prox == NULL ? g->paginaAtual : g->paginaAtual->prox);
    VerificaHistory(h, g->paginaAtual->dado.link);
  }
}

#endif
