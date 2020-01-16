#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Nodo
{
    struct _Nodo *next;
    int numero;
} Nodo;
typedef Nodo *Lista;

void leggiLista(Lista *testa);
void stampaLista(Lista lista);
float calcolaMedia(Lista testa);

int main()
{
    printf("hey\n");

    Lista lista = NULL;

    leggiLista(&lista);

    printf("La lista inserita è:\n");
    stampaLista(lista);

    float media = calcolaMedia(lista);

    printf("La media dei numeri nella lista (contati singolarmente) è: %f\n", media);

    return 0;
}

void leggiLista(Lista *testa)
{
    Lista lista;
    int n;

    // Se la testa della lista è null la inizializzo e inserisco un numero, altrimenti non c'è nè bisogno
    fflush(stdin);
    if (*testa == NULL && scanf("%d", &n))
    {
        *testa = malloc(sizeof(Nodo));
        (*testa)->numero = n;
    }

    // Raggiungo l'ultimo elemento della lista
    lista = *testa;
    while (lista->next != NULL)
        lista = lista->next;

    // Aggiungo elementi alla lista leggendoli da tastiera finchè l'utente non inserisce una cosa diversa da un numero
    fflush(stdin);
    while (scanf("%d", &n))
    {
        lista->next = malloc(sizeof(Nodo));
        lista = lista->next;
        lista->numero = n;
    }
}

void stampaLista(Lista lista)
{
    while (lista != NULL)
    {
        printf("%d\n", lista->numero);
        lista = lista->next;
    }
}

float calcolaMedia(Lista testa)
{
    // Memorizzo in una variabile long int la somma dei numeri da contare nella media
    long int sommaNumeri = 0;
    int countNumeri = 0; // Qui memorizzo il totale dei numeri considerati
    float media;

    // Uso due corridori, uno principale che scorre la lista una volta e l'altro usato per controllare se il numero corrente è stato già considerato
    Lista corridore1 = testa;
    Lista corridore2;

    // Uso una variabile booleana per memorizzare il risultato del controllo sui numeri precedenti
    bool daMemorizzare;

    // Scorro la lista
    while (corridore1 != NULL)
    {
        // Parto dal presupposto che il numero corrente dia da memorizzare
        daMemorizzare = true;

        // Scorre gli elementi precedenti nella lista per controllare se ho già incontrato il numero corrente
        corridore2 = testa;

        while (daMemorizzare && corridore2 != corridore1)
        {
            // Controllo il numero
            if (corridore2->numero == corridore1->numero)
                daMemorizzare = false;
            else
                corridore2 = corridore2->next;
        }

        // Ora che so se devo memorizzare il numero posso aggiungerlo alla somma
        if (daMemorizzare)
        {
            sommaNumeri += corridore1->numero;
            countNumeri++;
        }

        // Proseguo nella lista
        corridore1 = corridore1->next;
    }

    // Ora che ho controllato tutti i numeri posso calcolare la media e darla come risultato
    media = (float)sommaNumeri / countNumeri;
    return media;
}