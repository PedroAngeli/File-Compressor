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


/*Percorre a arvore e preenche um bitmap com o caminho ate as folhas, para criar
* o cabecalho.
* inputs: Ponteiro para arvore, Ponteiro para bitmap.
* output: nenhum.
* pre-condicao: nenhum.
* pos-condicao: Cabecalho preenchido.
*/
void CriaCabecalho(bitmap* cabecalho,Arvore* arv);

char** CriaVetorDeCodigos(Lista* p, char** codigo);


/*Percorre a lista de arvore e realiza os passos do arquivo de Huffman,
* ate sobrar so um elemento na lista de arvores.
* inputs: Ponteiro para lista de arvores.
* output: nenhum.
* pre-condicao: nenhum.
* pos-condicao: Lista de arvore com um so elemento.
*/
void IteraHuffman(Lista* lista);


/*Percorre a tabela de huffman e coloca os codigos bitmap adequados nos elementos
* inputs: Ponteiro para o vetor de tabela huffman, um bitmap temporario que
* sera usado para preencher os codigos e quando chegar no ultimo nivel coloca-lo
* na tabela, um inteiro indicando a direcao que o nivel superior percorreu (esquerda ou direita)
* um ponteiro para uma arvore, uma string de folhas, que armazenara as folhas.
* output: nenhum.
* pre-condicao: vetor de tabela alocado.
* pos-condicao: Codigos alocados na tabela, folhas alocadas no vetor de folhas.
*/
void ImprimeCabecalho(bitmap cabecalho);


/*Percorre a tabela de huffman e coloca os codigos bitmap adequados nos elementos
* inputs: Ponteiro para o vetor de tabela huffman, um bitmap temporario que
* sera usado para preencher os codigos e quando chegar no ultimo nivel coloca-lo
* na tabela, um inteiro indicando a direcao que o nivel superior percorreu (esquerda ou direita)
* um ponteiro para uma arvore, uma string de folhas, que armazenara as folhas.
* output: nenhum.
* pre-condicao: vetor de tabela alocado.
* pos-condicao: Codigos alocados na tabela, folhas alocadas no vetor de folhas.
*/
void CriaTabela(Tabela** huffman,char* buffer,int direcao,Arvore* arv, unsigned char* folhas,int indice);


/*Cria uma tabela do tipo Huffman (que possui o codigo de cada letra)
* inputs: Ponteiro para um vetor de tabela e inteiro com o tamanho da tabela (256 - Tamanho maximo da ascii)
* output: nenhum.
* pre-condicao: Ponteiro para vetor de tabelas já alocado.
* pos-condicao: Elementos da tabela alocados, e campos do elemento inicializados.
*/
void CriaTabelaVazia(Tabela** Huffman,int tam);


/*Retorna o campo bitmap (codigo) armazenado num elemento da tabela de codigos.
* inputs: Ponteiro para elemento da tabela de codigos.
* output: Variavel do tipo bitmap com o codigo do elemento da tabela.
* pre-condicao: Elemento não nulo.
* pos-condicao: nenhum.
*/
bitmap BitMapHuffman(Tabela* Huffman);


/*Escreve a extensão do arquivo que será compactado no arquivo de saida.
* inputs: string com nome do arquivo, ponteiro para arquivo de saida.
* output: nenhum.
* pre-condicao: arquivo de saida aberto.
* pos-condicao: extensao escrita no arquivo de saida.
*/
void EscreveExtensao(char* nomeDoArquivo, FILE* saida);


/*Gera o arquivo compactado, imprime no arquivo a extensão, o cabecalho e o codigo.
* inputs: vetor de tabela de codigos, vetor com os bytes armazenados no arquivo
* de entrada, o tamanho do arquivo de entrada, o arquivo de entrada, o arquivo
* de saida, o cabecalho que sera colocado na saida, o nome do arquivo de entrada,
* e um vetor com as folhas da arvore gerada.
* output: nenhum.
* pre-condicao: nenhuma.
* pos-condicao: arquivo de saida compactado gerado.
*/
void GeraCompactado(Tabela** Huffman,unsigned char* bytesDoArquivo,long long unsigned int tamanhoDoArquivo,FILE* entrada,FILE* saida, bitmap cabecalho, char* nomeDoArquivo,char* folhas);


/* Retorna o proximo muitiplo de oito do numero dado como argumento.
* inputs: numero.
* output: proximo multiplo de oito.
* pre-condicao: nenhum.
* pos-condicao: nenhum.
*/
unsigned int ProxMultiploOito(unsigned int tam);


/* Imprime o codigo compactado de cada caractere.
* inputs: vetor de tabela huffman, vetor de frequencia
* output: nenhum
* pre-condicao: nenhum.
* pos-condicao: nenhum.
*/
void PrintaBitMapHuffman(Tabela** Huffman,long long unsigned int* frequencia);


/* Funcao que percorre a arvore para cada caractere para encontrar seu código compactado.
* inputs: vetor de tabela huffman, Pointeiro para lista de arvores, string com as folahs da arvore.
* output: nenhum
* pre-condicao: nenhum.
* pos-condicao: vetor de tabela huffman preeenchido.
*/
void AchaCodigos(Tabela** Huffman,Lista* lista,char* folhas);


void LiberaTabela(Tabela** Huffman);

#endif
