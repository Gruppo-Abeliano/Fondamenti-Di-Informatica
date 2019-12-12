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

//###############     SENZA UTILIZZO DOPPI PUNTATORI     ################
int main(int argc, char const *argv[]) {
  char ContenutoLista[MAX_CARATTERI+1];
  ElemLista *pTesta,*pCorrente,*pPrecedeDaElim;*pDaEliminare;
  int ContaPassi;

  printf("\nInserisci caratteri da inserire nella lista : ");
  scanf("%s",ContenutoLista);

  pTesta = CreaLista();
  StampaElementi(pTesta);

  if(NULL!=pTesta)
  {
    pCorrente = pTesta->pProssimo;
    ContaPassi = 1;
    pPrecedeDaElim = NULL;
    while(NULL!=pCorrente)
    {
      if(ContaPassi == -1)
      {
        if(NULL==pPrecedeDaElim)
        {
          pPrecedeDaElim = pTesta;
        }
        pPrecedeDaElim = pPrecedeDaElim->pProssimo;
      }
      ContaPassi = -1*Contapassi;
      pCorrente = pCorrente->pProssimo;
    }
    if(NULL==pPrecedeDaElim)
    {
      pDaEliminare = pTesta;
      pTesta = pDaEliminare->pProssimo;
      free(pDaEliminare);
    } else {
      pDaEliminare = pPrecedeDaElim->pProssimo;
      pPrecedeDaElim = pDaEliminare->pProssimo;
      free(pDaEliminare);
    }
  }
  return 0;
}
