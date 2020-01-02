#include <stdio.h>
#include <string.h>

// Esempio di conica: 1x^2 + 1xy + 1y^2 + 1x + 1y + 1

typedef enum
{
    IPERBOLE_EQUILATERA,
    IPERBOLE_NON_EQUILATERA,
    PARABOLA,
    ELLISSE_REALE,
    ELLISSE_IMMAGINARIA,
    RETTE_REALI_INCIDENTI,
    RETTE_REALI_PARALLELE_O_COMPLESSE_CONIUGATE,
    RETTE_IMMAGINARIE_CONIUGATE_INCIDENTI
} tipi_coniche;

typedef struct
{
    // Matrice dei termini quadratici e misti
    float A[2][2];

    // Vettore dei termini singoli
    float b[2];

    // Coefficiente
    float c;

    // Matrice associata al polinomio
    float B[3][3];

    // Traccia di A, determinante di A e determinante di B
    float I1, I2, I3;

    // Classificazione della conica
    tipi_coniche tipo;
} polinomio;

void leggiConica(polinomio *conica);
void mostraConica(polinomio conica);
void mostraMatrice(float *matrice, int m, int n);
float calcolaTraccia(float *matrice, int n);
float calcolaDeterminante(float *matrice, int n);
void ottieniMatriceMinore(float *originale, int n, float *nuova, int i, int j);
void classificaConica(polinomio *conica);

int main()
{
    polinomio conica;

    // Leggo la conica
    leggiConica(&conica);

    // Mostro la conica in forma matriciale
    mostraConica(conica);

    // Classifico la conica
    classificaConica(&conica);

    switch (conica.tipo)
    {
    case IPERBOLE_EQUILATERA:
        printf("Iperbole equilatera");
        break;
    case IPERBOLE_NON_EQUILATERA:
        printf("Iperbole non equilatera");
        break;
    case PARABOLA:
        printf("Parabola");
        break;
    case ELLISSE_REALE:
        printf("Ellisse reale");
        break;
    case ELLISSE_IMMAGINARIA:
        printf("Ellisse immaginaria");
        break;
    case RETTE_REALI_INCIDENTI:
        printf("Rette reali incidenti");
        break;
    case RETTE_REALI_PARALLELE_O_COMPLESSE_CONIUGATE:
        printf("Rette reali parallele o complesse immaginarie");
        break;
    case RETTE_IMMAGINARIE_CONIUGATE_INCIDENTI:
        printf("Rette immaginarie coniugate incidenti");
        break;
    }
    printf("\n");

    return 0;
}

// Legge la conica da linea di comando e salva i paramentri nell'oggetto in ingresso
void leggiConica(polinomio *conica)
{
    // Controllo se in ingresso è stato fornito un puntatore valido
    if (conica == NULL)
        return;

    char stringaConica[100];
    int check;

    // Chiedo all'utente di inserire la conica
    printf("Inserisci il polinomio che identifica la conica:\n");
    printf("(Es: a(1,1)x^2 + 2a(1,2)xy + a(2,2)*y^2 + 2b(1)x + 2b(2)y + c\n con spazi e numeri al postom di a(i,j), b(i) e c inserendo 0 se i termini sono nulli)\n");

    // Leggo la conica
    scanf("%[^\n]", stringaConica);

    printf("Equazione letta: %s\n", stringaConica);

    // Analizzo la stringa ed estraggo i dati, es: 1x^2 + 1xy + 1y^2 + 1x + 1y + 1
    check = sscanf(stringaConica, "%fx^2 + %fxy + %fy^2 + %fx + %fy + %f", &conica->A[0][0], &conica->A[1][0], &conica->A[1][1], &conica->b[0], &conica->b[1], &conica->c);

    printf("%.1f\n", conica->A[0][0]);

    // Controllo se tutti i termini sono stati letti
    printf("check: %d\n", check);
    if (check != 6)
    {
        printf("Alcuni termini non sono stati letti, riprova\n");
        return;
    }

    // Salvo i dati in modo corretto

    // Dimezzo alcuni valori
    conica->b[0] /= 2;
    conica->b[1] /= 2;
    conica->A[1][0] /= 2;

    // Rendo simmetrica A
    conica->A[0][1] = conica->A[1][0];

    // Copio in B i termini di A
    conica->B[0][0] = conica->A[0][0];
    conica->B[0][1] = conica->A[0][1];
    conica->B[1][0] = conica->A[1][0];
    conica->B[1][1] = conica->A[1][1];

    // Anche quelli di b
    conica->B[0][2] = conica->b[0];
    conica->B[1][2] = conica->b[1];
    conica->B[2][0] = conica->b[0];
    conica->B[2][1] = conica->b[1];

    // E c
    conica->B[2][2] = conica->c;
}

