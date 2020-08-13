#ifndef STRUCTS_DEFINITION_BROWSER_HISTORY
#define STRUCTS_DEFINITION_BROWSER_HISTORY

typedef struct _link {
  int link;
} link;

typedef struct _doubleNode {
  link dado;
  struct _doubleNode *prox;
  struct _doubleNode *ant;
} doubleNode;

typedef struct _gerenciador {
  doubleNode *paginaAtual;
} gerenciador;

typedef struct _node {
  link dado;
  struct _node *prox;
} node;

typedef struct _history {
  node *antigo;
  node *novo;
  int cnt;
} history;

#endif
