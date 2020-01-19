#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LEGTH 1000

int main(int argc, char *argv[])
{
    FILE *file;
    char linea[MAX_LINE_LEGTH];
    int i;
    int nDirettive, nCommenti, nIstruzioni, nCaratteriUtili;

    if (argc <= 1)
    {
        printf("E' necessario specificare il nome del file\n");
        return 1;
    }

    file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("Errore nell'apertura del file\n");
        return 1;
    }

    nDirettive = 0;
    nCommenti = 0;
    nIstruzioni = 0;
    nCaratteriUtili = 0;

    while (!feof(file))
    {
        // Leggo la linea
        for (i = 0; i < MAX_LINE_LEGTH; i++)
        {
            fscanf(file, "%c", &linea[i]);
            if (linea[i] == '\n')
                i = MAX_LINE_LEGTH;
        }

        // Cerco il primo carattere utile
        for (i = 0; linea[i] == ' '; i++)
            ;

        // Controllo il primo carattere
        if (linea[i] == '#')
            nDirettive++;
        else if (linea[i] == '/')
            nCommenti++;
        if (linea[i] != '\n')
            nIstruzioni++;

        nCaratteriUtili++;

        for (; linea[i] != '\n'; i++)
            nCaratteriUtili++;
    }

    fclose(file);

    // Stampo i risultati
    printf("a) Numero righe direttive:  %d\n", nDirettive);
    printf("a) Numero righe commenti:   %d\n", nCommenti);
    printf("a) Numero righe istruzioni: %d\n", nIstruzioni);
    printf("a) Numero caratteri utuli:  %d\n", nCaratteriUtili);

    return 0;
}