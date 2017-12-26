#include "tArvore.h"
#include "tLista.h"
#include "tLeitura.h"
#include "tHuffman.h"
#include "bitmap.h"

#define MAX_SIZE_OF_ASCII 256

int main(int argc,char** argv)
{
	char nomeArquivo[100];

	VerificaParametro(argc);

	NomeArquivo(argv[1],nomeArquivo);

	FILE* entrada =  AbrirArquivo('r',nomeArquivo);

	VerificaArquivo(entrada);

	char formato[10];

	LerFormato(formato,entrada);

	int tamanhoCabecalho;

	fread(&tamanhoCabecalho,sizeof(int),1,entrada);

	GeraDescompactado(entrada,tamanhoCabecalho, nomeArquivo, formato);

	return 0;
}
