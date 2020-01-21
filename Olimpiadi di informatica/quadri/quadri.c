//#define DEBUG

#ifdef DEBUG
#include <stdio.h>
#endif // DEBUG

int quadri(int N, long long M, int V[])
{
    long long sommaTemp;
    int j = 1;
    int B = N;

    for (int i = 0; i < N; i++)
    {
#ifdef DEBUG
        printf("Controllo l'elemento %d (%d)\n", i, V[i]);
#endif // DEBUG
        sommaTemp = V[i];

        for (j = 1; sommaTemp <= M && i + j < N && j < B; j++)
        {
            sommaTemp += V[i + j];
#ifdef DEBUG
            printf("\t%d: Valore successivo: %d, somma temporanea: %d\n", j, V[i + j], sommaTemp);
#endif // DEBUG
        }

        if (sommaTemp > M)
            j--;
#ifdef DEBUG
        printf("Calcolo per la posizione %d completato\n", i);
        printf("Valore B in questa posizione: %d\n\n", j);
#endif // DEBUG

        if (j < B && sommaTemp > M)
            B = j;

        // Se nel'esecuzione i + j è arrivato a N allora non devo preoccuparmi degli ultimi j - 1 numeri, quindi esco da ciclo
#ifdef DEBUG
        printf("Esecuzione precedente arrivata in posizione %d (%d)\n", i + j, N);
#endif // DEBUG
        if (i + j >= N)
            i = N;
    }

    return B;
}
