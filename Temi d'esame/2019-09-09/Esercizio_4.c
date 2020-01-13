#include <stdio.h>
#include <stdlib.h>

typedef struct ELEMENTO
{
  int numero;
  struct ELEMENTO *pProx;
} ElemLista;
typedef ElemLista *Lista;

Lista creaLista();
void leggiLista(Lista daLeggere);
Lista eliminaNRicorrenze(Lista list,int n);
void cancellaElemento(Lista *pTesta,int numero);

int main(int argc, char const *argv[]) {
  Lista listaDaElaborare;
  int numeroRicorrenza;

  /*
    Crea la lista dinamica.
  */
  listaDaElaborare = NULL;
  listaDaElaborare = creaLista();
  leggiLista(listaDaElaborare);

  /*
    Chiedo all'utente il numero che identifica la ricorrenza da controllare
  */
  printf("\nInserisci un numero. Verranno eliminati dalla lista i numeri che si presentano con tale ricorrenza : ");
  scanf("%d",&numeroRicorrenza);

  /*
    Elaboro la lista dinamica.
  */
  listaDaElaborare = eliminaNRicorrenze(listaDaElaborare,numeroRicorrenza);

  /*
    Leggo il risultato ottenuto.
  */
  printf("\nNuova lista : ");
  leggiLista(listaDaElaborare);

  return 0;
}

Lista eliminaNRicorrenze(Lista list,int n)
{
  Lista PuntDaEliminare,PuntScorriLista1,PuntScorriLista2;
  Lista *pPuntElemento;
  int numeroDaControllare,contaOccorrenze;

  if((list == NULL) || (list->pProx == NULL && n>1)) return list;

  pPuntElemento = &list;
  if(n<1) return list;
  else if(n==1)
  {
    /*
      Se n è uguale a 1 tutti gli elementi della lista vanno eliminati.
    */
    if(list->pProx == NULL)
    {
      free((*pPuntElemento));
      (*pPuntElemento) = NULL;
      return (*pPuntElemento);
    } else {
      PuntDaEliminare = list;
      while((*pPuntElemento) != NULL)
      {
        (*pPuntElemento) = PuntDaEliminare->pProx;
        free(PuntDaEliminare);
        PuntDaEliminare = *pPuntElemento;
      }
    }

    return list;
  } else {
    /*
      Se sono arrivato qui, vuol dire che la lista non è vuota e ci sono almeno 2 elementi
      al suo interno. Pertanto inizio a scandirla dall'inizio numero per numero e conto quante
      volte ciascun numero è situato nella lista, se scopro che esso si trova all'interno almeno
      n volte allora lo cancello.
    */
    PuntScorriLista1 = *pPuntElemento;
    while(PuntScorriLista1 != NULL)
    {
      numeroDaControllare = PuntScorriLista1->numero;
      contaOccorrenze = 0;
      /*
        Scorro la lista dall'inizio e conto quante volte un numero si trova nella lista.
      */
      PuntScorriLista2 = *pPuntElemento;
      while(PuntScorriLista2 != NULL)
      {
        if(numeroDaControllare == PuntScorriLista2->numero) ++contaOccorrenze;
        PuntScorriLista2 = PuntScorriLista2->pProx;
      }
      /*
        Controllo se l'elemento in analisi è presente almeno n volte nella lista. In tal caso
        lo elimino.
      */
      if(contaOccorrenze >= n)
      {
        while(contaOccorrenze > 0)
        {
          cancellaElemento(pPuntElemento,numeroDaControllare);
          --contaOccorrenze;
        }
        PuntScorriLista1 = *pPuntElemento;
      } else {
        PuntScorriLista1 = PuntScorriLista1->pProx;
      }
    }

    return (*pPuntElemento);
  }
}

void cancellaElemento(Lista *pTesta,int numero)
{
  Lista Punt;
  if((*pTesta) == NULL) return;
  if((*pTesta)->numero == numero)
  {
    Punt = (*pTesta);
    (*pTesta) = (*pTesta)->pProx;
    free(Punt);
  } else {
    cancellaElemento(&((*pTesta)->pProx),numero);
  }
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
