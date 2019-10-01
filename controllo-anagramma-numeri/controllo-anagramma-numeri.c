#include <stdio.h>

// Permette di ottenre il numero di cifre di un numero
int ottieniNumeroCifre(int numero);

// Permette di ottenere la cifra di un numero in una data posizione (contando a partire da 0 come gli array)
int ottieniCifra(int numero, int n, int cifre);

// Permette di calcolare la potenza e di 10
int pot(int e);

// Ritorna 1 se la cifra dta è presente nel numero, altrimenti 0
int controllaPresenza(int numero, int cifra, int cifre);

int main(int argc, char const *argv[])
{
    int numero1, numero2;
    int cifre1, cifre2;
    int i, j;
    int cifra;
    int anagramma = 1; // Assumo che il numero sia palindromo (vedi dopo)

    // Chiedo all'utente i due numero
    printf("Inserisci il primo numero: ");
    scanf("%d", &numero1);
    printf("Inserisci il secondo numero: ");
    scanf("%d", &numero2);

    // Calcolo quante cifre hanno i numeri iterando la divisione per 10 fino a quando il quoziente è minore di 0
    cifre1 = ottieniNumeroCifre(numero1);
    cifre2 = ottieniNumeroCifre(numero2);
    
    // Controllo se i due numeri hanno la stessa quantità di cifre
    if(cifre1 == cifre2) {
        // Controllo cifra per cifra se quelle presenti nel primo numero sono presenti nel secondo
        for(i = 0; i < cifre1; i++) {
            // Contronto una del primo con quelle del secondo
            cifra = ottieniCifra(numero1, i, cifre1);

            if(!controllaPresenza(numero2, cifra, cifre2)) {
                anagramma = 0;
            }
        }
    } else {
        anagramma = 0;
    }

    if(anagramma) {
        printf("I numeri che hai inserito sono anagrammi\n");
    } else {
        printf("I numeri che hai inserito non sono anagrammi\n");
    }

    return 0;
}

int ottieniNumeroCifre(int numero)
{
    int cifre = 0;

    while (numero > 0)
    {
        cifre++;
        numero /= 10; 
    }

    return cifre;
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

int controllaPresenza(int numero, int cifra, int cifre)
{
    int i;
    int presente = 0; // Assumo la cifra per non presente

    if(cifra < 10) {
        for(i = 0; i < cifre; i++) {
            if(cifra == ottieniCifra(numero, i, cifre)) {
                presente = 1;
            }
        }
    }

    return presente;
}