/*
  Autore : Paolo Pertino
  Esercizio 1 - Tema Esame 28-01-2019
  Descrizione : dato un numero compreso tra 1 e 2, la funzione generaMantissa memorizza le 23 cifre dopo la virgola della
                sua rappresentazione binaria in un array di 23 elementi.

  Tempo impiegato : 4 minuti __ scrittura funzione generaMantissa
*/

#include <stdio.h>

#define DIMENSIONE 23

typedef int array[DIMENSIONE];

void generaMantissa(array mantissa,float numero);
void leggiMantissa(array mantissa);


int main(int argc, char const *argv[]) {
  float numero;
  array mantissa;

  do
  {
    printf("Inserisci un numero compreso tra 0 e 1 (estremi esclusi) : ");
    scanf("%f",&numero);

    if(numero<= 0 || numero >=1) printf("\nNumero non valido.\n");
  } while(numero<= 0 || numero >=1);

  generaMantissa(mantissa,numero);
  leggiMantissa(mantissa);

  return 0;
}

void generaMantissa(array mantissa,float numero)
{
  int contatore;
  float prodotto;

  contatore = 0;
  prodotto = numero;

  while(contatore<DIMENSIONE)
  {
    prodotto = prodotto * 2;
    if(prodotto>=1)
    {
      mantissa[contatore] = 1;
      prodotto -= 1;
    } else {
      mantissa[contatore] = 0;
    }

    ++contatore;
  }
}

void leggiMantissa(array mantissa)
{
  int contatore;

  for(contatore=0;contatore<DIMENSIONE;contatore++)
  {
    printf("%d",mantissa[contatore]);
  }
}
