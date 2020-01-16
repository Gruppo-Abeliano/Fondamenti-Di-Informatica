#include <stdio.h>
#include <stdlib.h>

typedef struct ElementoLista
{
    struct ElementoLista *next;
    int num;
} * Lista;

void stampaLista(Lista lista);
Lista codificaInRLC(int *numeroDaCodificare, int n);

int main()
{
    //int array[] = {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0};
    int array[] = {1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0};
    int n = sizeof(array) / sizeof(int);

    Lista codificaRLC = codificaInRLC(array, n);

    stampaLista(codificaRLC);

    return 0;
}

void stampaLista(Lista lista)
{
    while (lista != NULL)
    {
        printf("%d\n", lista->num);
        lista = lista->next;
    }
}

// La funzione accetta un array e la sua dimensione
Lista codificaInRLC(int *numeroDaCodificare, int n)
{
    // Uso un valore intero come indicatore della cifra da corrente da contare
    int cifraCorrente = 0; // Partiamo contando lo 0

    // Uso un contatore per memorizzare a che punto della lista sono arrivato nell'array
    int i = 0;

    // Creo la testa della lista, il valore verrà inizializzato a 0, se non ci saranno numeri nell'array la codifica RLC sarà composta da un solo numero uguale a 0 ad indicare che il numero codificato è vuoto, ovvero pari a 0
    Lista testa = malloc(sizeof(struct ElementoLista));

    // Uso un orridore, ovvero un puntatore separato per non perdere la testa della lista
    Lista corridore = testa;

    while (i < n)
    {
        // Inizializzo il valore a 0 come già spiegato
        corridore->num = 0;

        // Conto i numeri fino a quando non incontro un elemento diverso
        while (numeroDaCodificare[i] == cifraCorrente && i < n)
        {
            corridore->num++;
            i++;
        }

        // A questo punto posso cambiare la cifra corrente;
        cifraCorrente = !cifraCorrente;

        // Procedo di una posizione e ripeto
        if (i < n)
        {
            corridore->next = malloc(sizeof(struct ElementoLista));
            corridore = corridore->next;
        }
    }

    // Laascio come risultato il puntatore alla testa della lista
    return testa;
}
