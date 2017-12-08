#include "tArvore.h"


struct arvore
{
	Arvore* direita;
	Arvore* esquerda;
	char info;
	int valor;
};


Arvore* CriaArvore(Arvore* esq,Arvore* dir,int valor,char info)
{
	Arvore* arv = (Arvore*) malloc(sizeof(Arvore));

	arv->esquerda=esq;
	arv->direita=dir;
	arv->valor=valor;
	arv->info=info;

	return arv;
}

