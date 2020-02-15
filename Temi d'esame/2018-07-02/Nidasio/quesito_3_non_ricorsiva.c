#include <stdio.h>

#define DIMENSIONE_MASSIMA 100

typedef struct
{
    int cifre[DIMENSIONE_MASSIMA];
    int count;
} Rappresentazione;

Rappresentazione converti(int numero, int base);

int main()
{
    int numero, base;
    Rappresentazione conversione;
    int i;

    printf("Inserisci il numero da convertire: ");
    scanf("%d", &numero);

    printf("Inserisci la base da usare: ");
    scanf("%d", &base);

    conversione = converti(numero, base);

    printf("Numero convertito:\n");
    for(i = 0; i < conversione.count; i++) printf("%d", conversione.cifre[i]);
    printf("\n");

    return 0;
}

Rappresentazione converti(int numero, int base)
{
    int resto;
    Rappresentazione conversione = {
        .cifre = {0},
        .count = 0,
    };
    int i, tmp;

    // Converto
    while (numero > 0)
    {
        resto = numero % base;
        numero /= base;

        conversione.cifre[conversione.count] = resto;
        conversione.count++;
    }

    // Ribalto le cifre
    for(i = 0; i < conversione.count / 2; i++) {
        tmp = conversione.cifre[i];
        conversione.cifre[i] = conversione.cifre[conversione.count - i - 1];
        conversione.cifre[conversione.count - i - 1] = tmp;
    }

    return conversione;
}