#include <stdio.h>
#include <stdlib.h>

#define MAX_LUNGHEZZA 100

typedef char testo[MAX_LUNGHEZZA];
typedef int contatore;

void trovaComune(testo TestoA, testo TestoB);

int main(int argc, char const *argv[]) {
  testo TestoA = "alternativamente";                  //Definisco le variabili già predeterminate dall'esercizio
  testo TestoB = "eternita";
  
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

  printf("%s", TestoComune);
}
