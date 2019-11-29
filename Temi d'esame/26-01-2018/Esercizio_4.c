/*
  Autore : Paolo Pertino
  Esercizio 4 - Tema Esame 26-01-2018
  Descrizione : data una lista dinamica classica di interi, la funzione CostruisciBidir crea una nuova lista bidirezionale
                , ovvero una lista dinamica che olre ad avere il puntatore all'elemento succesivo, ne hanno uno che
                punta all'elemento precedente.

  Tempo impiegato : ?? minuti __ scrittura funzione CostruisciBidir
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct LISTAMONO
{
  int info;
  struct LISTAMONO *pNext;
} ElemListaMonoDim;
typedef ElemListaMonoDim *ListaMonoDirezionale;
typedef struct LISTABIDIM
{
  int info;
  struct LISTABIDIM *pProx;
  struct LISTABIDIM *pPrec;
} ElemListaBiDim;
typedef ElemListaBiDim *ListaBidirezionale;

ListaBidirezionale CostruisciBidir(ListaMonoDirezionale L);
void aggiungiElemento(ListaMonoDirezionale *toCompile, int Elemento);
void mostraLista(ListaMonoDirezionale toRead);

int main(int argc, char const *argv[]) {
  ListaMonoDirezionale listaIniziale;
  ListaBidirezionale listaFinale;
  int toAdd;

  listaIniziale = NULL;
  listaFinale = NULL;

  do
  {
    printf("LISTA 1 - Inserisci un numero : (STOP quando numero < 0) ");
    scanf("%d", &toAdd);
    if (toAdd >= 0)
      aggiungiElemento(&listaIniziale, toAdd);
  } while (toAdd >= 0);

  mostraLista(listaIniziale);
  listaFinale = CostruisciBidir(listaIniziale);

  printf("\nLista Costruita...");
  return 0;
}

ListaBidirezionale CostruisciBidir(ListaMonoDirezionale L)
{
  ListaBidirezionale l1,l2;

  if(L==NULL) return NULL;

  l1 = CostruisciBidir(L->pNext);
  l2 = malloc(sizeof(ElemListaBiDim));

  l2->pProx = l1;
  if(l1!=NULL) l1->pPrec = l2;
  l2->pPrec = NULL;
  return l2;
}

void aggiungiElemento(ListaMonoDirezionale *toCompile, int Elemento)
{
  ListaMonoDirezionale punt;
  if (*toCompile == NULL)
  {
    punt = malloc(sizeof(ElemListaMonoDim));
    punt->info = Elemento;
    punt->pNext = NULL;
    *toCompile = punt;
  }
  else
  {
    aggiungiElemento(&((*toCompile)->pNext), Elemento);
  }
}

void mostraLista(ListaMonoDirezionale toRead)
{
  int contatore;

  contatore = 1;
  while (toRead != NULL)
  {
    printf("\nElemento %d : %d", contatore, toRead->info);
    toRead = toRead->pNext;
    ++contatore;
  }
}
