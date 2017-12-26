#ifndef TARVORE_H
#define TARVORE_H

#include <stdlib.h>
#include "bitmap.h"

typedef struct arvore Arvore;

Arvore* CriaArvore(Arvore* esq,Arvore* dir,int valor,unsigned char info);

Arvore* CriaPai(Arvore* esq, Arvore* dir);

int ArvoreValor(Arvore* arv);

char ArvoreInfo(Arvore* arv);

int ArvoreVazia(Arvore* arv);

void ImprimeArvore(Arvore *arv);

int TamanhoArvore(Arvore* arv);

char* ObtemCodigoDoChar(Arvore* arv, char info, char* buffer, char* value);

char* GeraStringCabecalho(Arvore* arv, char* header, char* value);

Arvore* ArvoreEsquerda(Arvore* arv);

Arvore* ArvoreDireita(Arvore* arv);

Arvore* CriaArvoreDescompactada(unsigned char* cabecalho, unsigned char* folhas);

unsigned char PercorreArvore(Arvore* arv, bitmap codigo,  int* pos);

void LiberaArvore(Arvore* arv);

#endif
