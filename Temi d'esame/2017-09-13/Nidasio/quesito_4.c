#include <stdio.h>
#include <stdlib.h>

/** Le direttuve include necessarie al programma sono stdio.h in quanto sono necessarie
 * le funzioni che operano su file e stdlib per utulizzare malloc
*/

struct ValoreElementoLista
{
    int numero;
    char carattere;
};

typedef struct ElementoLista
{
    struct ElementoLista *next;
    struct ValoreElementoLista valore;
} * Lista;

void leggiLista(Lista *lista);
void mostraLista(Lista lista);
void list2File(Lista lista);
Lista file2List();

int main()
{
    Lista listaInserita = NULL;
    Lista listaLetta = NULL;

    // Leggo la lista da riga di comando
    printf("Inserisci i valori della lista:\n");
    leggiLista(&listaInserita);

    // Mostro la lista inserita
    printf("Lista inserita:\n");
    mostraLista(listaInserita);

    // Scrivo la lista su file
    list2File(listaInserita);

    // Leggo la lista fa file
    listaLetta = file2List();

    // Mostro la lista letta
    printf("Lista letta da file:\n");
    mostraLista(listaLetta);

    return 0;
}

void leggiLista(Lista *lista)
{
    int numero;
    char carattere;

    // Leggo valori fino a quando l'utente li inserisce
    while (scanf("%d %c", &numero, &carattere) == 2)
    {
        *lista = malloc(sizeof(struct ElementoLista));
        (*lista)->valore.numero = numero;
        (*lista)->valore.carattere = carattere;
        lista = &(*lista)->next;
    }
}

void mostraLista(Lista lista)
{
    while (lista != NULL)
    {
        printf("%d %c\n", lista->valore.numero, lista->valore.carattere);
        lista = lista->next;
    }
}

void list2File(Lista lista)
{
    FILE *file;

    //1: Controllo se la lista è vuota, in questo caso non  creo il file
    if (lista == NULL)
        return;

    //2: Creo o apre il file, controllando l'esito dell'operazione
    file = fopen("contents.dat", "wb");
    if (file == NULL)
        return; // Si potrebbe ritornare un vaklore intero per indicare se l'esecuzione della funzione ha avuto successo

    //3: Inserisco nel file i valori
    while (lista != NULL)
    {
        fwrite(&lista->valore, sizeof(struct ValoreElementoLista), 1, file);
        lista = lista->next;
    }

    //4: Chiudo il file
    fclose(file);
}

Lista file2List()
{
    FILE *file;
    Lista testa = NULL;
    Lista *lista;
    struct ValoreElementoLista valore;

    // Inizializzo il contenuto della cella a cui punta lista il valore null
    lista = &testa; // E salvo l'indirizzo per poter poi restituire la testa della lista

    //1: Apro il file e controllo se esiste
    file = fopen("contents.dat", "rb");
    if (file == NULL)
        return NULL;

    //2: Leggo i dati creando la lista, finchè è possibile leggere degli elementi
    while (fread(&valore, sizeof(struct ValoreElementoLista), 1, file) > 0)
    {
        *lista = malloc(sizeof(struct ElementoLista));
        (*lista)->valore = valore;
        lista = &(*lista)->next;
    }

    //3: Chiudo il file
    fclose(file);

    //4: Ritorno la testa della lista
    return testa;
}