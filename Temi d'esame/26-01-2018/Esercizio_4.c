/*
  Autore : Paolo Pertino
  Esercizio 4 - Tema Esame 26-01-2018
  Descrizione :

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

int main(int argc, char const *argv[]) {

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
