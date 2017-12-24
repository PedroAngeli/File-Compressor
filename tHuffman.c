#include "tHuffman.h"
#include "tLeitura.h"

struct tabela
{
	char c;
	bitmap bm;
};

bitmap BitMapHuffman(Tabela* Huffman)
{
	return Huffman->bm;
}


void CriaTabelaVazia(Tabela** Huffman,int tam)
{

	for(int i=0;i<tam;i++)
	{
		Huffman[i]= (Tabela*) malloc(sizeof(Tabela));
		Huffman[i]->bm = bitmapInit(SIZE_MB);
		Huffman[i]->c=(char)i;
	}

}

int count=0;

void CriaTabela(Tabela** huffman,bitmap bm,int direcao,Arvore* arv,char* folhas)
{

	if(arv==NULL) return;

	if(direcao==1) bitmapAppendLeastSignificantBit(&bm,'1');
	else if(direcao==0) bitmapAppendLeastSignificantBit(&bm,'0');


	if(ArvoreEsquerda(arv)==NULL && ArvoreDireita(arv)==NULL)
	{
		folhas[count] = ArvoreInfo(arv);






		count++;
		strncpy(bitmapGetContents(huffman[(unsigned char)ArvoreInfo(arv)]->bm),bitmapGetContents(bm),bitmapGetLength(bm));
		huffman[(unsigned char)ArvoreInfo(arv)]->bm.max_size = bitmapGetMaxSize(bm);
		huffman[(unsigned char)ArvoreInfo(arv)]->bm.length =  bitmapGetLength(bm);

		printf("\n Letra: %c %03d -> ", ArvoreInfo(arv), ArvoreInfo(arv));
		for(int i =0; i < bm.length; i++)
			printf("%d", bitmapGetBit(bm, i));
		printf("\n");

		return;
	}

	CriaTabela(huffman,bm,0,ArvoreEsquerda(arv),folhas);
	if(direcao==2) bm = bitmapInit(SIZE_MB);
	CriaTabela(huffman,bm,1,ArvoreDireita(arv),folhas);

}

void ObtemFolhasDaArvore(Arvore* arv, char* folhas, int* contador){

		if(arv==NULL) return;

		if(ArvoreValor(arv)==1)
		{
			folhas[*contador] = ArvoreInfo(arv);
			printf("Achou folha! %03d\n", folhas[*contador]);
			printf("Contador:%d\n", *contador);
			(*contador)++;
			return;
		}

		ObtemFolhasDaArvore(ArvoreEsquerda(arv), folhas, contador);
		ObtemFolhasDaArvore(ArvoreDireita(arv), folhas, contador);
}

void CriaCabecalho(bitmap* cabecalho,Arvore* arv)
{
	if(arv==NULL) return;

	if(ArvoreEsquerda(arv)==NULL && ArvoreDireita(arv)==NULL)
	{
		bitmapAppendLeastSignificantBit(cabecalho,'1');
		return;
	}

	bitmapAppendLeastSignificantBit(cabecalho,'0');

	CriaCabecalho(cabecalho,ArvoreEsquerda(arv));


	CriaCabecalho(cabecalho,ArvoreDireita(arv));

}

void EscreveExtensao(char* nomeDoArquivo, FILE* saida){
	int i, TemPonto = 0;
	for(i = 0; i < strlen(nomeDoArquivo); i++){
		if(nomeDoArquivo[i] == '.'){
			TemPonto = 1;
			i++;
			break;
		}
	}
	if(TemPonto){
		fwrite(nomeDoArquivo+i, sizeof(unsigned char), strlen(nomeDoArquivo)-i, saida);
	}
	fwrite("#", sizeof(unsigned char), 1, saida);
	printf("enttensao:%s", nomeDoArquivo+i);
}



void GeraCompactado(Tabela** Huffman,unsigned char* bytesDoArquivo,long long unsigned int tamanhoDoArquivo,FILE* entrada,FILE* saida, bitmap cabecalho, char* nomeDoArquivo,char* folhas)
{
	bitmap all = bitmapInit(SIZE_MB);
	EscreveExtensao(nomeDoArquivo, saida);

	int tamanhoCabecalho = (int)bitmapGetLength(cabecalho);
	fwrite(&tamanhoCabecalho,sizeof(int),1,saida);
	//fwrite(bitmapGetContents(cabecalho), sizeof(unsigned char), ProxMultiploOito(bitmapGetLength(cabecalho))/8, saida);
	printf("Cabecalho: ");
	for(int i = 0; i < cabecalho.length; i++){
		unsigned char str[2];
		CriaStringChar(bitmapGetBit(cabecalho, i), str);
		fwrite(&str[0], sizeof(unsigned char), 1, saida);
		printf("%d", str[0]);
	}
	printf("\nFolhas:%d\n", strlen(folhas));
	for(int i = 0; i < strlen(folhas); i++)
		printf("%03d ", folhas[i]);
	fwrite(folhas,sizeof(unsigned char),strlen(folhas),saida);

	while(tamanhoDoArquivo>0)
	{
		int retorno = fread(bytesDoArquivo,sizeof(char),SIZE_MB,entrada);
		tamanhoDoArquivo-=retorno;

		for(int i=0;i<retorno-1;i++)
		{
			for(int j=0;j<bitmapGetLength(Huffman[bytesDoArquivo[i]]->bm);j++)
			{
				if(bitmapGetLength(all) < SIZE_MB)
					bitmapAppendLeastSignificantBit(&all,bitmapGetBit(Huffman[bytesDoArquivo[i]]->bm,j));

				else
				{
					fwrite(bitmapGetContents(all),sizeof(unsigned char),bitmapGetLength(all),saida);
					bitmap all = bitmapInit(SIZE_MB);
					bitmapAppendLeastSignificantBit(&all,bitmapGetBit(Huffman[bytesDoArquivo[i]]->bm,j));
				}
			}
		}

	}

	long int tamanhoCodigo = ProxMultiploOito(bitmapGetLength(all));
	printf("bitmapGetLength(all):%d\n", bitmapGetLength(all));
	printf("Tamanho do codigo: %d\n", tamanhoCodigo);
	fwrite(bitmapGetContents(all),sizeof(unsigned char),tamanhoCodigo/8,saida);
	int tamanhoLixo = tamanhoCodigo-bitmapGetLength(all);
	printf("Tamanho do lixo: %d\n", tamanhoLixo);
	fwrite(&tamanhoLixo,1,1,saida);

}


unsigned int ProxMultiploOito(unsigned int tam){
	int i;
	for(i = tam; i < tam+9; i++){
		if(i%8 == 0){
			break;
		}
	}
	return i;

}



void IteraHuffman(Lista* lista)
{
	OrdenaLista(lista);
	Arvore* arv;
	Celula* p;

	while(ListaPrimeiro(lista) != ListaUltimo(lista))
		{
			p = ListaPrimeiro(lista);
			arv = CriaPai(ListaArvore(p), ListaArvore(ListaProx(p)));
			InsereOrdenado(lista, arv);
			ModificaPrimeiro(lista, ListaProx(ListaProx(p)));
			free(ListaProx(p));
			free(p);

		}

}
