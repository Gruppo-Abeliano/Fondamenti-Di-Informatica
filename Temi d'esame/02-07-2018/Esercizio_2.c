#include <stdlib.h>
#include <stdio.h>

typedef struct EL
{
  int numero;
  struct EL *prox;
} ElementoLista;
typedef ElementoLista *Lista;

Lista Fusione(Lista lista1,Lista lista2);
void aggiungiElemento(Lista *toCompile,int Elemento);
void mostraLista(Lista toRead);

int main(int argc, char const *argv[]) {
  Lista l1,l2,listaFinale;
  int toAdd;

  l1 = NULL;
  l2 = NULL;

  do {
    printf("LISTA 1 - Inserisci un numero : (STOP quando numero < 0) ");
    scanf("%d",&toAdd);
    if(toAdd>=0) aggiungiElemento(&l1,toAdd);
  } while (toAdd>=0);

  do {
    printf("LISTA 2 - Inserisci un numero : (STOP quando numero < 0) ");
    scanf("%d",&toAdd);
    if(toAdd>=0) aggiungiElemento(&l2,toAdd);
  } while (toAdd>=0);

  printf("\nLista 1 :");
  mostraLista(l1);
  printf("\nLista 2 :");
  mostraLista(l2);

  listaFinale = Fusione(l1,l2);

  printf("\n\n\n");
  mostraLista(listaFinale);

  return 0;
}

Lista Fusione(Lista lista1,Lista lista2)
{
  
}

void mostraLista(Lista toRead)
{
  int contatore;

  contatore = 1;
  while(toRead != NULL)
  {
    printf("\nElemento %d : %d",contatore,toRead->numero);
    toRead = toRead->prox;
    ++contatore;
  }
}
