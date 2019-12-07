/*
  Autore : Paolo Pertino
  Esercizio 3 - Tema Esame 23-02-2017
  Descrizione : dato un numero intero, la funzione ricorsiva massimaDecimale restituisce la cifra più alta della
                rappresentazione decimale.

  Tempo impiegato : 4 minuti __ scrittura funzione massimaDecimale
*/

#include <stdio.h>

int massimaDecimale(int numero);

int main()
{
  int numero;

  printf("Inserisci un numero : ");
  scanf("%d",&numero);

  printf("La massima cifra decimale del numero inserito e' %d",massimaDecimale(numero));
}

int massimaDecimale(int numero)
{
  int massimoReturn,prossimoMassimo;

  if(numero == 0) return 0;

  massimoReturn = numero % 10;
  prossimoMassimo = massimaDecimale(numero/10);

  if(prossimoMassimo > massimoReturn) massimoReturn = prossimoMassimo;

  return massimoReturn;
}
