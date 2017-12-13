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

Arvore* CriaPai(Arvore* esq, Arvore* dir){
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

/*
void CriaCabecalho(Arvore* arv, char* header, char* value){
	Arvore* p = arv;
	int tam = TamanhoArvore(arv);
	char temp[2305];
	if(p != NULL){
		if(p->esquerda == NULL && p->direita == NULL)
		{
			char* temp2[2];
			temp2[0] = p->info;
			temp2[1] = '\0';
			strcat(header, temp2);
		}
		else
		{
			if(value != NULL){
				strcat(temp, value);
				CriaCabecalho(p->esquerda, header, "0");
				strcat(temp, value);
				CriaCabecalho(p->direita, header, "1");
				strcat(header, temp);
			}
		}
	}
}
*/

