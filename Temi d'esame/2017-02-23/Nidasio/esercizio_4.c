#include <stdio.h>

int trovaCifraMassima(int num);

int main()
{
    int num;

    printf("Inserisci un numero, troverò la sua cifra più grande: ");
    scanf("%d", &num);

    printf("La cifra più grande all'interno del numero %d è: %d\n", num, trovaCifraMassima(num));

    return 0;
}

int trovaCifraMassima(int num)
{
    int primaCifra = num % 10;

    if (primaCifra == 9 || num < 10)
        return primaCifra;

    int prossimaCifra = trovaCifraMassima(num / 10);

    return (primaCifra > prossimaCifra ? primaCifra : prossimaCifra);
}