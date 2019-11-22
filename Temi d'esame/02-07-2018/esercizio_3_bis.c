#include <stdio.h>

/**
 * Autore: Alberto Nidasio
 * Scopo: Convertire un numero dalla base 10 a un'altra base
 * Descrizione: La funzione ricorsiva converti ritorna una lisga sequenziale che contiene le cifre risultate dalla conversione
*/

#define CIFRE 4

typedef struct ListaDinamica
{
    int numeroConvertito[CIFRE];
    int cifre;
} Lista;

Lista converti(int n, int b);

int main()
{
    int n, b, i;

    printf("Inserisci il numero da convertire: ");
    scanf("%d", &n);

    printf("Inserisci la base nella quale convertire il numero: ");
    scanf("%d", &b);

    Lista lista = converti(n, b);

    if (lista.cifre > 0)
        printf("Il numero %d convertito in base %d è: ", n, b);
    for (i = 0; i < lista.cifre; i++)
        printf("%d", lista.numeroConvertito[i]);
    if (lista.cifre > 0)
        printf("\n");
    return 0;
}

// Suppongo che b > 1 e n > 0
Lista converti(int n, int b)
{
    Lista lista;
    int resto, quoziente;

    // Calcolo il resto del numero diviso la base data
    resto = n % b;
    quoziente = n / b;

    // Se il quozinente è 0 allora il resto è l'ultima cifra che ci interessa
    if (quoziente == 0) // In questo caso creo una nuova lista e aggiungo l'elemento
    {
        lista.numeroConvertito[0] = resto; // Inserisco la cifra
        lista.cifre = 1;

        // Inizializzo il resto delle cifre a -1 così segnalo che il valore non  da contare
        int i;
        for (i = 1; i < CIFRE; i++)
            lista.numeroConvertito[i] = -1;

        return lista;
    }
    else // Altrimenti non ci troviamo all'ultima cifra e prima di inserire quella calcolata a questo massaggio clacolo le restanti
    {
        lista = converti(quoziente, b);

        // Controllo se c'è spazio per inserire la cifra
        if (lista.cifre >= CIFRE)
        {
            printf("Cifre impostate non sufficienti per memorizzare il numero\n");
            lista.cifre = -1;
        }
        else if (lista.cifre > 0)
        {
            // Inserisco il numero
            lista.numeroConvertito[lista.cifre] = resto;
            lista.cifre++;
        }

        return lista;
    }
}