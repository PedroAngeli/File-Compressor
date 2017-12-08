#ifndef TLISTA_H
#define TLISTA_H

#include "tArvore.h"
#include <stdlib.h>

typedef struct lista Lista;

typedef struct celula Celula;

Lista* CriaListaVazia();

void CriaListaDeArvore(Lista* lista,unsigned char* bytesDoArquivo,long long unsigned int* frequencia,int tam);

void InsereNaLista(Lista* lista,Arvore* arv);

#endif
