#include "tArvore.h"
#include "tLista.h"
#include "tLeitura.h"
#include "tHuffman.h"
#include "bitmap.h"

#define MAX_SIZE_OF_ASCII 256

int main(int argc,char** argv)
{
	char nomeArquivo[100];
	char acao[100];
	Lista* lista;

	VerificaParametro(argc);
	VerificaAcao(argc);

	NomeArquivo(argv[1],nomeArquivo);

	Acao(argv[2],acao);

	FILE* entrada =  AbrirArquivo('r',nomeArquivo);

	VerificaArquivo(entrada);

	long long unsigned int tamanhoDoArquivo = CalculaTamanhoArquivo(entrada);

	unsigned char bytesDoArquivo[tamanhoDoArquivo];

	LerArquivo(tamanhoDoArquivo,entrada,bytesDoArquivo);

	FecharArquivo(entrada);

	long long unsigned int frequencia[MAX_SIZE_OF_ASCII];

	ZeraFrequencia(frequencia,MAX_SIZE_OF_ASCII);

	VerificaFrequencia(frequencia,bytesDoArquivo,tamanhoDoArquivo);

	lista=CriaListaVazia();

	CriaListaDeArvore(lista,bytesDoArquivo,frequencia,MAX_SIZE_OF_ASCII);

	IteraHuffman(lista);

	bitmap cabecalho;

	cabecalho = bitmapInit(SIZE_MB);

	CriaCabecalho(&cabecalho,ListaArvore(ListaPrimeiro(lista)));

	Tabela* Huffman[MAX_SIZE_OF_ASCII];

	CriaTabelaVazia(Huffman,MAX_SIZE_OF_ASCII);

	bitmap bm = bitmapInit(SIZE_MB);

	CriaTabela(Huffman,bm,2,ListaArvore(ListaPrimeiro(lista)));

	GeraCompactado(Huffman,bytesDoArquivo,tamanhoDoArquivo);

	return 0;
}
