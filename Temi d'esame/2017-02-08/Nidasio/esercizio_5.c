#include <stdio.h>
#include <stdlib.h>

typedef struct El
{
    enum
    {
        oper,
        val
    } tipo;
    char operatore;
    float valore;
    struct El *next;
} * Espressione;

void leggiEspressione(Espressione *testa);
int leggiOperazione(struct El *operazione);
void stampaEspresisone(Espressione espressione);
float calcola(Espressione espressione);

int main()
{
    Espressione espressione = NULL;

    leggiEspressione(&espressione);

    printf("Operazione inserita:\n");
    stampaEspresisone(espressione);

    float valoreEspressione = calcola(espressione);

    printf("Il valore dell'espressione è: %.3f\n", valoreEspressione);

    return 0;
}

void leggiEspressione(Espressione *testa)
{
    Espressione lista;
    struct El operazione;

    // Se la testa della lista è null la inizializzo e inserisco un numero, altrimenti non c'è nè bisogno
    fflush(stdin);
    if (*testa == NULL && leggiOperazione(&operazione))
    {
        *testa = malloc(sizeof(struct El));
        (*testa)->tipo = operazione.tipo;
        (*testa)->operatore = operazione.operatore;
        (*testa)->valore = operazione.valore;
    }

    // Raggiungo l'ultimo elemento della lista
    lista = *testa;
    while (lista->next != NULL)
        lista = lista->next;

    // Aggiungo elementi alla lista leggendoli da tastiera finchè l'utente non inserisce una cosa diversa da un numero
    fflush(stdin);
    while (leggiOperazione(&operazione))
    {
        lista->next = malloc(sizeof(struct El));
        lista = lista->next;
        lista->tipo = operazione.tipo;
        lista->operatore = operazione.operatore;
        lista->valore = operazione.valore;
    }
}

int leggiOperazione(struct El *operazione)
{
    char tipo;
    char operatore;
    float valore;
    char buff;

    printf("Inserisci O per oprazione oppure V per valore\n(qualsiasi altri valore per annullare): ");
    scanf("%c", &tipo);

    // Pulisco il buffer
    while ((buff = getchar()) != '\n' && buff != EOF)
        ;

    if (tipo == 'O')
    {
        printf("Inserisci l'operatore da aggiungere: ");
        scanf("%c", &operatore);

        // Pulisco il buffer
        while ((buff = getchar()) != '\n' && buff != EOF)
            ;

        if (operatore != '+' && operatore != '-' && operatore != '*' && operatore != '/')
            return 0;

        operazione->tipo = oper;
        operazione->operatore = operatore;

        return 1;
    }
    else if (tipo == 'V')
    {
        printf("Inserisci il valore da aggiungere: ");
        scanf("%f", &valore);

        // Pulisco il buffer
        while ((buff = getchar()) != '\n' && buff != EOF)
            ;

        operazione->tipo = val;
        operazione->valore = valore;

        return 1;
    }

    return 0;
}

void stampaEspresisone(Espressione espressione)
{
    while (espressione != NULL)
    {
        if (espressione->tipo == oper)
            printf("%c  ", espressione->operatore);
        else
            printf("%.3f ", espressione->valore);
        espressione = espressione->next;
    }
    printf("\n");
}

// Avviso: questa funzione modifica il puntatore che gli si fornisce!
float calcola(Espressione punt)
{
    Espressione primoOperando, secondoOperando;
    Espressione cursore;
    int counter = 1;

    if (punt->tipo == val)
        return (punt->valore);

    primoOperando = punt->next;

    cursore = punt->next;
    while (counter > 0)
    {
        cursore = cursore->next;
        if (cursore->tipo == oper)
            counter += 2;
        counter--;
    }

    secondoOperando = cursore->next;

    printf("Operatore: %c\n", punt->operatore);
    printf("Espressione: "); stampaEspresisone(punt);
    double test1 = calcola(primoOperando);
    double test2 = calcola(secondoOperando);
    printf("Valori: %f %f\n", test1, test2);

    if (punt->operatore == '+')
        return (calcola(primoOperando) + calcola(secondoOperando));
    if (punt->operatore == '-')
        return (calcola(primoOperando) - calcola(secondoOperando));
    if (punt->operatore == '*')
        return (calcola(primoOperando) * calcola(secondoOperando));
    return (calcola(primoOperando) / calcola(secondoOperando));
}