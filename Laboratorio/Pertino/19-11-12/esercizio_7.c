/*
  Modificare la funzione Minimo in modo che riceva anche un secondo parametro di ingresso di tipo char, chiamato Soglia. 
  La funzione modificata restituisce il minimo carattere di valore superiore a Soglia tra quelli contenuti nel dato di tipo TipoL 
  che riceve in ingresso. Se la lista non contiene alcun carattere superiore a Soglia, la funzione restituisce TERMINATORE. 
  Si modifichi la chiamata a Minimo presente nel blocco main in modo da usare la nuova versione della funzione.
  Scrivere una funzione (chiamata Ordina) che riceve in ingresso un dato di tipo TipoL e ne modifica il contenuto in modo che
  i caratteri che esso contiene risultino in ordine di valore crescente. Il codice di Ordina deve usare la funzione Minimo.
  Modificare il blocco main in modo che, se Lista contiene almeno un elemento, dopo aver stampato il carattere di minimo valore, 
  prima usi Ordina per ordinare il contenuto della lista sequenziale, poi stampi il contenuto della lista modificata.
*/

#include <stdio.h>
#include <stdlib.h>

#define CAPIENZA 10
#define TERMINATORE '/'
#define INIZIO_ALFABETO 'a'
#define FINE_ALFABETO 'z'

typedef char ArrayCaratteri[CAPIENZA];
typedef int Contatore;
typedef enum{false,true}bool;
typedef struct
{
  ArrayCaratteri Caratteri;
  int numeroElementi;
} TipoL;

void compilaLista(TipoL *toCompile);
void leggiLista(TipoL *toRead);
char Minimo(TipoL *checkMinimo,char Soglia);
TipoL Ordina(TipoL *toOrder);
bool checkElementi(TipoL *toCheck);

int main(int argc, char const *argv[]) {
  TipoL Lista,ListaOrdinata;
  char minimo,soglia;
  bool isCompiled;

  Lista.numeroElementi=0;

  compilaLista(&Lista);
  leggiLista(&Lista);
  isCompiled = checkElementi(&Lista);

  if(isCompiled == true)
  {
    printf("\nInserisci il carattere Soglia(Verra' ricercato il minimo carattere presenta nella lista maggiore del valore di soglia) : ");
    scanf("%c",&soglia);
    minimo = Minimo(&Lista,soglia);
    if(minimo != TERMINATORE) printf("\nIl carattere minimo della lista e' %c.",minimo);
    else printf("\nNon e' stato trovato alcun carattere maggiore della soglia inserita.");
  }

  ListaOrdinata = Ordina(&Lista);
  leggiLista(&ListaOrdinata);

  return 0;
}

void compilaLista(TipoL *toCompile)
{
  Contatore ScorriLista;

  printf("\n***INIZIO FASE INSERIMENTO | PREMERE INVIO PER CONTINUARE***\n");
  system("pause");

  ScorriLista = 0;
  do
  {
    printf("\nInserisci il %d carattere nella lista : ",ScorriLista+1);
    scanf("%c%*c",&((*toCompile).Caratteri[(*toCompile).numeroElementi]));
    if((*toCompile).Caratteri[(*toCompile).numeroElementi] == TERMINATORE)
    {
      printf("\nFine inserimento.");
    } else if ((*toCompile).Caratteri[(*toCompile).numeroElementi] < INIZIO_ALFABETO || (*toCompile).Caratteri[(*toCompile).numeroElementi] > FINE_ALFABETO) {
      printf("\nIl carattere inserito non e' valido ed e' stato ignorato.");
    } else {
      ++(*toCompile).numeroElementi;
    }
    ++ScorriLista;
  } while((*toCompile).Caratteri[(*toCompile).numeroElementi] != TERMINATORE && ScorriLista<CAPIENZA);
}

void leggiLista(TipoL *toRead)
{
  Contatore ScorriLista;

  if((*toRead).numeroElementi == 0)
  {
    printf("\nLa lista e' vuota.");
    return;
  }

  printf("\nLista : ");
  for(ScorriLista=0;ScorriLista<(*toRead).numeroElementi;++ScorriLista)
  {
    printf("%c",(*toRead).Caratteri[ScorriLista]);
  }
}

char Minimo(TipoL *checkMinimo,char Soglia)
{
  char carattereMinimo;
  bool trovato;
  Contatore scorriLista;

  trovato = false;
  scorriLista=0;
  do
  {
    if(checkMinimo->Caratteri[scorriLista]>Soglia && trovato==false)
    {
      trovato = true;
      carattereMinimo = checkMinimo->Caratteri[scorriLista];
    }
    if(trovato==true && checkMinimo->Caratteri[scorriLista]>Soglia && carattereMinimo>checkMinimo->Caratteri[scorriLista])
    {
      carattereMinimo = checkMinimo->Caratteri[scorriLista];
    }

    ++scorriLista;
  } while(scorriLista<checkMinimo->numeroElementi);

  if(trovato==true) return carattereMinimo;
  else return TERMINATORE;
}

TipoL Ordina(TipoL *toOrder)
{
  Contatore scorriLista;
  TipoL listaOrdinata;

  listaOrdinata.numeroElementi = 0;
  listaOrdinata.Caratteri[0] = Minimo(toOrder,INIZIO_ALFABETO-1);
  ++(listaOrdinata.numeroElementi);
  for(scorriLista=1;scorriLista<toOrder->numeroElementi;scorriLista++)
  {
    listaOrdinata.Caratteri[scorriLista] = Minimo(toOrder,listaOrdinata.Caratteri[scorriLista-1]);
    ++(listaOrdinata.numeroElementi);
  }

  return listaOrdinata;
}

bool checkElementi(TipoL *toCheck)
{
  if(toCheck->numeroElementi>0) return true;
  else return false;
}
