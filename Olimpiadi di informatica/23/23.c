#include <stdio.h>
#include <assert.h>

// constraints
#define MAXT 10000

// input data
int T, i;
int N[MAXT];
int memoria[10000][2];

int main()
{
    //  uncomment the following lines if you want to read/write from files
    // freopen("ois_23/input0.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &T));
    for (i = 0; i < T; i++)
    {
        assert(1 == scanf("%d", &N[i]));

        int numeriSpeciali = 0;

        int j = 1;
        int k;

        // Controllo se è già presente in memoria qualcosa
        for (k = 0; k < i; k++)
        {
            //printf("Controllo la memoria in k:%d, [0]:%d, [1]:%d, N:%d\n", k, memoria[k][0], memoria[k][1], N[i]);
            if (memoria[k][0] <= N[i] && memoria[k][0] >= j)
            {
                j = memoria[k][0] + 1;
                numeriSpeciali = memoria[k][1];
                //printf("Mi piace %d\n", memoria[k][0]);
            }
        }

        //printf("Parto da %d con %d\n", j, numeriSpeciali);
        for (; j <= N[i]; j++)
        {
            int sommaCifreBase2 = 0;
            int sommaCifreBase3 = 0;
            int cifra, numero;

            // Calcolo la somma delle cifre in base 2
            numero = j;
            while (numero > 0)
            {
                cifra = numero % 2;
                sommaCifreBase2 += cifra;
                numero /= 2;
            }

            numero = j;
            while (numero > 0)
            {
                cifra = numero % 3;
                sommaCifreBase3 += cifra;
                numero /= 3;
            }

            if (sommaCifreBase2 == sommaCifreBase3)
                numeriSpeciali++;
        }

        memoria[i][0] = N[i];
        memoria[i][1] = numeriSpeciali;

        printf("%d ", numeriSpeciali); // print the result
    }
    printf("\n");
    return 0;
}