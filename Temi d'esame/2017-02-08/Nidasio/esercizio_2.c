#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct _p
{
    struct _p *next;
    int x, y;
} punto_t;

void leggiLista(punto_t **testa);
void stampaLista(punto_t *lista);
bool controllaScorciatoia(punto_t *lineaA, punto_t *lineaB);

int main()
{
    punto_t *lineaA = NULL;
    punto_t *lineaB = NULL;

    printf("Inserisci la prima linea:\n");
    leggiLista(&lineaA);

    printf("Inserisci la seconda linea:\n");
    leggiLista(&lineaB);

    printf("Linea A:\n");
    stampaLista(lineaA);

    printf("Linea B:\n");
    stampaLista(lineaB);

    bool scorciatoia = controllaScorciatoia(lineaA, lineaB);

    printf("A è una scorciatoia di B? %c\n", (scorciatoia ? 'S' : 'N'));

    return 0;
}

void leggiLista(punto_t **testa)
{
    punto_t *lista;
    int x, y;


    // Se la testa della lista è null la inizializzo e inserisco un numero, altrimenti non c'è nè bisogno
    fflush(stdin);
    if (*testa == NULL && scanf("%d %d", &x, &y))
    {
        *testa = malloc(sizeof(punto_t));
        (*testa)->x = x;
        (*testa)->y = y;
    }

    // Raggiungo l'ultimo elemento della lista
    lista = *testa;
    while (lista->next != NULL)
        lista = lista->next;

    // Aggiungo elementi alla lista leggendoli da tastiera finchè l'utente non inserisce una cosa diversa da un numero
    fflush(stdin);
    while (scanf("%d %d", &x, &y))
    {
        lista->next = malloc(sizeof(punto_t));
        lista = lista->next;
        lista->x = x;
        lista->y = y;
    }
}

void stampaLista(punto_t *lista)
{
    while (lista != NULL)
    {
        printf("[%d,%d]\n", lista->x, lista->y);
        lista = lista->next;
    }
}

bool controllaScorciatoia(punto_t *lineaA, punto_t *lineaB)
{
    double lunghezzaA = 0;
    double lunghezzaB = 0;

    // Se le due linee non partono dallo stesso punto allora A non è sicuramente una scorciatoia
    if (lineaA->x != lineaB->x || lineaA->y != lineaB->y)
        return false;

    // Scorro le due linee e calcolo le loro lunghezze
    while (lineaA->next != NULL)
    {
        lunghezzaA += sqrt(pow(lineaA->x - lineaA->next->x, 2) + pow(lineaA->y - lineaA->next->y, 2));
        lineaA = lineaA->next;
    }
    while (lineaB->next != NULL)
    {
        lunghezzaB += sqrt(pow(lineaB->x - lineaB->next->x, 2) + pow(lineaB->y - lineaB->next->y, 2));
        lineaB = lineaB->next;
    }

    // Ora che sono alla fine posso controllare se le due linee finiscono nello stesso punto e le loro lunghezze
    if (lineaA->x == lineaB->x && lineaA->y == lineaB->y && lunghezzaA < lunghezzaB)
        return true;
    return false;
}