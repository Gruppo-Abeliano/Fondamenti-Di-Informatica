#include <stdio.h>
#include <stdlib.h>

typedef struct ElementoListaBidirezionale
{
    struct ElementoListaBidirezionale *next;
    struct ElementoListaBidirezionale *prev;
    int valore;
} * ListaBidirezionale;

typedef struct ElementoLista
{
    struct ElementoLista *next;
    int valore;
} * Lista;

void leggiListaMonodirezionale(Lista *testa);
void stampaListaMonodirezionale(Lista lista);
void stampaListaBidirezionale(ListaBidirezionale lista);
ListaBidirezionale costruisciListaBidirezionale(Lista lista);

int main()
{
    Lista lista = NULL;
    ListaBidirezionale listaBidirezionale;

    leggiListaMonodirezionale(&lista);

    printf("Lista monodirezionale:\n");
    stampaListaMonodirezionale(lista);

    listaBidirezionale = costruisciListaBidirezionale(lista);

    printf("Lista monodirezionale:\n");
    stampaListaBidirezionale(listaBidirezionale);

    return 0;
}

void leggiListaMonodirezionale(Lista *testa)
{
    Lista lista;
    int valore;

    // Se la testa della lista è null la inizializzo e inserisco un numero, altrimenti non c'è nè bisogno
    fflush(stdin);
    if (*testa == NULL && scanf("%d", &valore))
    {
        *testa = malloc(sizeof(struct ElementoLista));
        (*testa)->valore = valore;
    }
    else
    {
        return;
    }

    // Raggiungo l'ultimo elemento della lista
    lista = *testa;
    while (lista->next != NULL)
        lista = lista->next;

    // Aggiungo elementi alla lista leggendoli da tastiera finchè l'utente non inserisce una cosa diversa da un numero
    fflush(stdin);
    while (scanf("%d", &valore))
    {
        lista->next = malloc(sizeof(struct ElementoLista));
        lista = lista->next;
        lista->valore = valore;
        fflush(stdin);
    }
}

void stampaListaMonodirezionale(Lista lista)
{
    while (lista != NULL)
    {
        printf("%d ", lista->valore);
        lista = lista->next;
    }
    printf("\n");
}

void stampaListaBidirezionale(ListaBidirezionale lista)
{
    printf("Dal primo all'ultimo:\n");
    while (lista->next != NULL)
    {
        printf("%d ", lista->valore);
        if (lista->next != NULL)
            lista = lista->next;
    }
    printf("%d ", lista->valore);
    printf("\n");

    printf("Dall'ultimo al primo:\n");
    while (lista != NULL)
    {
        printf("%d ", lista->valore);
        lista = lista->prev;
    }
    printf("\n");
}

ListaBidirezionale costruisciListaBidirezionale(Lista lista)
{
    // Costruisco la lista normalmente mantenendo un puntatore all'elemento precedente per impostare prev
    ListaBidirezionale testa = NULL;
    ListaBidirezionale corridore, corridorePrev;

    if (lista != NULL)
    {
        testa = malloc(sizeof(struct ElementoListaBidirezionale));
        testa->next = NULL;
        testa->prev = NULL;
        testa->valore = lista->valore;
        lista = lista->next;
    }

    corridore = testa;

    while (lista != NULL)
    {
        corridore->next = malloc(sizeof(struct ElementoListaBidirezionale));
        corridorePrev = corridore;
        corridore = corridore->next;
        corridore->valore = lista->valore;
        corridore->prev = corridorePrev;
        corridore->next = NULL;
        lista = lista->next;
    }

    return testa;
}