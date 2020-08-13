#ifndef ADD_GERENCIADOR_BROWSER_HISTORY
#define ADD_GERENCIADOR_BROWSER_HISTORY

#include <stdio.h>
#include <stdlib.h>

#include "../../base/structs-definition.c"

void AddGerenciador(gerenciador *g, int link) {
  doubleNode *temp = (doubleNode *)malloc(sizeof(doubleNode));
  temp->dado.link = link;
  temp->prox = NULL;
  if (g->paginaAtual == NULL) {
    g->paginaAtual = temp;
    g->paginaAtual->ant = NULL;
  } else {
    if (g->paginaAtual->prox != NULL) {
      doubleNode *temp_1 = g->paginaAtual->prox;
      while (temp_1->prox != NULL) {
        temp_1 = temp_1->prox;
        free(temp_1->ant);
      }
      free(temp_1);
    }
    temp->ant = g->paginaAtual;
    g->paginaAtual->prox = temp;
    g->paginaAtual = temp;
  }
}

#endif
