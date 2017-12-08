#include "tArvore.h"
#include "tLista.h"
#include "tLeitura.h"

#define MAX_SIZE_OF_ASCII 256

int main(int argc,char** argv)
{
	char nomeArquivo[100];
	char acao[100];

	VerificaParametro(argc);

	NomeArquivo(argv[1],nomeArquivo);
		
	FILE* entrada =  AbrirArquivo('r',nomeArquivo);

	VerificaArquivo(entrada);

	Acao(argv[2],acao);

	long long unsigned int tamanhoDoArquivo = CalculaTamanhoArquivo(entrada);

	unsigned char bytesDoArquivo[tamanhoDoArquivo]; 

	LerArquivo(tamanhoDoArquivo,entrada,bytesDoArquivo);

	FecharArquivo(entrada);

	long long unsigned int frequencia[MAX_SIZE_OF_ASCII];

	ZeraFrequencia(frequencia,MAX_SIZE_OF_ASCII);

	VerificaFrequencia(frequencia,bytesDoArquivo,tamanhoDoArquivo);

	for(int i=0;i<257;i++)
		printf("%c:  %llu\n",(char)i,frequencia[i]);

	
	return 0;
}
