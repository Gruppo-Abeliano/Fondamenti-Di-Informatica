#include <stdio.h>

// Permette di ottenere la cifra di un numero in una data posizione (contando a partire da 0 come gli array)
int ottieniCifra(int numero, int n, int cifre);

// Permette di calcolare la potenza e di 10
int pot(int e);

int main(int argc, char const *argv[])
{
    int numeroDaControllare;
    int cifre;
    int quoziente;
    int i, j;
    int cifra1, cifra2;
    int palindromo = 1; // Assumo che il numero sia palindromo (vedi dopo)

    // Chiedo all'utente il numero
    printf("Inserisci un numero, ti diro' se e' palindromo: ");
    scanf("%d", &numeroDaControllare);

    // Calcolo quante cifre ha il numero iterando la divisione per 10 fino a quando il quoziente è minore di 0
    cifre = 0;
    quoziente = numeroDaControllare;
    while (quoziente > 0)
    {
        cifre++;
        quoziente /= 10; 
    }
    printf("Il numero che hai inserito ha %d cifre\n", cifre);

    // Ora controllo se il numero è palindromo
    for(i = 0; i < cifre/2; i++) // La divisione di un intero dispari mi mi permette di saltare la cifre in mezzo
    {
        // Controllo se le cifre (i) e (cifre - i - 1) sono identiche,
        // appena non lo sono fermo il ciclo e imposto il numero come non palindromo
        cifra1 = ottieniCifra(numeroDaControllare, i, cifre);
        cifra2 = ottieniCifra(numeroDaControllare, cifre - i - 1, cifre);
        if(cifra1 != cifra2) {
            i = cifre; // In questo modo fermo il ciclo
            palindromo = 0;
        } else {
        }
    }

    if(palindromo) {
        printf("Il numero che hai inserito e' palindromo\n");
    } else {
        printf("Il numero che hai inserito non e' palindromo\n");
    }

    return 0;
}

int ottieniCifra(int numero, int n, int cifre)
{
    // Per ottenere la cifra in posizione n
    // divido il numero per 10^(cifre - n - 1)
    // e calcolo il modulo per ottenere solo la cifra
    return (numero / (int) pot(cifre - n - 1)) % 10;
}

int pot(int e)
{
    int i;
    int n = 1;

    for(i = 0; i < e; i++)
    {
        n *= 10;
    }

    return n;
}
