#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Autore: Alberto Nidasio
 * Note: Esercizio 5 della prova d'esame del 2017-07-03
*/

#define TIPO_MATRICE 4

void inizializzaMatrice(int matrice[2][TIPO_MATRICE][TIPO_MATRICE]);
void mostraMatrice(int matrice[TIPO_MATRICE][TIPO_MATRICE]);
void trovaMassimi(int matrice[TIPO_MATRICE][TIPO_MATRICE], int matriceConMassimi[TIPO_MATRICE][TIPO_MATRICE]);

int main() {
    int matrice[2][TIPO_MATRICE][TIPO_MATRICE];

    inizializzaMatrice(matrice);

    printf("Matrice iniziale\n");
    mostraMatrice(matrice[0]);

    trovaMassimi(matrice[0], matrice[1]);

    printf("Matrice con solo i  massimi\n");
    mostraMatrice(matrice[1]);

    return 0;
}

// Inizializza la matrice [0] con numeri casuali tra 0 e 100 e la matrice [1] con 0
void inizializzaMatrice(int matrice[2][TIPO_MATRICE][TIPO_MATRICE])
{
    int i;

    srand(time(0));
    for(i = 0; i < TIPO_MATRICE*TIPO_MATRICE; i++)
    {
        matrice[0][i % TIPO_MATRICE][i / TIPO_MATRICE] = rand() % 101;
        matrice[1][i % TIPO_MATRICE][i / TIPO_MATRICE] = 0;
    }
}

void mostraMatrice(int matrice[TIPO_MATRICE][TIPO_MATRICE])
{
    int i, j;

    for(i = 0; i < TIPO_MATRICE; i++)
    {
        for(j = 0; j < TIPO_MATRICE; j++)
            printf("%d\t", matrice[i][j]);
        printf("\n");
    }
}

// Trova i massimi locali e li inserisce nella seconda matrice nelle loro posizioni
void trovaMassimi(int matrice[TIPO_MATRICE][TIPO_MATRICE], int matriceConMassimi[TIPO_MATRICE][TIPO_MATRICE])
{
    int i, j, k, check, x, y;
    
    for(i = 0; i < TIPO_MATRICE; i++)
        for(j = 0; j < TIPO_MATRICE; j++)
        {
            check = 1;
            for(k = 0; k < 9 && check; k++)
            {
                x = i + (k % 3) - 1;
                y = j + (k / 3) - 1;
                if(x >= 0 && y >= 0 && x < TIPO_MATRICE && y < TIPO_MATRICE && !(x == i && y == j) && matrice[x][y] >= matrice[i][j])
                    check = 0;
            }
            if(check) matriceConMassimi[i][j] = matrice[i][j];
        }
}