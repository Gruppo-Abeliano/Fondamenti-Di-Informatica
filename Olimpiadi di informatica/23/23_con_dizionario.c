#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define MAX_LUNGHEZZA_DIZIONARIO_BASE3_POT 13 // Potrebbe essere eccessivo, per calcolare il dizionario si effettuano 3^POT chiamate alla funzione, quindi N*3^POT operazioni
#define MAX_LUNGHEZZA_DIZIONARIO_BASE3 1594323 // 3^MAX_LUNGHEZZA_DIZIONARIO_POT
#define MAX_LUNGHEZZA_DIZIONARIO_BASE2_POT 20 // Potrebbe essere eccessivo, per calcolare il dizionario si effettuano 3^POT chiamate alla funzione, quindi N*3^POT operazioni
#define MAX_LUNGHEZZA_DIZIONARIO_BASE2 1048576 // 3^MAX_LUNGHEZZA_DIZIONARIO_POT
#define MAXT 10000

int T;
long N[MAXT];

typedef struct
{
    long elemento;
    int numeri_speciali;
} ElementoArrayCopia; // L'utilizzo della struct è solo estetico, lo spazio di memoria occupato da un elemento è di 16 byte, lo stesso di quanto occuperebbe un array di 2 long

void costruisci_dizionario_base3(int *dizionario, long index, int offset, int n);
void costruisci_dizionario_base2(int *dizionario, long index, int offset, int n);
#ifdef DEBUG
void stampa_dizionario(int base, int *dizionario, long dimensione_dizionario);
#endif // DEBUG
int funzione_ordinatrice(const void *pa, const void *pb);

