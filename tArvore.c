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

char* CriaCabecalho(Arvore* arv, char* header, char* value){
	Arvore* p = arv;
	char temp[2305];
	char* ret1 = (char*) malloc(sizeof(char)*2305);
	char* ret2 = (char*) malloc(sizeof(char)*2305);
	if(p != NULL){
		if(TamanhoArvore(arv) == 1)
		{
			char temp2[2];
			temp2[0] = p->info;
			temp2[1] = '\0';
			strcat(header, value);
			strcat(header, temp2);
			return header;
		}
		else{
			if(value == NULL){
				strcpy(ret1, CriaCabecalho(p->esquerda, temp, "0"));
				strcpy(ret2, CriaCabecalho(p->direita, temp, "1"));
			}
			else{
				strcpy(temp, header);
				strcpy(ret1, CriaCabecalho(p->esquerda, strcat(temp, value), "0"));
				strcpy(temp, header);
				strcpy(ret2, CriaCabecalho(p->direita, strcat(temp, value), "1"));
			}
			if(ret1 != NULL && ret2 != NULL){
					strcat(ret1, ret2);
					return ret1;
			}
			else if(ret1 != NULL){
				return ret1;
			}
			else if(ret2 != NULL){
				return ret2;
			}
		}
	}

	return NULL;
}
