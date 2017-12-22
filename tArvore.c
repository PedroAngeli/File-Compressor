#include "tArvore.h"
#include <string.h>
#include <stdio.h>

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

Arvore* CriaPai(Arvore* esq, Arvore* dir)
{
	int soma = ArvoreValor(esq) + ArvoreValor(dir);
	return CriaArvore(esq, dir, soma, '\0');
}

int ArvoreVazia(Arvore* arv)
{
	return (arv == NULL);
}

int ArvoreValor(Arvore* arv)
{
	return arv->valor;
}

char ArvoreInfo(Arvore* arv)
{
	return arv->info;
}

Arvore* ArvoreEsquerda(Arvore* arv)
{
	return arv->esquerda;
}

Arvore* ArvoreDireita(Arvore* arv)
{
	return arv->direita;
}

int TamanhoArvore(Arvore* arv){
	int i = 0;
	Arvore* p = arv;
	if(!ArvoreVazia(p)){
		i = 1;
		i += TamanhoArvore(p->esquerda);
		i += TamanhoArvore(p->direita);
	}
	return i;
}

void ImprimeArvore(Arvore *arv){
	Arvore* p = arv;
	printf("<");
	if(p != NULL){
		printf("(%c:%d)", p->info, p->valor);
		ImprimeArvore(p->esquerda);
		ImprimeArvore(p->direita);
	}
	printf(">");
}

