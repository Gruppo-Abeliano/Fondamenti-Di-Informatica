#include <stdio.h>
#include <math.h>

void stampaCifre(int numero);

int main()
{
    int numero = 123456789;

    stampaCifre(numero);

    return 0;
}

void stampaCifre(int numero)
{
    int i;

    // Prima di tutto calcolo il numero delle cifre
    int numeroCifre = 0;

    for (i = numero; i > 0; i /= 10)
        numeroCifre++;

    // Ora stampo le cifre
    for (i = 0; i < numeroCifre; i++)
        printf("%d\n", (numero / ((int) pow(10, (numeroCifre - i - 1)))) % 10);
}