#include <stdio.h>

#define RIGHE 4
#define COLONNE 4

typedef int Matrice[RIGHE][COLONNE];

void mantieniSoloMassimi(Matrice matrice);

int main()
{
    int i, j;
    Matrice matrice = {
        {12, 11, 14, 15},
        {8, 15, 9, 17},
        {13, 10, 11, 10},
        {7, 6, 12, 11}};

    printf("Matrice di partenza:\n");
    for (i = 0; i < RIGHE; i++)
    {
        for (j = 0; j < COLONNE; j++)
            printf("%d ", matrice[i][j]);
        printf("\n");
    }

    mantieniSoloMassimi(matrice);
    printf("Matrice di arrivo:\n");
    for (i = 0; i < RIGHE; i++)
    {
        for (j = 0; j < COLONNE; j++)
            printf("%d ", matrice[i][j]);
        printf("\n");
    }
}

void mantieniSoloMassimi(Matrice matrice)
{
    Matrice reference;
    int i, j;

    for (i = 0; i < RIGHE; i++)
    {
        for (j = 0; j < COLONNE; j++)
        {
            if (
                (j == 0 || matrice[i][j] > matrice[i][j - 1]) &&
                (j == (COLONNE - 1) || matrice[i][j] > matrice[i][j + 1]) &&
                (i == 0 || matrice[i][j] > matrice[i - 1][j]) &&
                (i == (RIGHE - 1) || matrice[i][j] > matrice[i + 1][j]))
            {
                reference[i][j] = 1;
            }
            else
            {
                reference[i][j] = 0;
            }
        }
    }

    for (i = 0; i < RIGHE; i++)
        for (j = 0; j < COLONNE; j++)
            if (!reference[i][j])
                matrice[i][j] = 0;
}