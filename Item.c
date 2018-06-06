//Item.c


int criaItem(char palavra[],int frequencia , arvore **raiz)
{
	((*raiz) -> item) = (lista *) malloc(sizeof(lista));

	if((*raiz) -> item == NULL)
	{
		printf("ERROR!!\n");
		return (-1);
	}

	strcpy((*raiz)-> item ->palavra, palavra);
	(*raiz)-> item ->frequencia = frequencia;
	(*raiz)-> item -> prox = NULL;
	return 0;

}




