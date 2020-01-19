#include <stdio.h>

#define CIFRE_MANTISSA 23

void generaMantissa(float mantissa, int mantissaBinaria[CIFRE_MANTISSA]);

int main()
{
    float mantissa;
    int mantissaBinaria[CIFRE_MANTISSA];
    int i;

    printf("Inserisci la mantissa (compresa tra 0 e 1) da trasformare in binario: ");
    scanf("%f", &mantissa);

    printf("\nLa mantissa inserita è: %f\n\n", mantissa);

    generaMantissa(mantissa, mantissaBinaria);

    printf("La mantissa generata è:\n");
    for(i = 0; i < CIFRE_MANTISSA; i++) printf("%d", mantissaBinaria[i]);
    printf("\n");

    return 0;
}

void generaMantissa(float mantissa, int mantissaBinaria[CIFRE_MANTISSA])
{
    int i;

    // Se la mantissa non è nelle specifiche la funzione non può essere eseguita
    if(mantissa <= 0 || mantissa >= 1) return;

    for(i = 0; i < CIFRE_MANTISSA; i++) {
        mantissa *= 2;
        if(mantissa >= 1) mantissaBinaria[i] = 1;
        else mantissaBinaria[i] = 0;
        if(mantissa >= 1) mantissa -= 1;
    }
}