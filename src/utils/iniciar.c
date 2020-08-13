#ifndef INICIAR_BROWSER_HISTORY
#define INICIAR_BROWSER_HISTORY

#include <stdio.h>

#include "../base/structs-definition.c"

void Iniciar(gerenciador *g, history *h) {
  g->paginaAtual = NULL;
  h->antigo = NULL;
  h->novo = NULL;
  h->cnt = 0;
}

#endif
