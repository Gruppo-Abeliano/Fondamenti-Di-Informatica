#include <stdlib.h>
#include <stdio.h>

/**
 * Autore originale: Leonardo Pesce
 * Autore: Alberto Nidasio
 * Scopo: Inserire e visualizzare due stringhe salvate come liste dinamiche
*/

typedef struct Carattere {
    char carattere;
    struct Carattere *next;
} *Stringa;

void inserimento_testo(Stringa);
void stampa_testo(Stringa);

int main() {
    Stringa a, b;
    a = malloc(sizeof(Stringa));
    b = malloc(sizeof(Stringa));

    // Chiedo all'utente di inserire le stringhe

    printf("Inserire la prima stringa:\n");
    inserimento_testo(a);

    printf("Inserire la seconda stringa:\n");
    inserimento_testo(b);

    // Mostro a schemro le stringhe inserite in precedenza

    printf("La prima stringa è:\n");
    stampa_testo(a);

    printf("La seconda stringa è:\n");
    stampa_testo(b);

    return 0;
}

void inserimento_testo(Stringa stringa) {
    char x;
    printf("Inserire la stringa (invio per terminare la frase):\n");

    fflush(stdin);
    do {
        scanf("%c", &x);
        if(x != '\n') {
            stringa->carattere = x;
            stringa->next = malloc(sizeof(Stringa));
            stringa = stringa->next;
        }
    } while (x != '\n');
    stringa->next = NULL;
}

void stampa_testo(Stringa stringa) {
    while(stringa->next != NULL) {
        printf("%c", stringa->carattere);
        stringa = stringa->next;
    }
    printf("\n");
}