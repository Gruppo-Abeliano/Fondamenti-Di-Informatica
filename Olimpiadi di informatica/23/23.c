#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// constraints
#define MAXT 10000

// input data
int T, i, j, k, l, T_copia;
long N[MAXT];

#define DEBUG

/**
 * Descrizione del problema:
 *   Un numero è speciale se le somme delle sue cifre in base 2 e base 3 sono uguali.
 *   Dati T numeri deternimare, per ciascuno, quanti, tra 1 e lui sono speciali
 * 
 * Spiegazione metodo risolutivo:
 *   Cambiamento di base:
 *     Per cambiare la base di un numero bisogna calcolare il modulo del numero per la base,
 *     questo ci da la prima cifra, le successive cifre si calcolano sempre con il modulo ma
 *     utilizzando il risultato troncato della divisione del numero per la base.
 * 
 *     Esempio:
 *       Trasformare 7 in base 3
 *       7 % 3 = 1 (proseguo con 7 / 3 = 2)
 *       2 % 3 = 2
 *       Somma cifre: 3
 * 
 *       Trasformo 7 in base 2
 *       7 % 2 = 1 (proseguo con 7 / 2 = 3)
 *       3 % 2 = 1 (proseguo con 3 / 2 = 1)
 *       1 % 2 = 1
 *       Somma cifre: 3
 * 
 *       N.B. Quando calcolo le cifre in una base di un numero (e quindi la loro somma) posso
 *       riutilizzare il risultato di un numero precedente. Ad esempio se, per calcolare 7in
 *       base 3, se precedentemente avevo già calcolato il valore di 3 potevo riutilizzarlo
 * 
 *       Altri esempi
 * 
 *       Trasformare 8 in base 3
 *       8 % 3 = 2 (proseguo con 8 / 3 = 2)
 *       2 % 3 = 2 (potevo riutilizzare il risultato di prima)
 *       Somma cifre: 3
 * 
 *   Calcolo somme delle cifre:
 *     Per calcolare la somma delle cifre di un numero (come osservato precedentemente)
 *     Utilizzerò il metodo mostrato fino a quando non incontro un numero già calcolato
 *     che utilizzerò per velocizzare il calcolo
 * 
 *   Per ottimizzare questi calcoli rimuoverò eventuali doppioni dei numeri richiesti e li
 *   ordinerò (po verranno rimessi nell'ordine principale per stampare l'output)
*/


int cmpfunc(const void *pa, const void *pb)
{
    const int (*a)[3] = (const int (*)[3]) pa;
    const int (*b)[3] = (const int (*)[3]) pb;
    return ((*a)[0] - (*b)[0]);
}


int main()
{
    // Leggo da file mentre sviluppo il codice (altrimenti il programma legge i valori da tastiera)
#ifdef DEBUG
    freopen("ois_23/input0.txt", "r", stdin);
#endif // DEBUG

    // Leggo quanti numeri dovrò controllare
    assert(1 == scanf("%d", &T));

    // Leggo i valori da controllare
    for (i = 0; i < T; i++)
        assert(1 == scanf("%d", &N[i]));

    // Stampo i dati in ingresso per debug
#ifdef DEBUG
    printf("Dati di ingresso:");
    for (int i = 0; i < T; i++)
        printf(" %d", N[i]);
    printf("\n");
#endif // DEBUG

    // RISOLUZIONE

    // 1: Copio i dati in ingresso in un nuovo arrau e rimuovo eventuali doppioni
    long N_copia[T][3]; // [0] = numero, [1] = numero di numeri speciari rispetto a [0], [2] = somma delle cifre del numero [0]
    j = 0;
    for (i = 0; i < T; i++)
    {
        // Uso l per controllare se c'è un doppione
        l = 0;

        // Controllo se il valore N[i] è già presente in N_copia
        for(k = 0; k < i && l == 0; k++)
            if(N_copia[k][0] == N[i])
                l = 1;

        // Se il numero è nuovo lo inserisco in N_copia
        if(!l)
        {
            N_copia[j][0] = N[i];
            N_copia[j][1] = 0;
            N_copia[j][2] = 0;
            j++;
        }
    }
    T_copia = j;

    // Mostro il nuovo array N_copia
#ifdef DEBUG
    printf("Dati di N_copia:");
    for (int i = 0; i < T_copia; i++)
        printf(" (%d, %d, %d)", N_copia[i][0], N_copia[i][1], N_copia[i][2]);
    printf("\n");
#endif // DEBUG

    // 2: Odino T_copia
    qsort(N_copia, T_copia, 3*sizeof(int), cmpfunc);

    // Mostro N_copia oridnato
#ifdef DEBUG
    printf("Dati di N_copia ordinato:");
    for (int i = 0; i < T_copia; i++)
        printf(" (%d, %d, %d)", N_copia[i][0], N_copia[i][1], N_copia[i][2]);
    printf("\n");
#endif // DEBUG

    // 3: Calcolo i numeri speciali per ogni elemento dell'array N_copia
    int sommaCifreBase2;
    int sommaCifreBase3;
    int cifra, numero;

    for(i = 0; i < T_copia; i++)
    {
        // Se sono dalla seconda posizione posso riutlizzare il risultato precedente
        // (il numero di numeri speciali)
        if(i > 0)
        {
            N_copia[i][1] = N_copia[i - 1][1];
            k = N_copia[i - 1][0]; // Parto a calcolare da copia
        }
        else
        {
            k = 0;
        }

        for (; k < N_copia[i][0]; k++)
        {
            sommaCifreBase2 = 0;
            sommaCifreBase3 = 0;

            // Calcolo la somma delle cifre in base 2
            numero = k + 1;
            while (numero > 0)
            {
                cifra = numero % 2;
                sommaCifreBase2 += cifra;
                numero /= 2;
            }

            // Calcolo la somma delle cifr in base 3
            numero = k + 1;
            while (numero > 0)
            {
                cifra = numero % 3;
                sommaCifreBase3 += cifra;
                numero /= 3;
            }

            if (sommaCifreBase2 == sommaCifreBase3)
                N_copia[i][1]++;
        }

        // Alla fine mi salvo il valore della somma delle cifre per calcoli successivi
        N_copia[i][2] = sommaCifreBase3;
    }

    // Mostro N_copia con i risultati
#ifdef DEBUG
    printf("Dati di N_copia con risultati:\n");
    for (int i = 0; i < T_copia; i++)
        printf(" %d:\t(%d, %d, %d)\n", i, N_copia[i][0], N_copia[i][1], N_copia[i][2]);
    printf("\n");
#endif // DEBUG

    // Stampo i valori nell'ordine originale
    //printf("Risultato: ");
    for (i = 0; i < T; i++)
        // Cerco il valore di N[i]
        for (j = 0; j < T; j++)
        {
            if(N[i] == N_copia[j][0]) {
                printf("%d ", N_copia[j][1]);
                j = T;
            }
        }

    printf("\n");
    return 0;
}