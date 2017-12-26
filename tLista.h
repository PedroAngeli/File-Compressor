#ifndef TLISTA_H
#define TLISTA_H

#include "tArvore.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct lista Lista;

typedef struct celula Celula;

Lista* CriaListaVazia();

void CriaListaDeArvore(Lista* lista,unsigned char* bytesDoArquivo,long long unsigned int* frequencia,int tam);

void InsereNaLista(Lista* lista,Arvore* arv);

void InsereOrdenado(Lista* lista, Arvore* arv);

void OrdenaLista(Lista* lista);

void ImprimeLista(Lista* lista);

Celula* ListaProx(Celula* lista);

Celula* ListaPrimeiro(Lista* lista);

Celula* ListaUltimo(Lista* lista);

Arvore* ListaArvore(Celula* lista);

void ModificaPrimeiro(Lista* lista, Celula* dest);

void ModificaPrimeiro(Lista* lista, Celula* dest);

void LiberaCelula(Celula* p);

void LiberaLista(Lista* lista);

#endif
