#include <stdio.h>

#define L 11 // Larghezza della matrice
#define A 10 // Altezza della matrice
#define VALORE_OSTACOLO 1000
#define VALORE_ACCESSO -1
#define VALORE_META 0

void mostraPiano(int piano[A][L], int percorso);

int main()
{
    int piano[A][L] = {
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, 1000, 1000, 1000, -1, -1, -1, -1, -1},
        {-1, -1, -1, 1000, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, 1000, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, 1000, 1000, 1000, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}};
    int i, j;                 // Contatori
    int valore = VALORE_META; // Indica il valore da cercare
    int trovatiLibreri;       // memorizza il numero di punti accessibili non ancora sovrascritti
    int xPartenza, yPartenza; // Coordinate da cui calcolare il percorso
    int l, t, r, b;           // Variabile in cui salvo i valori dei vicini

    printf("Input:\n");
    mostraPiano(piano, 0);

    do
    {
        trovatiLibreri = 0;

        // Controllo tutta la matrice alla ricerca del numero salvato precedentemente, partendo da 1
        for (i = 0; i < A; i++)
            for (j = 0; j < L; j++)
            {
                // Solo se la cella corrente non è un'ostacolo
                if (piano[i][j] == VALORE_ACCESSO)
                {
                    trovatiLibreri++;
                    // Controllo se un vicino è uguale al numero che cerco

                    if (j > 0 && piano[i][j - 1] == valore) // Left
                    {
                        piano[i][j] = valore + 1;
                    }
                    else if (i > 0 && piano[i - 1][j] == valore) // Top
                    {
                        piano[i][j] = valore + 1;
                    }
                    else if (j < L - 1 && piano[i][j + 1] == valore) // Right
                    {
                        piano[i][j] = valore + 1;
                    }
                    else if (i < A - 1 && piano[i + 1][j] == valore) // Bottom
                    {
                        piano[i][j] = valore + 1;
                    }
                }
            }
        valore++;

        // printf("\n%d %d\n", valore, trovatiLibreri);
        // mostraPiano(piano);
    } while (trovatiLibreri == -1 || trovatiLibreri > 0);

    printf("\nOutput 1:\n");
    mostraPiano(piano, 0);

    // Ora chiedo le coordinate da cui si vuole partire
    printf("Inserisci le coordinate da cui vuoi partire per raggiungere la meta:\nx: ");
    scanf("%d", &xPartenza);
    printf("y: ");
    scanf("%d", &yPartenza);

    // Calcolo il percorso
    i = xPartenza;
    j = yPartenza;
    while (piano[i][j] != 0) // Finchè non raggiungo la meta
    {
        // Recupero il valore dei vicini
        if (j > 0) // Left
        {
            l = piano[i][j - 1];
        }
        else
        {
            l = VALORE_OSTACOLO;
        }
        if (i > 0) // Top
        {
            t = piano[i - 1][j];
        }
        else
        {
            t = VALORE_OSTACOLO;
        }
        if (j < L - 1) // Right
        {
            r = piano[i][j + 1];
        }
        else
        {
            r = VALORE_OSTACOLO;
        }
        if (i < A - 1) // Bottom
        {
            b = piano[i + 1][j];
        }
        else
        {
            b = VALORE_OSTACOLO;
        }

        //printf("\nl: %d t: %d r: %d b: %d\n", l, t, r, b);

        // Controllo qual'è il minore dei vicini per capire dove spostarmi
        if (l <= t && l <= r && l <= b) // Left
        {
            piano[i][j] = VALORE_OSTACOLO + '<';
            j--;
            //printf("<\n");
        }
        else if (t <= l && t <= r && t <= b) // Top
        {
            piano[i][j] = VALORE_OSTACOLO + '^';
            i--;
            //printf("^\n");
        }
        else if (r <= l && r <= t && r <= b) // Right
        {
            piano[i][j] = VALORE_OSTACOLO + '>';
            j++;
            //printf(">\n");
        }
        else // Bottom
        {
            piano[i][j] = VALORE_OSTACOLO + 'v';
            i++;
            //printf("v\n");
        }
    }
    piano[xPartenza][yPartenza] = VALORE_OSTACOLO + 'P'; // La partenza avrà il carattere P

    // Sistemo i valori della tabella
    for (i = 0; i < A; i++)
        for (j = 0; j < L; j++)
        {
            if (piano[i][j] == VALORE_OSTACOLO) piano[i][j] = '*';
            else if (piano[i][j] > VALORE_OSTACOLO) piano[i][j] -= VALORE_OSTACOLO;
            else if (piano[i][j] == 0) piano[i][j] = 'M';
            else piano[i][j] = '-';
        }

    printf("\nOutput 2:\n");
    mostraPiano(piano, 1);

    return (0);
}

void mostraPiano(int piano[A][L], int percorso)
{
    int i, j;

    for (i = 0; i < A; i++)
    {
        for (j = 0; j < L; j++)
        {

            if (!percorso)
            {
                // Numero
                switch (piano[i][j])
                {
                case 1000:
                    printf("\033[0;32m");
                    break;
                case -1:
                    printf("\033[0;31m");
                    break;
                default:
                    printf("\033[0;36m");
                    break;
                }
                printf("%5d", piano[i][j]);
            }
            else
            {
                // Numero
                switch (piano[i][j])
                {
                case '-':
                    printf("\033[0;32m");
                    break;
                case 'M':
                    printf("\033[0;31m");
                    break;
                case 'P':
                    printf("\033[0;31m");
                    break;
                case '*':
                    printf("\033[0;35m");
                    break;
                default:
                    printf("\033[0;36m");
                    break;
                }
                printf("%c", (char) piano[i][j]);
            }

            // Reimposto il colore
            printf("\033[0m");
        }
        printf("\n");
    }
}