#include <stdio.h>
#include <stdlib.h>

#define M 3 // Righe
#define N 4 // Colonne

// Dichiarazione delle funzioni

void richiediMatrice(float[M][N]);
void mostraMatrice(float[M][N]);
void trovaPivot(float[M][N], int[M][2]);
void metodoDiGauss(float[M][N]);
void ordinaMatricePerPivot(float[M][N], int[M][2]);
void mostraPivot(int[M][2]);

// Main

int main(int argc, char const *argv[]) {
    float matrice[M][N] = {
        {1, 2, 4, 5},
        {0, 0, 12, 7},
        {2, 4, 1, 21}
    };

    // Richiedo tutti i parametri della matrice
    //richiediMatrice(matrice);

    // Mostro la matrice
    mostraMatrice(matrice);

    // Eseguo il metodo di Gauss
    metodoDiGauss(matrice);

    // Mostro la matrice
    mostraMatrice(matrice);

    return 0;
}

// Sviluppo delle funzioni

// Richiede all'utente di inserire tutti gli elementi della matrice
void richiediMatrice(float matrice[M][N]) {
    int i, j;

    // Per ogni vettore riga
    for(i = 0; i < M; i++) {
        printf("Preparati ad inserire gli elementi del vettore riga n %d\n", i + 1);
        // Richiedo ciascun componente
        for(j = 0; j < N; j++) {
            printf("\tInserisci il parametro n %d: ", j + 1);
            scanf("%f", &matrice[i][j]);
        }
    }
}

// Mostra gli elementi della matrice nel terminale
void mostraMatrice(float matrice[M][N]) {
    int i, j;

    // Mostro ciascun vettore riga
    for(i = 0; i < M; i++) {
        // Mostro ciascun componente

        switch(i) {
            case 0:
                printf("┌");
                break;
            case M - 1:
                printf("└");
                break;
            default:
                printf("|");
                break;
        }

        for(j = 0; j < N; j++) {
            printf("%.2f", matrice[i][j]);

            if(j < N - 1) printf(",");
            printf("\t");
        }

        switch(i) {
            case 0:
                printf("┐");
                break;
            case M - 1:
                printf("┘");
                break;
            default:
                printf("|");
                break;
        }

        printf("\n");
    }
    printf("\n");
}

// Permette di trovare il pivot di una data riga
void trovaPivot(float matrice[M][N], int pivot[M][2]) {
    int i, j;

    // Recupero i pivot
    for(i = 0; i < M; i++) {
        pivot[i][0] = -1;
        pivot[i][1] = i;

        // Trovo la colonna del pivot controllando, nella riga specificata,
        // il valore di ciasuna colonna in ordine crescente
        for(j = 0; j < N; j++) {
            if(matrice[i][j]) {
                pivot[i][0] = j;
                j = N;
            }
        }
    }
}

// Esegue il metodo di Gauss
void metodoDiGauss(float matrice[M][N]) {
    int i, pivot[M][2];

    // Recupero i pivot
    trovaPivot(matrice, pivot);

    mostraPivot(pivot);

    // Ordino la matrice in base ai pivot
    ordinaMatricePerPivot(matrice, pivot);

    mostraPivot(pivot);

    // Trasformo la matrice in una matrice a scala

}

// Ordinamento dei pivot
void ordinaMatricePerPivot(float matrice[M][N], int pivot[M][2]) {
    int i, j, k, max[2] = {0};
    int pivot0, pivot1;
    int elementoMatrice;

    // Ordino la matrice in base ai pivot
    for(int i = 0; i < M; i++) {
        for(int j = i + 1; j < M; j++){
            if(pivot[i][0] > pivot[j][0]) {
                // Pivot
                pivot0 = pivot[i][0];
                pivot1 = pivot[i][1];

                pivot[i][0] = pivot[j][0];
                pivot[i][1] = pivot[j][1];

                pivot[j][0] = pivot0;
                pivot[j][1] = pivot1;

                // Matrice
                for(k = 0; k < N; k++) {
                    elementoMatrice = matrice[i][k];
                    matrice[i][k] = matrice[j][k];
                    matrice[j][k] = elementoMatrice;
                }
            }
        }
    }
}

// Mostra i pivot
void mostraPivot(int pivot[M][2]) {
    int i;
    for(i = 0; i < M; i++) printf("Pivot riga %d: (%d, %d)\n", i + 1, pivot[i][0] + 1, pivot[i][1] + 1);
    printf("\n");
}

// Trasforma la matrice in una matrice a scala
//void portaAScala(float matrice[M][N], int start)