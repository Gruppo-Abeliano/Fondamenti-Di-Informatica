#include <stdio.h>

#define L 12 // Larghezza della matrice
#define A 10 // Altezza della matrice

void mostraPiano(int piano[A][L]);

int main()
{
    int piano[A][L] = {
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
    int i, j; // Contatori
    int t;    // Indica se ho trovato un elemento

    printf("Input:\n");
    mostraPiano(piano);

    // Coloro la regione
    for (i = 0; i < A; i++) // Per ogni riga
    {
        // Continuo finchè non ho controllato tutte le colonne
        j = 0;
        t = 0;

        for (j = 0; j < L; j++)
        {
            // Se non abbiamo già trovato un perimetro di apertura (-1, 1)
            if (!t)
            {
                //Controllo se ci troviamo difronte a un perimetro di apertura
                if (j < L - 1 && piano[i][j] == -1 && piano[i][j + 1] >= 1)
                {
                    t = 1;
                    j++;
                }
            }
            else
            {
                // Se abbiamo già trovato un perimetro in precedenza coloro le celle finchè non ne trovo uno di chiusura (1. -1)
                if (piano[i][j + 1] != -1) // Non controllo il l'indice che uso viste le ipotesi
                {
                    if (piano[i][j] != 1)
                        piano[i][j] = 2; // Coloro solo se non c'è già 1
                }
                else
                {
                    t = 0;
                }
            }
        }
    }

    printf("\nOutput 1:\n");
    mostraPiano(piano);

    // Sistemo i dati cambiando i -1 con 0 e i 2 con 1
    for (i = 0; i < A; i++)
        for (j = 0; j < L; j++)
        {
            if (piano[i][j] == -1)
                piano[i][j] = 0;
            if (piano[i][j] == 2)
                piano[i][j] = 1;
        }

    printf("\nOutput 2:\n");
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