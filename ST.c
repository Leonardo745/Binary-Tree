#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ST.h"

int Inserir(char palavra[], arvore **raiz)
{
	if(*raiz == NULL)
	{
		(*raiz) = (struct tArvore *) malloc(sizeof(arvore));
		if(*raiz == NULL) return (-1);
		strcpy((*raiz)->palavra, palavra);
		(*raiz)->frequencia = 1;
		(*raiz)->esq = (*raiz)->dir = NULL;
		return (1);
	}
	if(strcmp((*raiz)->palavra, palavra) == 0) //strcmp retorna 0 se for igual
	{
		(*raiz)->frequencia += 1;
		return (0);
	}
	if(strcmp((*raiz)->palavra, palavra) > 0) return (Inserir(palavra, &(*raiz)->esq));
	return (Inserir(palavra, &(*raiz)->dir));
}

void Imprimir(arvore *raiz, lista **inicio)
{
	if(raiz)
	{
		Imprimir(raiz->esq, inicio);
		ordenaPorValor(raiz, inicio);
		Imprimir(raiz->dir, inicio);
	}
}

void ordenaPorValor(arvore *raiz, lista **inicio) {

	lista *anterior, *atual, *novo;

	novo = (lista *) malloc(sizeof(lista));

	atual = *inicio;
    anterior = NULL;

	novo->frequencia = raiz->frequencia;

	strcpy(novo->palavra,raiz->palavra);

	if(atual == NULL) {
    	novo->prox = NULL;
    	*inicio = novo;
    } 
	else {
        while(atual != NULL && atual->frequencia > novo->frequencia) {

            anterior = atual;
            atual = atual->prox;
        }
        
        novo->prox = atual;
        
        if(anterior == NULL) {

            *inicio = novo;
        } 
		
		else {
            anterior->prox = novo;
        }
    }
}

void print(lista *inicio, int exibir) {

	int i = 0;

	while(inicio != NULL && i < exibir) {
		printf("%i %s\n", inicio->frequencia, inicio->palavra);
		inicio = inicio->prox;
		i += 1;
	}
}
