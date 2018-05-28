#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ST.h"
#include "Item.h"

int main(int argc, char *argv[ ])
{
	arvore *raiz = NULL;
	lista *inicio = NULL;
	char palavra[50];
	int i, exibir = 0;

	for (i = 0; i < argc; i++)
	{
		if(argv[i][0] == '-' && argv[i][1] == 'n') 
			exibir = atoi(&argv[i][2]);
	}

	printf("%i\n", exibir);

	while((scanf("%s", palavra)) != EOF)
	{
		Inserir(palavra, &raiz);
	}

	Imprimir(raiz, &inicio);

	print(inicio, exibir);
	
	return 0;
}
