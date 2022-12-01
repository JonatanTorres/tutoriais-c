#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
	int info;
	struct lista *ant;
	struct lista *prox;
} TLDE; // Tipo Lista Duplamente Encadeada

/*Prot�tipo de fun��es -colocar no TLDE.h*/
TLDE *insere_ini(TLDE *l, int elem);

/*Inicializar Lista - igual a TLSE*/
TLDE *inicializa(void)
{
	return NULL;
}

/*Liberar a lista da mem�ria - vers�o iterativa - igual a TLSE*/
void libera(TLDE *l)
{
	TLDE *p = l;
	while (p)
	{
		TLDE *t = p;
		p = p->prox;
		free(t);
	}
}

/*Liberar a lista da mem�ria - vers�o recursiva - igual a TLSE*/
// Obs:libera de tr�s para frente.
void libera_rec(TLDE *l)
{
	if (l)
	{
		libera_rec(l->prox);
		free(l);
	}
}

/*Imprimir  - Vers�o iterativa - igual a TLSE*/
TLDE *imprimir(TLDE *l)
{
	TLDE *p = l;
	while (p)
	{
		printf("%d ", p->info);
		p = p->prox;
	}
}

/*Imprimir  - Vers�o recursiva - igual a TLSE*/
TLDE *imprimir_rec(TLDE *l)
{
	if (l)
	{
		printf("%d ", l->info);
		imprimir_rec(l->prox);
	}
}

/*Imprimir Reverso  - Vers�o iterativa - igual a TLSE*/
TLDE *imprimir_reverso(TLDE *l)
{
	TLDE *p = l, *laux = inicializa();
	while (p)
	{
		laux = insere_ini(laux, p->info);
		p = p->prox;
	}
	imprimir(laux);
	libera(laux);
}

/*Imprimir Reverso  - Vers�o recursiva - igual a TLSE*/
TLDE *imprimir_reverso_rec(TLDE *l)
{
	if (l)
	{ // bastou inverter as linhas do imprimir_rec
		imprimir_rec(l->prox);
		printf("%d ", l->info);
	}
}

/*Imprimir Ida e Volta*/
TLDE *imprimir_ida_volta(TLDE *l)
{
	TLDE *p = l, *aux;
	printf("Ida: ");
	while (p)
	{
		printf("%d ", p->info);
		if (!p->prox)
		{
			aux = p;
		}
		p = p->prox;
	}
	printf("  Volta: ");
	while (aux)
	{
		printf("%d ", aux->info);
		aux = aux->ant;
	}
}

/*Busca  - Vers�o iterativa - igual a TLSE*/
TLDE *busca(TLDE *l, int x)
{
	TLDE *resp = l;
	while ((resp) && (resp->info != x))
	{
		resp = resp->prox;
	}
	return resp;
}

/*Busca  - Vers�o recursiva - igual a TLSE*/
TLDE *busca_rec(TLDE *l, int x)
{
	if (!l || (l->info == x))
		return l;
	return busca_rec(l->prox, x);
}

/*Inserir no in�cio - vers�o iterativa*/
TLDE *insere_ini(TLDE *l, int elem)
{
	TLDE *novo = (TLDE *)malloc(sizeof(TLDE));
	if (!novo)
		exit(1);
	novo->info = elem;
	novo->ant = NULL;
	if (l)
		l->ant = novo;
	novo->prox = l;
	return novo;
}

/*Inserir no fim - vers�o iterativa*/
TLDE *insere_fim(TLDE *l, int elem)
{
	TLDE *p = l;
	while (p && p->prox)
		p = p->prox;
	TLDE *novo = (TLDE *)malloc(sizeof(TLDE));
	if (!novo)
		exit(1);
	novo->info = elem;
	novo->ant = p;
	novo->prox = NULL;
	if (p)
		p->prox = novo;
	else
		l = novo;
	return l;
}

/*Inserir no fim - vers�o recursiva - Desenvolvido por Andr�*/
TLDE *insere_fim_rec(TLDE *l, int elem)
{
	if (!l || l->ant == NULL)
	{
		return insere_ini(l, elem);
	}
	else if (!l->prox)
	{ // ou <=
		TLDE *novo = (TLDE *)malloc(sizeof(TLDE));
		if (!novo)
			exit(1);
		novo->info = elem;
		novo->ant = l;
		l->prox = novo;
		novo->prox = NULL;
		return l;
	}
	l->prox = insere_fim_rec(l->prox, elem);
}

