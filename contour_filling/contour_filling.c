#include <stdio.h>

/**
 * Autori: Paolo Pertino e Alberto Nidasio
 * 
 * Scopo: riempire un contorno
 */

#define L 12 // Larghezza della matrice
#define A 10 // Altezza della matrice
#define BORDO_INTERNO 1
#define BORDO_ESTERNO -1

// Definisco il tipo di matrice che utilizzderò
typedef int matrice[A][L];
typedef enum
{
    false, // Valore 0
    true
} bool;

// Questa funzione permette di visualizzare il piano nella linea di comando
void mostraPiano(matrice piano);

// Permette di riempire i contorni presenti in una martrice, (vedi il pdf per definizione di controrno)
void contourFilling(matrice piano);

int main()
{
    matrice piano = {
        {0, 0, 0, 0, -1, -1, -1, -1, 0, 0, 0, 0},
        {0, 0, -1, -1, 1, 1, 1, 1, -1, 0, 0, 0},
        {0, -1, 1, 1, 0, 0, 0, 0, 1, -1, 0, 0},
        {-1, 1, 0, 0, 0, 1, 1, 0, 0, 1, -1, 0},
        {-1, 1, 0, 0, 1, -1, -1, 1, 0, 1, -1, 0},
        {0, -1, 1, 0, 0, 1, 1, 0, 0, 1, -1, 0},
        {-1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1},
        {-1, 1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0},
        {0, -1, -1, 1, -1, -1, -1, -1, 1, 1, -1, 0},
        {0, 0, 0, -1, 0, 0, 0, 0, -1, -1, 0, 0}};

    printf("Input:\n");
    mostraPiano(piano);

    contourFilling(piano);

    printf("\nOutput :\n");
    mostraPiano(piano);

    return (0);
}

void mostraPiano(int piano[A][L])
{
    int i, j;

    for (i = 0; i < A; i++)
    {
        for (j = 0; j < L; j++)
        {
            // Numero
            switch (piano[i][j])
            {
            case 1:
                printf("\033[0;32m");
                break;
            case 2:
                printf("\033[0;31m");
                break;
            case -1:
                printf("\033[0;33m");
                break;
            default:
                printf("\033[0;36m");
                break;
            }
            printf("%3d", piano[i][j]);

            // Reimposto il colore
            printf("\033[0m");
        }
        printf("\n");
    }
}

void contourFilling(matrice piano)
{
    int i, j;     // Contatori
    bool interno; // Indica se, durante il ciclo, mi trovo nell'area da segnare

    // Coloro la regione
    for (i = 0; i < A; i++) // Per ogni riga
    {
        // Continuo finchè non ho controllato tutte le colonne
        interno = false;

        for (j = 0; j < L; j++)
        {
            // Se non abbiamo già trovato un bordo esterno seguito da uno interno, quindi se siamo all'interno dell'area
            if (!interno)
            {
                // Controllo se ci troviamo difronte a un perimetro di apertura (-1, 1)
                if (piano[i][j] == BORDO_ESTERNO && j < L - 1 && piano[i][j + 1] == BORDO_INTERNO)
                {
                    interno = true;
                    j++;
                }
            }
            else
            {
                // Se abbiamo già trovato un perimetro in precedenza coloro le celle finchè non trovo un bordo esterno
                if (piano[i][j + 1] != BORDO_ESTERNO) // Non controllo l'indice che uso viste le ipotesi
                    piano[i][j] = 1;                  // Qui si potrebbe inserire un numero differente per visualizzare dove sono state modificate le cella (vedere la commit af812f9ad90e4bf274d3bda312b9f65902f6e398 era stato fatto)
                else
                    interno = false;
            }
        }
    }

    // Sistemo i dati cambiando i BORDO_ESTERNO con 0
    for (i = 0; i < A; i++)
        for (j = 0; j < L; j++)
            if (piano[i][j] == BORDO_ESTERNO)
                piano[i][j] = 0;
}