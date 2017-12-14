#ifndef TARVORE_H
#define TARVORE_H

#include <stdlib.h>

typedef struct arvore Arvore;

Arvore* CriaArvore(Arvore* esq,Arvore* dir,int valor,char info);

Arvore* CriaPai(Arvore* esq, Arvore* dir);

int ArvoreValor(Arvore* arv);

char ArvoreInfo(Arvore* arv);

int ArvoreVazia(Arvore* arv);

char* CriaCabecalho(Arvore* arv, char* header, char* value);

void ImprimeArvore(Arvore *arv);

int TamanhoArvore(Arvore* arv);

#endif
