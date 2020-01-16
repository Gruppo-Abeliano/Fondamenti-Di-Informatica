#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int controllaFile(char *nomeFile1, char *nomeFile2);

int main()
{
    char *nomeFile1 = "file1.txt\0";
    char *nomeFile2 = "file2.txt\0";

    int risultato = controllaFile(nomeFile1, nomeFile2);

    printf("Risultato del controllo: %d\n", risultato);
}

int controllaFile(char *nomeFile1, char *nomeFile2)
{
    // Apro i due file
    FILE *file1 = fopen(nomeFile1, "rb");
    FILE *file2 = fopen(nomeFile2, "rb");

    // Utilizzo due variabili char per memorizzare e controllare ciascun byte dei due file
    char byteFile1, byteFile2;

    // Uso due variabili intere per controllare la corretta lettura dei byte
    int check1, check2;

    // Uso una variabile booleana per controllare se i due file sono uguali e una per concludere il ciclo
    bool uguali = true; // Parto dal presupposto che siano uguali
    bool fineControllo = false;

    do
    {
        // Leggo un byte da ciascun file
        check1 = fread(&byteFile1, sizeof(byteFile1), 1, file1);
        check2 = fread(&byteFile2, sizeof(byteFile2), 1, file2);

        // Controllo se sono stati letti entrambi
        if (!check1 && !check2)
        {
            // In questo caso i file sono entrambi finiti, posso concludere che sono uguali (siccome niente è successo prima)
            fineControllo = true;
        }
        else if (check1 && check2)
        {
            // In questo caso ad entrambi i file sono stati letti un byte che posso confrontarte
            if (byteFile1 != byteFile2) uguali = false; // Se sono differenti segno i file come diversi, questo concluderà il ciclo
        } else {
            // Altrimenti uno dei due file è finito prima, questo implica che sono diversi
            uguali = false;
        }
    } while(uguali && !fineControllo);

    // Arrivati a questo punto la variabile uguali indica se i due file sono uguali, posso chiuderli e restituire il risultato
    fclose(file1);
    fclose(file2);

    return (uguali ? 0 : 1);
}