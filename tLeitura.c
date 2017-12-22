#include "tLeitura.h"


FILE* AbrirArquivo(char c,char* nome)
{
	if(c=='r')
		return fopen(nome,"rb");

	return fopen(nome,"wb+");
}

void VerificaParametro(int argc)
{
	if(argc<=1)
	{
		printf("Digite o nome do arquivo.\n");
		exit(1);
	}
}

void VerificaArquivo(FILE* arquivo)
{
	if(arquivo==NULL)
	{
		printf("Erro ao abrir o arquivo.\n");
		exit(1);
	}
}

long long unsigned int CalculaTamanhoArquivo(FILE* arquivo)
{
    long long unsigned int posicaoAtual = ftell(arquivo);
 
    long long unsigned int tamanho;
 
    fseek(arquivo, 0, SEEK_END);
    tamanho = ftell(arquivo);
 
    fseek(arquivo, posicaoAtual, SEEK_SET);
 
    return tamanho;

}

void LerArquivo(long long unsigned int tam,FILE* arquivo,unsigned char* bytesDoArquivo,long long unsigned int* frequencia)
{
	while(tam>0)
	{
		int retorno = fread(bytesDoArquivo,sizeof(unsigned char),SIZE_MB,arquivo);
		tam-=retorno;
		VerificaFrequencia(frequencia,bytesDoArquivo,retorno);
		
	}
	
}

void FecharArquivo(FILE* arquivo)
{
	fclose(arquivo);
}

void ZeraFrequencia(long long unsigned int* frequencia,int tam)
{
	memset(frequencia,0,sizeof(long long unsigned int)*tam);
}

void VerificaFrequencia(long long unsigned int* frequencia,unsigned char* bytesDoArquivo,long long unsigned int tamanhoDoArquivo)
{
	int i;
	
	for(i=0;i<tamanhoDoArquivo-1;i++)
		frequencia[bytesDoArquivo[i]]++;

}
void NomeArquivo(char* argv,char* nomeArquivo)
{
	strcpy(nomeArquivo,argv);
}

void Acao(char* argv,char* acao)
{
	strcpy(acao,argv);
}

void VerificaAcao(int argc)
{
	if(argc<=2)
	{
		printf("Digite a acao desejada.\n");
		exit(1);
	}

}
