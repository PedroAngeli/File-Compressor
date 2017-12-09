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

void OrdenaLista(Lista* lista)
{

	//selection sort
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
	//bubblesort
	/*if(lista->primeiro == NULL) return;
	if(lista->primeiro == lista->ultimo) return;
	int verifica=1;
	Arvore* aux;

	while(verifica)
	{
		verifica=0;

		for(Celula* p = lista->primeiro;p!=lista->ultimo;p=p->prox)
		{
				if(ArvoreValor(p->arvore) < ArvoreValor(p->prox->arvore))
				{
					aux = p->arvore;
					p->prox->arvore = p->arvore;
					p->arvore = aux;
					verifica=1;
				}
		}

	}*/

}

void ImprimeLista(Lista* lista)
{
	//tam=TamanhoDaLista(lista);

	for(Celula* p=lista->primeiro;p!=NULL;p=p->prox)
		printf("%c ",ArvoreInfo(p->arvore));
}

void IteraHuffman(Lista* lista){
	OrdenaLista(lista);
	Arvore* arv;
	Celula* p = lista->primeiro;
	//Descomente o While quando fizer a funcao InsereOrdenado
	//while(p->prim != p->ultimo){
		arv = CriaPai(p->arvore, p->prox->arvore);
		//InsereOrdenado(arv);
		lista->primeiro = p->prox->prox;
	//}
}
