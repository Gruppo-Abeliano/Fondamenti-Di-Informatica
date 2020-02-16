#include <stdio.h>

/**
 * Da migliorare e completare
*/

#define DIMENSIONE_GRIGLIA 5
#define STR_EXPAND(tok) #tok
#define STR(tok) STR_EXPAND(tok)

int main()
{
    FILE *file;
    char griglia[DIMENSIONE_GRIGLIA][DIMENSIONE_GRIGLIA]; // Righe e colonne
    int i, j;
    char parola[DIMENSIONE_GRIGLIA + 1] = {0};
    int linea, colonna, index, trovata;

    //1: Apro il file
    file = fopen("mappa.txt", "r");
    if (file == NULL)
        return 1;

    //2: Leggo il file inserendo i dati nella riglia
    for (i = 0; i < DIMENSIONE_GRIGLIA * DIMENSIONE_GRIGLIA; i++)
        fscanf(file, "%c", &griglia[i / DIMENSIONE_GRIGLIA][i % DIMENSIONE_GRIGLIA]);

    for (i = 0; i < DIMENSIONE_GRIGLIA; i++)
    {
        for (j = 0; j < DIMENSIONE_GRIGLIA; j++)
            printf("%C ", griglia[i][j]);
        printf("\n");
    }

    //3: Chiedo all'utente la parola da cercare
    printf("Inserisci la parola da cercare (max %d caratteri): ", DIMENSIONE_GRIGLIA);
    scanf("%" STR(DIMENSIONE_GRIGLIA) "s", parola);

    //4: Cerco la parola in orizzonatale
    trovata = 0;
    for (i = 0; i < DIMENSIONE_GRIGLIA && !trovata; i++) // Righe
    {
        index = 0;

        for (j = 0; j < DIMENSIONE_GRIGLIA && !trovata; j++) // Colonne
        {
            printf("%c %c\n", parola[index], griglia[i][j]);
            if (parola[index] == griglia[i][j])
            {
                if (index == 0)
                {
                    linea = i;
                    colonna = j;
                }
                index++;
            }
            else if (index > 0)
            {
                j = DIMENSIONE_GRIGLIA;
            }

            if (parola[index] == '\0')
            {
                trovata = 1;
                printf("Trovato\n");
            }
        }
    }

    //5: Mostro il risultato
    printf("La parola è presente nella griglia a linea %d e colonna %d\n", linea, colonna);

    return 0;
}