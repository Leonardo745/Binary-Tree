#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ST.h"
#include "Item.h"

int main(int argc, char *argv[ ])
{
	arvore *raiz = NULL;
	lista *inicio = NULL;
	char palavra[50], operacao, nome_arquivo[20];
	int i, numero_n;

	for (i = 0; i < argc; i++)
	{
		if(argv[i][0] == '-' && argv[i][1] == 'n') 
			numero_n = atoi(&argv[i][2]);
		if(argv[i][0] == '-' && argv[i][1] == 'w')
		{
			operacao = 'w';
			strcpy(nome_arquivo, argv[i]);
			//(nome_arquivo);
		}
		if(argv[i][0] == '-' && argv[i][1] == 'r')
		{
			operacao = 'r';
			strcpy(nome_arquivo, argv[i]);
			//nomeDoArquivo(nome_arquivo);
		}
	}

	//printf("%c\n", operacao);
	//printf("%s\n", nome_arquivo);

	while((scanf("%s", palavra)) != EOF)
	{
		Inserir(palavra, &raiz);
	}

	Imprimir(raiz, &inicio);

	print(inicio, numero_n);
	
	return 0;
}
