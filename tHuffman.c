#include "tHuffman.h"


struct tabela
{
	char c;
	bitmap bm;
};



char* CriaCabecalho(Lista* p, char* cabecalho){
	Arvore* arv = ListaArvore(ListaPrimeiro(p));
	char* valor = NULL;
	cabecalho = (char*) malloc(sizeof(char)*2035);
 	char* buffer = (char*) malloc(sizeof(char)*2035);
	cabecalho = GeraStringCabecalho(arv, buffer, valor);
	return cabecalho;
}

char** CriaVetorDeCodigos(Lista* p, char** codigo){
	Arvore* arv = ListaArvore(ListaPrimeiro(p));
	codigo = (char**) malloc(sizeof(char*)*256);
	char* buffer = (char*) malloc(sizeof(char)*20);
	int i;
	for(i = 0; i < 256; i++){
		codigo[i] = (char*) malloc(sizeof(char)*20);
		strcpy(buffer, ObtemCodigoDoChar(arv, (char)i, buffer, NULL));
		strcpy(codigo[i], buffer);
		codigo[i][strlen(buffer)-1] = '\0';
	}
	return codigo;
}

void IteraHuffman(Lista* lista){
	OrdenaLista(lista);
	Arvore* arv;
	Celula* p = ListaPrimeiro(lista);
	while(ListaPrimeiro(lista) != ListaUltimo(lista)){
		p = ListaPrimeiro(lista);
		arv = CriaPai(ListaArvore(p), ListaArvore(ListaProx(p)));
		InsereNoFinal(lista, arv);
		ModificaPrimeiro(lista, ListaProx(ListaProx(p)));
		OrdenaLista(lista);
	}
	/*Cabecalho
	char* header = (char*) malloc(sizeof(char)*2305);
	strcpy(header, CriaCabecalho(arv, NULL, NULL));
	printf("%s\n", header);
	char* header2 = (char*) malloc(sizeof(char)*2305);
	printf("%s", ObtemCodigoDoChar(arv, 'p', header2, NULL));
	char** codigo = (char**) malloc(sizeof(char*)*256);
	CriaVetorDeCodigos(arv, codigo);
	printf("%s\n", codigo['o']);
	Cabecalho*/
}
