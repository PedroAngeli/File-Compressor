#ifndef TLEITURA_H
#define TLEITURA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tHuffman.h"

/*Abre o arquivo com nome especificado no modo especificado ('r' para leitura, qualquer outra coisa para escrita).
* inputs: caractere (modo de abertura), nome do arquivo.
* output: ponteiro para arquivo.
* pre-condicao: nenhum.
* pos-condicao: Arquivo aberto no modo adequado.
*/
FILE* AbrirArquivo(char c,char* nome);


/*Trata a entrada, sai do programa se o nome do arquivo nao for especificado.
* inputs: tamanho do argumento de execucao do programa.
* output: nenhum.
* pre-condicao: nenhum.
* pos-condicao: Sai ou se mantem no programa.
*/
void VerificaParametro(int argc);


/*Trata a entrada, sai do programa se a abertura do arquivo falhar.
* inputs: Ponteiro para o arquivo.
* output: nenhum.
* pre-condicao: nenhum.
* pos-condicao: Sai ou se mantem no programa.
*/
void VerificaArquivo(FILE* arquivo);


/*Calcula o tamanho em bytes do arquivo de entrada.
* inputs: Ponteiro para o arquivo.
* output: tamanho do arquivo
* pre-condicao: nenhuma.
* pos-condicao: nenhuma.
*/
long long unsigned int CalculaTamanhoArquivo(FILE* arquivo);


/*Le o arquivo e coloca a frequencia dos caracteres no vetor de frequencia.
* inputs: tamanho do arquivo, ponteiro para arquivo, string para armazenar os caracteres,
* ponteiro para o vetor de frequencia.
* output: tamanho do arquivo
* pre-condicao: nenhuma.
* pos-condicao: nenhuma.
*/
void LerArquivo(long long unsigned int tam,FILE* arquivo,unsigned char* bytesDoArquivo,long long unsigned int* frequencia);

/*Fecha o arquivo.
* inputs: Ponteiro para o arquivo.
* output: nenhum.
* pre-condicao: Arquivo aberto.
* pos-condicao: Arquivo fechado.
*/
void FecharArquivo(FILE* arquivo);


/*Inicializa a frequencia dos elementos do vetor de frequencia com zero.
* inputs: vetor de frequencia, tamanho do vetor de frequencia.
* output: nenhum.
* pre-condicao: nenhuma.
* pos-condicao: vetor de frequencia zerado.
*/
void ZeraFrequencia(long long unsigned int* frequencia,int tam);


/*Percorre o vetor com os bytes do arquivo e aumenta a frequencia dos caracteres no vetor de frequencia.
* inputs: vetor de frequencia, vetor de bytes do arquivo.
* output: nenhum.
* pre-condicao: nenhuma.
* pos-condicao: vetor de frequencia com frequencias adequadas para cada caractere.
*/
void VerificaFrequencia(long long unsigned int* frequencia,unsigned char* bytesDoArquivo,long long unsigned int tamanhoDoArquivo);


/*Copia o argumento de entrada "nome do arquivo" para uma string.
* inputs: argumento de entrada, string que ira armazena o nome do arquivo.
* output: nenhum.
* pre-condicao: nenhuma.
* pos-condicao: Nome do arquivo armazenado.
*/
void NomeArquivo(char* argv,char* nomeArquivo);

void Acao(char* argv,char* acao);

void VerificaAcao(int argc);


/*Le o formato armazenado no inicio do arquivo compactado, para poder descompactar com o formato correto.
* inputs: string que ira armazenar o formato, ponteiro para arquivo de entrada.
* output: nenhum.
* pre-condicao: nenhuma.
* pos-condicao: formato armazenado.
*/
void LerFormato(char* formato,FILE* entrada);


/*Percorre o cabecalho e contabiliza a quatidade de (1)s, que é a quantidade de folhas da arvore.
* inputs: string do cabecalho, tamanho do cabecalho.
* output: quantidade de folhas da arvore.
* pre-condicao: nenhuma.
* pos-condicao: nenhuma.
*/
int ObtemQuantidadeDeFolhasCabecalho(char* cabecalho, int tam);

/*Armazena o nome do arquivo sem a extensao no final.
* inputs: nome do arquivo, string que ira armazenar o nome do arquivo sem extensao.
* output: nenhum.
* pre-condicao: nenhuma.
* pos-condicao: nome sem extensao armazenada.
*/
void ObtemNomeSemExtensao(char* nomeDoArquivo, char* nomeSaida);



/*Gera o arquivo final descompactado
* Le o arquivo compactado, procura a extensao da saida
* le o cabecalho, cria a arvore geradora.
* Le o codigo compactado e percorre a arvore para achar os respectivos caracteres.
* inputs: Ponteiro para arquivo de entrada, tamanho do cabecalho, nome do arquivo de entrada, formato do mesmo.
* output: nenhum.
* pre-condicao: nenhuma.
* pos-condicao: nome sem extensao armazenada.
*/
void GeraDescompactado(FILE* entrada,int tamanhoAparenteCabecalho, char* nomeArquivo, char* formato);


/*Funcao auxiliar que cria uma string a partir de um caractere
* inputs: caractere, string destino
* output: nenhum.
* pre-condicao: nenhuma.
* pos-condicao: string preenchida.
*/
char* CriaStringChar(char c, char* str);

#endif
