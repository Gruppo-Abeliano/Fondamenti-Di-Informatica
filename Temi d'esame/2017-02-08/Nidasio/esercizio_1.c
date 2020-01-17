#include <stdio.h>
#include <stdlib.h>

typedef struct ElementoLista
{
    struct ElementoLista *next;
    int numero;
    int occorrenze;
} * Lista;

void stampaLista(Lista lista);
Lista analizzaFile(FILE *daLeggere);

int main()
{
    FILE *file = fopen("input_esercizio_1.c", "r");

    Lista lista = analizzaFile(file);

    stampaLista(lista);

    return 0;
}

Lista analizzaFile(FILE *daLeggere)
{
    Lista testa = NULL;
    Lista *corridore;
    int tmp;

    // Leggo il file finchè è possibile aggiornando la lista di conseguenza
    while (fscanf(daLeggere, "%d", &tmp) != EOF)
    {
        // Se la testa della lista è nulla la inizializzo
        if (testa == NULL)
        {
            testa = malloc(sizeof(struct ElementoLista));
            testa->numero = tmp;
            testa->occorrenze = 1;
        }
        else
        {
            // Controllo se l'elemento è già presente
            corridore = &testa;

            while (*corridore != NULL)
            {
                if ((*corridore)->numero == tmp)
                {
                    (*corridore)->occorrenze++;
                    break;
                }
                corridore = &(*corridore)->next;
            }

            if (*corridore == NULL)
            {
                // Nonn ho trovato l'elemento, lo creo
                *corridore = malloc(sizeof(struct ElementoLista));
                (*corridore)->numero = tmp;
                (*corridore)->occorrenze = 1;
            }
        }
    }

    return testa;
}

void stampaLista(Lista lista)
{
    while (lista != NULL)
    {
        printf("['%d',%d]\n", lista->numero, lista->occorrenze);
        lista = lista->next;
    }
}