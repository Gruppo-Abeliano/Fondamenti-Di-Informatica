#include <stdio.h>

#define DIMENSIONE 5

void RicBubbleSort(float Arr[],int N);

int main(int argc, char const *argv[]) {
  float Array[DIMENSIONE] = {5,4,3,2,1};

  RicBubbleSort(Array,DIMENSIONE);

  for(int i=0;i<5;i++)
  {
    printf("\n%.2f",Array[i]);
  }
  return 0;
}

void RicBubbleSort(float Arr[],int N)
{
  int contatore;
  float temp;

  /*
    Porto l'elemento più grande in fondo all'array e successivamente chiamo me stesso con
    un array più piccolo.
  */

  /*
    CASO BASE : l'array passato ha dimensione 1.
  */
  if(N == 1) return;

  contatore = 0;
  while(contatore < N-1)
  {
    if(Arr[contatore] > Arr[contatore+1])
    {
      temp = Arr[contatore+1];
      Arr[contatore+1] = Arr[contatore];
      Arr[contatore] = temp;
    }
    ++contatore;
  }
  /*
    Eseguo la chiamata ricorsiva
  */
  RicBubbleSort(Arr,N-1);
}
