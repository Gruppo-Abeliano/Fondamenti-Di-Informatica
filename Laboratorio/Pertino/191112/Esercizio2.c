/*
Modificare il blocco main dell'ESERCIZIO 1 in modo che l'utente possa inserire nella lista sequenziale un numero di caratteri a sua scelta,
purché non superiore a CAPIENZA. La fase di input deve terminare quando l'utente immette uno speciale carattere TERMINATORE 
definito con una #define (tale carattere non va inserito nella lista), oppure quando sono state inserite nella lista CAPIENZA 
lettere minuscole. 
Se l'utente inserisce un carattere che non appartiene all'alfabeto minuscolo ed è diverso dal TERMINATORE, 
il carattere non viene inserito nella lista sequenziale e viene stampato il messaggio 
“Il carattere inserito non è valido ed è stato ignorato”.
*/

#include <stdio.h>
#include <stdlib.h>

#define CAPIENZA 10
#define TERMINATORE '/'

typedef char ArrayCaratteri[CAPIENZA];
typedef int Contatore;
typedef struct
{
  ArrayCaratteri Caratteri;
  int numeroElementi;
} TipoL;

void compilaLista(TipoL *toCompile);
void leggiLista(TipoL *toRead);

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

  printf("\n***INIZIO FASE INSERIMENTO | PREMERE INVIO PER CONTINUARE***\n");
  system("pause");

  ScorriLista = 0;
  do
  {
    printf("\nInserisci il %d carattere nella lista : ",ScorriLista+1);
    scanf("%c%*c",&((*toCompile).Caratteri[(*toCompile).numeroElementi]));

    if((*toCompile).Caratteri[(*toCompile).numeroElementi] < 'a' || (*toCompile).Caratteri[(*toCompile).numeroElementi] > 'z')
    {
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
