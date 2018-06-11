#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "STb.h"

void inserirB(char palavra[], int *h, arvore **raiz)
{
	struct arvore *p1, *p2;
     
    if (*raiz == NULL) 
    {
    	(*raiz) = (arvore *) malloc(sizeof(arvore));
		*h = 1;
		strcpy((*raiz)->palavra, palavra);
		(*raiz) -> esq = (*raiz) -> dir = NULL;
		(*raiz) -> bal=C;
	}
	else
		if(strcmp((*raiz)->palavra, palavra) > 0) 
		{
			inserirB(palavra, h, &(*raiz)->esq);
			if (*h) 
			{
				switch ((*raiz)->bal)
				{
					case D: 
						(*raiz)->bal = C;
						*h=0;
						break;
					case C:
						(*raiz)->bal = E;
						break;
					case E: 
						p1 = (*raiz)->esq;
						if (p1->bal == E) 
						{ // rebalanceamento simples
							(*raiz) -> esq = p1->dir;
							p1->dir = (*raiz);
							(*raiz)->bal= C;
							(*raiz) = p1; 
						}
						else 
						{ //rebalanceamento duplo
							p2 = p1->dir;
							p1->dir = p2->esq;
							p2->esq = p1;
							(*raiz)->esq=p2->dir;
							p2->dir=(*raiz);
							//printf("P1, bal : %d  %d\n", p1->chave, p1->bal);
							//printf("P2, bal : %d  %d\n", p2->chave, p2->bal);
							//printf("Raiz, bal : %d  %d\n", (*raiz)->chave, (*raiz)->bal); getchar();
							if (p2->bal==E) (*raiz)->bal = D;
							else (*raiz)->bal = C;
							if (p2->bal==D) p1->bal = E;
							else p1->bal = C;
							(*raiz) = p2;
						}
						(*raiz)->bal = C;
						*h=0;
						break;
				}      
			}
		}
		else
			if(strcmp((*raiz)->palavra, palavra) < 0) 
			{
				inserirB(palavra, h, &(*raiz)->dir);
				if (*h) 
				{
					switch ((*raiz)->bal)
					{
						case E:
							(*raiz)->bal = C;
							*h=0;
							break;
						case C:
							(*raiz)->bal = D;
							break;
						case D: 
							p1= (*raiz) -> dir;
							if (p1->bal == D) 
							{ // rebalanceamento simples
								(*raiz) -> dir = p1->esq;
								p1->esq = (*raiz);
								(*raiz)->bal= C;
								(*raiz) = p1; 
							}
							else 
							{ //rebalanceamento duplo
								p2 = p1->esq;
								p1->esq = p2->dir;
								p2->dir = p1;
								(*raiz)->dir=p2->esq;
								p2->esq=(*raiz);
								if (p2->bal==D) (*raiz)->bal = E;
								else (*raiz)->bal = C;
								if (p2->bal==E) p1->bal = D;
								else p1->bal = C;
								(*raiz) = p2;
							}
							(*raiz)->bal = C;
							*h=0;
								break;
					}      
				}
			}
}

void imprimirB(arvore *raiz)
{
	if (raiz != NULL)
	{
		printf("%i %s\n", raiz->frequencia, raiz->palavra);
		imprimirB(raiz->esq);
		imprimirB(raiz->dir);
	}
}