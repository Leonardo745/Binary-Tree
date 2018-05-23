#include <stdlib.h>
#include <stdio.h>



typedef struct
{
	char palavra[100];
	struct tree *direita;
} tree;

int main()
{
	

	char palavra[100];
	long long int i;
	tree *ptree;
	

	while(scanf("%s", &palavra) != EOF)
	{
		i++;
		//printf("%s " , palavra);
		ptree = (tree*) malloc(sizeof(tree));
		
	}

	printf("%lli\n", i);
	
	return 0;
}