int main()
{
    // Leggo i dati da file
#ifdef DEBUG
    freopen("ois_23/input1.txt", "r", stdin);
#endif // DEBUG

    // Leggo quanti numeri dovrò controllare
    assert(1 == scanf("%d", &T));

    // Leggo i valori da controllare
    for (int i = 0; i < T; i++)
        assert(1 == scanf("%ld", &N[i]));

        // Stampo i dati ricevuti in ingresso
#ifdef DEBUG
    printf("Dati di ingresso (%d numeri):\n", T);
    for (int i = 0; i < T; i++)
        printf(" %ld", N[i]);
    printf("\n\n");
#endif // DEBUG

    // Creo un nuovo array in cui copio e ordin i valori letti, eliminando i doppioni
    ElementoArrayCopia N_copia[T]; // [0] = numero, [1] = numero di numeri speciari rispetto a [0]
    int T_copia = 0;
    int doppione;
    for (int i = 0; i < T; i++)
    {
        doppione = 0;

        // Controllo se il valore N[i] è già presente in N_copia
        for (int k = 0; k < i && doppione == 0; k++)
            if (N_copia[k].elemento == N[i])
                doppione = 1;

        // Se il numero è nuovo (quindi non è un doppione) lo inserisco in N_copia
        if (!doppione)
        {
            N_copia[T_copia].elemento = N[i];
            N_copia[T_copia].numeri_speciali = 0;
            T_copia++;
        }
    }

    // Stampo il nuovo array N_copia
#ifdef DEBUG
    printf("Dati di N_copia (%d numeri):\n", T_copia);
    for (int i = 0; i < T_copia; i++)
        printf(" (%ld, %d)", N_copia[i].elemento, N_copia[i].numeri_speciali);
    printf("\n\n");
#endif // DEBUG

    // Ordino l'array copia
    qsort(N_copia, T_copia, sizeof(ElementoArrayCopia), funzione_ordinatrice);

    // Stampo il nuovo array N_copia
#ifdef DEBUG
    printf("Dati di N_copia ordinato:\n");
    for (int i = 0; i < T_copia; i++)
        printf(" (%ld, %d)", N_copia[i].elemento, N_copia[i].numeri_speciali);
    printf("\n\n");
#endif // DEBUG

    // Trovo il valore massimo (con il quale decido la base dei dizionari)
    long max_n = 0;
    for (int i = 0; i < T_copia; i++)
        if (N_copia[i].elemento > max_n)
            max_n = N_copia[i].elemento;

            // Calcolo i dizionari
#ifdef DEBUG
    printf("Calcolo i dizionari (in base al numero massimo %ld):\n\n", max_n);
#endif // DEBUG

    // Dizionatio in base 3

    int dimensione_dizionario_base3_pot; // Dimensione del dizionario in potenza di 3;
    long dimensione_dizionario_base3;    // Dimensione del dizionario e base della conversione da eseguire al posto di 3

    // Calcolo la dimensione del dizionario da generare
    dimensione_dizionario_base3_pot = log(max_n) / log(3); // log3(n) = loge(n) / loge(3)

    // Controllo se non supera il limite
    if (dimensione_dizionario_base3_pot > MAX_LUNGHEZZA_DIZIONARIO_BASE3_POT)
        dimensione_dizionario_base3_pot = MAX_LUNGHEZZA_DIZIONARIO_BASE3_POT;
    dimensione_dizionario_base3 = (long)pow(3, dimensione_dizionario_base3_pot);
#ifdef DEBUG
    printf(" Dimensione del dizionario per la base 3: 3^%d = %ld\n", dimensione_dizionario_base3_pot, dimensione_dizionario_base3);
#endif // DEBUG

    int dizionario_base3[dimensione_dizionario_base3];

    // Creo il dionario in maniera ricorsiva
    costruisci_dizionario_base3(dizionario_base3, 0, 0, dimensione_dizionario_base3_pot - 1);

    // Stampo il dizionario creato
#ifdef DEBUG
    stampa_dizionario(3, dizionario_base3, dimensione_dizionario_base3);
#endif // DEBUG

    // Dizionario base 2

    int dimensione_dizionario_base2_pot; // Dimensione del dizionario in potenza di 2;
    long dimensione_dizionario_base2;    // Dimensione del dizionario e base della conversione da eseguire al posto di 2

    // Calcolo la dimensione del dizionario da generare
    dimensione_dizionario_base2_pot = log(max_n) / log(2); // log2(n) = loge(n) / loge(2)

    // Controllo se non supera il limite
    if (dimensione_dizionario_base2_pot > MAX_LUNGHEZZA_DIZIONARIO_BASE2_POT)
        dimensione_dizionario_base2_pot = MAX_LUNGHEZZA_DIZIONARIO_BASE2_POT;
    dimensione_dizionario_base2 = (long)pow(2, dimensione_dizionario_base2_pot);
#ifdef DEBUG
    printf(" Dimensione del dizionario per la base 2: 2^%d = %ld\n", dimensione_dizionario_base2_pot, dimensione_dizionario_base2);
#endif // DEBUG

    int dizionario_base2[dimensione_dizionario_base2];

    // Creo il dionario in maniera ricorsiva
    costruisci_dizionario_base2(dizionario_base2, 0, 0, dimensione_dizionario_base2_pot - 1);

    // Stampo il dizionario creato
#ifdef DEBUG
    stampa_dizionario(2, dizionario_base2, dimensione_dizionario_base2);
#endif // DEBUG

    // Calcolo in numeri speciali per ogni elemento di N_copia
    long numero, resto;
    int sommaCifre_base3, sommaCifre_base2;
    long index;

    for (int i = 0; i < T_copia; i++)
    {
        // Dalla seconda posizione in poi posso riutlizzare il risultato precedente (ovvero il numero di numeri speciali)
        if (i > 0)
        {
            N_copia[i].numeri_speciali = N_copia[i - 1].numeri_speciali;
            index = N_copia[i - 1].elemento; // Parto a calcolare da copia
        }
        else
            index = 0;

        for (; index < N_copia[i].elemento; index++)
        {
            // Calcolo le somme delle cifre in base 3 e 2

            // Calcolo la somma delle cifre in base 3 calcolando il numero in base dimensione_dizionario_base3 (che è una potenza di 3)
            numero = index + 1;
            sommaCifre_base3 = 0;
            while (numero > 0)
            {
                //printf("Divido il numero %ld per %ld e ottengo il resto: ", numero, dimensione_dizionario_base3);
                resto = numero % dimensione_dizionario_base3;
                sommaCifre_base3 += dizionario_base3[resto]; // Prendo il valore della somma selle cifre in base tre per questo resto
                numero /= dimensione_dizionario_base3;       // Ottengo il risultato della divisione per passare al prossimo ciclo
                //printf("resto: %d, somma cifre: %d, prossimo numero: %ld\n", resto, sommaCifre_base3, numero);
            }
            //printf("La somma delle cifre di %ld codificato in base 3 è: %d\n\n", index + 1, sommaCifre_base3);

            // Calcolo la somma delle cifre in base 2 calcolando il numero in base dimensione_dizionario_base2 (che è una potenza di 2)
            numero = index + 1;
            sommaCifre_base2 = 0;
            while (numero > 0)
            {
                //printf("Divido il numero %ld per %ld e ottengo: ", numero, dimensione_dizionario_base2);
                resto = numero % dimensione_dizionario_base2;
                sommaCifre_base2 += dizionario_base2[resto]; // Prendo il valore della somma selle cifre in base tre per questo resto
                numero /= dimensione_dizionario_base2;       // Ottengo il risultato della divisione per passare al prossimo ciclo
                //printf("resto: %d, somma cifre: %d, prossimo numero: %ld\n", resto, sommaCifre_base2, numero);
            }
            //printf("La somma delle cifre di %ld codificato in base 2 è: %d\n\n\n", index + 1, sommaCifre_base2);

            if (sommaCifre_base3 == sommaCifre_base2)
                N_copia[i].numeri_speciali++;
        }
    }

    // Mostro i risultati del calcolo
#ifdef DEBUG
    printf("Dati di N_copia con risultati:\n");
    for (int i = 0; i < T_copia; i++)
        printf(" %d:\t(%ld, %d)\n", i, N_copia[i].elemento, N_copia[i].numeri_speciali);
    printf("\n");
#endif // DEBUG

    // Stampo i valori nell'ordine originale
    //printf("Risultato: ");
    for (int i = 0; i < T; i++)
        // Cerco il valore di N[i]
        for (int j = 0; j < T; j++)
        {
            if (N[i] == N_copia[j].elemento)
            {
                printf("%d ", N_copia[j].numeri_speciali);
                j = T;
            }
        }

    printf("\n");

    return 0;
}

