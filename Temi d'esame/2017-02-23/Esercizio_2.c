/*
  Autore : Paolo Pertino
  Descrizione : lettura da file di un testo ed evidenziazione di determinate caratteristiche
  Esercizio 2 - Tema d'esame 23-02-2017
*/

#include <stdio.h>
#include <string.h>

#define FILE_INPUT "./Input.txt"
#define MAX_LUNGHEZZA 100
#define SPAZIO ' '
#define A_CAPO '\n'
#define FINE_RIGA '\0'

int main(int argc, char const *argv[]) {
  FILE *fInput;
  int numLinee,numCaratteriTot,numCaratteriLineaCorr,numeroMaxCaratteriLinea;
  int cursore;
  char rigaCorrente[MAX_LUNGHEZZA+1],rigaPiuLunga[MAX_LUNGHEZZA+1];

  fInput = fopen(FILE_INPUT,"r");
  if(fInput == NULL)
  {
    printf("\nErrore nell'apertura del file.");
    return 1;
  }

  numLinee = 0;
  numCaratteriTot = 0;
  numeroMaxCaratteriLinea = 0;
  while(fgets(rigaCorrente,MAX_LUNGHEZZA+1,fInput))
  {
    cursore = 0;
    numCaratteriLineaCorr = 0;
    while(rigaCorrente[cursore] != FINE_RIGA)
    {
      if(rigaCorrente[cursore] != SPAZIO && rigaCorrente[cursore] != A_CAPO)
      {
        ++numCaratteriTot;
        ++numCaratteriLineaCorr;
      }
      ++cursore;
    }

    if(numCaratteriLineaCorr>numeroMaxCaratteriLinea)
    {
      numeroMaxCaratteriLinea = numCaratteriLineaCorr;
      strcpy(rigaPiuLunga,rigaCorrente);
    }

    ++numLinee;
  }

  fclose(fInput);

  printf("\nLinee : %d\nCar : %d\nMax, Med : %d,%d\nLinea max: %s",numLinee,numCaratteriTot,numCaratteriTot,numCaratteriTot/numLinee,rigaPiuLunga);
  return 0;
}
