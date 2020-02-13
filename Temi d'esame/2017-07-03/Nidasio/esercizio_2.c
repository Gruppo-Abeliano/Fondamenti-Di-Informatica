#include <stdio.h>

#define N 5

typedef int Matrice[N][N];

int calcolaDifferenzaDiagonali(Matrice matrice, int start);

int main()
{
    Matrice matrice = {
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
    };
    int differenza;

    // Calcolo la differenza
    differenza = calcolaDifferenzaDiagonali(matrice, 0);

    printf("La differenza tra la somma delgi elementi sulle diagonali è: %d\n", differenza);

    return 0;
}

/**
 * Questa funzione ricorsiva calcola la differenza tra la somma degli elementi sulla diagonale principale e quelli sulla diagonale secondaria
 * Il funzionamento della funzione è il seguente:
 * Somma e sottrae gli elementi ai 4 angoli reiterando per la matrice quadrata ottenuta togliendo le prime e ultime righe e colonne
 * fino a quando non rimane una matrice 1x1 o 0x0
*/
int calcolaDifferenzaDiagonali(Matrice matrice, int start)
{
    // Se ci troviamo alla fine della ricorsione si conclude il calcolo
    if (N / 2 - start <= 0)
        return 0;

    // Altrimenti sommo e sottraggio gli elementi agli estremi e calcolo il successivo passo della ricorsione
    return matrice[start][start] +
           matrice[N - start - 1][N - start - 1] -
           matrice[N - start - 1][start] -
           matrice[start][N - start - 1] +
           calcolaDifferenzaDiagonali(matrice, start + 1);
}