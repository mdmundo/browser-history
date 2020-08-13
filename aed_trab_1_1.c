#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _link {
	int link;
} link;

typedef struct _doubleNode {
	link dado;
	struct _doubleNode *prox;
	struct _doubleNode *ant;
} doubleNode;

typedef struct _gerenciador{
	doubleNode *paginaAtual;
} gerenciador;

typedef struct _node {
	link dado;
	struct _node *prox;
} node;

typedef struct _history{
	node *antigo;
	node *novo;
	int cnt;
} history;

int InputInt();
void MostraHistory_Recursiva(node *temp);
void MostraHistory(history *h);
void PaginaAtualMostra(gerenciador *g);
void VerificaHistory(history *h, int link);
void AddHistory(history *h, int link);
void AddGerenciador(gerenciador *g, int link);
void AbrirLink(gerenciador *g, history *h, int link);
void Avancar(gerenciador *g, history *h);
void Voltar(gerenciador *g, history *h);
void Iniciar(gerenciador *g, history *h);

void main() {
	gerenciador *g = (gerenciador *)malloc(sizeof(gerenciador));
	history *h = (history *)malloc(sizeof(history));
	Iniciar(g, h);
	while(1) {
		PaginaAtualMostra(g);
		puts("1 - Abrir Link");
		puts("2 - Voltar");
		puts("3 - Avancar");
		puts("4 - Mostrar History");
		puts("0 - Sair");
		puts("Digite uma opção:");
		switch(InputInt()){
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
				exit(1);
			default:
				puts("Opcao Invalida!");
				break;
		}
	}
}

void Iniciar(gerenciador *g, history *h) {
	g->paginaAtual = NULL;
	h->antigo = NULL;
	h->novo = NULL;
	h->cnt = 0;
}

void Voltar(gerenciador *g, history *h) {
	if (g->paginaAtual != NULL)
	{
		g->paginaAtual = (g->paginaAtual->ant == NULL ? g->paginaAtual : g->paginaAtual->ant);
		VerificaHistory(h, g->paginaAtual->dado.link);
	}
}

void Avancar(gerenciador *g, history *h) {
	if (g->paginaAtual != NULL)
	{
		g->paginaAtual = (g->paginaAtual->prox == NULL ? g->paginaAtual : g->paginaAtual->prox);
		VerificaHistory(h, g->paginaAtual->dado.link);
	}
}

void AbrirLink(gerenciador *g, history *h, int link) {
	AddGerenciador(g, link);
	VerificaHistory(h, link);
}

void AddGerenciador(gerenciador *g, int link) {
	doubleNode *temp = (doubleNode *)malloc(sizeof(doubleNode));
	temp->dado.link = link;
	temp->prox = NULL;
	if (g->paginaAtual == NULL)
	{
		g->paginaAtual = temp;
		g->paginaAtual->ant = NULL;
	} else {
		if (g->paginaAtual->prox != NULL)
		{
			doubleNode *temp_1 = g->paginaAtual->prox;
			while (temp_1->prox != NULL)
			{
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

void AddHistory(history *h, int link) {
		node *temp = (node *)malloc(sizeof(node));
		temp->dado.link = link;
		temp->prox = NULL;
		if (h->antigo == NULL)
		{
			h->novo = h->antigo = temp;
			h->cnt++;
		} else {
			h->novo->prox = temp;
			h->novo = temp;
			h->cnt++;
		}
}

void VerificaHistory(history *h, int link) {
	if (h->antigo != NULL)
	{
		if (h->novo->dado.link == link) return;
		if (h->antigo->dado.link == link)
		{
			h->novo->prox = h->antigo;
			h->novo = h->antigo;
			h->antigo = h->antigo->prox;		
			h->novo->prox = NULL;
			return;
		}
		node *temp_0 = h->antigo;
		while (temp_0->prox != NULL) {
			if (temp_0->prox->dado.link == link)
			{
				h->novo->prox = temp_0->prox;
				h->novo = temp_0->prox;
				temp_0->prox = temp_0->prox->prox;
				h->novo->prox = NULL;
				return;
			}
			temp_0 = temp_0->prox;
		}
		if (h->cnt >= 5) {
			temp_0 = h->antigo;
			h->antigo = h->antigo->prox;
			free(temp_0);
			h->cnt--;
			AddHistory(h, link);
			return;
		}
	}
	AddHistory(h, link);
}

void MostraHistory(history *h) {
	if (h->novo != NULL) {
		node *temp = h->antigo;
		MostraHistory_Recursiva(temp);
	}
}

void PaginaAtualMostra(gerenciador *g) {
	if (g->paginaAtual != NULL)
	{
		puts("pAtual----");
		printf("link:%4d\n", g->paginaAtual->dado.link);
		puts("----------");
	}
}

void MostraHistory_Recursiva(node *temp) {
	if (temp->prox != NULL)
	{
		MostraHistory_Recursiva(temp->prox);
	}
	puts("His-------");
	printf("link:%4d\n", temp->dado.link);
	puts("----------");
}

int InputInt() {
	char *endptr_i;
	char str_i[20];
	int i = -1;
	
	fgets(str_i, 20, stdin);
	i = strtol(str_i, &endptr_i, 0);
	
	if (*endptr_i != '\n' || str_i[0] == '\n' || endptr_i == str_i || i == -2147483648 || i == 2147483647)
	{
		puts("ERROR: Inteiro invalido, tente novamente");
		return InputInt();
	}
	return i;
}