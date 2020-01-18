#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LUNGHEZZA_MATRICOLA 6

typedef char Matricola[LUNGHEZZA_MATRICOLA + 1];

void controllaMatricolaEFile();

int main()
{
    controllaMatricolaEFile();
    return 0;
}

void controllaMatricolaEFile()
{
    Matricola matricola;
    FILE *file;
    bool trovato;
    char toCheck;
    int i;

    // Chiedo all'utente di inserire la matricola
    printf("Inserisci la matricola: ");
    scanf("%6s", matricola);
    printf("Matricola inserita: %s\n", matricola);

    // Apro il file
    file = fopen("input_esercizio_5.txt", "r");

    trovato = true;
    if (file == NULL)
        trovato = false;

    // Controllo carattere per carattere
    for(i = 0; i < LUNGHEZZA_MATRICOLA && matricola[i] != '\0'; i++)
    {
        trovato = false;
        while (!trovato && fread(&toCheck, sizeof(char), 1, file))
        {
            if (toCheck == matricola[i])
                trovato = true;
        }
        rewind(file);
    }

    if (trovato)
        printf("OK\n");
    else
        printf("KO\n");
}