#ifndef THUFFMAN_H
#define THUFFMAN_H

#include "bitmap.h"
#include "tLista.h"
#include "tArvore.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE_MB 8000000

typedef struct tabela Tabela;

void CriaCabecalho(bitmap* cabecalho,Arvore* arv);

char** CriaVetorDeCodigos(Lista* p, char** codigo);

void IteraHuffman(Lista* lista);

void ImprimeCabecalho(bitmap cabecalho);

void CriaTabela(Tabela** huffman,bitmap bm,int direcao,Arvore* arv,char* folhas);

void CriaTabelaVazia(Tabela** Huffman,int tam);

bitmap BitMapHuffman(Tabela* Huffman);

void EscreveExtensao(char* nomeDoArquivo, FILE* saida);

void GeraCompactado(Tabela** Huffman,unsigned char* bytesDoArquivo,long long unsigned int tamanhoDoArquivo,FILE* entrada,FILE* saida, bitmap cabecalho, char* nomeDoArquivo,char* folhas);

unsigned int ProxMultiploOito(unsigned int tam);

void ObtemFolhasDaArvore(Arvore* arv, char* folhas, int* contador);

#endif
