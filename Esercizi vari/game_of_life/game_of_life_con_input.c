#include <stdio.h>
#include <stdlib.h>

/**
 * Autore: Alberto Nidasio
 * Scopo: Implementare il "Game of Life" di Conway 
 * Link: https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
 * 
 * Regole del gioco:
 * - Il campo viene inizializzato random e le celle possono essere o vive o morte
 * - Ad ogni round:
 *  - Solo le celle vive con 2 o 3 celle vicine vive continuano a vivere
 *  - Se una cella morta ha tre celle vicine vive rinasce
*/

#define DIMENSIONE_CAMPO_X 10
#define DIMENSIONE_CAMPO_Y 10
#define VIVA 1
#define MORTA 0
#define EPOCHE 100
#define DELAY_MS 500

void inizializzaCampo(FILE *fileStatoInizialeCampo, int campo[DIMENSIONE_CAMPO_X][DIMENSIONE_CAMPO_Y]);
void mostraCampo(int campo[DIMENSIONE_CAMPO_X][DIMENSIONE_CAMPO_Y]);
int calcolaProssimaEpoca(int campo[DIMENSIONE_CAMPO_X][DIMENSIONE_CAMPO_Y], int prossimoCampo[DIMENSIONE_CAMPO_X][DIMENSIONE_CAMPO_Y]);
int calcolaViciniVivi(int prossimoCampo[DIMENSIONE_CAMPO_X][DIMENSIONE_CAMPO_Y], int i, int j);

int main(int argc, char **argv)
{
    int campo[2][DIMENSIONE_CAMPO_X][DIMENSIONE_CAMPO_Y]; // [X][Y]
    int check = 1;

    // Provo ad aprire il file e leggere lo stado iniziale da assegnare al campo
    if(argc < 2) return 0; // Se non c'è il file non avvio nemmeno il programma
    FILE *fileStatoInizialeCampo = fopen(argv[1], "r");
    if(fileStatoInizialeCampo)
    {
        inizializzaCampo(fileStatoInizialeCampo, campo[0]);
        fclose(fileStatoInizialeCampo);
    }

    // Continuo fino a quando il gioco finisce (quando nessuna cella nasce e nessuna muore)
    for(int i = 0; check /*i < EPOCHE*/; i++)
    {
        system("clear"); // Pulisco lo schermo dalla stampa dell'epoca precedente
        check = calcolaProssimaEpoca(campo[i % 2], campo[(i + 1) % 2]);
        mostraCampo(campo[(i + 1) % 2]);
        usleep(DELAY_MS * 1000); // Aspetto il delay impostato prima di passare alla prossima epoca
    }

    return 0;
}

// Inizializza il campo tramite il file dato
void inizializzaCampo(FILE *fileStatoInizialeCampo, int campo[DIMENSIONE_CAMPO_X][DIMENSIONE_CAMPO_Y])
{
    int colonne, righe;

    fscanf(fileStatoInizialeCampo, "%d %d\n", &colonne, &righe);
    for(int i = 0; i < colonne; i++, fscanf(fileStatoInizialeCampo, "\n"))
        for(int j = 0; j < righe; j++)
            fscanf(fileStatoInizialeCampo, "%d", &campo[i][j]);
}

// Mosta il campo nella console
void mostraCampo(int campo[DIMENSIONE_CAMPO_X][DIMENSIONE_CAMPO_Y])
{
    for(int i = 0; i < DIMENSIONE_CAMPO_X; i++, printf("\n"))
        for(int j = 0; j < DIMENSIONE_CAMPO_Y; j++)
            if(campo[i][j]) printf("\u2588\u2588");
            else printf("  ");
}

// Calcola la prossima epoca, ritorna -1 se la prossima epoca non ha modifiche alrimenti il numero di celle modificate
int calcolaProssimaEpoca(int campo[DIMENSIONE_CAMPO_X][DIMENSIONE_CAMPO_Y], int prossimoCampo[DIMENSIONE_CAMPO_X][DIMENSIONE_CAMPO_Y])
{
    int viciniVivi, modificati = 0;

    // Controllo ogni cella quanti vicini vivi ha
    for(int i = 0; i < DIMENSIONE_CAMPO_X; i++)
        for(int j = 0; j < DIMENSIONE_CAMPO_Y; j++)
        {
            viciniVivi = calcolaViciniVivi(campo, i, j);

            if((campo[i][j] && viciniVivi >= 2 && viciniVivi <= 3) || // Se una cella viva ha 2 o 3 vicini vivi allora continua a vivere
                (!campo[i][j] && viciniVivi == 3)) // Una cella morta se ha 3 vicini vivi resuscita
                prossimoCampo[i][j] = VIVA;
            else // Altrimenti muore
                prossimoCampo[i][j] = MORTA;

            if(campo[i][j] != 
prossimoCampo[i][j]) modificati++;
        }
    return modificati;
}

// Calcola quante celle vicine ci sono ad una data coordinata
int calcolaViciniVivi(int campo[DIMENSIONE_CAMPO_X][DIMENSIONE_CAMPO_Y], int i, int j)
{
    int x, y, viciniVivi = 0;

    for(int k = 0; k < 9; k++)
    {
        x = i + (k % 3) - 1;
        y = j + (k / 3) - 1;
        if(x > 0 && y > 0 && x < DIMENSIONE_CAMPO_X && y < DIMENSIONE_CAMPO_Y && campo[x][y]) viciniVivi++;
    }
    return viciniVivi;
}