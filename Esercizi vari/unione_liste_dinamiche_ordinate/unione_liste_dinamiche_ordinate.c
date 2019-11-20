#include <stdio.h>
#include <stdlib.h>

/**
 * Autore: Alberto Nidasio
 * Scopo: Combina due liste dinamiche ordinate
*/

typedef struct ElementoLista
{
    int valore;
    struct ElementoLista *successivo;
} * Lista;

Lista inizializzaElemento(int valore);
Lista creaLista();
void aggiungiInOrdine(Lista *lista, int valore);
void mostraLista(Lista lista);
void combinaListe(Lista *lista1, Lista lista2);

int main()
{
    Lista lista1, lista2;

    // Chiedo all'utente di inserire due liste
    lista1 = creaLista();
    lista2 = creaLista();

    // Mostro le liste appena create
    printf("Lista 1:\n");
    mostraLista(lista1);
    printf("Lista 2:\n");
    mostraLista(lista2);

    // Combino le liste
    combinaListe(&lista1, lista2);

    printf("Le liste sono state combinate, ecco il risultato:\n");
    mostraLista(lista1);

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

// Permette all'utente di creare una lista
Lista creaLista()
{
    Lista lista = NULL;
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

    return lista;
}

// Stampa tutti gli elementi fino alla fine della lista
void mostraLista(Lista lista)
{
    int n = 0;
    for (; lista != NULL; lista = lista->successivo, n++)
        printf("Elemento %d: %d\n", n, lista->valore);
}

// Combina due liste mantenendo gli elementi in ordine crescente
void combinaListe(Lista *lista1, Lista lista2)
{
    Lista *tmp1 = lista1;
    Lista tmp2, tmp3, tmp4 = lista2;

    while (tmp4 != NULL) // Se la lista2 è nulla non c'è niente da fare
    {
        tmp2 = tmp4;
        tmp3 = tmp4;
        
        // Cerco l'elemento della lista 1 prima del quale inserire uno o più elementi della lista2
        while (*tmp1 != NULL && (*tmp1)->valore < tmp2->valore) // Mi fermo al primo elemento con valore superiore a quello da inserire
            tmp1 = &((*tmp1)->successivo);

        // Adsesso trovo l'elemento di lista2 dopo il quale riprendere con lista1
        while (tmp3->successivo != NULL && *tmp1 != NULL && tmp3->successivo->valore <= (*tmp1)->valore)
            tmp3 = tmp3->successivo;

        tmp4 = tmp3->successivo;

        // Inserisco l'elemento
        tmp3->successivo = *tmp1;
        *tmp1 = tmp2;
    }
}
