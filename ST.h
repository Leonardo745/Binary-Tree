#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct tArvore arvore;
typedef struct tLista lista;

struct tArvore
{
	char palavra[50];
	int frequencia;
	struct tArvore *dir, *esq;
};

struct tLista {
	char palavra[50];
	int frequencia;
	struct tLista *prox;
};

int Inserir(char palavra[], arvore **raiz);
void Imprimir(arvore *raiz, lista **inicio);
void ordenaPorValor(arvore *raiz, lista **inicio);
void print(lista *inicio, int exibir);
void nomeDoArquivo(char nome_arquivo[], char operacao, lista *inicio, int numero_n);
void escreverNoArquivo(char nome_arquivo[], lista *inicio, int numero_n);
void leNoArquivo(char nome_arquivo[], lista *inicio, int numero_n);
void Word(arvore *raiz, char palavra []);
int procura(arvore *raiz, char palavra[], int *posicao);
