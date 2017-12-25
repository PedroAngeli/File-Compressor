#include "tArvore.h"
#include "bitmap.h"
#include <string.h>
#include <stdio.h>
#include "PrintaArvore.h"

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
		printf(" %03d ", p->info);
		ImprimeArvore(p->esquerda);
		ImprimeArvore(p->direita);
	}
	printf(">");
}



int contadorDoCabecalho = -1;
int contadorDeFolhas = 0;
Arvore* CriaArvoreDescompactada(char* cabecalho, char* folhas){
	//preordem
	contadorDoCabecalho++;
	if((int)cabecalho[contadorDoCabecalho] == 1){
		Arvore* folha = CriaArvore(NULL, NULL, 1, folhas[contadorDeFolhas]);
		// printf("Achou folha(%c)\n", folhas[contadorDeFolhas]);
		contadorDeFolhas++;
		return folha;
	}
	Arvore* esq = CriaArvoreDescompactada(cabecalho, folhas);
	// printf("----------------ESQ-----------------\n");
	// print_t(esq);
	Arvore* dir = CriaArvoreDescompactada(cabecalho, folhas);
	// printf("----------------DIR-----------------\n");
	// print_t(dir);
	Arvore* no = CriaArvore(esq, dir, 0, '\0');
	// printf("----------------juntas-----------------\n");
	// print_t(no);
	return no;
}




char PercorreArvore(Arvore* arv, bitmap codigo,  int* pos){
	Arvore* p = arv;
	if(p->valor == 1){
			printf("|%c|\n", p->info);
			//(*pos)++;
			return p->info;
	}
	char cod = bitmapGetBit(codigo, *pos);
	printf("%d", cod);
	(*pos)++;

	if(cod == 0)
		return PercorreArvore(arv->esquerda, codigo, pos);
	else if(cod == 1)
		return PercorreArvore(arv->direita, codigo, pos);
	//(*pos)++;
}
