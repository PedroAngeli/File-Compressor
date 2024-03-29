#include "tArvore.h"
#include "tLista.h"
#include "tLeitura.h"
#include "tHuffman.h"
#include "bitmap.h"

#define MAX_SIZE_OF_ASCII 256

int main(int argc,char** argv)
{
	char nomeArquivo[100];

	Lista* lista;

	VerificaParametro(argc);

	NomeArquivo(argv[1],nomeArquivo);

	FILE* entrada =  AbrirArquivo('r',nomeArquivo);

	VerificaArquivo(entrada);

	long long unsigned int tamanhoDoArquivo = CalculaTamanhoArquivo(entrada);

	long long unsigned int frequencia[MAX_SIZE_OF_ASCII];

	ZeraFrequencia(frequencia,MAX_SIZE_OF_ASCII);

	unsigned char bytesDoArquivo[SIZE_MB];

	LerArquivo(tamanhoDoArquivo,entrada,bytesDoArquivo,frequencia);

	FecharArquivo(entrada);

	lista=CriaListaVazia();

	CriaListaDeArvore(lista,bytesDoArquivo,frequencia,MAX_SIZE_OF_ASCII);

	IteraHuffman(lista);

	bitmap cabecalho;

	cabecalho = bitmapInit(SIZE_MB);

	CriaCabecalho(&cabecalho,ListaArvore(ListaPrimeiro(lista)));

	Tabela* Huffman[MAX_SIZE_OF_ASCII];

	CriaTabelaVazia(Huffman,MAX_SIZE_OF_ASCII);

	bitmap bm = bitmapInit(SIZE_MB);

	unsigned char folhas[MAX_SIZE_OF_ASCII];

	AchaCodigos(Huffman,lista,folhas);




	//ImprimeArvore(ListaArvore(ListaPrimeiro(lista)));


	//PrintaBitMapHuffman(Huffman,frequencia);

	entrada =  AbrirArquivo('r',nomeArquivo);

	VerificaArquivo(entrada);

	char nomeSaida[1000];
	ObtemNomeSemExtensao(nomeArquivo, nomeSaida);
	strcat(nomeSaida, ".comp");
	FILE* saida = AbrirArquivo('w', nomeSaida);

	VerificaArquivo(saida);

	GeraCompactado(Huffman,bytesDoArquivo,tamanhoDoArquivo,entrada,saida, cabecalho, nomeArquivo,folhas);

	FecharArquivo(entrada);
	FecharArquivo(saida);

	bitmapFreeContents(&cabecalho);
	bitmapFreeContents(&bm);
	LiberaTabela(Huffman);
	LiberaLista(lista);

	return 0;
}
