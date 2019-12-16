#include <stdio.h>
#include <stdlib.h>

#define RIGHE 13
#define COLONNE 9
#define LUNGHEZZA_NOME_FILE 20

typedef struct Vocabolo {
    char vocabolo[RIGHE];
    struct Vocabolo *successivo;
} Vocaboli;

typedef struct {
    char cruciverbaCompletato[RIGHE][COLONNE];
    Vocaboli vocaboliOrizzonatali;
    Vocaboli vocaboliVerticali;
} Cruciverba;

int main()
{
    char nomeFile[LUNGHEZZA_NOME_FILE];
    Cruciverba cruciverba;

    int i, j;

    /* Leggo il nome del file da aprire */
    scanf("%20s", nomeFile);

    /* Apro il file */
    FILE *input = fopen(nomeFile, "r");

    /* Leggo l'input da file */
    for(i = 0; i < RIGHE; i++)
        for(j = 0; j < COLONNE; j++)
            fscsanf("%c", cruciverba.cruciverbaCompletato[i][j]);

    /* DEBUG */
    for(i = 0; i < RIGHE; i++)
    {
        for(j = 0; j < COLONNE; j++)
            printf("%c", cruciverba.cruciverbaCompletato[i][j]);
        printf("\n");
    }

    return 0;
}