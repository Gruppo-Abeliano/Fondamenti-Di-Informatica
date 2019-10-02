#include "numero_palindromo.h"

/**
 * Autore: Alberto Nidasio
 * Scopo: Controlla se un numero è palindromo
 * Descrizione: Questo programa controlla se un numero è palindromo confrontando
 * ciascuna i-esima cifra con la (cifre - i - 1)-esima cifra
*/

int controllaPalindromo(int numero);
int ottieniCifra(int numero, int n, int cifre);
int pot(int e);

// Controlla se un numero è palindromo
int controllaPalindromo(int numero)
{
    int cifre = 0;
    int quoziente;
    int cifra1, cifra2;
    int i;
    int palindromo = 1; // Assumo che il numero sia palindromo (vedi dopo)

    // Calcolo quante cifre ha il numero iterando la divisione per 10 fino a quando il quoziente è minore di 0
    quoziente = numero;
    while (quoziente > 0)
    {
        cifre++;
        quoziente /= 10;
    }

    // Ora controllo se il numero è palindromo
    for (i = 0; i < cifre / 2; i++) // La divisione di un intero dispari mi mi permette di saltare la cifre in mezzo
    {
        // Controllo se le cifre (i) e (cifre - i - 1) sono identiche,
        // appena non lo sono fermo il ciclo e imposto il numero come non palindromo
        cifra1 = ottieniCifra(numero, i, cifre);
        cifra2 = ottieniCifra(numero, cifre - i - 1, cifre);
        if (cifra1 != cifra2)
        {
            i = cifre; // In questo modo fermo il ciclo
            palindromo = 0;
        }
    }

    return palindromo;
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
