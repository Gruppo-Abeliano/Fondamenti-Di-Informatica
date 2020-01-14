#include <stdio.h>
#include <stdlib.h>

typedef struct ElementoLista
{
    int numero;
    struct ElementoLista *next;
} * Lista;

void leggiLista(Lista *testa);
void stampaLista(Lista lista);
void bubbleSort(Lista testa);

int main()
{
    Lista lista = NULL;

    leggiLista(&lista);

    printf("La lista inserita è:\n");
    stampaLista(lista);

    // Ordino la lista
    bubbleSort(lista);

    printf("La lista ordinata è:\n");
    stampaLista(lista);
 
    return 0;
}

void leggiLista(Lista *testa)
{
    Lista lista;
    int n;

    //Pulisco il buffer
    fflush(stdin);

    // Se la testa della lista è null la inizializzo e inserisco un numero, altrimenti non c'è nè bisogno
    if (*testa == NULL && scanf("%d", &n))
    {
        *testa = malloc(sizeof(struct ElementoLista));
        (*testa)->numero = n;
    }

    // Raggiungo l'ultimo elemento della lista
    lista = *testa;
    while (lista->next != NULL)
        lista = lista->next;

    // Aggiungo elementi alla lista leggendoli da tastiera finchè l'utente non inserisce una cosa diversa da un numero
    fflush(stdin);
    while (scanf("%d", &n))
    {
        lista->next = malloc(sizeof(struct ElementoLista));
        lista = lista->next;
        lista->numero = n;
    }
}

void stampaLista(Lista lista)
{
    while (lista != NULL)
    {
        printf("%d\n", lista->numero);
        lista = lista->next;
    }
}

void bubbleSort(Lista testa)
{
    // Controllo se la testa della lista è nulla e se il prossimo elemento è nullo,
    // se lo è significa che siamo in fondo alla lista e non è possibile ordinare alcunchè
    if(testa == NULL || testa->next == NULL) return;

    // Parto dal presupposto che l'elemento minore sia quello in testa
    int min = testa->numero;
    Lista corridore = testa;
    Lista punMin = testa;

    while(corridore->next != NULL)
    {
        if(min > corridore->next->numero) {
            punMin = corridore->next;
            min = punMin->numero;
        }
        corridore = corridore->next;
    }

    // Adesso posso scambiare i due valore e procedere con l'ordinamento
    punMin->numero = testa->numero;
    testa->numero = min;

    // Ora richiamo la funzione passandogli l'indirizzo del puntatore all'elemento dopo la testa
    bubbleSort(testa->next);
}