#include <stdio.h>
#include <stdlib.h>

typedef struct ElementoLista
{
    int valore;
    struct ElementoLista *successivo;
} * Lista;

Lista inizializzaElemento(int valore);
void aggiungiInOrdine(Lista *lista, int valore);
void mostraLista(Lista lista);

int main()
{
    Lista lista = NULL;

    // Chiedo all'utente quanti valori vuole inserire
    int n, i, valore;
    printf("Inserisci il numero di valori che vuoi salvare: ");
    scanf("%d", &n);

    if (n > 0)
        printf("Ora digita i valori in ordine!\n");
    for (i = 0; i < n; i++)
    {
        printf("Inserisci l'elemento numero %d: ", i + 1);
        scanf("%d", &valore);

        // Aggiungo un elemento alla lista
        aggiungiInOrdine(&lista, valore);
    }

    // Adesso chiedo all'utente di inserire un valore che verrà aggiunto in ordine
    printf("\nInserisci un ultimo valore, verrà aggiunto in ordine: ");
    scanf("%d", &valore);

    aggiungiInOrdine(&lista, valore);

    // Mostro la lista
    printf("\nEcco la lista con il nuovo valore inserito in ordine: \n");
    mostraLista(lista);

    return 0;
}

// Alloca un nuovo elemento assognandogli il valore dato
Lista inizializzaElemento(int valore)
{
    Lista nuovaLista = malloc(sizeof(struct ElementoLista));

    nuovaLista->valore = valore;
    nuovaLista->successivo = NULL;

    return nuovaLista;
}

// Aggiunge un valore nella lista in modo ordinato (assume che la lista sia ordinata)
void aggiungiInOrdine(Lista *lista, int valore)
{
    // Cerco l'elemento prima del quale inserire il nuovo valore
    Lista *tmp = lista;
    while (*tmp != NULL && (*tmp)->valore < valore) // Mi fermo al primo elemento con valore superiore a quello da inserire
        tmp = &((*tmp)->successivo);

    Lista nuovo = inizializzaElemento(valore);
    nuovo->successivo = *tmp;
    *tmp = nuovo;
}

// Stampa tutti gli elementi fino alla fine della lista
void mostraLista(Lista lista)
{
    int n = 0;
    for (; lista != NULL; lista = lista->successivo, n++)
        printf("Elemento %d: %d\n", n, lista->valore);
}