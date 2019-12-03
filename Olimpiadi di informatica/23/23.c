#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// constraints
#define MAXT 10000

// input data
int T, i;
int N[MAXT];

int ordinaNumeri(int N_ordinato[MAXT][2]);

int main()
{
    //  uncomment the following lines if you want to read/write from files
    freopen("ois_23/input0.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &T));

    // Leggo tutti i valori dal file e li inserisco nell'array N
    for (i = 0; i < T; i++)
        assert(1 == scanf("%d", &N[i]));

    // Stampo per debug
    for (int i = 0; i < T; i++)
        printf("%d\n", N[i]);
    printf("------\n");

    // Ordino gli T numeri nell'array N
    int N_ordinato[T][2];
    int L_N_O = ordinaNumeri(N_ordinato);
    printf("numeri non doppioni %d\n", L_N_O);

    // Stampo l'array ordinato per debug
    for (int i = 0; i < L_N_O; i++)
        printf("%d %d\n", N_ordinato[i][0], N_ordinato[i][1]);
    printf("------\n");

    // Calcolo quanti i numeri speciali partendo da quello precedente
    int k;
    int sommaCifreBase2;
    int sommaCifreBase3;
    int cifra, numero;
    for (int i = 0; i < L_N_O; i++)
    {
        if (i > 0) // Dal secondo in poi riutilizzo il risultato precedente
        {
            //printf("Uso il risultato precedente %d, somma:%d\n", i, N_ordinato[i - 1][1]);
            N_ordinato[i][1] = N_ordinato[i - 1][1];
            k = N_ordinato[i - 1][0];
        }
        else
        {
            k = 0;
        }

        for (; k < N_ordinato[i][0]; k++)
        {
            sommaCifreBase2 = 0;
            sommaCifreBase3 = 0;

            // Calcolo la somma delle cifre in base 2
            numero = k + 1;
            while (numero > 0)
            {
                cifra = numero % 2;
                sommaCifreBase2 += cifra;
                numero /= 2;
            }

            numero = k + 1;
            while (numero > 0)
            {
                cifra = numero % 3;
                sommaCifreBase3 += cifra;
                numero /= 3;
            }

            if (sommaCifreBase2 == sommaCifreBase3)
                N_ordinato[i][1]++;
        }
    }

    // Stampo l'array ordinato per debug
    /*for (int i = 0; i < T; i++)
        printf("%d %d\n", N_ordinato[i][0], N_ordinato[i][1]);
    printf("------\n");*/

    // Stampo i valori nell'ordine originale
    for (int i = 0; i < T; i++)
    {
        // Cerco il valore di N[i]
        for (int j = 0; j < T; j++)
        {
            if(N[i] == N_ordinato[j][0]) {
                printf("%d ", N_ordinato[j][1]);
                j = T;
            }
        }
    }

    printf("\n");
    return 0;
}

int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int ordinaNumeri(int N_ordinato[MAXT][2])
{
    int N_temp[T];
    int j = 0, doppione;
    // Copio i numeri in un nuovo array
    for (int i = 0; i < T; i++)
    {
        printf("step: %d %d\n", i, N[i]);
        doppione = 0;
        // Controllo se il valore N[i] è già stato inserito
        for(int k = 0; k < i; k++) {
            printf("controllo %d %d\n", N_temp[k], N[i]);
            if(N_temp[k] == N[i]) doppione = 1;
        }
        printf("doppione: %d\n", doppione);
        if(!doppione) {
            printf("non è un doppione, inserisco %d ", N[i]);
            printf("in posizione %d\n", j);
            N_temp[j] = N[i];
            j++;
        }
    }

    for (int i = 0; i < j; i++)
        printf("%d\n", N_temp[i]);
    printf("------\n");

    // Ordino il nuovo array
    qsort(N_temp, T, sizeof(int), cmpfunc);

    for (int i = 0; i < j; i++)
    {
        N_ordinato[i][0] = N_temp[i];
        N_ordinato[i][1] = 0;
    }

    return j;
}