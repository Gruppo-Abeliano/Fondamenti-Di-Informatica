#include <stdio.h>
#include <stdlib.h>

typedef struct ElementoLista {
    int valore;
    struct ElementoLista *precedente;
    struct ElementoLista *successivo; 
} ElementoLista;

typedef ElementoLista *Lista;

ElementoLista *inizializzaElemento();
ElementoLista *aggiungiElemento(Lista lista, int valore);
void mostraLista(Lista lista);

int main()
{
    Lista lista = inizializzaElemento();

    // Chiedo all'utente quanti valori vuole inserire
    int n, i, tmp;
    printf("Inserisci il numero di valori che vuoi salvare:");
    scanf("%d", &n);

    // Salvo temporaneamente l'indirizzo all'ultimo valore della lista (in questo modo non devo cercare l'ultimo elemento)
    // ElementoLista *ultimoElemento = lista;
    for(i = 0; i < n; i++) {
        printf("Inserisci l'elemento numero %d: ", i + 1);
        scanf("%d", &tmp);

        // Aggiungo un elemento alla lista
        if(i > 0) aggiungiElemento(lista, tmp);
        else lista->valore = tmp;
    }

    // Mostro la lista
    mostraLista(lista);

    return 0;
}

ElementoLista *inizializzaElemento() {
    ElementoLista *nuovaLista = malloc(sizeof(ElementoLista));

    nuovaLista->valore = -1;
    nuovaLista->precedente = NULL;
    nuovaLista->successivo = NULL;

    return nuovaLista; 
}

ElementoLista *aggiungiElemento(Lista lista, int valore) {
    // Recupero l'ultimo elemento della lista
    ElementoLista *tmp = lista;
    while(tmp->successivo != NULL) tmp = tmp->successivo;

    // Creo un nuovo elemento (se non è il primo)
    tmp->successivo = inizializzaElemento();

    // Salvo il valore nel nuovo elemento
    tmp->successivo->valore = valore;

    // Ritorno l'indirizzo dell'ultimo elemento
    return tmp->successivo;
}

void mostraLista(Lista lista) {
    // Stampo tutti gli elementi fino alla fine della lista
    ElementoLista *tmp = lista;
    int n = 0;

    while(tmp != NULL) {
        n++;
        printf("Elemento %d: %d\n", n, tmp->valore);
        tmp = tmp->successivo;
    }
}