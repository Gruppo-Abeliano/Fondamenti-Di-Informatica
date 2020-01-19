#include <stdio.h>
#include <stdlib.h>

typedef struct ElementoLista
{
    struct ElementoLista *next;
    int valore;
} * Lista;

void leggiLista(Lista *testa);
void stampaLista(Lista lista);
Lista creaListaDispari(Lista lista, int includi);

int main() {
    Lista lista = NULL;
    Lista listaDispari;

    printf("Inserisci gli elementi della lista:\n");
    leggiLista(&lista);

    printf("Lista inserita:\n");
    stampaLista(lista);

    // Creo la lista dispari
    listaDispari = creaListaDispari(lista, 1);

    printf("Lista dispari creata:\n");
    stampaLista(listaDispari);
    
    return 0;
}

void leggiLista(Lista *testa)
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

void stampaLista(Lista lista)
{
    while (lista != NULL)
    {
        printf("%d ", lista->valore);
        lista = lista->next;
    }
    printf("\n");
}

Lista creaListaDispari(Lista lista, int includi)
{
    Lista nuovaLista;

    if (lista == NULL)
        return NULL;

    if (includi)
    {
        nuovaLista = malloc(sizeof(struct ElementoLista));
        nuovaLista->valore = lista->valore;
        nuovaLista->next = creaListaDispari(lista->next, 0);
        return nuovaLista;
    }

    return creaListaDispari(lista->next, 1);
}