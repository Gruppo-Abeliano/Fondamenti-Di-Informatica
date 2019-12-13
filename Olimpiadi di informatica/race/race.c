#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

//#define DEBUG

#define MAX_CORRIDORI 65536

int N, i, j;
int CORRIDORI[MAX_CORRIDORI][3];

int cmpfunc(const void *pa, const void *pb)
{
    const int(*a)[3] = (const int(*)[3])pa;
    const int(*b)[3] = (const int(*)[3])pb;

    int posizioneA = (*a)[0] + (i + 1) * (*a)[1];
    int posizioneB = (*b)[0] + (i + 1) * (*b)[1];

    int differenza = posizioneB - posizioneA;

    //printf("posA: %d posB: %d - ", posizioneA, posizioneB);
    //printf("a vs b: (%d,%d,%d) vs (%d,%d,%d) - diff: %d - i: %d\n", (*a)[0], (*a)[1], (*a)[2], (*b)[0], (*b)[1], (*b)[2], differenza, i);
    if (differenza == 0)
        if ((*a)[2] - (*b)[2])
            return 1;
        else
            return -1;
    else
        return differenza;
}

int main()
{
#ifdef DEBUG
    freopen("unimi_race/race.input1.txt", "r", stdin);
#endif // DEBUG

    // Leggo i dati
    assert(1 == scanf("%d", &N));
    for (i = 0; i < N; i++)
    {
        assert(1 == scanf("%d", &CORRIDORI[i][0]));
        assert(1 == scanf("%d", &CORRIDORI[i][1]));
        CORRIDORI[i][2] = i;
    }

#ifdef DEBUG
    printf("Dati iniziali:\n%d\n", N);
    for (i = 0; i < N; i++)
        printf("%d\t%d\t%d\n", CORRIDORI[i][0], CORRIDORI[i][1], CORRIDORI[i][2]);
#endif // DEBUG

    // Risolvo il problema
    int minutiTotali = log2(N);

    // Aggiungo, per ogni minuto, i metri B di goni corridore ai metri iniziali A
    for (i = 0; i < minutiTotali; i++)
    {
        /*for (j = 0; j < N - i * 2; j++) // Aggiorno solo quelli che non sono stati rimossi dall'esistenza
            CORRIDORI[j][0] += CORRIDORI[j][1];*/

        // Ordino i corridori
        qsort(CORRIDORI, N - i * 2, 3 * sizeof(int), cmpfunc);

#ifdef DEBUG
        printf("Dati allo step %d:\n", i);
        printf("%d\t%d\t%d\n", CORRIDORI[0][0], CORRIDORI[0][1], CORRIDORI[0][2]);
        for (j = 1; j < N - (i + 1) * 2; j++)
            printf("%d\t%d\t%d\n", CORRIDORI[j][0], CORRIDORI[j][1], CORRIDORI[j][2]);
        printf("\n");
#endif // DEBUG
    }

    // Stampo il risultato
    printf("%d\n", CORRIDORI[0][2]);
    return 0;
}
