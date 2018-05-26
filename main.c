#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ST.h"

int quant_palavras(char *[]);

int main(int argc, char *argv[ ])
{
	char palavra[50];
	int contador = 0;


	while((scanf("%s", palavra)) != EOF)
	{
		contador++;
	}

	//printf("%d\n", argc);
	//printf("%s\n", argv[1]);
	//printf("%d\n", quant_palavras(argv));
	
	printf("%d\n", contador);

	
	return 0;
}

int quant_palavras(char *string[ ])
{
	//retorna um int com o numero inserido depois do -n inserido por parametro na main
	int tamanho;
	int i;
	int palavras;
	char temp[50];
	
	tamanho = strlen(string[1]);
	
	for(i = 0;i<tamanho;i++)
	{
		temp[i] = string[1][i+2];
	}

	sscanf(temp,"%d",&palavras);

	return palavras;
}
