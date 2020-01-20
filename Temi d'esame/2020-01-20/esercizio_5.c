#include <stdio.h>
#include <stdlib.h>

#define MAX_LUNGHEZZA_NOME 100

int main(int argc, char *argv[])
{
    char nome1[MAX_LUNGHEZZA_NOME + 1], nome2[MAX_LUNGHEZZA_NOME + 1];
    FILE *file1, *file2;
    int numero;

    /*printf("Inserisci i nomi dei file:\n");
    scanf("%s", nome1);
    scanf("%s", nome2);*/

    if (argc <= 2)
    {
        printf("E' necessario inserire i nomi dei due file\n");
        return 1;
    }

    file1 = fopen(argv[1], "a");
    file2 = fopen(argv[2], "r");

    if (file1 == NULL)
    {
        printf("File %s non trovato\n", nome1);
        return 1;
    }

    if (file2 == NULL)
    {
        printf("File %s non trovato\n", nome2);
        return 1;
    }

    while (EOF != fscanf(file2, "%d\n", &numero))
    {
        fprintf(file1, "%d\n", numero);
        printf("copiato il numero %d\n", numero);
    }

    fclose(file1);
    fclose(file2);

    return 0;
}