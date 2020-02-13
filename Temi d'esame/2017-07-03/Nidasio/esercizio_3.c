#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ElementoLista
{
    struct ElementoLista *next;
    int valore;
} * Lista;

void riempiLista(Lista *lista);
void stampaLista(Lista lista);
void aggiungiInCoda(Lista *lista, int val, int k);

int main()
{
    Lista lista = NULL;
    int val, k;

    // Inserisco la lista
    riempiLista(&lista);

    // Mostro il suo contenuto
    stampaLista(lista);

    // Chiedo all'utente il nuovo valore e la posizione in cui aggiungerlo
    printf("Inserisci l'ultimo valore da aggiungere: "); scanf("%d", &val);
    printf("e la posizione in cui metterlo: "); scanf("%d", &k);

    // Lo aggiungio
    aggiungiInCoda(&lista, val, k);

    // Ristampo la lista
    stampaLista(lista);

    return 0;
}

void riempiLista(Lista *lista)
{
    Lista corridore;
    int input;
    bool utenteStufo = false;

    // Se la testa della lista è nulla la inizializzo
    if (*lista == NULL)
    {
        printf("Inserisci un valore da appendere alla lista (negativo per uscire): ");
        fflush(stdin);
        scanf("%d", &input);
        if (input < 0)
            return;

        *lista = malloc(sizeof(struct ElementoLista));
        corridore = *lista;
        corridore->next = NULL;
        corridore->valore = input;
    }

    // Continuo finchè l'utente non si stanca
    while (!utenteStufo)
    {
        printf("Inserisci un valore da appendere alla lista (negativo per uscire): ");
        fflush(stdin);
        scanf("%d", &input);
        if (input < 0)
        {
            utenteStufo = true;
        }
        else
        {

            corridore->next = malloc(sizeof(struct ElementoLista));
            corridore = corridore->next;
            corridore->next = NULL;
            corridore->valore = input;
        }
    }
}

void stampaLista(Lista lista)
{
    printf("Contenuto della lista:\n");

    while (lista != NULL)
    {
        printf("%d\n", lista->valore);
        lista = lista->next;
    }
}

void aggiungiInCoda(Lista *lista, int val, int k)
{
    Lista corridore1, *corridore2;
    int contatore = 1;
    
    // Scorro la lista mantenendo un puntatore k posizioni indietro

    corridore1 = *lista;
    corridore2 = lista;
    while(corridore1 != NULL) {
        if(contatore >= k) corridore2 = &((*corridore2)->next);
        corridore1 = corridore1->next;
        contatore++;
    }

    // Inserisco il nuovo elemento
    corridore1 = *corridore2;
    *corridore2 = malloc(sizeof(struct ElementoLista));
    (*corridore2)->valore = val;
    (*corridore2)->next = corridore1;
}