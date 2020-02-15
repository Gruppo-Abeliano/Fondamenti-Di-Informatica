#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *file;
    int parte2, parte1; // Parte 2 della tessere i-esima e parte 1 della tessera successiva

    //1: Controllo se l'utente ha inserito un path valido

    if(argc < 2) {
        printf("E' necessario specificare il path di un file\n");
        return 1;
    }

    file = fopen(argv[1], "r");

    if(file == NULL) {
        printf("Errore nell'apertura del file\n");
        return 1;
    }

    //2: Leggo il file e controllo se la sequenza di tessere descritta è una catena

    // Leggo il primo numero così da avanzare il puntatore del file
    fscanf(file, "(%d", &parte1);

    while(fscanf(file, ",%d)(%d", &parte2, &parte1) > 0) {
        if(parte1 != parte2) {
            printf("La sequenza di tessere non è una catena\n");
            return 1;
        }
    }

    printf("La sequenza di tessere è una catena\n");
    return 0;
}