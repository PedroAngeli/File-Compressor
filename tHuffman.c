#include "tHuffman.h"


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
		Huffman[i]->bm = bitmapInit(20);
		Huffman[i]->c=(char)i;
	}

}

void CriaTabela(Tabela** huffman,bitmap bm,int direcao,Arvore* arv)
{

	if(direcao==1) bitmapAppendLeastSignificantBit(&bm,'1');
	else if(direcao==0) bitmapAppendLeastSignificantBit(&bm,'0');

	if(arv==NULL) return;
	
	if(ArvoreEsquerda(arv)==NULL && ArvoreDireita(arv)==NULL)
	{
		huffman[(int)ArvoreInfo(arv)]->bm=bm; 
		if(ArvoreInfo(arv)=='r') printf("%s",bitmapGetContents(bm));
		return;
	}

	CriaTabela(huffman,bm,0,ArvoreEsquerda(arv));
	if(direcao==2) bm = bitmapInit(SIZE_MB);
	CriaTabela(huffman,bm,1,ArvoreDireita(arv));

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

void ImprimeCabecalho(bitmap cabecalho){
	printf("%s", bitmapGetContents(cabecalho));
}

void GeraCompactado(Tabela** Huffman,unsigned char* bytesDoArquivo,long long unsigned int tamanhoDoArquivo)
{
	bitmap all = bitmapInit(SIZE_MB);

	for(int i = 0; i < tamanhoDoArquivo ; i++)
	{
		
		for(int j= 0;j<bitmapGetLength(Huffman[bytesDoArquivo[i]]->bm);j++)
		{
			
		}
	}
	

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
