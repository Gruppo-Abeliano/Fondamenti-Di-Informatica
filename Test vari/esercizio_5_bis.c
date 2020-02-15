#include <stdio.h>

#define MAX_CARATTERI 20

typedef char Parola[MAX_CARATTERI];
typedef struct
{
    Parola parola;
    int nElementi;
    char caratteri[MAX_CARATTERI - 1];
    int numeroCaratteri[MAX_CARATTERI - 1];
} ListaOccorrenze;

void leggiParola(Parola parola);
void calcolaOccorrenze(ListaOccorrenze *listaOccorrenze);

int main()
{
    ListaOccorrenze listaOccorrenze;
    int i;

    leggiParola(listaOccorrenze.parola);

    printf("Parola inserita: %s\n", listaOccorrenze.parola);

    // Calcolo le occorrenze
    calcolaOccorrenze(&listaOccorrenze);

    for (i = 0; i < listaOccorrenze.nElementi; i++)
        printf("[\'%c\',%d]", listaOccorrenze.caratteri[i], listaOccorrenze.numeroCaratteri[i]);
    printf("\n");

    return 0;
}

void leggiParola(Parola parola)
{
    printf("Inserisci una parola di di non più di 20 caratteri: ");
    scanf("%s", parola);
}

void calcolaOccorrenze(ListaOccorrenze *listaOccorrenze)
{
    char carattere;
    int i, offset = 0;

    // Prendo il primo carattere in parola
    carattere = listaOccorrenze->parola[0];

    // Controllo se siamo alla fine della lista
    if (carattere == '\0')
    {
        ListaOccorrenze listaNulla;
        listaNulla.nElementi = 0;
        return listaNulla;
    }

    // Creo una lista occorrenze e inserisco il carattere
    listaOccorrenze->nElementi = 1;
    listaOccorrenze->caratteri[0] = carattere;
    listaOccorrenze->numeroCaratteri[0] = 1;

    // Recupero i risultati successivi
    parola++;
    calcolaOccorrenze(listaOccorrenze);

    // Inserisco i risultati successivi nella mia lista occorrenze
    for (i = 0; i < prossimoCalcolo.nElementi; i++)
    {
        // Controllo se il carattere i-esimo è quello che ho valutato prima
        if (carattere == prossimoCalcolo.caratteri[i] && offset == 0)
        {
            // In questo caso incremento il mio contatore e porto offset a 1
            listaOccorrenze.numeroCaratteri[0]++;
            offset = 1;
        }
        else
        {
            listaOccorrenze.caratteri[i + 1 - offset] = prossimoCalcolo.caratteri[i];
            listaOccorrenze.numeroCaratteri[i + 1 - offset] = prossimoCalcolo.numeroCaratteri[i];
            listaOccorrenze.nElementi++;
        }
    }

    // Ritorno il risultato
    return listaOccorrenze;
}