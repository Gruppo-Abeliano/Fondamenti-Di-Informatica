#include <stdio.h>

/**
 * Analisi del problema:
 * Per trovare l'elemento di peso minimo basta girare la lista con uno dei due puntatori.
 * La difficoltà sta nel modificare tutti i puntatori, non solo quelli che si usa per girare la lista.
 * Come funziona: giro la lista una volta con i puntatori ai pesi controllando il valore dell'elemento successivo e tengo in
 * memoria il puntatore all'elemento precedente di quello con il peso specifico minimo.
 * Una volta trovato l'elemento da eliminare recupero il puntatore all'elemento precedente tramite volume.
 * Elimino l'elemento e aggiorno i puntatori
*/

typedef struct ElementoListaDoppia
{
    struct ElementoListaDoppia *pNextPeso;
    struct ElementoListaDoppia *pNextVolume;
    float peso, volume;
} *ListaDoppia;

void leggiLista(ListaDoppia lista);
void eliminaElementoPesoSpecificoMinore(ListaDoppia *lista);

int main()
{
    return 0;
}

void leggiLista(ListaDoppia lista)
{
    float peso, volume;

    // Leggo la lista per ordine di peso e poi sistemo i puntatori per volume

    printf("Inserisci peso e volume degli elementi:\n");

    while(scanf("%f %f", &peso, &volume)) {
        lista->pNextPeso = malloc(sizeof(struct ElementoListaDoppia));
        lista = lista->pNextPeso;
        lista->peso = peso;
        lista->volume = volume;
    }
}

void eliminaElementoPesoSpecificoMinore(ListaDoppia *lista)
{
    // Ricordiamo che il primo elemento della lista contiene solo i puntatori ai primi elementi
}