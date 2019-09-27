#include <stdio.h>
#include "../riduzione_di_gauss/riduzione_di_gauss.h"

int main(int argc, char const *argv[])
{
    int m; // Righe
    int n; // Colonne

    // Richiedo la dimensione della matrice
    printf("Insersci il numero di righe della matrice: ");
    scanf("%d", &m);
    printf("Insersci il numero di colonne della matrice: ");
    scanf("%d", &n);

    float matrice[m][n];

    // Richiedo tutti i parametri della matrice all'utente
    richiediMatrice(m, n, matrice);

    // Mostro la matrice di partenza
    printf("Matrice di partenza\n");
    mostraMatrice(m, n, matrice, 0, -1, -1);

    // Eseguo il metodo di Gauss
    metodoDiGauss(m, n, matrice, 0, 0);

    // Mostro la matrice
    printf("Matrice portata a scala\n");
    mostraMatrice(m, n, matrice, 0, -1, -1);

    return 0;
}
