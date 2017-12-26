#ifndef TLISTA_H
#define TLISTA_H

#include "tArvore.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct lista Lista;

typedef struct celula Celula;


/*Cria uma lista (sentinela) vazia.
* inputs: nenhum.
* output: Ponteiro para lista (sentinela).
* pre-condicao: nenhuma
* pos-condicao: sentinela alocada.
*/
Lista* CriaListaVazia();


/*Preenche a lista (sentinela) com celulas alocadas
* alocando as arvores com frequencia e info nas celulas na lista.
* inputs: Ponteiro para lista de arvores, vetor com bytes do arquivos, vetor de
* frequencias e tamanho do arquivo
* output: nenhum.
* pre-condicao: sentinela alocada.
* pos-condicao: Lista de arvores preenchida.
*/
void CriaListaDeArvore(Lista* lista,unsigned char* bytesDoArquivo,long long unsigned int* frequencia,int tam);


/*Insere uma Arvore no primeiro elemento da lista.
* inputs: Ponteiro uma lista (sentinela) e ponteiro para uma arvore.
* output: nenhum.
* pre-condicao: sentinela alocada.
* pos-condicao: Arvore inserida na lista.
*/
void InsereNaLista(Lista* lista,Arvore* arv);


/*Procura o primeiro elemento com frequencia maior e insere antes dele.
* inputs: Ponteiro uma lista (sentinela) e ponteiro para uma arvore.
* output: nenhum.
* pre-condicao: sentinela alocada.
* pos-condicao: Arvore inserida na lista na posicao adequada (ordernada).
*/
void InsereOrdenado(Lista* lista, Arvore* arv);


/*Ordena a lista de arvores pela frequencia do caractere.
* inputs: Ponteiro uma lista (sentinela).
* output: nenhum.
* pre-condicao: nenhuma
* pos-condicao: Lista de arvores ordenada.
*/
void OrdenaLista(Lista* lista);


/*Imprime os elementos com suas frequencias
* inputs: Ponteiro uma lista (sentinela).
* output: nenhum.
* pre-condicao: nenhuma.
* pos-condicao: nenhuma.
*/
void ImprimeLista(Lista* lista);


/*Retorna o proximo elemento da lista.
* inputs: Ponteiro para uma celula da lista.
* output: Ponteiro para proxima celula.
* pre-condicao: Celula nao nula.
* pos-condicao: nenhuma.
*/
Celula* ListaProx(Celula* lista);


/*Retorna o primeiro elemento da lista.
* inputs: Ponteiro para a sentinela (lista)
* output: Ponteiro para primeira celula da lista.
* pre-condicao: sentinela alocada.
* pos-condicao: nenhuma.
*/
Celula* ListaPrimeiro(Lista* lista);


/*Retorna o ultimo elemento da lista.
* inputs: Ponteiro para a sentinela (lista)
* output: Ponteiro para ultima celula da lista.
* pre-condicao: sentinela alocada.
* pos-condicao: nenhuma.
*/
Celula* ListaUltimo(Lista* lista);


/*Retorna a arvore armazenada na celula.
* inputs: Ponteiro para celula da lista.
* output: Ponteiro para arvore armazenada na celula da lista.
* pre-condicao: sentinela alocada.
* pos-condicao: nenhuma.
*/
Arvore* ListaArvore(Celula* lista);


/*Aponta o primeiro elemento da lista para outra celula.
* inputs: Ponteiro para lista (sentinela) e ponteiro para celula destino.
* output: nenhum.
* pre-condicao: sentinela alocada.
* pos-condicao: Primeiro elemento da lista é a celula destino.
*/
void ModificaPrimeiro(Lista* lista, Celula* dest);


/*Aponta o ultimo elemento da lista para outra celula.
* inputs: Ponteiro para lista (sentinela) e ponteiro para celula destino.
* output: nenhum.
* pre-condicao: sentinela alocada.
* pos-condicao: Ultimo elemento da lista é a celula destino.
*/
void ModificaPrimeiro(Lista* lista, Celula* dest);


/*Libera Celula e seus conteudos
* inputs: Ponteiro para celula.
* output: nenhum.
* pre-condicao: nenhuma
* pos-condicao: celula liberada.
*/
void LiberaCelula(Celula* p);


/*Libera a lista inteira, suas celulas e conteudos
* inputs: Ponteiro para lista (sentinela)
* output: nenhum.
* pre-condicao: nenhuma
* pos-condicao: lista liberada.
*/
void LiberaLista(Lista* lista);

#endif
