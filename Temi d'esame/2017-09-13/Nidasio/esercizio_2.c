#include <stdio.h>
#include <string.h>

/**
 * Il programma assume che tutti i caratteri di tutte le stringhe inserite siano MINUSCOLI
*/

#define TRUE 1
#define FALSE 0

#define LUNGHEZZA_MAX_STRINGA 20
#define NUMERO_MAX_STRIGHE_VOCABOLARIO 10

// L'ultimo elemento del vocaoblario sarà composto da una stringa con il solo carattere terminatore
typedef char Vocabolario[NUMERO_MAX_STRIGHE_VOCABOLARIO + 1][LUNGHEZZA_MAX_STRINGA];

int confrontaParteIniziale(char *A, char *B);
int controllaVocabolario(char *C, Vocabolario vocabolario);

int main()
{
    Vocabolario vocabolario = {
        "achille",
        "alberto",
        "alessandra",
        "leonardo",
        "matteo",
        "paolo",
    };
    char C[LUNGHEZZA_MAX_STRINGA];

    printf("Inserisci la stringa da cercare nel vocabolario: ");
    scanf("%s", C);

    if(controllaVocabolario(C, vocabolario)) printf("Stringa trovata\n");
    else printf("Stringa mancante\n");

    return 0;
}

/**
 * Questa funzione riceve in ingresso due stringhe (A e B).
 * Restituisce 1 se la stringa A è parte iniziale della stringa B, altrimenti 0
 * La funzione è ricorsiva e procede avanzando di unb posto i puntatori degli array delle stringhe.
*/
int confrontaParteIniziale(char *A, char *B)
{
    //1: Se entrambe le stringhe sono finite restituisco TRUE
    if (*A == '\0' && *B == '\0')
        return TRUE;

    //2: Se la stringa B finisce prima della sringa A allora non va bene
    if (*B == '\0' && *A != '\0')
        return FALSE;

    //3: Se la stirnga A è finita mentre la B no allora è tutto OK
    if (*A == '\0' && *B != '\0')
        return TRUE;

    //4: Altrimenti controllo se i primi elementi delle stringhe sono uguali
    if (*A == *B)
        return confrontaParteIniziale(A + 1, B + 1);
    else
        return FALSE;
}

/**
 * Controlla se un elemento del vocabolario inizia con la srtringa C
*/
int controllaVocabolario(char *C, Vocabolario vocabolario)
{
    //1: Se sono arrivato alla fine del vocabolrario allora è finita
    if(**vocabolario == '\0') return FALSE;

    //2: Controllo se il primo elemento del vocabolario ha C come parte iniziale
    if(confrontaParteIniziale(C, *vocabolario)) return TRUE;

    //3: Controllo se non abbiamo superato la stringa C nel vocabolario, altrimenti contunuo
    if(strcmp(C, *vocabolario) < 0) return FALSE;

    return contrillaVocabolario(C, vocabolario + 1);
}