/*
  Autore: Paolo Pertino
  Esercizio 1 - Tema Esame 04-09-2018

  Descrizione: Scrivere un sottoprogramma che, ricevendo in ingresso un float con valore compreso tra 0 e 1
               (esclusi gli estremi), generi le prime 23 cifre della sua rappresentazione binaria. Dato il
               numero frazionario 1/3 (un terzo), calcolarne la rappresentazione floating point a singola
               precisione secondo il formato IEEE 754.
*/

#include <stdio.h>

void mantissa(float numero);

int main(int argc, char const *argv[]) {
  float numero;

  /*
    Chiedo all'utente di inserire il numero compreso tra 0 e 1 come richiesto dal testo.
  */
  printf("Inserisci un numero compreso tra 0 e 1 : ");
  scanf("%f",&numero);

  /*
    Calcolo le 23 cifre della sua rappresentazione binaria dopo la virgola e le mostro a schermo.
  */
  mantissa(numero);
  return 0;
}

void mantissa(float numero)
{
  int contatore;

  /*
    Devo mostrare in output 23 numeri, quindi devo effettuare 23 volte l'operazione.
  */
  contatore = 0;
  while(contatore < 23)
  {
    numero *= 2;
    if(numero >= 1)
    {
      printf("1");
      numero -= 1;
    } else {
      printf("0");
    }
    ++contatore;
  }
}

/*
  1/3 in IEEE754
  Segno = 0 (numero positivo)
  Esponente polarizzato = -2+127 = (125)bin = 01111101
  Mantissa = 01010101010101010101010

  RISULTATO : 0 | 01111101 | 01010101010101010101010
*/
