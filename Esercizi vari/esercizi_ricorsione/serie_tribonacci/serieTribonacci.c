#include <stdio.h>
#include <stdlib.h>

typedef int Contatore;

int serieTribonacci(int numero);

int main(int argc, char const *argv[]) {
  int numeroElementi,risultato;
  Contatore iteratore;

  printf("Inserisci quanti elementi della serie di Tribonacci vuoi visualizzare : ");
  scanf("%d",&numeroElementi);

  for(iteratore=1;iteratore<=numeroElementi;iteratore++)
  {
    risultato = serieTribonacci(iteratore);
    printf("%d ",risultato);
  }
  return 0;
}

int serieTribonacci(int numero)
{
  if(numero==-2 || numero==-1 || numero==0) return 0;
  else if(numero==1) return 1;
  else return(serieTribonacci(numero-1)+serieTribonacci(numero-2)+serieTribonacci(numero-3));
}
