#include <stdbool.h>

bool visita(int N, int A[])
{
  bool incontro = false;
  int avanti[N],indietro[N];
  int somma=0;

  for(int i=0;i<N;i++)
  {
    somma+=A[i];
    avanti[i] = somma;
  }

  somma=0;
  for(int i=N-1;i>=0;i--)
  {
    somma+=A[i];
    indietro[i] = somma;
  }

  for(int i=0;i<N;i++)
  {
    if(avanti[i]==indietro[i])
    {
      incontro = true;
    }
  }
  return incontro;
}