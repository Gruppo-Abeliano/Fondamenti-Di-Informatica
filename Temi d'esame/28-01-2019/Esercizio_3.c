/*
  Autore : Paolo Pertino
  Esercizio 3 - Tema Esame 28-01-2019
  Descrizione : data una lista dinamica di interi, la funzione elementiPosPari crea una nuova lista dinamica contenente
                gli elementi situati in posizione pari della lista di partenza.

  Tempo impiegato : 14 minuti __ scrittura funzione generaMantissa
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct ELEMENTO
{
  int numero;
  struct ELEMENTO *pProx;
} ElemLista;
typedef ElemLista *Lista;

Lista elementiPosPari(Lista lista1);
void aggiungiElemento(Lista *toCompile, int Elemento);
void mostraLista(Lista toRead);

int main(int argc, char const *argv[]) {
  Lista listaIniziale,listaModificata;
  int toAdd;

  listaIniziale = NULL;

  //INPUT PHASE
  do
  {
    printf("Inserisci un numero (STOP quando numero < 0) : ");
    scanf("%d", &toAdd);
    if (toAdd >= 0)
      aggiungiElemento(&listaIniziale, toAdd);
  } while (toAdd >= 0);

  printf("\n\nLista iniziale :\n");
  mostraLista(listaIniziale);

  //ELABORAZIONE
  listaModificata = elementiPosPari(listaIniziale);

  //OUTPUT PHASE
  printf("\n\nLista modificata :\n");
  mostraLista(listaModificata);
  return 0;
}

Lista elementiPosPari(Lista lista1)
{
  int contatore;
  Lista listaFinale,puntCor;

  listaFinale = NULL;
  contatore = 0;
  while(lista1 != NULL)
  {
    ++contatore;

    if(contatore%2 == 0)
    {
      if(listaFinale==NULL)
      {
        listaFinale = malloc(sizeof(ElemLista));
        listaFinale->numero = lista1->numero;
        listaFinale->pProx = NULL;
        puntCor = listaFinale;
      } else {
        puntCor->pProx = malloc(sizeof(ElemLista));
        puntCor = puntCor->pProx;
        puntCor->numero = lista1->numero;
        puntCor->pProx = NULL;
      }
    }
    lista1 = lista1->pProx;
  }

  return listaFinale;
}

void aggiungiElemento(Lista *toCompile, int Elemento)
{
  Lista punt;
  if (*toCompile == NULL)
  {
    punt = malloc(sizeof(ElemLista));
    punt->numero = Elemento;
    punt->pProx = NULL;
    *toCompile = punt;
  }
  else
  {
    aggiungiElemento(&((*toCompile)->pProx), Elemento);
  }
}

void mostraLista(Lista toRead)
{
  int contatore;

  contatore = 1;
  while (toRead != NULL)
  {
    printf("\nElemento %d : %d", contatore, toRead->numero);
    toRead = toRead->pProx;
    ++contatore;
  }
}
