#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LUNGHEZZA_PAROLA 20

/**
 * Esercizio svolto direttamente con una lista dinamica
*/

typedef char Parola[LUNGHEZZA_PAROLA];

typedef struct _ListaOccorrenze
{
    struct _ListaOccorrenze *next;
    char carattere;
    int occorrenze;
} * ListaOccorrenze;

void costruisciLista(ListaOccorrenze *testa, Parola parola);
void stampaLista(ListaOccorrenze lista);

int main() {
    Parola parola = "Ciao Paolo!\0";

    ListaOccorrenze listaOccorrenze = NULL;

    costruisciLista(&listaOccorrenze, parola);

    stampaLista(listaOccorrenze);

    return 0;
}


void costruisciLista(ListaOccorrenze *testa, Parola parola)
{
    ListaOccorrenze corridore;
    bool trovato;

    // Se siamo arrivati alla fine della parola concludo la ricorsione
    if (parola[0] == '\0')
        return;

    // Se la testa della lista è nulla inizializzo il primo elemento e proseguo
    if (*testa == NULL)
    {
        *testa = malloc(sizeof(struct _ListaOccorrenze));
        (*testa)->carattere = parola[0];
        (*testa)->occorrenze = 1;
    }
    else
    {
        // Altrimento scorro la lista, se trovo lo stesso carattere aumento le sue occorrenze, altrimenti creo un nuovo elemento della lista
        corridore = *testa;
        trovato = false;

        do
        {
            if (corridore->carattere == parola[0])
            {
                corridore->occorrenze++;
                trovato = true;
                break;
            }
            if (corridore->next != NULL)
                corridore = corridore->next;
        } while (corridore->next != NULL);

        if (!trovato)
        {
            corridore->next = malloc(sizeof(struct _ListaOccorrenze));
            corridore = corridore->next;
            corridore->carattere = parola[0];
            corridore->occorrenze = 1;
        }
    }

    costruisciLista(testa, ++parola);
}

void stampaLista(ListaOccorrenze lista)
{
    while (lista != NULL)
    {
        printf("['%c',%d]\n", lista->carattere, lista->occorrenze);
        lista = lista->next;
    }
}