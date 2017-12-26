all: compactador descompactador

compactador: Compactador.c
	gcc -g Compactador.c tLeitura.c tLista.c tArvore.c tHuffman.c bitmap.c -o compactador

descompactador: Descompactador.c
	gcc -g Descompactador.c tLeitura.c tLista.c tArvore.c tHuffman.c bitmap.c -o descompactador
