#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CARATTERE_TEMINATORE 'S'

const int N = 3;

typedef struct ElementoLista
{
    struct ElementoLista *next;
    char carattere;
} * Lista;

void leggiLista(Lista *testa);
void stampaLista(Lista lista);
int almenoN(Lista lista, char daCercare, int volte);
int almenoNConsec(Lista lista, char daCercare, int volte);

int main()
{
    Lista lista = NULL;
    char daCercare;
    bool check, checkConsec;

    leggiLista(&lista);

    printf("Lista inserita:\n");
    stampaLista(lista);

    printf("Inserisci il carattere da cercare: ");
    fflush(stdin);
    scanf("%c", &daCercare);

    check = almenoN(lista, daCercare, N);
    checkConsec = almenoNConsec(lista, daCercare, N);

    printf("Risultati:\nNon consecutivo: %d\nConsecutivo: %d\n", check, checkConsec);

    return 0;
}

void leggiLista(Lista *testa)
{
    Lista lista;
    char carattere = CARATTERE_TEMINATORE;

    // Se la testa della lista è null la inizializzo e inserisco un numero, altrimenti non c'è nè bisogno
    fflush(stdin);
    if (*testa == NULL && scanf("%c", &carattere) && carattere != CARATTERE_TEMINATORE)
    {
        *testa = malloc(sizeof(struct ElementoLista));
        (*testa)->carattere = carattere;
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
    while (scanf("%c", &carattere) && carattere != CARATTERE_TEMINATORE)
    {
        lista->next = malloc(sizeof(struct ElementoLista));
        lista = lista->next;
        lista->carattere = carattere;
        fflush(stdin);
    }
}

void stampaLista(Lista lista)
{
    while (lista != NULL)
    {
        printf("%c ", lista->carattere);
        lista = lista->next;
    }
    printf("\n");
}

int almenoN(Lista lista, char daCercare, int volte)
{
    if (volte <= 0)
        return true;

    while (lista != NULL && lista->carattere != daCercare)
        lista = lista->next;

    if (lista != NULL)
        return almenoN(lista->next, daCercare, volte - 1);

    return false;
}

int almenoNConsec(Lista lista, char daCercare, int volte)
{
    if (volte == N)
        while (lista != NULL && lista->carattere != daCercare)
            lista = lista->next;
    if (volte <= 0)
        return true;
    if (lista == NULL)
        return false;
    if (lista->carattere != daCercare)
        return false;
    return almenoNConsec(lista->next, daCercare, volte - 1);
}