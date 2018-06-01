#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ST.h"
#include "Item.h"

int main(int argc, char *argv[ ])
{
	arvore *raiz = NULL;
	lista *inicio = NULL;
	char palavra[50], operacao, nome_arquivo[20], palavraEncontrar[50];
	int i, numero_n, flag = 0;

	for (i = 0; i < argc; i++)
	{
		if(argv[i][0] == '-' && argv[i][1] == 'n') 
			numero_n = atoi(&argv[i][2]);
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
		if(argv[i][0] == '-' && argv[i][1] == 's') {
			strcpy(palavraEncontrar,argv[i]);
			flag = 1;
		}
	}

	//printf("%s\n", palavraEncontrar);
	//printf("%c\n", operacao);
	//printf("%s\n", nome_arquivo);

	while((scanf("%s", palavra)) != EOF)
	{
		Inserir(palavra, &raiz);
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
