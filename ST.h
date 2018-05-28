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
