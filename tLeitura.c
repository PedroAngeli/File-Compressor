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

void LerFormato(char* formato,FILE* entrada)
{
	fscanf(entrada,"%[^#]",formato);
	fscanf(entrada,"%*c");
}

void LeCabecalho(FILE* entrada,int tamanhoAparente)
{
	int tamanhoReal = ProxMultiploOito(tamanhoAparente);
	int tamanhoLixo = tamanhoReal - tamanhoAparente;

	bitmap cabecalho = bitmapInit(tamanhoReal);
	bitmap aux;
	int contador = 0;
	
	int vezes = (tamanhoAparente/8)+1;
	
	while(contador < vezes)
	{
		aux = bitmapInit(8);

		fscanf(entrada,"%c",&aux.contents[0]);
		
		aux.length=8;
		
		if(contador != vezes-1) for(int i=0;i<8;i++) bitmapAppendLeastSignificantBit(&cabecalho, bitmapGetBit(aux,i));
		
			contador++;
	}
	for(int i=0;i<8-tamanhoLixo;i++)
		bitmapAppendLeastSignificantBit(&cabecalho, bitmapGetBit(aux,i));
	
	unsigned char Cabecalho[tamanhoReal+1];

	//printf("%s",cabecalho.contents);
	int j=0;
	for(;j<cabecalho.length;j++)
	{
		printf("%d",bitmapGetBit(cabecalho,j));
		Cabecalho[j]=bitmapGetBit(cabecalho,j);
	}

	

}
