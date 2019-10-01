#include <stdio.h>
#include <math.h>

// Permette di ottenere la cifra di un numero in una data posizione (contando a partire da 0 come gli array)
int ottieniCifra(int numero, int n, int cifre);

int main(int argc, char const *argv[])
{
    int numeroDaControllare;
    int cifre;
    int quoziente;
    int i, j; // Usate per i cicli
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
            printf("Cifra diverse, fine\n");
            i = cifre; // In questo modo fermo il ciclo
            palindromo = 0;
        } else {
            printf("Cifre uguali, proseguo\n");
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
    return (numero / (int) pow(10, cifre - n - 1)) % 10;
}