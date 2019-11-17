/*
  Scrivere una funzione (chiamata Minimo) che ha come parametro d'ingresso un dato di tipo TipoL e restituisce il minimo carattere 
  tra quelli contenuti nella lista sequenziale ricevuta in ingresso, ovvero quello più vicino all'inizio dell'alfabeto minuscolo. 
  E' richiesto che Minimo operi correttamente solo se la lista che riceve in ingresso contiene almeno un carattere.
  Nel programma dell'Esercizio 4, aggiungere al blocco main una parte che verifica se Lista contiene almeno 1 elemento e, 
  in tal caso, chiama la funzione Minimo (passandole Lista) e stampa a schermo il carattere restituito da Minimo.
  NOTA: in C l'insieme dei char è ordinato, dunque è possibile fare confronti del tipo if(Char1<Char2) tra dati di tipo char.
*/

#include <stdio.h>
#include <stdlib.h>

#define CAPIENZA 10
#define TERMINATORE '/'

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
char Minimo(TipoL *checkMinimo);
bool checkElementi(TipoL *toCheck);

int main(int argc, char const *argv[]) {
  TipoL Lista;
  char minimo;
  bool isCompiled;

  Lista.numeroElementi=0;

  compilaLista(&Lista);
  leggiLista(&Lista);
  isCompiled = checkElementi(&Lista);

  if(isCompiled == true)
  {
    minimo = Minimo(&Lista);
    printf("\nIl carattere minimo della lista e' %c.",minimo);
  } else {
    printf("\nLa lista e' vuota.");
  }

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

    if ((*toCompile).Caratteri[(*toCompile).numeroElementi] < 'a' || (*toCompile).Caratteri[(*toCompile).numeroElementi] > 'z') {
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

  printf("\nLa lista inserita e' : ");
  for(ScorriLista=0;ScorriLista<(*toRead).numeroElementi;++ScorriLista)
  {
    printf("%c",(*toRead).Caratteri[ScorriLista]);
  }
}

char Minimo(TipoL *checkMinimo)
{
  char carattereMinimo;
  Contatore scorriLista;

  carattereMinimo = checkMinimo->Caratteri[0];
  for(scorriLista=0;scorriLista<checkMinimo->numeroElementi;++scorriLista)
  {
    if(carattereMinimo>checkMinimo->Caratteri[scorriLista])
    {
      carattereMinimo = checkMinimo->Caratteri[scorriLista];
    }
  }

  return carattereMinimo;
}

bool checkElementi(TipoL *toCheck)
{
  if(toCheck->numeroElementi>0) return true;
  else return false;
}
