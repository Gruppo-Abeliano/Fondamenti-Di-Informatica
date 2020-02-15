#include <stdio.h>

#define DIMENSIONE_IMMAGINE 5

typedef int Immagine[DIMENSIONE_IMMAGINE][DIMENSIONE_IMMAGINE]; // Righe, colonne

int calcolaPerimetro(Immagine immagine);

int main()
{
    Immagine immagine = {
        {0, 0, 1, 1, 1},
        {0, 0, 1, 1, 1},
        {0, 0, 0, 1, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0},
    };
    int perimetro;

    perimetro = calcolaPerimetro(immagine);

    printf("Il perimetro dell'imagine è: %d pixel\n", perimetro);

    return 0;
}

int calcolaPerimetro(Immagine immagine)
{
    int i, j;
    int perimetro = 0;

    // Controllo i bordi interni
    for (i = 1; i < DIMENSIONE_IMMAGINE; i++) // Righe
    {
        for (j = 1; j < DIMENSIONE_IMMAGINE; j++) // Colonne
        {
            // Controllo il pixel sopra e a sinistra
            if (immagine[i][j] != immagine[i - 1][j])
                perimetro++;
            if (immagine[i][j] != immagine[i][j - 1])
                perimetro++;
        }
    }

    // Controllo i perimetri esterni
    for (i = 0; i < DIMENSIONE_IMMAGINE; i++)
    {
        if (immagine[0][i])
            perimetro++;
        if (i != 0 && immagine[0][i] != immagine[0][i - 1])
            perimetro++;
        if (immagine[DIMENSIONE_IMMAGINE - 1][i])
            perimetro++;
        if (immagine[i][0])
            perimetro++;
        if (i != 0 && immagine[i][0] != immagine[i - 1][0])
            perimetro++;
        if (immagine[i][DIMENSIONE_IMMAGINE - 1])
            perimetro++;
    }

    // Ritorno il perimentro
    return perimetro;
}