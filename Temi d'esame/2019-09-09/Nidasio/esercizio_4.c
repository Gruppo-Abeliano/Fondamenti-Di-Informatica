#include <stdio.h>
#include <stdlib.h>

typedef struct ElementoLista
{
    int numero;
    struct ElementoLista *next;
} * Lista;

void leggiLista(Lista *testa);
void stampaLista(Lista lista);
void rimuoviOccorrenzeEccessive(Lista *lista, int n);
int contaOccorrenze(Lista lista, int numero);
void eliminaNumero(Lista *lista, int numero);

int main()
{
    Lista lista = NULL;
    int n;

    leggiLista(&lista);

    printf("La lista inserita è:\n");
    stampaLista(lista);

    // Chiedo all'utente il numero
    printf("Insersci il numero n: ");
    fflush(stdin);
    scanf("%d", &n);

    // Rimuovo gli elementi della lista con più di n occorrenze
    rimuoviOccorrenzeEccessive(&lista, n);

    printf("Il risultato è:\n");
    stampaLista(lista);

    return 0;
}

void leggiLista(Lista *testa)
{
    Lista lista;
    int n;

    //Pulisco il buffer
    fflush(stdin);

    // Se la testa della lista è null la inizializzo e inserisco un numero, altrimenti non c'è nè bisogno
    if (*testa == NULL && scanf("%d", &n))
    {
        *testa = malloc(sizeof(struct ElementoLista));
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
        lista->next = malloc(sizeof(struct ElementoLista));
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

void rimuoviOccorrenzeEccessive(Lista *testa, int n)
{
    Lista *corridore1 = testa;
    Lista corridore2;
    int occorrenze;

    // Se n è minore o uguale a 0 la funzione non deve essere eseguita
    if (n <= 0)
        return;

    // Se n è uguale a 1 vanno eliminati tutti gli elementi della lista
    if (n == 1)
    {
        while (*corridore1 != NULL)
        {
            corridore2 = *corridore1;
            corridore1 = &(*corridore1)->next;
            free(corridore2);
        }

        // Imposto la testa a NULL
        (*testa) = NULL;

        return;
    }

    // Scorro la lista, per ogni numero controllo quante occorrenze ha, se sono maggiori di n lo elimino da tutta la lista
    while ((*corridore1) != NULL)
    {
        // Controllo quante volte il numero corrente è presente nella lista
        occorrenze = contaOccorrenze((*corridore1)->next, (*corridore1)->numero) + 1;

        printf("Numero di occorrenze per %d sono: %d\n", (*corridore1)->numero, occorrenze);

        // Se le occorrenze del numero corrente sono maggiori o uguali di n elimino il numero dalla lista
        if (occorrenze >= n)
            eliminaNumero(corridore1, (*corridore1)->numero);
        else
            corridore1 = &(*corridore1)->next;
    }
}

int contaOccorrenze(Lista lista, int numero)
{
    int occorrenze = 0;

    while (lista != NULL)
    {
        if (lista->numero == numero)
            occorrenze++;
        lista = lista->next;
    }

    return occorrenze;
}

void eliminaNumero(Lista *lista, int numero)
{
    Lista tmp;

    while ((*lista) != NULL)
    {
        if ((*lista)->numero == numero)
        {
            tmp = (*lista);
            (*lista) = (*lista)->next;
            free(tmp);
        }
        else
        {
            lista = &(*lista)->next;
        }
    }
}