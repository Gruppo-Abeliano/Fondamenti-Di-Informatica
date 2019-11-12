/*
Produrre una versione modificata del programma dell'Esercizio 2 che, ogniqualvolta l'utente immette una lettera minuscola,
verifica che essa sia effettivamente diversa da tutte quelle già contenute in Lista. 
Nel caso in cui la lettera immessa dall'utente risulti uguale ad una di quelle già presenti in Lista,
essa non viene inserita nella lista sequenziale e viene stampato il messaggio d'errore “Il carattere inserito è un doppione ed è 
stato ignorato.”.
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
bool checkDoppioni(TipoL *toCheck,char carattereDaControllare);

int main(int argc, char const *argv[]) {
  TipoL Lista;

  Lista.numeroElementi=0;

  compilaLista(&Lista);
  leggiLista(&Lista);
  return 0;
}

void compilaLista(TipoL *toCompile)
{
  Contatore ScorriLista;
  bool isDoppione;

  printf("\n***INIZIO FASE INSERIMENTO | PREMERE INVIO PER CONTINUARE***\n");
  system("pause");

  ScorriLista = 0;
  do
  {
    printf("\nInserisci il %d carattere nella lista : ",ScorriLista+1);
    scanf("%c%*c",&((*toCompile).Caratteri[(*toCompile).numeroElementi]));
    isDoppione = checkDoppioni(toCompile,(*toCompile).Caratteri[(*toCompile).numeroElementi]);

    if(true==isDoppione)
    {
      printf("\nIl carattere inserito e' un doppione e non e' stato inserito.");
    } else if ((*toCompile).Caratteri[(*toCompile).numeroElementi] < 'a' || (*toCompile).Caratteri[(*toCompile).numeroElementi] > 'z') {
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

bool checkDoppioni(TipoL *toCheck,char carattereDaControllare)
{
  Contatore ScorriLista;
  bool trovato;

  trovato = false;

  for(ScorriLista=0;ScorriLista<(*toCheck).numeroElementi;++ScorriLista)
  {
    if(carattereDaControllare == (*toCheck).Caratteri[ScorriLista]) trovato=true;
  }

  return trovato;
}
