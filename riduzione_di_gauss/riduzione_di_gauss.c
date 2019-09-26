#include <stdio.h>
#include <stdlib.h>

#define M 3 // Righe
#define N 4 // Colonne
//#define DEBUG // Commentare per eliminare gli output di debug

/**
 * Autore: Alberto Nidasio
 * Scopo: Eseguire la riduzione di Gauss
 * Descrizione: Questo programma esegue il metodo della riduzione di Gauss
 * che si sviluppa in questi 3 passaggi:
 *   1: Si ordinano le righe per la posizione dei propri pivot
 *   2: Si modificano le righe successive alla prima in modo tale che i loro
 *      pivot non siano nella stessa posizione di quello della prima riga
 *      (tramite la moltiplicazione)
 *   3: Si ripete il procedimento dal punto 1 considerando la matrice senza la
 *      prima riga
*/

void richiediMatrice(float[M][N]);
void mostraMatrice(float[M][N], int, int, int);
void metodoDiGauss(float[M][N], int, int);
void trovaPivot(float[M][N], int[M][2], int, int);
void ordinaMatricePerPivot(float[M][N], int[M][2]);

int main(int argc, char const *argv[]) {
    #ifndef DEBUG
        float matrice[M][N];
    #endif

    #ifdef DEBUG
        float matrice[M][N] = {
            {1, 2, -1, -3},
            {2, 0, -1, -1},
            {1, -1, 1, -2}
        };
    #endif

    #ifndef DEBUG
        // Richiedo tutti i parametri della matrice all'utente
        richiediMatrice(matrice);
    #endif

    // Mostro la matrice di partenza
    printf("Matrice di partenza\n");
    mostraMatrice(matrice, 0, -1, -1);

    // Eseguo il metodo di Gauss
    metodoDiGauss(matrice, 0, 0);

    // Mostro la matrice
    printf("Matrice portata a scala\n");
    mostraMatrice(matrice, 0, -1, -1);

    return 0;
}

// Richiede all'utente di inserire tutti gli elementi della matrice
void richiediMatrice(float matrice[M][N]) {
    int i, j;

    printf("Preparati ad inserire gli elementi del vettore (%d, %d)\n", M, N);

    // Per ogni vettore riga
    for(i = 0; i < M; i++) {
        printf("Riga n %d\n", i + 1);

        // Richiedo ciascun parametro
        for(j = 0; j < N; j++) {
            printf("\tInserisci il parametro n %d: ", j + 1);
            scanf("%f", &matrice[i][j]);
        }
    }
}

// Mostra gli elementi della matrice nel terminale
void mostraMatrice(float matrice[M][N], int tab, int startM, int startN) {
    int i, j, t;

    // Mostro ciascun vettore riga
    for(i = 0; i < M; i++) {
        for(t = 0; t < tab; t++) printf("\t");

        // Simboli per l'apertura della matrice
        switch(i) {
            case 0:
                printf("\033[0;32m┌\033[0m");
                break;
            case M - 1:
                printf("\033[0;32m└\033[0m");
                break;
            default:
                printf("\033[0;32m|\033[0m");
                break;
        }

        // Mostro ciascun parametro
        for(j = 0; j < N; j++) {
            // Evidenzio il carattere se succede alle coordinate indicate
            if(i >= startM && j >= startN) printf("\033[0;33m");

            printf("%.2f", matrice[i][j]);

            // Reimposto il colore se modificato
            if(i >= startM && j >= startN) printf("\033[0m");

            if(j < N - 1) printf(",");
            printf("\t");
        }

        // Simboli per la chiusura della matrice
        switch(i) {
            case 0:
                printf("\033[0;32m┐\033[0m");
                break;
            case M - 1:
                printf("\033[0;32m┘\033[0m");
                break;
            default:
                printf("\033[0;32m|\033[0m");
                break;
        }

        printf("\n");
    }
    printf("\n");
}

// Esegue il metodo di Gauss trasformando la matrice in una matrice a scala
// (si aspetta una matrice con pivot ordinati)
void metodoDiGauss(float matrice[M][N], int startM, int startN) {
    // Controllo i valori di startM e startN per vedere se il procedimento è finito
    if(startM < M && startN < N)  {
        int i, j, pivot[M][2];
        float coeff;

        #ifdef DEBUG
            printf("Porto a scala  partendo dalla posizione (%d, %d)\n", startM, startN);
        #endif

        // 1: Si ordinano le righe per la posizione dei propri pivot

        // 1.1: Recupero i pivot
        trovaPivot(matrice, pivot, startM, startN);

        // 1.2: Ordino la matrice in base ai pivot
        ordinaMatricePerPivot(matrice, pivot);

        #ifdef DEBUG
            printf("\tMatrice di partenza\n");
            mostraMatrice(matrice, 1, startM, startN);
        #endif
    
        // Controllo se il primo valore (startM, startN) è nullo
        if(!matrice[startM][startN]) {
            // In questo caso posso spostarmi di una colonna
            startN++;

            // N.B. Se il primo valore è nullo vuol dire che non c'è alcun'altra riga con
            // pivot in questa posizione
            //metodoDiGauss(matrice, startM, startN + 1);
        }

        // 2: Si modificano le righe successive alla prima in modo tale che i loro
        //    pivot non siano nella stessa posizione di quello della prima riga

        // Motodo: Se il pivot della prima riga è in colonna j si somma alla riga i per ogni i>1
        // la prima riga  moltiplicata per  –aij/a1j, in tal modo tutte le righe, eccetto la prima,
        // hanno tutti 0 nella colonna j (e tutte le righe hanno 0 nelle colonne h con h<j)
        
        for(i = startM + 1; i < M; i++) {
            coeff = - matrice[i][startN] / matrice[startM][startN];
            for(j = startN; j < N; j++) {
                matrice[i][j] += matrice[startM][j] * coeff;
            }

            #ifdef DEBUG
                printf("\tCoefficiente per riga %d: %f\n\n", i, coeff);
            #endif
        }
        
        #ifdef DEBUG
            printf("\tRisultato\n");
            mostraMatrice(matrice, 1, startM, startN);
        #endif

        // 3: Proseguo con la ricorsione spostandomi di una colonna e di una riga
        metodoDiGauss(matrice, startM + 1, startN + 1);
    }
}

// Permette di trovare il pivot di una data riga
void trovaPivot(float matrice[M][N], int pivot[M][2], int startM, int startN) {
    int i, j;

    // Inizializzo la matrice di pivot a 0
    for(i = 0; i < M; i++) {
       pivot[i][0] = 0;
       pivot[i][1] = 0;
    }

    // Recupero i pivot
    for(i = startM; i < M; i++) {
        pivot[i][0] = -1;
        pivot[i][1] = i;

        // Trovo la colonna del pivot controllando, nella riga specificata,
        // il valore di ciasuna colonna in ordine crescente
        for(j = startN; j < N; j++) {
            if(matrice[i][j]) {
                pivot[i][0] = j;
                j = N;
            }
        }
    }
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