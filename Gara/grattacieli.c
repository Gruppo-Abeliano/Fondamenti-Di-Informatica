#include <stdio.h>
#include <stdlib.h>

#define LUNGHEZZA_NOME_FILE 13 + 1 /* + 1 per \0 */
#define MAX_N 10

/* #define DEBUG */

void leggiDati(int *N, int griglia[MAX_N][MAX_N], int bordo[MAX_N * 4]);
int controlloGriglia(int N, int griglia[MAX_N][MAX_N]);
int controllaBordi(int N, int griglia[MAX_N][MAX_N], int bordo[MAX_N * 4]);

int main()
{
    /* Dati del programma */
    int N;
    int griglia[MAX_N][MAX_N]; /* Righe e colonne */
    int bordo[MAX_N * 4];

    /* Risultati dei calcoli */
    int risultatoGriglia, risultatoBordi;

    /* Leggo i dati da file */
    leggiDati(&N, griglia, bordo);

    /* Controllo la griglia */
    risultatoGriglia = controlloGriglia(N, griglia);

    /* Controlliamo i bordi */
    risultatoBordi = controllaBordi(N, griglia, bordo);

#ifdef DEBUG
    printf("Corretto? %s\n", risultatoBordi ? "Sì" : "No");
#endif /* DEBUG */

    printf("%d\n", risultatoGriglia && risultatoBordi);

    return 0;
}

void leggiDati(int *N, int griglia[MAX_N][MAX_N], int bordo[MAX_N * 4])
{
    int i;
    int j;
    FILE *input;

#ifndef DEBUG
    /* Nome del file da aprire */
    char nomeFile[LUNGHEZZA_NOME_FILE];
#endif /* DEBUG */

#ifndef DEBUG

    /* Leggo il nome del file da aprire */
    scanf("%13s", nomeFile);
    input = fopen(nomeFile, "rb");
#else
    input = fopen("skysol1.bin", "rb");
#endif /* DEBUG */

    /* Leggo l'input da file */
    fread(N, sizeof(int), 1, input);
    for (i = 0; i < *N; i++)
    {
        for (j = 0; j < *N; j++)
        {
            fread(&griglia[i][j], sizeof(int), 1, input);
        }
    }
    for (i = 0; i < *N * 4; i++)
    {
        fread(&bordo[i], sizeof(int), 1, input);
    }

#ifdef DEBUG
    printf("N: %d\n", *N);
    printf("Griglia:\n");
    for (i = 0; i < *N; i++)
    {
        for (j = 0; j < *N; j++)
            printf("%d ", griglia[i][j]);
        printf("\n");
    }
    printf("Bordo:\n");
    for (i = 0; i < (*N) * 4; i++)
        printf("%d ", bordo[i]);
    printf("\n");
#endif /* DEBUG */
}

int controlloGriglia(int N, int griglia[MAX_N][MAX_N])
{
    int i;
    int j;
    int l;

    /* Ciclo colonne */
    for (j = 0; j < N; j++)
    {
        /* Ciclo righe */
        for (i = 0; i < N; i++)
        {
            /* Controllo righe */
            for (l = i + 1; l < N; l++)
            {
                if (griglia[j][i] == griglia[j][l])
                {
                    return 0;
                }
            }
            /* Ciclo colonne */
            for (l = j + 1; l < N; l++)
            {
                if (griglia[j][i] == griglia[l][i])
                {
                    return 0;
                }
            }
        }
    }

    return 1;
}

int controllaBordi(int N, int griglia[MAX_N][MAX_N], int bordo[MAX_N * 4])
{
    int i;
    int j;
    int offset;
    int corretto;
    int contatore;
    int tetto;

    corretto = 1;
    offset = 0;

    /* Top */
    for (i = 0; i < N && corretto; i++)
    {
        contatore = 1;
        tetto = griglia[0][i];

        for (j = 1; j < N; j++)
        {
            if (griglia[j][i] > tetto)
            {
                tetto = griglia[j][i];
                contatore++;
            }
        }

        if (contatore != bordo[offset + i])
        {
            corretto = 0;
        }
    }

    offset = N;

    /* Right */
    for (i = 0; i < N && corretto; i++)
    {
        contatore = 1;
        tetto = griglia[i][N - 1];

        for (j = 1; j < N; j++)
        {
            if (griglia[i][N - 1 - j] > tetto)
            {
                tetto = griglia[i][N - 1 - j];
                contatore++;
            }
        }

        if (contatore != bordo[offset + i])
        {
            corretto = 0;
        }
    }

    offset = 2 * N;

    /* Bottom */
    for (i = N - 1; i >= 0 && corretto; i--)
    {
        contatore = 1;
        tetto = griglia[N - 1][i];

        for (j = N - 1; j >= 0; j--)
        {
            if (griglia[j][i] > tetto)
            {
                tetto = griglia[j][i];
                contatore++;
            }
        }

        if (contatore != bordo[offset + N - 1 - i])
        {
            corretto = 0;
        }
    }

    offset = 3 * N;

    /* Left */
    for (i = 0; i < N && corretto; i++)
    {
        contatore = 1;
        tetto = griglia[N - 1 - i][0];

        for (j = 1; j < N; j++)
        {
            if (griglia[N - 1 - i][j] > tetto)
            {
                tetto = griglia[N - 1 - i][j];
                contatore++;
            }
        }

        if (contatore != bordo[offset + i])
        {
            corretto = 0;
        }
    }

    return corretto;
}
