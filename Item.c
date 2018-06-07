//Item.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Item.h"
#include "ST.h"

int criaItem(char palavra[],int frequencia , arvore **raiz)
{
	(*raiz)->item = (lista *) malloc(sizeof(lista));

	if((*raiz) -> item == NULL)
	{
		printf("ERROR!!\n");
		return (-1);
	}

	strcpy((*raiz)-> item ->palavra, palavra);
	(*raiz)-> item ->frequencia = frequencia;
	(*raiz)-> item -> prox = NULL;
	return 0;

}

void percorre_lista(arvore *raiz, arvore **raiz_ordenada)
{
	if(item->prox != NULL) {
		criaItem(raiz->item->palavra, raiz->item->frequencia, &item);
	}
	else {
	percorre_lista(raiz, item->prox);
	}
}
