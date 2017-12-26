#include "tArvore.h"
#include "bitmap.h"
#include <string.h>
#include <stdio.h>

struct arvore
{
	Arvore* direita;
	Arvore* esquerda;
	unsigned char info;
	int valor;
};


Arvore* CriaArvore(Arvore* esq,Arvore* dir,int valor,unsigned char info)
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
		printf("%d", p->info);
		ImprimeArvore(p->esquerda);
		ImprimeArvore(p->direita);
	}
	printf(">");
}

int contadorDoCabecalho = -1;
int contadorDeFolhas = 0;
Arvore* CriaArvoreDescompactada(unsigned char* cabecalho, unsigned char* folhas){
	//preordem
	contadorDoCabecalho++;
	if((int)cabecalho[contadorDoCabecalho] == 1){
		Arvore* folha = CriaArvore(NULL, NULL, 0, folhas[contadorDeFolhas]);
		contadorDeFolhas++;
		return folha;
	}
	Arvore* esq = CriaArvoreDescompactada(cabecalho, folhas);
	Arvore* dir = CriaArvoreDescompactada(cabecalho, folhas);
	Arvore* no = CriaArvore(esq, dir, 0, '\0');
	return no;
}

unsigned char PercorreArvore(Arvore* arv, bitmap codigo,  int* pos){
	Arvore* p = arv;
	if(p != NULL)
	{
			if(p->esquerda == NULL && p->direita == NULL){
					//printf("|%d| ", p->info);
					return p->info;
			}
			//printf("|Travou no pos:%d|", (*pos)+1);
			unsigned char cod = bitmapGetBit(codigo, *pos);
			//printf("|%d:pos:%d|", cod, *pos);
			(*pos)++;

			if(cod == 0)
				return PercorreArvore(arv->esquerda, codigo, pos);
			else if(cod == 1)
				return PercorreArvore(arv->direita, codigo, pos);

	}
}

void LiberaArvore(Arvore* arv){
	if(arv!=NULL){
		LiberaArvore(arv->esquerda);
		LiberaArvore(arv->direita);
		free(arv);
	}
}
