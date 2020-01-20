#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

typedef struct
{
    int codifica[MAX_LENGTH];
    int size;
} CodificaRlc;

CodificaRlc *convertiNumero(int numero[], int N);

int main()
{
    int numero[MAX_LENGTH];
    int n, i;
    CodificaRlc *codifcaRlc;

    n = 0;
    printf("Inserisci ciascuna cifra del numero:\n");
    while (scanf("%d", &numero[n]))
    {
        if (numero[n] > 1)
            numero[n] = 1;
        else if (numero[n] < 0)
            numero[n] = 0;
        n++;
    }

    codifcaRlc = convertiNumero(numero, n);

    printf("Numero inserito:\n");
    for (i = 0; i < n; i++)
        printf("%d", numero[i]);
    printf("\n");

    printf("Numero convertito:\n");
    for (i = 0; i < codifcaRlc->size; i++)
        printf("%d", codifcaRlc->codifica[i]);
    printf("\n");
}

CodificaRlc *convertiNumero(int numero[], int N)
{
    int check, count, i;
    CodificaRlc *codifica;
    codifica = malloc(sizeof(CodificaRlc));
    codifica->size = 0;

    check = 0;
    count = 0;

    for (i = 0; i < N; i++)
    {
        if (numero[i] == check)
        {
            count++;
        }
        else
        {
            codifica->codifica[codifica->size] = count;
            codifica->size++;
            count = 1;
            check = !check;
        }
    }
    codifica->codifica[codifica->size] = count;
    codifica->size++;

    return codifica;
}