/*Inserir ordenado - vers�o iterativa*/
TLDE *insere_ord(TLDE *l, int elem)
{
	if (!l || (l->info >= elem)) // lista vazia ou inser��o no in�cio
		return insere_ini(l, elem);
	TLDE *p = l;
	while ((p->prox) && (p->info < elem))
	{
		p = p->prox;
	}
	TLDE *novo = insere_ini(NULL, elem);
	if (!p->prox && p->info < elem)
	{ // Inser��o no fim
		p->prox = novo;
		novo->ant = p;
	}
	else
	{ // inser��o no meio
		novo->prox = p;
		p->ant->prox = novo;
		novo->ant = p->ant;
		p->ant = novo;
	}
	return l;
}

/*Inserir ordenado - vers�o recursiva - Densevolvido por Andr� Lucio*/
TLDE *insere_ord_rec(TLDE *l, int elem)
{
	// prim parte do if lista vazia e a seg parte inser��o no in�cio
	if (!l || ((l->info >= elem) && (l->ant == NULL)))
	{
		return insere_ini(l, elem);
	}
	else if (!l->prox && l->info < elem)
	{ // ou <=
		return insere_fim(l, elem);
	}

	if (l->info >= elem)
	{
		TLDE *novo = (TLDE *)malloc(sizeof(TLDE));
		if (!novo)
			exit(1);
		novo->info = elem;
		novo->ant = l->ant;
		novo->prox = l;
		l->ant = novo;
		return novo;
	}
	else
	{
		l->prox = insere_ord_rec(l->prox, elem);
	}
}

/*Retirar a primeira ocorr�ncia de x  - vers�o iterativa*/
TLDE *retira_1_ocorr(TLDE *l, int x)
{
	TLDE *p = busca(l, x);
	if (!p)
		return l;
	if (!p->ant)
		l = l->prox; // remo��o na frente
	else
		p->ant->prox = p->prox;
	if (p->prox)
		p->prox->ant = p->ant;
	free(p);
	return l;
}

int main(int argc, char *argv[])
{
	TLDE *l;
    l = inicializa();
	l = insere_ord(l, 2);
	l = insere_ord(l, 5);
	l = insere_ord(l, 9);
	l = insere_ord(l, 7);
    l = insere_ord(l, 10);
	/*
	printf("\nInserir inicio - iterativo\n");
	l = inicializa();
	l = insere_ini(l, 10);
	l = insere_ini(l, 11);
	l = insere_ini(l, 12);
	imprimir_ida_volta(l);
	printf("\nInserir fim - iterativo\n");
	l = inicializa();
	l = insere_fim(l, 10);
	l = insere_fim(l, 11);
	l = insere_fim(l, 12);
	imprimir_ida_volta(l);
	printf("\nInserir fim - recursivo\n");
	l = inicializa();
	l = insere_fim_rec(l, 10);
	l = insere_fim_rec(l, 11);
	l = insere_fim_rec(l, 12);
	imprimir_ida_volta(l);
	printf("\nInserir ordenado - iterativo\n");
	l = inicializa();
	l = insere_ord(l, 13);
	l = insere_ord(l, 12);
	l = insere_ord(l, 11);
	l = insere_ord(l, 10);
	imprimir_ida_volta(l);
	printf("\nInserir ordenado - recursivo\n");
	l = inicializa();
	l = insere_ord_rec(l, 20);
	l = insere_ord_rec(l, 10);
	l = insere_ord_rec(l, 30);
	l = insere_ord_rec(l, 15);
	l = insere_ord_rec(l, 18);
	imprimir_ida_volta(l);
	printf("\nRetirar inicio\n");
	l = retira_1_ocorr(l, 10);
	imprimir_ida_volta(l);
	printf("\nRetirar fim\n");
	l = retira_1_ocorr(l, 30);
	imprimir_ida_volta(l);
	printf("\nRetirar meio\n");
	l = retira_1_ocorr(l, 18);
	imprimir_ida_volta(l);*/

	return 0;
}