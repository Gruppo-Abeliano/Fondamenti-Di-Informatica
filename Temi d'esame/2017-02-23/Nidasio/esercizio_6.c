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

int main()
{
    Parola parola = "Ciao Paolo!\0";

    ListaOccorrenze listaOccorrenze = NULL;

    costruisciLista(&listaOccorrenze, parola);

    stampaLista(listaOccorrenze);

    return 0;
}

void costruisciLista(ListaOccorrenze *testa, Parola parola)
{
    ListaOccorrenze corridore;
    ListaOccorrenze tmp;
    bool trovato;

    // Se la lettera è maiuscola la rendo minuscola
    if(parola[0] < 'a' && parola[0] >= 'A') parola[0] += 'a' - 'A';

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

        // Se non è stato trovato devo inserire il nuovo elemento in posizione corretta, in modo tale che la lista risulti ordinata alfabeticamente
        if (!trovato)
        {
            // Controllo se l'elemento va inserito prima della testa
            if ((*testa)->carattere > parola[0])
            {
                corridore = malloc(sizeof(struct _ListaOccorrenze));
                corridore->carattere = parola[0];
                corridore->occorrenze = 1;
                corridore->next = *testa;
                *testa = corridore;
            }
            else
            {
                // Altrimenti riscorro la lista per trovare il punto appropriato in cui inserire l'elemento
                corridore = *testa;

                while (corridore->next != NULL && corridore->next->carattere < parola[0])
                    corridore = corridore->next;

                tmp = corridore->next;
                corridore->next = malloc(sizeof(struct _ListaOccorrenze));
                corridore = corridore->next;
                corridore->carattere = parola[0];
                corridore->occorrenze = 1;
                corridore->next = tmp;
            }
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