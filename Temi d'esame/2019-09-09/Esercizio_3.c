#include <stdio.h>
#include <stdlib.h>

typedef struct EL
{
  int numero;
  struct EL *pProx;
} ElemLista;
typedef ElemLista *Lista;

Lista creaLista();
void leggiLista(Lista daLeggere);
void Scambia(Lista *pLista);

int main(int argc, char const *argv[]) {
  Lista nuovaLista;

  nuovaLista = NULL;
  nuovaLista = creaLista();
  leggiLista(nuovaLista);

  Scambia(&nuovaLista);
  leggiLista(nuovaLista);
  return 0;
}

void Scambia(Lista *pLista)
{
  Lista ElementoSuccessivo,Punt;

  /*
    Controllo il caso base ovvero se l'elemento passato vale NULL. In tal caso interrompo la funzione
  */
  if(*pLista == NULL) return;

  /*
    Altrimenti scambio io i primi due valori e passo allo schiavo la coda della lista.
  */
  ElementoSuccessivo = (*pLista)->pProx->pProx;
  Punt = (*pLista)->pProx;
  (*pLista)->pProx = ElementoSuccessivo;
  Punt->pProx = *pLista;
  *pLista = Punt;

  Scambia(&(Punt->pProx->pProx));
}

Lista creaLista()
{
  Lista Punt,newList;
  int numeroDaInserire;
  int continuareAdInserire;

  /*
    Inizializzo i due puntatori.
  */
  Punt = NULL;
  newList = NULL;

  /*
    Inserisco i dati con un ciclo do-while, finchè l'utente non decide di fermarsi.
  */
  do {
    printf("Inserisci un numero : ");
    scanf("%d",&numeroDaInserire);

    if(newList == NULL)
    {
      newList = malloc(sizeof(ElemLista));
      newList->numero = numeroDaInserire;
      newList->pProx = NULL;
      Punt = newList;
    } else {
      Punt->pProx = malloc(sizeof(ElemLista));
      Punt = Punt->pProx;
      Punt->numero = numeroDaInserire;
      Punt->pProx = NULL;
    }

    printf("\nVuoi inserire altri numeri?\n1. SI\n2.NO\nScelta : ");
    scanf("%d",&continuareAdInserire);
  } while(continuareAdInserire == 1);

  return newList;
}

void leggiLista(Lista daLeggere)
{
  while(daLeggere != NULL)
  {
    printf("[%d]",daLeggere->numero);
    daLeggere = daLeggere->pProx;
  }
}
