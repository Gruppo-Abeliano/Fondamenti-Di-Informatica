#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CARATTERE_TEMINATORE 'S'

typedef struct ElementoLista
{
    struct ElementoLista *next;
    char carattere;
} * Lista;

void leggiLista(Lista *testa);
void stampaLista(Lista lista);
void eliminaElementoCentrale(Lista *lista);

int main()
{
    Lista lista = NULL;

    leggiLista(&lista);

    printf("Lista originale: ");
    stampaLista(lista);

    eliminaElementoCentrale(&lista);

    printf("Lista elaborata: ");
    stampaLista(lista);

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

void eliminaElementoCentrale(Lista *lista)
{
    Lista corridore1, corridore2;
    bool avanzato;

    // Controllo se la lista ha un solo elemento
    if ((*lista)->next == NULL)
    {
        // In questo caso devo eliminare il primo elemento
        free(*lista);
        *lista = NULL;
    }
    else
    {
        // Altrimenti scorro la lista tramite due corridori
        corridore1 = *lista;
        corridore2 = *lista;
        avanzato = true;

        corridore1 = corridore1->next;

        if (corridore1->next == NULL)
        {
            free(corridore1);
            corridore2->next = NULL;
        }
        else
        {
            corridore1 = corridore1->next;
            while (corridore1 != NULL)
            {
                // Avanzo il secondo corridore una volta si e una volta no, mantenendolo un passo dietro all'emento centrale
                if (!avanzato)
                {
                    corridore2 = corridore2->next;
                    avanzato = true;
                }
                else
                {
                    avanzato = false;
                }

                printf("%c %c\n", corridore1->carattere, corridore2->carattere);
                corridore1 = corridore1->next;
            }

            // A questo punto sono arrivato alla fine della lista e il corridore2 punta all'elemento precendete a quello centrale
            corridore1 = corridore2->next->next;
            free(corridore2->next);
            corridore2->next = corridore1;
        }
    }
}