void costruisci_dizionario_base3(int *dizionario, long index, int offset, int n)
{
    // Controllo se siamo arrivati alla fine
    if (n == 0)
    {
        // Se siamo alla fine salva in posizione index il numero offset
        dizionario[index] = offset;
        dizionario[index + 1] = offset + 1;
        dizionario[index + 2] = offset + 2;
    }
    else
    {
        // Altrimenti chiamo i successivi 3 rami dell'esecuzione

        // Ramo 0 (Posso risparmiare una chiamata controllando se mi trovo a n = 0)
        costruisci_dizionario_base3(dizionario, index, offset, n - 1);

        // Ramo 1
        costruisci_dizionario_base3(dizionario, index + pow(3, n), offset + 1, n - 1);

        // Ramo 2
        costruisci_dizionario_base3(dizionario, index + 2 * pow(3, n), offset + 2, n - 1);
    }
}

void costruisci_dizionario_base2(int *dizionario, long index, int offset, int n)
{
    // Controllo se siamo arrivati alla fine
    if (n == 0)
    {
        // Se siamo alla fine salva in posizione index il numero offset
        dizionario[index] = offset;
        dizionario[index + 1] = offset + 1;
    }
    else
    {
        // Altrimenti chiamo i successivi 3 rami dell'esecuzione

        // Ramo 0
        costruisci_dizionario_base2(dizionario, index, offset, n - 1);

        // Ramo 1
        costruisci_dizionario_base2(dizionario, index + pow(2, n), offset + 1, n - 1);
    }
}

#ifdef DEBUG
void stampa_dizionario(int base, int *dizionario, long dimensione_dizionario)
{
    printf(" Dizionario per la base %d:\n", base);
    for (long i = 0; i < dimensione_dizionario; i++)
        printf(" %ld:\t%d\n", i, dizionario[i]);
    printf("\n");
}
#endif // DEBUG

int funzione_ordinatrice(const void *pa, const void *pb)
{
    const ElementoArrayCopia *a = (const ElementoArrayCopia *)pa;
    const ElementoArrayCopia *b = (const ElementoArrayCopia *)pb;
    return ((*a).elemento - (*b).elemento);
}