#include <stdio.h>
#include <stdlib.h>

typedef struct _ElemLista
{
    struct _ElemLista *next;
    float valore;
} ElemLista;

typedef ElemLista *Lista;

void leggiLista(Lista *testa);
void stampaLista(Lista lista);
void fondi(Lista l1, Lista l2, Lista *pl);

int main()
{
    Lista l1 = NULL;
    Lista l2 = NULL;
    Lista l3;

    printf("Inserisci la prima lista (ordinata!):\n");
    leggiLista(&l1);

    printf("Inserisci la seconda lista (ordinata!):\n");
    leggiLista(&l2);

    printf("Le lista inserite sono:\n");
    stampaLista(l1);
    stampaLista(l2);

    fondi(l1, l2, &l3);

    printf("Risultato:\n");
    stampaLista(l3);

    return 0;
}

void leggiLista(Lista *testa)
{
    Lista lista;
    float valore;

    // Se la testa della lista è null la inizializzo e inserisco un numero, altrimenti non c'è nè bisogno
    fflush(stdin);
    if (*testa == NULL && scanf("%f", &valore))
    {
        *testa = malloc(sizeof(ElemLista));
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
    while (scanf("%f", &valore))
    {
        lista->next = malloc(sizeof(ElemLista));
        lista = lista->next;
        lista->valore = valore;
        fflush(stdin);
    }
}

void stampaLista(Lista lista)
{
    while (lista != NULL)
    {
        printf("%.2f ", lista->valore);
        lista = lista->next;
    }
    printf("\n");
}

void fondi(Lista l1, Lista l2, Lista *pl)
{
    if (l1 == NULL && l2 == NULL)
        return;
    
    *pl = malloc(sizeof(ElemLista));

    if(l1 == NULL || (l1 != NULL && l2 != NULL && l1->valore > l2->valore)) {
        (*pl)->valore = l2->valore;
        fondi(l1, l2->next, &(*pl)->next);
    } else if(l2 == NULL || (l1 != NULL && l2 != NULL && l1->valore < l2->valore)) {
        (*pl)->valore = l1->valore;
        fondi(l1->next, l2, &(*pl)->next);
    }
}