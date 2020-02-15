#include <stdio.h>

#define LUNGHEZZA_ARRAY 30

int massimaCrescente(int array[LUNGHEZZA_ARRAY]);

int main()
{
    int array[LUNGHEZZA_ARRAY] = {
        3, 2, 4, 6, 1, 3, 2, 4, 6, 7, 9, 3, 2,
    };
    int indiceMassimo;

    indiceMassimo = massimaCrescente(array);

    printf("L'indice della sequenza crescente più lunga è: %d\n", indiceMassimo);

    return 0;
}

int massimaCrescente(int array[LUNGHEZZA_ARRAY])
{
    int indiceMassimo, indiceCorrente;
    int numeroMassimo, numeroCorrente;
    int i;

    indiceMassimo = 0;
    indiceCorrente = 0;
    numeroMassimo = 1;
    numeroCorrente = 1;

    // Cerco la sequenza più lunga di elementi crescenti nell'array, continuo finchè ha senso proseguire
    for (i = 1; i < LUNGHEZZA_ARRAY; i++)
    {
        // Se l'elemento è crescente continuo ad incrementare il contatore altrimenti riparto dall'elemento attuale
        if (array[i - 1] < array[i])
        {
            numeroCorrente++;
        }
        else
        {
            indiceCorrente = i;
            numeroCorrente = 1;
        }

        if (numeroMassimo < numeroCorrente)
        {
            indiceMassimo = indiceCorrente;
            numeroMassimo = numeroCorrente;
        }
    }

    return indiceMassimo;
}