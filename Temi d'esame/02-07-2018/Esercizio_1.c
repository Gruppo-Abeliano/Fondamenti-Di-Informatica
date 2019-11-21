/*
  Autore : Paolo Pertino
  Esercizio 1 - Tema Esame 02-07-2018
  Descrizione : dato un array di DIM elementi, la funzione MassimaLunghezza restituisce l'indice dell'inizio della sequenza più lunga
                di numeri disposti in ordine crescente nell'array.
*/

#include <stdio.h>
#include <stdlib.h>

#define DIM 10

typedef int arrayInteri[DIM];
typedef int Contatore;

int MassimaLunghezza(arrayInteri vettore);

int main(int argc, char const *argv[]) {
  arrayInteri array = {3,2,8,4,5,7,8,9,11,21};

  printf("La sequenza di numeri disposti in ordine crescente piu' lunga inizia all'indice %d", MassimaLunghezza(array));
  return 0;
}

int MassimaLunghezza(arrayInteri vettore)
{
  Contatore scorriArray,scorriArrayTemp,lunghMax,lunghMaxTemp;
  int indiceReturn;

  indiceReturn = 0;
  scorriArray = 0;
  lunghMax = 0;

  while(scorriArray<DIM-1)
  {
    lunghMaxTemp = 0;
    if(vettore[scorriArray]<=vettore[scorriArray+1])
    {
      scorriArrayTemp = scorriArray+1;
      ++lunghMaxTemp;
      while((scorriArrayTemp<DIM-1) && (vettore[scorriArrayTemp]<=vettore[scorriArrayTemp+1]))
      {
        ++lunghMaxTemp;
        ++scorriArrayTemp;
      }
    }

    if(lunghMaxTemp>lunghMax)
    {
      lunghMax = lunghMaxTemp;
      indiceReturn = scorriArray;
    }

    ++scorriArray;
  }

  return indiceReturn;
}
