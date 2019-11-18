#include <stdio.h>
#include <stdlib.h>

#define MAX_CARATTERI 100

typedef struct EL
{
  char Dato;
  struct EL *pProssimo;
} ElemLista;

//FUNZIONI DA UTILIZZARE PER IL DEBUGGING(NON RICHIESTE NEL TEMA D'ESAME)
ElemLista *CreaLista(char *ElencoCaratteri);
void StampaElementi(ElemLista *pTesta);

//###############     CON UTILIZZO DOPPI PUNTATORI     ###############\\
int main(int argc, char const *argv[]) {
  char ContenutoLista[MAX_CARATTERI+1];
  ElemLista *pTesta,*pCorrente,*pDaEliminare;
  ElemLista **ppPuntADaElim;
  int ContaPassi;

  printf("\nInserisci stringa da inserire nella lista.");
  scanf("%s",ContenutoLista);

  pTesta = CreaLista(ContenutoLista);
  StampaElementi(pTesta);

  if(NULL!=pTesta)
  {
    pCorrente = pTesta->pProssimo;
    ContaPassi = 1;
    ppPuntADaElim = &pTesta;

    while(NULL!=pCorrente)
    {
      if(ContaPassi==-1)
      {
        ppPuntADaElim = &((*ppPuntADaElim)->pProssimo);
      }
    }
    ContaPassi = -1*ContaPassi;
    pCorrente = pCorrente->pProssimo;
  }

  /*
    A questo punto del programma ppPuntADaElim punta al campo pProssimo dell'elemento della lista prima di quello da eliminare.
      1) Mettiamo dunque dentro a pDaEliminare una copia del puntatore che andrà eliminato.
      2) Devo ora collegare l'elemento precedente di quello da eliminare con quello immediatamente successivo.
      3) Elimino l'elemento.
  */
  pDaEliminare = *ppPuntADaElim;                // (1)
  *ppPuntADaElim = pDaEliminare->pProssimo;     // (2)
  free(pDaEliminare);                           // (3)

  return 0;
}
