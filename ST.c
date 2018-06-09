#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ST.h"
#include "Item.h"
/*
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
*/

int Inserir(char palavra[], arvore **raiz)
{
	if(*raiz == NULL)
	{
		(*raiz) = (arvore *) malloc(sizeof(arvore));
		if((*raiz) == NULL) return (-1);
		
		(*raiz)->esq = NULL;
		(*raiz)->dir = NULL;

		criaItem(palavra,1, raiz);

		return (1);

	}
	if(strcmp((*raiz)->item ->palavra, palavra) == 0) 
	{
		(*raiz)->item->frequencia += 1;
		return (0);
	}

	if(strcmp((*raiz)->item->palavra, palavra) > 0) 
		return (Inserir(palavra, &(*raiz)->esq));

	return (Inserir(palavra, &(*raiz)->dir));


}

void ordenaPorValor(arvore *raiz , arvore **raiz_ordenada)
{
	if(raiz)
	{
		ordenaPorValor(raiz->esq, raiz_ordenada);
		inserePorValor(raiz, raiz_ordenada);
		ordenaPorValor(raiz->dir, raiz_ordenada);
	}
}

int inserePorValor(arvore *raiz,arvore **raiz_ordenada)
{
	if(*raiz_ordenada == NULL)
	{
		(*raiz_ordenada) = (arvore *) malloc(sizeof(arvore));
		
		(*raiz_ordenada)->esq = NULL;
		(*raiz_ordenada)->dir = NULL;

		criaItem(raiz -> item -> palavra ,raiz -> item -> frequencia, raiz_ordenada);

	}

	//strcmp retorna 0 se for igual
	if((raiz -> item -> frequencia) == ((*raiz_ordenada) -> item -> frequencia)) 
	{

		percorre_lista(raiz, raiz_ordenada);
		return 0;
	}

	if((raiz->item->frequencia) > ((*raiz_ordenada) -> item -> frequencia)) 
		return (inserePorValor(raiz, &(*raiz_ordenada)->esq));

	return (inserePorValor(raiz, &(*raiz_ordenada)->dir));

}

int Imprimir(arvore *raiz, int *exibir)
{
	if(raiz)
	{
		Imprimir(raiz->esq, exibir);
		printf("%s %i\n", raiz->item->palavra, raiz->item->frequencia);
		if(raiz->item->prox != NULL)
			ImprimirLista(raiz->item->prox->prox, exibir);
		Imprimir(raiz->dir, exibir);
	}
}

void ImprimirLista(lista *item, int *exibir) {

	lista *aux = item;

    for (aux = item; item != NULL; item = item->prox) {

		printf("%s %i\n", item->palavra, item->frequencia);
    }
}

/*
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
*/
