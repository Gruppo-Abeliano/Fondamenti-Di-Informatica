#include "anagramma_numeri.h"

/**
 * Autore: Alberto Nidasio
 * Scopo: Controlla se due numeri sono anagrammi
 * Descrizione: Questo programma permette di controllare se due numeri sono anagrammi. Controlla
 * per ogni cifra se i due numeri ne contengono la stessa quantità
*/

int ottieniNumeroCifre(int numero);
int ottieniCifra(int numero, int n, int cifre);
int pot(int e);
int contaCifra(int numero, int cifra, int cifre);

// Permette di ottenre il numero di cifre di un numero
int ottieniNumeroCifre(int numero)
{
    int cifre = 0;

    // Calcolo quante cifre ha il numero iterando la divisione per 10 fino a quando il quoziente è minore di 0

    while (numero > 0)
    {
        cifre++;
        numero /= 10;
    }

    return cifre;
}

// Permette di ottenere la cifra di un numero in una data posizione (contando a partire da 0 come gli array)
int ottieniCifra(int numero, int n, int cifre)
{
    // Per ottenere la cifra in posizione n
    // divido il numero per 10^(cifre - n - 1)
    // e calcolo il modulo per ottenere solo la cifra
    return (numero / (int)pot(cifre - n - 1)) % 10;
}

// Permette di calcolare la potenza e di 10
int pot(int e)
{
    int i;
    int n = 1;

    for (i = 0; i < e; i++)
        n *= 10;

    return n;
}

// Conta quante volte una cifra occorre in un numero
int contaCifra(int numero, int cifra, int cifre)
{
    int i;
    int conteggio = 0;

    for (i = 0; i < cifre; i++)
        if (ottieniCifra(numero, i, cifre) == cifra)
            conteggio++;

    return conteggio;
}