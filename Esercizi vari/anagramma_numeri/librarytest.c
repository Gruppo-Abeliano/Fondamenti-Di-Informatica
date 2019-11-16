#include <stdio.h>
#include "anagramma_numeri.h"

int main(int argc, char const *argv[])
{
    int numero1, numero2;

    // Chiedo all'utente i due numero
    printf("Inserisci il primo numero: ");
    scanf("%d", &numero1);
    printf("Inserisci il secondo numero: ");
    scanf("%d", &numero2);

    if (controllaAnagrama(numero1, numero2))
        printf("I numeri che hai inserito sono anagrammi\n");
    else
        printf("I numeri che hai inserito non sono anagrammi\n");

    return 0;
}