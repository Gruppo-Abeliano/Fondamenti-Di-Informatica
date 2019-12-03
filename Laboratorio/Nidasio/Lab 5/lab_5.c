#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento
{
    int numero;
    struct Elemento *prossimo;
} TipoElemento;

typedef enum
{
    FALSE,
    TRUE
} boolean;

/* Crea una lista dinamica contenente interi positivi o nulli letti
 * da tastiera e restituisce la testa di tale lista. L'input da tastiera
 * termina quando l'utente inserisce un numero negativo
*/
TipoElemento *RiempiLista(void);

/* Stampa a schermo gli interi contenuti nella lista avente testa Testa */
void StampaLista(TipoElemento *Testa);

/* Restituisce true se almeno uno dei numeri contenuti nella lista avente
 * testa Testa compare due o più volte nella lista; altrimenti restituisce false
*/
boolean ContieneDoppioni(TipoElemento *Testa);

int main()
{
    // Ripempo la lista
    TipoElemento *lista = RiempiLista();

    // Stampo la lista
    StampaLista(lista);

    // Controllo se nella lista ci sono doppioni
    boolean doppioni = ContieneDoppioni(lista);

    if(doppioni == TRUE) printf("La lista contiene doppioni\n");
    else printf("La lista non contiene doppioni\n");

    return 0;
}

TipoElemento *RiempiLista(void)
{
    int input;
    TipoElemento *testa;
    TipoElemento *puntatore = NULL;

    do
    {
        // Leggo il valore da tastiera
        printf("Inserisci un numero da inserire nella lista (x<0 per uscire): ");
        scanf("%d", &input);

        if (input >= 0)
        {
            if (puntatore == NULL)
            {
                puntatore = malloc(sizeof(TipoElemento));
                testa = puntatore;
            }
            else
            {
                puntatore->prossimo = malloc(sizeof(TipoElemento));
                puntatore = puntatore->prossimo;
            }
            puntatore->numero = input;
        }
    } while (input >= 0);

    return testa;
}

void StampaLista(TipoElemento *Testa)
{
    while (Testa != NULL)
    {
        printf("%d\n", Testa->numero);
        Testa = Testa->prossimo;
    }
}

boolean ContieneDoppioni(TipoElemento *Testa)
{
    TipoElemento *doppione;

    while (Testa != NULL)
    {
        // Controllo se trovo un altri elemento successivo a quello corrente con lo stesso numero
        doppione = Testa->prossimo;

        while(doppione != NULL)
        {
            if(doppione->numero == Testa->numero) return TRUE;
            doppione = doppione->prossimo;
        }

        Testa = Testa->prossimo;
    }

    return FALSE;
}