#include "tLista.h"

struct celula
{
	Celula* prox;
	Arvore* arvore;
};

struct lista
{
	Celula *primeiro, *ultimo;	
};
