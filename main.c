#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ST.h"
#include "Item.h"
#include "STb.h"


int main(int argc, char *argv[ ])
{
	arvore *raiz = NULL;
	arvore *raiz_ordenada = NULL;

	char palavra[50];
	char operacao;
	char nome_arquivo[20];
	char palavraEncontrar[50];
	int i;
	int numero_n;
	int flag = 0;
	int balaceada = 0;

	while((scanf("%s", palavra)) != EOF)
	{
		Inserir(palavra, &raiz);
	}
	
	ordenaPorValor(raiz , &raiz_ordenada);
	
	Imprimir(&raiz);
}	
/*
	for (i = 0; i < argc; i++)
	{
		if(argv[i][0] == '-' && argv[i][1] == 'n')
		{
			numero_n = atoi(&argv[i][2]);
		}

		if(argv[i][0] == '-' && argv[i][1] == 'w')
		{
			operacao = 'w';
			strcpy(nome_arquivo, argv[i]);
			flag = 2;
		}

		if(argv[i][0] == '-' && argv[i][1] == 'r')
		{
			operacao = 'r';
			strcpy(nome_arquivo, argv[i]);
			flag = 2;
		}

		if(argv[i][0] == '-' && argv[i][1] == 's') 
		{
			strcpy(palavraEncontrar,argv[i]);
			flag = 1;
		}

		if(argv[i][0] == '-' && argv[i][1] == 'b')
		{
			balaceada = 1;
		}
	}
/*
	//printf("%s\n", palavraEncontrar);
	//printf("%c\n", operacao);
	//printf("%s\n", nome_arquivo);

	if(balaceada == 1)
	{
		while((scanf("%s", palavra)) != EOF)
		{
			InserirB(palavra, &raiz);
		}
	}
	else
	{
		while((scanf("%s", palavra)) != EOF)
		{
			Inserir(palavra, &raiz);
		}
	}


	Imprimir(raiz, &inicio);

	if(flag != 2)
		print(inicio, numero_n);

	if(flag == 1)
		Word(raiz, palavraEncontrar);
	if(flag == 2)
		nomeDoArquivo(nome_arquivo, operacao, inicio, numero_n);
		
	return 0;
}
*/
