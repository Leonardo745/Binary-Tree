typedef struct tLista lista;
typedef struct tArvore arvore;

struct tArvore
{
	lista *item;
	arvore *dir, *esq;
};

int Inserir(char palavra[], arvore **raiz);
void ordenaPorValor(arvore *raiz , arvore **raiz_ordenada);
void inserePorValor(arvore *raiz,arvore **raiz_ordenada);
void Imprimir(arvore *raiz);
void print(lista *inicio, int exibir);
void nomeDoArquivo(char nome_arquivo[], char operacao, lista *inicio, int numero_n);
void escreverNoArquivo(char nome_arquivo[], lista *inicio, int numero_n);
void leNoArquivo(char nome_arquivo[], lista *inicio, int numero_n);
void Word(arvore *raiz, char palavra []);
int procura(arvore *raiz, char palavra[], int *posicao);
