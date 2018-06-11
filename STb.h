#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct tArvore arvore;

enum Balance {E,C,D};

struct tArvore
{
	char palavra[50];
	int frequencia;
	enum Balance bal;
	arvore *dir, *esq;
};

void inserirB(char palavra[], int *h, arvore **raiz);
void imprimirB(arvore *raiz);