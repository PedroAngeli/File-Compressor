#include "tHuffman.h"


struct tabela
{
	unsigned char c;
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
		Huffman[i]->c=(unsigned char)i;
	}

}


void AchaCodigos(Tabela** Huffman,Lista* lista,char* folhas)
{

	char buffer[100000];


	CriaTabela(Huffman,buffer,2,ListaArvore(ListaPrimeiro(lista)),folhas,-1);

}

int count=0;

void CriaTabela(Tabela** huffman,char* buffer,int direcao,Arvore* arv,unsigned char* folhas,int indice)
{

	if(arv==NULL) return;

	if(direcao==1) buffer[indice] = '1';
	else if(direcao==0) buffer[indice] = '0';

	if(ArvoreEsquerda(arv)==NULL && ArvoreDireita(arv)==NULL)
	{
		buffer[indice+1] = '\0';
		//if(ArvoreInfo(arv)=='\0') printf("%s",buffer);
		folhas[count] = ArvoreInfo(arv);
		count++;
		huffman[(unsigned char)ArvoreInfo(arv)]->bm.max_size = SIZE_MB;
		 for(int i=0;i<strlen(buffer);i++)
			bitmapAppendLeastSignificantBit(&huffman[(unsigned char)ArvoreInfo(arv)]->bm,buffer[i]);
		huffman[(unsigned char)ArvoreInfo(arv)]->bm.length =  strlen(buffer);
		return;
	}

	CriaTabela(huffman,buffer,0,ArvoreEsquerda(arv),folhas,indice + 1);

	CriaTabela(huffman,buffer,1,ArvoreDireita(arv),folhas,indice + 1);

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
}



void GeraCompactado(Tabela** Huffman,unsigned char* bytesDoArquivo,long long unsigned int tamanhoDoArquivo,FILE* entrada,FILE* saida, bitmap cabecalho, char* nomeDoArquivo,char* folhas)
{
	bitmap all = bitmapInit(SIZE_MB);
	EscreveExtensao(nomeDoArquivo, saida);

	int tamanhoCabecalho = (int)bitmapGetLength(cabecalho);
	fwrite(&tamanhoCabecalho,sizeof(int),1,saida);
	fwrite(bitmapGetContents(cabecalho), sizeof(unsigned char), ProxMultiploOito(bitmapGetLength(cabecalho))/8, saida);
	fwrite(folhas,sizeof(unsigned char),count,saida);

	while(tamanhoDoArquivo>0)
	{
		int retorno = fread(bytesDoArquivo,sizeof(unsigned char),SIZE_MB,entrada);
		tamanhoDoArquivo-=retorno;

		for(long long int i=0;i<retorno;i++)
		{
			for(int j=0;j<bitmapGetLength(Huffman[bytesDoArquivo[i]]->bm);j++)
			{

				if(bitmapGetLength(all) < SIZE_MB)
					bitmapAppendLeastSignificantBit(&all,bitmapGetBit(Huffman[bytesDoArquivo[i]]->bm,j));

				else
				{
					fwrite(bitmapGetContents(all),sizeof(unsigned char),bitmapGetLength(all)/8,saida);
					all = bitmapInit(SIZE_MB);
					bitmapAppendLeastSignificantBit(&all,bitmapGetBit(Huffman[bytesDoArquivo[i]]->bm,j));
				}
			}
		}

	}

	int tamanhoCodigo = ProxMultiploOito(bitmapGetLength(all));
	fwrite(bitmapGetContents(all),sizeof(unsigned char),tamanhoCodigo/8,saida);
	tamanhoCodigo-=bitmapGetLength(all);
	fwrite(&tamanhoCodigo,sizeof(unsigned char),1,saida);
	bitmapFreeContents(&all);
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
	//ImprimeLista(lista);
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

void PrintaBitMapHuffman(Tabela** Huffman,long long unsigned int* frequencia)
{
	/*for(int i=0;i<256;i++)
	{
		if(frequencia[i])
			printf("%s\n",Huffman[i]->bm.contents);
	}*/


}


void LiberaTabela(Tabela** Huffman){
	for(int i = 0; i < 256; i++){
		bitmapFreeContents(&Huffman[i]->bm);
		free(Huffman[i]);
	}
}
