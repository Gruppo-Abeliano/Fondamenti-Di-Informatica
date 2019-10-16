/***
  Nome : Uguaglianza Testi
  Descrizione : #Dati in input due stringhe di caratteri, cerca la sequenza di caratteri più lunga condivisa da entrambe le stringhe di input e la stampa a schermo seguita dal carattere \0.
     ESEMPIO :
        input 1 : 'alternativamente'
        input 2 : 'eternita'
        Risultato : 'tern'
***/

//Importo Librerie
#include <stdio.h>
#include <stdlib.h>

//Definizione costanti esercizio
#define MAX_LUNGHEZZA 100

//Difinizione tipi utilizzati
typedef char testo[MAX_LUNGHEZZA];
typedef int contatore;

//Definisco funzioni
void trovaComune(testo TestoA, testo TestoB);
void inserisciTesti(testo TestoA, testo TestoB);

int main(int argc, char const *argv[]) {
  testo TestoA;                  //Definisco le variabili già predeterminate dall'esercizio
  testo TestoB;

  inserisciTesti(TestoA,TestoB);
  trovaComune(TestoA, TestoB);

  return 0;
}

void trovaComune(testo TestoA, testo TestoB)
{
  testo TestoComune;
  contatore CursoreA, CursoreB, CursoreComune, CursoreALocale, CursoreBLocale;
  int inizioTestoComune, massima_lunghezza, lunghezzaCorrente;

  massima_lunghezza = 0;
  CursoreA = 0;

  while('\0' != TestoA[CursoreA])
  {
    CursoreB = 0;
    while('\0' != TestoB[CursoreB])
    {
      if(TestoB[CursoreB] == TestoA[CursoreA])
      {
        lunghezzaCorrente = 1;
        CursoreALocale = CursoreA + 1;
        CursoreBLocale = CursoreB + 1;

        while(('\0' != TestoA[CursoreALocale]) && ('\0' != TestoB[CursoreBLocale]) && (TestoA[CursoreALocale] == TestoB[CursoreBLocale]))
        {
          ++lunghezzaCorrente;
          ++CursoreALocale;
          ++CursoreBLocale;
        }

        if(lunghezzaCorrente > massima_lunghezza)
        {
          inizioTestoComune = CursoreA;
          massima_lunghezza = lunghezzaCorrente;
        }
      }
      ++CursoreB;
    }
    ++CursoreA;
  }

  CursoreA = inizioTestoComune;
  CursoreComune = 0;

  while(CursoreComune < massima_lunghezza)
  {
    TestoComune[CursoreComune] = TestoA[CursoreA];
    ++CursoreA;
    ++CursoreComune;
  }
  TestoComune[CursoreComune] = '\0';

  printf("Il testo in comune delle due stringhe è %s ed ha lunghezza di %d caratteri", TestoComune, massima_lunghezza);
}

void inserisciTesti(testo TestoA, testo TestoB)
{
  printf("\nInserisci il primo testo da confrontare : ");
  scanf("%s", TestoA);
  printf("\nInserisci il secondo testo da confrontare : ");
  scanf("%s", TestoB);
}
