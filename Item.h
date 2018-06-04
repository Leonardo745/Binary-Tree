typedef struct tLista lista;

struct tLista 
{
	char palavra[50];
	int frequencia;
	struct tLista *prox;
};