#include <stdio.h>
#include <windows.h>

typedef struct Bloco
{
 int dado;
 struct Bloco *prox;
} Nodo;

Nodo *torreA, *torreB, *torreC, *torreD;
int mov, i;

void inicializa_lista(Nodo **N)//inicializa a lista
{
 *N = NULL;
}

Nodo * Cria_Nodo() //aloca memória para o nodo
{
 Nodo *p;
 p = (Nodo *) malloc(sizeof(Nodo));
 if(!p)
 {
 printf("Problema de alocação");
 exit(0);
 }
 return p;
}

void insere_inicio_lista(Nodo **N, int dado)
{
 Nodo *novo;
 novo = Cria_Nodo();
 novo->dado = dado;
 novo->prox = *N;
 *N = novo;
}

int remove_inicio_lista(Nodo **N)
{
	Nodo *aux;
	if(*N == NULL)
		return 0;
	else
	{
		mov = (*N)->dado;
		aux = (*N)->prox;
		free(*N);
		*N = aux;
	}
	return 1;
}

void imprime_lista_encadeada(Nodo *N)
{
 	Nodo *aux;
 	if(N == NULL){
	 }
	else
 	{
 		for(aux = N; aux != NULL; aux = aux->prox)
 			printf("\n      %d", aux->dado);
 	}
}

void imprime()
{
	system("cls");
	printf("------A------\n");
    imprime_lista_encadeada(torreA);
	printf("\n\n------B------\n");
	imprime_lista_encadeada(torreB);
	printf("\n\n------C------\n");
	imprime_lista_encadeada(torreC);
	printf("\n\n------D------\n");
	imprime_lista_encadeada(torreD);
	printf("\n\n\n...");
	system("pause");
}

void Hanoi4(int nDisks, Nodo **source, Nodo **intermed1, Nodo **intermed2, Nodo **dest)
{
    if ( nDisks == 1 )
    {
        imprime();
        remove_inicio_lista(source);
        insere_inicio_lista(dest, mov);
    }
    else if ( nDisks == 2 )
    {
        imprime();
        remove_inicio_lista(source);
        insere_inicio_lista(intermed1, mov);
        
        imprime();
        remove_inicio_lista(source);
        insere_inicio_lista(dest, mov);
        
        imprime();
        remove_inicio_lista(intermed1);
        insere_inicio_lista(dest, mov);
    }
    else
    {
        Hanoi4(nDisks - 2, source, intermed2, dest, intermed1);
        imprime();
        remove_inicio_lista(source);
        insere_inicio_lista(intermed2, mov);
        
        imprime();
        remove_inicio_lista(source);
        insere_inicio_lista(dest, mov);
        
        imprime();
        remove_inicio_lista(intermed2);
        insere_inicio_lista(dest, mov);
        
        Hanoi4(nDisks - 2, intermed1, source, intermed2, dest);
    }
}

int main()
{
	inicializa_lista(&torreA);
	inicializa_lista(&torreB);
	inicializa_lista(&torreC);
	inicializa_lista(&torreD);
	
  	for(i=8;i>0;i--){
  		insere_inicio_lista(&torreA, i);
	}
	
    Hanoi4(8, &torreA, &torreB, &torreC, &torreD);
    imprime();

    return 0;
}
