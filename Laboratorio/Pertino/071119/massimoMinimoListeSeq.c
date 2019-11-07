#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int numero;
  int massimo,minimo;
  int contaNumeri;

  massimo = 0;
  minimo = 0;
  contaNumeri = 0;
  
  do {
    printf("\nInserisci un numero della sequenza (0 per terminare) : ");
    scanf("%d", &numero);

    ++contaNumeri;

    if(numero > massimo) massimo = numero;
    else if(numero < minimo) minimo = numero;
  } while(numero != 0);

  if((numero == 0) && (contaNumeri == 1))
  {
    printf("\nNessun numero inserito");
  } else {
    printf("\nValore massimo: %d\nValore minimo: %d\nNumeri Inseriti: %d",massimo,minimo,contaNumeri-1);
  }
  return 0;
}
