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

int ObtemQuantidadeDeFolhasCabecalho(char* cabecalho, int tam){
	int count = 0, i;
	for(i = 0; i < tam; i++){
		if(cabecalho[i] == 1)
			count++;
	}
	return count;
}

void GeraDescompactado(FILE* entrada,int tamanhoAparenteCabecalho)
{
	int tamanhoRealCabecalho = ProxMultiploOito(tamanhoAparenteCabecalho);
	int tamanhoLixoCabecalho = tamanhoRealCabecalho - tamanhoAparenteCabecalho;

	bitmap cabecalho = bitmapInit(tamanhoRealCabecalho);
	bitmap aux;
	int contador = 0;

	int vezes = (tamanhoAparenteCabecalho/8)+1;

	while(contador < vezes)
	{
		aux = bitmapInit(8);

		fscanf(entrada,"%c",&aux.contents[0]);

		aux.length=8;

		if(contador != vezes-1) for(int i=0;i<8;i++) bitmapAppendLeastSignificantBit(&cabecalho, bitmapGetBit(aux,i));

			contador++;
	}
	for(int i=0;i<8-tamanhoLixoCabecalho;i++)
		bitmapAppendLeastSignificantBit(&cabecalho, bitmapGetBit(aux,i));

	unsigned char Cabecalho[tamanhoRealCabecalho+1];

	//printf("%s",cabecalho.contents);
	int j=0;
	for(;j<cabecalho.length;j++)
	{
		printf("%d", bitmapGetBit(cabecalho,j));
		Cabecalho[j]=bitmapGetBit(cabecalho,j);
	}

	//cria vetor com as folhas
	int qntfolhas = ObtemQuantidadeDeFolhasCabecalho(Cabecalho, tamanhoAparenteCabecalho);
	printf("qntfolhas:%d", qntfolhas);
	char folhas[qntfolhas+1];
	int i = 0;
	for(i = 0; i < qntfolhas; i++){
	  fscanf(entrada,"%c", folhas+i);
		printf("%c", folhas[i]);
	}

	Arvore* arvoreDeCodigo = CriaArvoreDescompactada(Cabecalho, folhas);
	ImprimeArvore(arvoreDeCodigo);


	long int tamanhoLixoCodigo;
	long int inicioDoCodigo = ftell(entrada);

	//Obtem tamanho do lixo do codigo, posicionado no final do arquivo
	fseek(entrada, -1, SEEK_END);
	fscanf(entrada, "%ld", &tamanhoLixoCodigo);
	tamanhoLixoCodigo-='0';
	long int finalDoCodigo = ftell(entrada);

	long int tamanhoRealCodigo = finalDoCodigo-inicioDoCodigo;
	long int tamanhoAparenteCodigo = tamanhoRealCodigo-tamanhoLixoCodigo;

	/*
	int contadorTotal = 0;
	int contadorPercorre = TamanhoMaxArvore;
	int vezes = (tamanhoAparenteCabecalho/8)+1;
	TamanhoMaxArvore = ProxMultiploOito(15);
	bitmap ant = bitmapInit(TamanhoMaxArvore*2);
	while(contadorTotal < vezes)
	{
		bitmap streamDeCodigo = bitmapInit(TamanhoMaxArvore*2);
		for(int i=contadorPercorre;i<ant.length-contadorPercorre;i++)
		{
			bitmapAppendLeastSignificantBit(&streamDeCodigo, bitmapGetBit(ant,i));
		}

		fread(bitmapGetContents(temporario), 1, TamanhoMaxArvore/8, entrada);
		for(i=0;i<TamanhoMaxArvore;)
		aux.length=TamanhoMaxArvore;

		aux2 = bitmapInit(16);
		fread(bitmapGetContents(temporario), 1, TamanhoMaxArvore/8-(streamDeCodigo.length), entrada);
		PercorreArvore(arvoreDeCodigo, &contador);


		contador++;
	}
	*/



}
