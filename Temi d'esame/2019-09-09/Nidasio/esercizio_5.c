#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MIN_V 1
#define MAX_V 13
#define MIN_S 1
#define MAX_S 4
#define N 52 // = MAX_V * MAX_S

bool mazzoCompleto(char *nomeFile);

int main()
{
    char *nomeFile = "mazzo.txt\0";

    bool check = mazzoCompleto(nomeFile);

    printf("Risultato del controllo: %d\n", check);

    return 0;
}

bool mazzoCompleto(char *nomeFile)
{
    // Inizializzo un array di N elementi tutti a 0, lo userò per controllare se ho tutte le carte
    bool check[N];
    int i;
    int s, v;
    FILE *file;

    file = fopen(nomeFile, "r");

    if (file == NULL)
        return false;

    for (i = 0; i < N; i++)
        check[i] = false;

    // Leggo il file
    while (fscanf(file, "(%d,%d)", &s, &v) == 2)
    {
        // Controllo i valori
        if (v < MIN_V || v > MAX_V || s < MIN_S || s > MAX_S)
        {
            fclose(file);
            return false;
        }
        check[(s - MIN_V) * MAX_V + (v - MIN_V)] = true;
    }
    fclose(file);

    // Controllo se ho tutte le carte
    for(i = 0; i < N; i++) if(!check[i]) return false;
    return true;
}