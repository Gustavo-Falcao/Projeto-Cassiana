
#include<stdio.h>

void troca(int* , int*);

int main()
{

    int j, x;

    printf("Informe um valor para j: ");
    scanf("%d", &j);

    printf("Informe um valor para x: ");
    scanf("%d", &x);

    printf("\nValor antes da troca j = %d x = %d", j, x);

    troca(&j, &x);

    printf("\nValor depois da troca j = %d x = %d", j, x);

}


void troca(int *a, int *b)
{
    int aux;

    aux = *a;
    *a = *b;
    *b = aux;
}