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
	int verifica=1;
	Celula* ant;

	while(verifica)
	{
		verifica=0;

		for(Celula* p = lista->primeiro;p!=lista->ultimo;p=p->prox)
		{
				if(ArvoreValor(p->arvore) < ArvoreValor(p->prox->arvore))
				{
					if(p==lista->primeiro)
					{
						
					}
					else
					{
						
						
					}
					verifica=1;
				}
			
			ant=p;
		}
		
	}

}

void ImprimeLista(Lista* lista)
{
	//tam=TamanhoDaLista(lista);

	for(Celula* p=lista->primeiro;p!=NULL;p=p->prox)
		printf("%c ",ArvoreInfo(p->arvore));
}

