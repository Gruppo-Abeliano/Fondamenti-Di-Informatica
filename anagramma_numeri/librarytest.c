#include <stdio.h>
#include "anagramma_numeri.h"

int main(int argc, char const *argv[])
{
    int numero1, numero2;
    int cifre1, cifre2, cifreMax;
    int i;
    int anagramma = 1; // Assumo che il numero sia palindromo (vedi dopo)

    // Chiedo all'utente i due numero
    printf("Inserisci il primo numero: ");
    scanf("%d", &numero1);
    printf("Inserisci il secondo numero: ");
    scanf("%d", &numero2);

    // Calcolo quante cifre hanno i numeri
    cifre1 = ottieniNumeroCifre(numero1);
    cifre2 = ottieniNumeroCifre(numero2);

    // Colcolo il numero di cifre massimo
    if (cifre1 > cifre2)
        cifreMax = cifre1;
    else
        cifreMax = cifre2;

    // Controllo per ciascuna cifra se i due numeri ne contengono la stessa quantità
    for (i = 0; i < 10 && anagramma; i++) // Fermo il ciclo se sis scopre che i numeri non sono anagrammi
    {
        if (contaCifra(numero1, i, cifreMax) != contaCifra(numero2, i, cifreMax))
        {
            // Se l'uguaglianza risulta falsa i numeri non sono anagrammi
            anagramma = 0;
        }
    }

    if (anagramma)
        printf("I numeri che hai inserito sono anagrammi\n");
    else
        printf("I numeri che hai inserito non sono anagrammi\n");

    return 0;
}