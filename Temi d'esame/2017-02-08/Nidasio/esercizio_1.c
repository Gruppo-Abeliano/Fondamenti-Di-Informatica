#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Funzionamento:
 * La funzione, supponendo che il file sia aperto correttamente, legge un elemento alla volta finchè non finisce il file.
 * Per ogni elemento letto scorre la lista controllando se è già presente. In caso positivo incrementa il contatore,
 * in caso negativo appende un elemento alla lista.
*/

typedef struct ElementoLista
{
    struct ElementoLista *next;
    int valore;
    int occorrenze;
} * Lista;

void stampaLista(Lista lista);
Lista leggiOccorrenze(FILE *file);

int main()
{
    FILE *file = fopen("input_esercizio_1.c", "r");

    Lista lista = leggiOccorrenze(file);

    stampaLista(lista);

    return 0;
}

Lista leggiOccorrenze(FILE *file)
{
    Lista testa = NULL;
    Lista *corridore;
    int input;
    bool trovato;

    // Leggo il file finchè è possibile aggiornando la lista di conseguenza
    while (fscanf(file, "%d", &input) != EOF)
    {
        // Controllo se è già presente l'elemento nella lista
        corridore = &testa;
        trovato = false;

        while (*corridore != NULL && !trovato)
        {
            if ((*corridore)->valore == input)
            {
                trovato = true;
                (*corridore)->occorrenze++;
            }
            corridore = &(*corridore)->next;
        }

        // Se non ho già trovato l'elemento allora lo aggiungo
        if (!trovato)
        {
            *corridore = malloc(sizeof(struct ElementoLista));
            (*corridore)->valore = input;
            (*corridore)->occorrenze = 1;
        }
    }

    return testa;
}

void stampaLista(Lista lista)
{
    while (lista != NULL)
    {
        printf("['%d',%d]\n", lista->valore, lista->occorrenze);
        lista = lista->next;
    }
}