/*
  Autore: Paolo Pertino
  Esercizio 5 - Tema Esame 13-09-2017

  Descrizione: data in ingresso alla funzione calcolaPerimetro un'immagine di dimensione predefinita,
               essa calcola il perimetro dell'oggetto contenuto all'interno. L'oggetto è definito da
               pixel vicini di diverso colore, come descritto nel testo dell'esercizio.

  Tempo esecuzione: 8 minuti.
*/

#include <stdio.h>

#define DIMENSIONE 5
#define DEBUG

typedef int Vettore[DIMENSIONE];
typedef Vettore Immagine[DIMENSIONE];

void getImmagine(Immagine immagineVuota);
void mostraImmagine(Immagine immagineDaMostrare);
int calcolaPerimetro(Immagine immagine);

int main(int argc, char const *argv[]) {
  #ifdef DEBUG
    Immagine immagine = {
      {0,0,0,0,0},
      {0,1,1,1,0},
      {0,1,1,1,0},
      {0,1,1,1,0},
      {0,0,0,0,0},
    };
  #else
    Immagine immagine;
  #endif
  int perimetro;

  /*
    Inserisco l'immagine da elaborare
  */
  #ifndef DEBUG
    getImmagine(immagine);
  #endif
  mostraImmagine(immagine);

  /*
    Elaboro l'immagine calcolando il perimetro dell'oggetto contenuto in essa.
    Fornisco infine il risultato ottenuto.
  */
  perimetro = calcolaPerimetro(immagine);

  printf("\nIl perimetro dell'oggetto rappresentato in figura e' : %d", perimetro);

  return 0;
}

int calcolaPerimetro(Immagine immagine)
{
  int perimetro;
  int scorriRiga,scorriColonna;

  /*
    Viene presupposto che il perimetro della figura non si trovi in prossimità della prima/ultima riga/colonna
    e che l'oggetto passato alla funzione sia regolare.
  */

  /*
    Scorro dunque la matrice dalla prima riga e prima colonna fino alla penultima riga e colonna, controllando
    sempre l'elemento a destra e l'elemento sotto a quello in indagine. Se il pixel è diverso, aggiungo 1 al
    perimetro, altrimenti proseguo.
  */
  perimetro = 0;
  for(scorriRiga=0;scorriRiga<DIMENSIONE-1;scorriRiga++)
  {
    for(scorriColonna=0;scorriColonna<DIMENSIONE-1;scorriColonna++)
    {
      if(immagine[scorriRiga][scorriColonna] != immagine[scorriRiga+1][scorriColonna]) ++perimetro;
      if(immagine[scorriRiga][scorriColonna] != immagine[scorriRiga][scorriColonna+1]) ++perimetro;
    }
  }

  /*
    Restituisco il perimetro dell'oggetto.
  */
  return perimetro;
}

void getImmagine(Immagine immagineVuota)
{
  int scorriRiga,scorriColonna;

  for(scorriRiga=0;scorriRiga<DIMENSIONE;scorriRiga++)
  {
    for(scorriColonna=0;scorriColonna<DIMENSIONE;scorriColonna++)
    {
      printf("Inserisci l'elemento [%d:%d]",scorriRiga+1,scorriColonna+1);
      scanf("%d",&immagineVuota[scorriRiga][scorriColonna]);
    }
  }
}

void mostraImmagine(Immagine immagineDaMostrare)
{
  int scorriRiga,scorriColonna;

  for(scorriRiga=0;scorriRiga<DIMENSIONE;scorriRiga++)
  {
    for(scorriColonna=0;scorriColonna<DIMENSIONE;scorriColonna++)
    {
      printf("%d ",immagineDaMostrare[scorriRiga][scorriColonna]);
    }
    printf("\n");
  }
}
