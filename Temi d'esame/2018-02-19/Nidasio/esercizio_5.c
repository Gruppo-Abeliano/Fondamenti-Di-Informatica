#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *file;
    char carattere;

    if(argc <= 1) {
        printf("E' necessario specificare il nome di un file\n");
        return 1;
    }

    file = fopen(argv[1], "r");

    if(file == NULL) {
        printf("Errore nell'apertura del file\n");
        return 1;
    }

    while(fread(&carattere, sizeof(char), 1, file)) {
        printf("%c", carattere);
    }

    fclose(file);
    return 0;
}