// Mostra la conica in forma matriciale
void mostraConica(polinomio conica)
{
    // Matrice A
    printf("Matrice A:\n");
    mostraMatrice((float *)conica.A, 2, 2);

    // Vettore b
    printf("Vettore b:\n");
    mostraMatrice((float *)conica.b, 2, 1);

    // Matrice B
    printf("Matrice B:\n");
    mostraMatrice((float *)conica.B, 3, 3);
}

// Mostra una matrice di tipo mxn
void mostraMatrice(float *matrice, int m, int n)
{
    int i, j;

    // Bordo alto
    printf("┌");
    for (i = 0; i < m; i++)
        printf("\t");
    printf("\t┐\n");

    // Elementi matrice
    for (j = 0; j < n; j++)
    {
        printf("│");
        for (i = 0; i < m; i++)
            printf("\t%2.1f ", matrice[j * n + i]);
        printf("\t│\n");
    }

    // Bordo basso
    printf("└");
    for (i = 0; i < m; i++)
        printf("\t");
    printf("\t┘\n");
}

// Calcola la traccia di una matrice quadrata di ordine n
float calcolaTraccia(float *matrice, int n)
{
    int i;
    float traccia = 0;

    for (i = 0; i < n; i++)
        traccia += matrice[i * n + i];

    return traccia;
}

// Calcola il determinante di una matrice quadrata di ordine n
float calcolaDeterminante(float *matrice, int n)
{
    if (n == 1)
    {
        return matrice[0];
    }
    else
    {
        int i;
        float determinante = 0;
        float matriceMinore[n - 1][n - 1];

        for (i = 0; i < n; i++)
        {
            ottieniMatriceMinore((float *)matrice, n, (float *)matriceMinore, i, 0);
            determinante += (i % 2 == 0 ? 1 : -1) * matrice[i * n] * calcolaDeterminante((float *)matriceMinore, n - 1);
        }

        return determinante;
    }
}

// Formatta la matrice minore per il calcolo del determinante
void ottieniMatriceMinore(float *originale, int n, float *nuova, int i, int j)
{
    int ii, jj;

    for (ii = 0; ii < n; ii++)
    {
        if (ii == i)
            ii++;

        for (jj = 0; jj < n; jj++)
        {
            if (jj == j)
                jj++;

            nuova[(ii > i ? ii - 1 : ii) * (n - 1) + (jj > j ? jj - 1 : jj)] = originale[ii * n + jj];
        }
    }
}

// Classifica una conica
void classificaConica(polinomio *conica)
{
    // Calcolo I1, I2 e I3
    (*conica).I1 = calcolaTraccia((float *)(*conica).A, 2);
    (*conica).I2 = calcolaDeterminante((float *)(*conica).A, 2);
    (*conica).I3 = calcolaDeterminante((float *)(*conica).B, 3);

    // Classifico
    if ((*conica).I3 == 0)
    {
        if ((*conica).I2 < 0)
            (*conica).tipo = RETTE_REALI_INCIDENTI;
        else if ((*conica).I2 == 0)
            (*conica).tipo = RETTE_REALI_PARALLELE_O_COMPLESSE_CONIUGATE;
        else
            (*conica).tipo = RETTE_IMMAGINARIE_CONIUGATE_INCIDENTI;
    }
    else
    {
        if ((*conica).I2 < 0)
        {
            if ((*conica).I1 == 0)
                (*conica).tipo = IPERBOLE_EQUILATERA;
            else
                (*conica).tipo = IPERBOLE_NON_EQUILATERA;
        }
        else if ((*conica).I2 == 0)
            (*conica).tipo = PARABOLA;
        else
        {
            if ((*conica).I1 * (*conica).I3 > 0)
                (*conica).tipo = ELLISSE_IMMAGINARIA;
            else
                (*conica).tipo = ELLISSE_REALE;
        }
    }
}