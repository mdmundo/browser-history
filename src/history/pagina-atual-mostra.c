#ifndef PAGINA_ATUAL_MOSTRA_BROWSER_HISTORY
#define PAGINA_ATUAL_MOSTRA_BROWSER_HISTORY

#include <stdio.h>

#include "../base/structs-definition.c"

void PaginaAtualMostra(gerenciador *g) {
  if (g->paginaAtual != NULL) {
    puts("pAtual----");
    printf("link:%4d\n", g->paginaAtual->dado.link);
    puts("----------");
  }
}

#endif
