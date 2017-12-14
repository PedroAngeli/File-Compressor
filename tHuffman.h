#ifndef THUFFMAN_H
#define THUFFMAN_H

#include "bitmap.h"
#include "tLista.h"
#include "tArvore.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct tabela Tabela;

char* CriaCabecalho(Lista* p, char* cabecalho);
char** CriaVetorDeCodigos(Lista* p, char** codigo);
void IteraHuffman(Lista* lista);


#endif
