#include <stdio.h>
#include <stdlib.h>

/**
 * Date due liste dinamiche ordinate e formate da numeri interi tutti diversi tra loro si chiede di
 * formare creare una lista dinamica con tutti gli elementi delle due liste in ordine.
*/

typedef struct ElementoLista
{
    struct ElementoLista *next;
    int valore;
} * Lista;

void leggiLista(Lista *lista);
void stampaLista(Lista lista);
Lista fusione(Lista lista1, Lista lista2);

int main()
{
    Lista lista1 = NULL;
    Lista lista2 = NULL;
    Lista listaFinale = NULL;

    // Leggo da tastiera le due liste dinamiche

    printf("Inserisci gli elementi della prima lista (un carattere per uscire):\n");
    leggiLista(&lista1);

    // Pulisco il buffer
    char buff;
    while ((buff = getchar()) != '\n' && buff != EOF)
        ;

    printf("Inserisci gli elementi della seconda lista (un carattere per uscire):\n");
    leggiLista(&lista2);

    // Mostro le liste

    printf("Lista 1:\n");
    stampaLista(lista1);

    printf("Lista 2:\n");
    stampaLista(lista2);

    // Le unisco
    listaFinale = fusione(lista1, lista2);

    // Mostro la lista finale
    printf("Lista finale:\n");
    stampaLista(listaFinale);

    return 0;
}

void leggiLista(Lista *lista)
{
    int input;

    while (scanf("%d", &input))
    {
        *lista = malloc(sizeof(struct ElementoLista));
        (*lista)->valore = input;
        lista = &(*lista)->next;
    }
}

void stampaLista(Lista lista)
{
    while (lista != NULL)
    {
        printf("%d\n", lista->valore);
        lista = lista->next;
    }
}

Lista fusione(Lista lista1, Lista lista2)
{
    Lista *nuovaLista = malloc(sizeof(Lista));
    Lista *testa;

    // Salvo la testa per poter poi restituire il puntatore al primo elemento
    testa = nuovaLista;

    // Continuo ad inserire elementi nella lista finale finchè non finisco
    while (lista1 != NULL || lista2 != NULL)
    {
        *nuovaLista = malloc(sizeof(struct ElementoLista));

        if (lista1 != NULL && lista2 != NULL)
        {
            if (lista1->valore < lista2->valore)
            {
                (*nuovaLista)->valore = lista1->valore;
                lista1 = lista1->next;
            }
            else
            {
                (*nuovaLista)->valore = lista2->valore;
                lista2 = lista2->next;
            }
        }
        else if (lista1 != NULL && lista2 == NULL)
        {
            (*nuovaLista)->valore = lista1->valore;
            lista1 = lista1->next;
        }
        else if (lista1 == NULL && lista2 != NULL)
        {
            (*nuovaLista)->valore = lista2->valore;
            lista2 = lista2->next;
        }

        nuovaLista = &(*nuovaLista)->next;
    }

    return *testa;
}