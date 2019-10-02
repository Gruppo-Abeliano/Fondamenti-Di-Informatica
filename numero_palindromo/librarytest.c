#include <stdio.h>
#include "numero_palindromo.h"

int main(int argc, char const *argv[])
{
    int numeroDaControllare;

    // Chiedo all'utente il numero
    printf("Inserisci un numero, ti diro' se e' palindromo: ");
    scanf("%d", &numeroDaControllare);

    // Controllo se il numero è palindromo
    if (controllaPalindromo(numeroDaControllare))
        printf("Il numero che hai inserito e' palindromo\n");
    else
        printf("Il numero che hai inserito non e' palindromo\n");

    return 0;
}