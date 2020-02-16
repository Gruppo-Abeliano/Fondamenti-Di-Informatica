#include <stdio.h>

// Conta le cifre decimali fino al primo 0

int main()
{
    long double numero, parteDecimale, tmp;
    int counter, i;

    // Chiedo all'utente il numero
    printf("Inserisci un numero reale: ");
    scanf("%Lf", &numero);

    //1: Isolo la parte decimale
    parteDecimale = numero - (int)numero;

    //2: Trovo il numero di cifre decimali
    tmp = parteDecimale;
    counter = 0;
    while ((int)(tmp * 10) != 0)
    {
        tmp = tmp * 10;
        tmp -= (int)tmp;
        counter++;
    }

    //3: Stampo il numero di cifre decimali
    printf("%d cifre decimali\n", counter);

    //4: Per ogni cifra controllo quante volte è presente nella parte decimale
    for (i = 1; i < 10; i++)
    {
        tmp = parteDecimale;
        counter = 0;
        while ((int)(tmp * 10) != 0)
        {
            tmp = tmp * 10;
            if((int) tmp == i) counter++;
            tmp -= (int)tmp;
        }
        if(counter > 0) printf("%d -> %d\n", i, counter);
    }

    return 0;
}