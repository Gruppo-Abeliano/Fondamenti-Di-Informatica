/*
  Autore : Paolo Pertino
  Descrizione : data una lista dinamica classica di interi, la funzione CostruisciBidir crea una nuova lista bidirezionale
                , ovvero una lista dinamica che olre ad avere il puntatore all'elemento succesivo, ne hanno uno che
                punta all'elemento precedente.
*/

#include <stdio.h>
#include <stdlib.h>

#define TERMINATORE '/'
#define RICORSIVA

typedef struct LISTAMONO
{
  char info;
  struct LISTAMONO *pNext;
} ElemListaMonoDim;
typedef struct LISTABIDIM
{
  char info;
  struct LISTABIDIM *pProx;
  struct LISTABIDIM *pPrec;
} ElemListaBiDim;
typedef struct
{
  ElemListaBiDim *pPrimoElem;
  ElemListaBiDim *pUltimoElem;
} ListaBidir;
typedef ElemListaMonoDim *ListaMonoDirezionale;
typedef ElemListaBiDim *ListaBidirezionale;

ListaBidirezionale CostruisciBidir(ListaMonoDirezionale L);
void aggiungiElemento(ListaMonoDirezionale *toCompile, char Elemento);
void mostraLista(ListaMonoDirezionale toRead);

int main(int argc, char const *argv[]) {
  ListaMonoDirezionale listaIniziale;
  ListaBidirezionale listaFinale;
  int toAdd;

  listaIniziale = NULL;
  listaFinale = NULL;

  do
  {
    printf("LISTA 1 - Inserisci un numero : (Carattere terminatore : /) ");
    scanf("%c", &toAdd);
    fflush(stdin);
    if (toAdd != TERMINATORE)
      aggiungiElemento(&listaIniziale, toAdd);
  } while (toAdd != TERMINATORE);

  mostraLista(listaIniziale);
  listaFinale = CostruisciBidir(listaIniziale);

  printf("\nLista Costruita...");
  return 0;
}

ListaBidirezionale CostruisciBidir(ListaMonoDirezionale L)
{
  #ifdef RICORSIVA
    ListaBidirezionale l1,l2;

    if(L==NULL) return NULL;

    l1 = CostruisciBidir(L->pNext);
    l2 = malloc(sizeof(ElemListaBiDim));

    l2->pProx = l1;
    if(l1!=NULL) l1->pPrec = l2;
    l2->pPrec = NULL;
    return l2;
  #else
    ListaMonoDirezionale pMonoCorr;
    ListaBidir TestaNuovaLista;
    ListaBidirezionale pBiCorrente;

    TestaNuovaLista.pPrimoElem = NULL;
    TestaNuovaLista.pUltimoElem = NULL;

    pMonoCorr = L;
    while(pMonoCorr != NULL)
    {
      if(TestaNuovaLista.pPrimoElem == NULL)
      {
        TestaNuovaLista.pPrimoElem = malloc(sizeof(ElemListaBiDim));
        TestaNuovaLista.pUltimoElem = TestaNuovaLista.pPrimoElem;
        TestaNuovaLista.pPrimoElem->info = pMonoCorr->info;
        pBiCorrente = TestaNuovaLista.pPrimoElem;
        pBiCorrente->pPrec = NULL;
        pBiCorrente->pProx = NULL;
      } else {
        pBiCorrente->pProx = malloc(sizeof(ElemListaBiDim));
        pBiCorrente->pProx->pPrec = pBiCorrente;
        pBiCorrente = pBiCorrente->pProx;
        pBiCorrente->pProx = NULL;
        pBiCorrente->info = pMonoCorr->info;
        TestaNuovaLista.pUltimoElem = pBiCorrente;
      }
      pMonoCorr = pMonoCorr->pNext;
    }

    return pBiCorrente;
  #endif
}

void aggiungiElemento(ListaMonoDirezionale *toCompile, char Elemento)
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
    printf("\nElemento %d : %c", contatore, toRead->info);
    toRead = toRead->pNext;
    ++contatore;
  }
}
