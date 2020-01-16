/*
  Autore: Paolo Pertino
  Esercizio 3 - Tema Esame 04-09-2018

  Descrizione:  Si scriva un sottoprogramma che, ricevendo in ingresso una lista dinamica di
                (almeno due) valori reali, la ordini in ordine crescente mediante l’algoritmo
                BubbleSort*.
                Suggerimento: è conveniente, ad ogni iterazione, portare il valore massimo in fondo
                alla lista anziché il valore minimo in testa alla lista.
                Nota: la versione implementata dell’algoritmo BubbleSort non deve essere necessariamente
                la più efficiente.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct EL
{
  int numero;
  struct EL *pProx;
} ElemLista;
typedef ElemLista *Lista;

Lista bubbleSortDinamico(Lista daOrdinare);
Lista creaLista();
void leggiLista(Lista daLeggere);

int main(int argc, char const *argv[]) {
  Lista nuovaListaDaOrdinare;

  /*
    * Creo la lista dinamica e la mostro a schermo.
  */
  nuovaListaDaOrdinare = creaLista();
  printf("\nLista inserita : ");
  leggiLista(nuovaListaDaOrdinare);

  /*
    * Ordino la lista dinamica con algoritmo bubblesort(non ottimizzato) e la mostro nuovamente.
  */
  nuovaListaDaOrdinare = bubbleSortDinamico(nuovaListaDaOrdinare);
  printf("\nLa nuova lista ordinata e' : ");
  leggiLista(nuovaListaDaOrdinare);

  return 0;
}

Lista bubbleSortDinamico(Lista daOrdinare)
{
  Lista PuntCor,PuntPrec,PuntContaElementi;
  float temp;
  int contaElementi,contatore;

  /*
    * Per implementare l'algoritmo devo scorrere la lista n volte, dove n è il numero di elementi
    * contenuti in essa.
  */

  /*
    * Scorro dunque la lista una prima volta per determinare quanti elementi contiene.
  */
  contaElementi = 0;
  PuntContaElementi = daOrdinare;
  while (PuntContaElementi != NULL)
  {
    ++contaElementi;
    PuntContaElementi = PuntContaElementi->pProx;
  }

  /*
    * Ora che conosco quanti elementi ci sono, devo scorrere la lista _contaElementi_ volte ed ordinarla
    * ogni volta.
  */
  contatore = 0;
  while (contatore < contaElementi)
  {
    PuntPrec = daOrdinare;
    PuntCor = daOrdinare->pProx;
    while (PuntCor != NULL)
    {
      /*
        * Se il numero precedente è maggiore di quello successivo li scambio, altrimenti proseguo.
      */
      if(PuntPrec->numero > PuntCor->numero)
      {
        temp = PuntCor->numero;
        PuntCor->numero = PuntPrec->numero;
        PuntPrec->numero = temp;
      }
      PuntPrec = PuntCor;
      PuntCor = PuntCor->pProx;
    }
    ++contatore;
  }

  return daOrdinare;
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
