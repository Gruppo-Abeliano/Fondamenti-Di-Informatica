#include <stdio.h>

int comparaStringhe(char *str1, char *str2, int i);

int main()
{
    char *str1 = "Ciaooooooooo\0";
    char *str2 = "Ciaooo\0";

    // Confronto le stringhe
    int risultato = comparaStringhe(str1, str2, 0);

    printf("Risultato: %d\n", risultato);

    return 0;
}

// Ritorna 1 se i caratteri all'indice i sono uguali, 0 se non lo sono
int comparaStringhe(char *str1, char *str2, int i) {
    printf("%c %c\n", str1[i], str2[i]);
    // Se siamo alla fine della prima stringa ma non alla fine della seconda restituisco 1 (true)
    if(str1[i] == '\0' && str2[i] != '\0') {
        printf("-- 1\n");
        return 1;
    }
    // Altrimenti se i caratteri non sono uguali oppure siamo alla fine delle stringhe (o della seconda)
    if(str1[i] != str2[i] || str1[i] == '\0' || str2[i] == '\0') {
        printf("-- 2\n");
        return 0;
    }
    // Altrimenti i valori sono uguali, ritorno il risultato del confronto successivo
    else {
        printf("-- 3\n");
        return comparaStringhe(str1, str2, i + 1);
    }
}