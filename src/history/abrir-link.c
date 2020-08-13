#ifndef ABRIR_LINK_BROWSER_HISTORY
#define ABRIR_LINK_BROWSER_HISTORY

#include "../base/structs-definition.c"
#include "tools/add-gerenciador.c"
#include "tools/verifica-history.c"

void VerificaHistory(history *h, int link);

void AbrirLink(gerenciador *g, history *h, int link) {
  AddGerenciador(g, link);
  VerificaHistory(h, link);
}

#endif
