#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 1000000

// input data
int N, i;
int G[MAXN];
int risultato;

int main()
{
    //  uncomment the following lines if you want to read/write from files
    //  freopen("ois_grades/input0.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for (i = 0; i < N; i++)
        assert(1 == scanf("%d", &G[i]));

    // Trovo la posizione del primo voto negativo
    int indexPrimoVotoNegativo = -1;

    for (i = 0; i < N && indexPrimoVotoNegativo == -1; i++)
        if (G[i] < 6)
            indexPrimoVotoNegativo = i;

    // Controllo se ho trovato almeno un numero negativo
    if (indexPrimoVotoNegativo >= 0)
    {
        // Cerco la posizione dell'ultimo voto positivo in lista
        int indexUltimoVotoPositivo = -1;
        for (i = N - 1; i > 0 && indexUltimoVotoPositivo == -1; i--)
            if (G[i] >= 6)
                indexUltimoVotoPositivo = i;

        // Controllo se è stato trovato un voto positivo
        if (indexUltimoVotoPositivo >= 0)
        {
            risultato = indexUltimoVotoPositivo - indexPrimoVotoNegativo + 1;

            if(risultato <= 0) risultato = -1;
        }
        else
        {
            risultato = -1;
        }
    }
    else
    {
        risultato = -1;
    }

    printf("%d\n", risultato); // print the result
    return 0;
}
