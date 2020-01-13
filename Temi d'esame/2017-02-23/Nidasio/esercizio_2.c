#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CARATTERI_RIGA 100
#define CHAR_TERMINATORE_RIGA '\n'
#define CHAR_SPAZIO ' '

int main(int argc, char *argv[])
{
    FILE *file;
    char *nomeFile;

    int numeroLinee = 0;
    int numeroTotaleCaratteri = 0;
    int maxCharPerRiga = 0;
    char lineaPiuLunga[MAX_CARATTERI_RIGA];

    char carattere;
    int caratteriLinea;
    int caratteriSpecialiLinea;
    int caratteriLineaDaContare;
    char linea[MAX_CARATTERI_RIGA];

    // Il nome del file viene fornito da riga di comando, quindi si trova nell'elemento in posizione 1 di argv
    // Controllo comunque se è presente
    if (argc >= 2)
    {
        nomeFile = argv[1];
    }
    else
    {
        printf("E' necessario fornire il file da leggere!\n");
        return 1;
    }

    file = fopen(nomeFile, "r");

    // Ore che abbiamo aperto il file abbiamo bisogno di calcolare:
    // 1. Il numero di linee presenti nel file;
    // 2. Il numero totale di caratteri;
    // 3. Il numero massimo e il numero medio di caratteri per linea;
    // 4. Il testo completo della linea più lunga presente nel file.

    // Inizio a leggere il file carattere per carattere
    caratteriLinea = 0;
    caratteriSpecialiLinea = 0;
    while (fscanf(file, "%c", &carattere) != EOF)
    {

        // Salvo il carattere e aumento il contatore dei caratteri
        linea[caratteriLinea] = carattere;
        caratteriLinea++;

        // Controllo se siamo arrivati a fine riga
        if (carattere == CHAR_TERMINATORE_RIGA)
        {
            // Aggiorno i contatori e continuo
            numeroLinee++;
            caratteriLineaDaContare = caratteriLinea - caratteriSpecialiLinea - 1;
            numeroTotaleCaratteri += caratteriLineaDaContare; // Tolgo gli spazi e l'acapo

            if (caratteriLineaDaContare > maxCharPerRiga)
            {
                // Aggiorno il numero di caratteri della linea più lunga
                maxCharPerRiga = caratteriLineaDaContare;

                // e salvo la linea in memoria
                memcpy(lineaPiuLunga, linea, MAX_CARATTERI_RIGA);
                lineaPiuLunga[caratteriLinea - 1] = '\0'; // Aggiungo il carattere terminatore per stampare correttamente la stringa
            }

            caratteriLinea = 0;
            caratteriSpecialiLinea = 0;
        }
        else
        {
            // Controllo se si tratta di uno spazio e continuo con la linea
            if (carattere == CHAR_SPAZIO)
                caratteriSpecialiLinea++;
        }
    }

    // Stampo i risultati
    printf("1. Il numero di linee presenti nel file e': %d\n", numeroLinee);
    printf("2. Il numero totale di caratteri e': %d\n", numeroTotaleCaratteri);
    printf("3. Il numero massimo e il numero medio di caratteri per linea sono: %d %.2f\n", maxCharPerRiga, (float) numeroTotaleCaratteri/numeroLinee);
    printf("4. Il testo completo della linea più lunga presente nel file e':\n%s\n", lineaPiuLunga);
}