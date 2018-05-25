#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ST.h"

int main(int argc, char *argv[ ])
{
	char palavra[50];
	int contador = 0;

	while((scanf("%s", palavra)) != EOF)
	{
		contador++;
	}

	printf("%d\n", contador);
	
	return 0;
}
