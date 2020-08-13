#include <stdio.h>
#include <stdlib.h>

#include "base/structs-definition.c"
#include "history/abrir-link.c"
#include "history/avancar.c"
#include "history/mostra-history.c"
#include "history/pagina-atual-mostra.c"
#include "history/voltar.c"
#include "utils/iniciar.c"
#include "utils/input-int.c"

int app(void) {
  gerenciador *g = (gerenciador *)malloc(sizeof(gerenciador));
  history *h = (history *)malloc(sizeof(history));
  Iniciar(g, h);
  while (1) {
    PaginaAtualMostra(g);
    puts("1 - Abrir Link");
    puts("2 - Voltar");
    puts("3 - Avancar");
    puts("4 - Mostrar History");
    puts("0 - Sair");
    puts("Digite uma opção:");
    switch (InputInt()) {
      case 1:
        puts("Link:");
        AbrirLink(g, h, InputInt());
        break;
      case 2:
        Voltar(g, h);
        break;
      case 3:
        Avancar(g, h);
        break;
      case 4:
        MostraHistory(h);
        break;
      case 0:
        return 0;
      default:
        puts("Opção Inválida!");
        break;
    }
  }
}