#ifndef TLEITURA_H
#define TLEITURA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tHuffman.h"


FILE* AbrirArquivo(char c,char* nome);

void VerificaParametro(int argc);

void VerificaArquivo(FILE* arquivo);

long long unsigned int CalculaTamanhoArquivo(FILE* arquivo);

void LerArquivo(long long unsigned int tam,FILE* arquivo,unsigned char* bytesDoArquivo,long long unsigned int* frequencia);

void FecharArquivo(FILE* arquivo);

void ZeraFrequencia(long long unsigned int* frequencia,int tam);

void VerificaFrequencia(long long unsigned int* frequencia,unsigned char* bytesDoArquivo,long long unsigned int tamanhoDoArquivo);

void NomeArquivo(char* argv,char* nomeArquivo);

void Acao(char* argv,char* acao);

void VerificaAcao(int argc);

void LerFormato(char* formato,FILE* entrada);

void LeCabecalho(FILE* entrada,int tamanhoAparente);

#endif
