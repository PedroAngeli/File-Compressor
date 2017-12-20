#include "tLista.h"
#include <string.h>

struct celula
{
	Celula* prox;
	Arvore* arvore;
};

struct lista
{
	Celula *primeiro, *ultimo;
};

Arvore* ListaArvore(Celula* lista){
	return lista->arvore;
}

Celula* ListaPrimeiro(Lista* lista){
	return lista->primeiro;
}

Celula* ListaUltimo(Lista* lista){
	return lista->ultimo;
}

Celula* ListaProx(Celula* lista){
	return lista->prox;
}

void ModificaPrimeiro(Lista* lista, Celula* dest){
	lista->primeiro = dest;
}

void ModificaUltimo(Lista* lista, Celula* dest){
	lista->ultimo = dest;
}

Lista* CriaListaVazia()
{
	Lista* lista = (Lista*) malloc(sizeof(Lista));

	lista->primeiro = NULL;
	lista->ultimo = NULL;

	return lista;
}

void CriaListaDeArvore(Lista* lista,unsigned char* bytesDoArquivo,long long unsigned int* frequencia,int tam)
{
	for(int i=0;i<tam;i++)
		if(frequencia[i])
		{
			Arvore* no = CriaArvore(NULL,NULL,frequencia[i],(char)i);
			InsereNaLista(lista,no);
		}
}

void InsereNaLista(Lista* lista,Arvore* arv)
{
	Celula* nova = (Celula*) malloc(sizeof(Celula));

	if(!(lista->primeiro) && !(lista->ultimo))
	{
		lista->primeiro=nova;
		lista->ultimo=nova;
		nova->arvore=arv;
		nova->prox=NULL;
	}
	else
	{
		Celula* aux;
		aux=lista->primeiro;
		lista->primeiro=nova;
		nova->prox=aux;
		nova->arvore=arv;
	}
}

void InsereOrdenado(Lista* lista, Arvore* arv)
{
	Celula* p = (Celula*) malloc(sizeof(Celula));
	p->arvore = arv;
	Celula* ant;	

	for(Celula* aux =  lista->primeiro; aux!=NULL; aux=aux->prox)
	{
		if(ArvoreValor(aux->arvore) > ArvoreValor(p->arvore))
		{
			if(aux==lista->primeiro)
			{
				p->prox=aux;
				lista->primeiro=p;
				return;
			}
			else
			{
				p->prox=ant->prox;
				ant->prox=p;
				return;
			}
		}

		ant=aux;
	}

	lista->ultimo=p;
	ant->prox=p;
	p->prox=NULL;
}

void OrdenaLista(Lista* lista)
{

	if(lista->primeiro == NULL) return;
	if(lista->primeiro == lista->ultimo) return;
	Celula* p = lista->primeiro;
	Celula* t;
	Arvore* aux;
	while(p != NULL){
		t = p->prox;
		while(t != NULL){
			if(ArvoreValor(p->arvore) > ArvoreValor(t->arvore)){
				aux = p->arvore;
				p->arvore = t->arvore;
				t->arvore = aux;
			}
			t = t->prox;
		}
		p = p->prox;
	}

}

void ImprimeLista(Lista* lista)
{
	//tam=TamanhoDaLista(lista);

	for(Celula* p=lista->primeiro;p!=NULL;p=p->prox)
		printf("{%c:%d}\t",ArvoreInfo(p->arvore), ArvoreValor(p->arvore));
	printf("\n");
}
