#include "tLeitura.h"
#include "tArvore.h"
#include "PrintaArvore.h"
#include "tHuffman.h"

#define SIZE_MB 8000000
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

	for(i=0;i<tamanhoDoArquivo;i++)
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


void ObtemNomeSemExtensao(char* nomeDoArquivo, char* nomeSaida){
	int i, len = strlen(nomeDoArquivo);
	for(i = 0; i < len; i++){
		nomeSaida[i]=nomeDoArquivo[i];
		if(nomeDoArquivo[i] == '.'){
			break;
		}
	}
	nomeSaida[i]= '\0';
}

char* CriaStringChar(char c, char* str){
	str[0] = c;
	str[1] = '\0';
	return str;
}




void GeraDescompactado(FILE* entrada,int tamanhoAparenteCabecalho, char* nomeArquivo, char* formato)
{
	char nomeSaida[1000];
	ObtemNomeSemExtensao(nomeArquivo, nomeSaida);
	if(strcmp(formato, "")){
	strcat(nomeSaida, ".");
	strcat(nomeSaida, formato);
	}
	printf("Saida: %s\n", nomeSaida);
	FILE* saida = AbrirArquivo('w', nomeSaida);

	/*int tamanhoRealCabecalho = ProxMultiploOito(tamanhoAparenteCabecalho);
	int tamanhoLixoCabecalho = tamanhoRealCabecalho - tamanhoAparenteCabecalho;

	bitmap cabecalho = bitmapInit(tamanhoRealCabecalho);
	bitmap aux;


	int vezes = (tamanhoAparenteCabecalho/8)+1;
	*/
	int contador = 0;
	char cabecalho[tamanhoAparenteCabecalho+1];
	while(contador < tamanhoAparenteCabecalho)
	{
		fscanf(entrada,"%c", &cabecalho[contador]);
		printf("|%d|", cabecalho[contador]);
		contador++;
	}
	cabecalho[contador] = '\0';

	printf("\nCabecalho(%d:%d): ", contador, tamanhoAparenteCabecalho);
	for(int i= 0 ; i < tamanhoAparenteCabecalho; i++)
		printf("%d",cabecalho[i]);
	printf("\n");

	//cria vetor com as folhas
	int qntfolhas = ObtemQuantidadeDeFolhasCabecalho(cabecalho, tamanhoAparenteCabecalho);

	printf("qntfolhas:%d", qntfolhas);
	char folhas[qntfolhas+1];
	int i = 0;
	for(i = 0; i < qntfolhas; i++){
	  fscanf(entrada,"%c", folhas+i);
		printf("%03d ", folhas[i]);
	}

	int contadorFolhas = 0;
	Arvore* arvoreDeCodigo = CriaArvoreDescompactada(cabecalho, folhas);
	print_t(arvoreDeCodigo);
	ObtemFolhasDaArvore(arvoreDeCodigo, folhas, &contadorFolhas);

	printf("\nPrimeiraFolha: %03d\n", folhas[0]);
	printf("\n");
	for(int i = 0; i < contadorFolhas; i++)
		printf("%03d ", folhas[i]);
	printf("\n");

	long int tamanhoLixoCodigo;
	long int tamanhoRealCodigo;
	long int tamanhoAparenteCodigo;
	long int inicioDoCodigo = ftell(entrada);
	printf("inicioDoCodigo: %d\n", inicioDoCodigo);
	//Obtem tamanho do lixo do codigo, posicionado no final do arquivo
	fseek(entrada, 0, SEEK_END);
	long int finalDoCodigo = ftell(entrada);
	printf("finalDoCodigo: %d\n", finalDoCodigo);
	fseek(entrada, finalDoCodigo-1, SEEK_SET);
	fread(&tamanhoLixoCodigo, sizeof(char), 1, entrada);
	printf("TamanhoLIXO: %d\n", tamanhoLixoCodigo);
	fseek(entrada, inicioDoCodigo, SEEK_SET);

	tamanhoRealCodigo = (finalDoCodigo-inicioDoCodigo-1)*8;
	tamanhoAparenteCodigo = tamanhoRealCodigo-tamanhoLixoCodigo;


	printf("TamanhoReal: %d\n", tamanhoRealCodigo);
	printf("tamanhoAparenteCodigo: %d\n", tamanhoAparenteCodigo );
	bitmap codigoFinal = bitmapInit(tamanhoRealCodigo);
	fread(codigoFinal.contents, sizeof(char), tamanhoRealCodigo/8, entrada);
	codigoFinal.length = tamanhoAparenteCodigo;
	printf("MAXSIZE:%d LENGTH:%d\n", codigoFinal.max_size, codigoFinal.length);
	for(i=0;i<codigoFinal.length;i++){
		printf("%d", bitmapGetBit(codigoFinal, i));
	}
	printf("\n");

	int iterador = 0;
	int countCodigo = 0;
	char streamDeCodigo[SIZE_MB];
	streamDeCodigo[0] = '\0';
	int qntIteracoes = tamanhoAparenteCodigo;

	while(iterador < qntIteracoes)
	{
		//printf("iterador: %d\n", iterador);
		if(countCodigo != 0 && countCodigo%SIZE_MB == 0){
			fwrite(streamDeCodigo, sizeof(char), SIZE_MB, saida);
			streamDeCodigo[0] = '\0';
			countCodigo = 0;
		}
		char buffer = PercorreArvore(arvoreDeCodigo, codigoFinal, &iterador);
		printf("buffer:%c; count:%d\n", buffer, countCodigo);
		streamDeCodigo[countCodigo++] = buffer;

	}
	if(tamanhoAparenteCodigo-iterador<SIZE_MB){
		//printf("iterador: %d\n", iterador);
		printf("streamDeCodigo:%s|size:%d|\n", streamDeCodigo, strlen(streamDeCodigo));
		fwrite(streamDeCodigo, sizeof(char), strlen(streamDeCodigo), saida);
	}


}
