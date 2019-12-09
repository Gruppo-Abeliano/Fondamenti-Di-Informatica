#include <stdio.h>

int quadri(int N, long long M, int V[])
{
    int sommaTemp, j;
    int B = N;


    for (int i = 0; i < N; i++)
    {
        printf("Controllo l'elemento %d (%d)\n", i, V[i]);
        sommaTemp = V[i];
        for(j = 1; sommaTemp <= M && i + j < N; j++)
        {
            sommaTemp += V[i + j];
            printf("\t%d: Valore successivo: %d, somma temporanea: %d\n", j, V[i + j], sommaTemp);
        }
        j--;
        printf("Calcolo per la posizione %d completato\n", i);
        printf("Valore B in questa posizione: %d\n\n", j);

        if(j < B)
        {
            
        }
    }

    return B;
}
