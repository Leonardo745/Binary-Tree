#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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

void ordenaPorValor(arvore *raiz, lista **inicio) 
{
	lista *anterior, *atual, *novo;

	novo = (lista *) malloc(sizeof(lista));

	atual = *inicio;
    anterior = NULL;

	novo->frequencia = raiz->frequencia;

	strcpy(novo->palavra,raiz->palavra);

	if(atual == NULL) 
	{
    	novo->prox = NULL;
    	*inicio = novo;
    } 
	else 
	{
        while(atual != NULL && atual->frequencia > novo->frequencia) 
        {
			anterior = atual;
            atual = atual->prox;
		}
        
        novo->prox = atual;
        
        if(anterior == NULL)
            *inicio = novo;
		else
            anterior->prox = novo;
    }
}

void print(lista *inicio, int numero_n) 
{
	int i = 0;

	while(inicio != NULL && i < numero_n) 
	{
		printf("%i %s\n", inicio->frequencia, inicio->palavra);
		inicio = inicio->prox;
		i += 1;
	}
}

void nomeDoArquivo(char nome_arquivo[], char operacao, lista *inicio, int numero_n)
{
	int tamanho = strlen(nome_arquivo);
	int i;

	//printf("%d\n", tamanho);
	for(i = 0; i < tamanho; i++)
	{
		if(i != 0 || i != 1)
			nome_arquivo[i-2] = nome_arquivo[i];
	}
	nome_arquivo[i-2] = '\0';

	strcat(nome_arquivo,".txt");

	//printf("%c\n", operacao);
	//printf("%s\n", nome_arquivo);

	if(operacao == 'w')
		escreverNoArquivo(nome_arquivo, inicio, numero_n);
	else
		leNoArquivo(nome_arquivo, inicio, numero_n);
}

void escreverNoArquivo(char nome_arquivo[], lista *inicio, int numero_n) {

	int i;

	FILE *arq;
	arq = fopen(nome_arquivo,"w");

	while(inicio != NULL && i < numero_n) {

		fprintf(arq, "%i %s\n", inicio->frequencia, inicio->palavra);
		inicio = inicio->prox;
		i += 1;
	}

	fclose(arq);
}

void leNoArquivo(char nome_arquivo[], lista *inicio, int numero_n) {

	int i;

	FILE *arq;
	arq = fopen(nome_arquivo,"r");

	while(inicio != NULL && i < numero_n) {

		fscanf(arq, "%d %s\n", &inicio->frequencia, inicio->palavra);
		printf("%i %s\n", inicio->frequencia, inicio->palavra);
		inicio = inicio->prox;
		i += 1;
	}

	fclose(arq);
}

void Word(arvore *raiz, char palavra [ ]) {

	clock_t comeco = clock();

	int posicao = 0, i, repeticao = 0;
	int tamanho = strlen(palavra);

	//printf("%s\n", palavra);

	for(i = 0; i < tamanho; i++)
	{
		if(i != 0 || i != 1)
			palavra[i-2] = palavra[i];
	}
	palavra[i-2] = '\0';

	repeticao = procura(raiz, palavra, &posicao);
	if(repeticao == 0)
		printf("palavra nao encontrada\n");
	else {
	printf("Palavra: %s\nRepeticao: %i\nPosicao: %i\n", palavra, repeticao, posicao);
	}

	clock_t fim = clock();

	double tempo = (double)(fim - comeco) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo de Execucao: %f µs\n", tempo);
}

int procura(arvore *raiz, char palavra[], int *posicao)
{
    if (raiz)
    {
        if(strcmp(raiz->palavra,palavra) == 0) {
			*posicao += 1;
	    	return (raiz->frequencia);
		}
        else
        {
            if(strcmp(raiz->palavra,palavra) < 0) {
				*posicao += 1;
                return procura(raiz->dir, palavra, posicao);
			}
            else {
				*posicao += 1;
                return procura(raiz->esq, palavra, posicao);
			}
        }
	return 0;
    }
	return 0;
}