#ifndef TARVORE_H
#define TARVORE_H

#include <stdlib.h>
#include "bitmap.h"

typedef struct arvore Arvore;


/*Inicializa uma Arvore
* inputs: Ponteiros para as duas arvores filhas (pode ser NULl), frequencia da letra e a letra.
* output: Ponteiro para uma arvore com raiz alocada.
* pre-condicao: Nenhuma
* pos-condicao: Arvore com campos info e valor inicializadas.
*/
Arvore* CriaArvore(Arvore* esq,Arvore* dir,int valor,unsigned char info);


/*Cria uma Arvore Pai.
* inputs: Arvore da esquerda e da direita.
* output: Arvore pai com valor da soma das frequencias das filhas.
* pre-condicao: Argumentos não nulos.
* pos-condicao: Arvore com valor inicializado e ponteiros para filhos não-nulos.
*/
Arvore* CriaPai(Arvore* esq, Arvore* dir);


/*Retorna valor (frequencia) da Arvore
* inputs: Ponteiro para Arvore.
* output: inteiro armazenado no campo valor da arvore.
* pre-condicao: Arvore não nula.
* pos-condicao: nenhuma
*/
int ArvoreValor(Arvore* arv);


/*Retorna info (char) da Arvore
* inputs: Ponteiro para Arvore.
* output: caractere armazenado no campo info da arvore.
* pre-condicao: Arvore não nula.
* pos-condicao: nenhuma
*/
char ArvoreInfo(Arvore* arv);


/* Retorna se a arvore é vazia.
*  inputs: Ponteiro para arvore
*  output: Inteiro indicando verdadeiro ou falso.
** Pre-Condicao: nenhuma
** Pos-Condicao: Nenhuma
*/
int ArvoreVazia(Arvore* arv);


/*Imprime os elementos da arvore em preordem
* inputs: Ponteiro para Arvore.
* output: Nenhum.
* pre-condicao: nenhuma.
* pos-condicao: nenhuma.
*/
void ImprimeArvore(Arvore *arv);


/*Retorna a quantidade de nos da arvore.
* inputs: Ponteiro para Arvore.
* output: inteiro que indica a quantidade de nos da arvore.
* pre-condicao: Arvore não nula.
* pos-condicao: nenhuma
*/
int TamanhoArvore(Arvore* arv);

char* ObtemCodigoDoChar(Arvore* arv, char info, char* buffer, char* value);

char* GeraStringCabecalho(Arvore* arv, char* header, char* value);


/*Retorna arvore da esquerda
* inputs: Ponteiro para Arvore.
* output: Ponteiro para Arvore.
* pre-condicao: Arvore não nula.
* pos-condicao: nenhuma
*/
Arvore* ArvoreEsquerda(Arvore* arv);


/*Retorna arvore da direita
* inputs: Ponteiro para Arvore.
* output: Ponteiro para Arvore.
* pre-condicao: Arvore não nula.
* pos-condicao: nenhuma
*/
Arvore* ArvoreDireita(Arvore* arv);


/*Percorre o cabecalho, que indica as folhas e não folhas da arvore em preordem
* e cria uma arvore com folhas a partir disso, essa arvore sera usada na
* descompactacao para traduzir os codigos.
* inputs: string com cabecalho e string com as folhas.
* output: Ponteiro para arvore.
* pre-condicao: cabecalho e folhas nao vazias.
* pos-condicao: Arvore final construida com as folhas adequadas.
*/
Arvore* CriaArvoreDescompactada(unsigned char* cabecalho, unsigned char* folhas);


/*Percorre a arvore procurando uma folha seguindo o caminho do codigo.
* inputs: Ponteiro para arvore, bitmap de codigo, posicao do codigo atual.
* output: Caractere que o codigo representa.
* pre-condicao: Arvore nao nula.
* pos-condicao: nenhuma
*/
unsigned char PercorreArvore(Arvore* arv, bitmap codigo,  int* pos);


/*Libera os nos da arvore
* inputs: Ponteiro para arvore
* output: nenhum
* pre-condicao: nenhuma.
* pos-condicao: Arvore liberada.
*/
void LiberaArvore(Arvore* arv);

#endif
