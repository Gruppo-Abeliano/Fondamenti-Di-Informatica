/*
  Autore: Paolo Pertino
  Esercizio 2 - Tema esame 2017-02-08

  Descrizione: data una lista dinamica contenente una serie di punti che definiscono una linea spezzata
               aperta non degenere nel piano, ed una seconda lista anch'essa rappresentante una linea,
               la funzione checkScorciatoia restituisce 1 se il primo segmento è scorciatoia del secondo
               oppure 0 altrimenti.

  Tempo di esecuzione: 17 minuti (per le funzioni checkScorciatoia,cercaInizio,cercaFine e calcolaLunghezza)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct PUNTO
{
  int x;
  int y;
  struct PUNTO *pProx;
} punto_t;
typedef struct
{
  int x;
  int y;
} PuntoDelPiano;
typedef punto_t *Lista;

Lista compilaLista();
int checkScorciatoia(Lista A,Lista B);
PuntoDelPiano cercaInizio(Lista segmento);
PuntoDelPiano cercaFine(Lista segmento);
double calcolaLunghezza(Lista segmento);

int main(int argc, char const *argv[]) {
  Lista segmentoA,segmentoB;
  int scorciatoiaCheck;

  /*
    Inizializzo le due liste dinamiche inserendo i punti.
  */
  segmentoA = NULL;
  segmentoB = NULL;

  segmentoA = compilaLista();
  segmentoB = compilaLista();

  /*
    Controllo se segmentoA è una scorciatoia di segmentoB
  */
  scorciatoiaCheck = checkScorciatoia(segmentoA,segmentoB);

  /*
    Gestisco il risultato ottenuto.
  */
  if(scorciatoiaCheck == 1) printf("\nIl primo segmento e' una scorciatoia del secondo.");
  else printf("\nIl primo segmento non e' scorciatoia del secondo.");

  return 0;
}

int checkScorciatoia(Lista A,Lista B)
{
  PuntoDelPiano inizioA,fineA,inizioB,fineB;
  double lunghezzaA,lunghezzaB;

  /*
    Trovo l'inizio e la fine di entrambi i segmenti.
  */
  inizioA = cercaInizio(A);
  inizioB = cercaInizio(B);
  fineA = cercaFine(A);
  fineB = cercaFine(B);

  /*
    Se inizio e fine non coincidono, posso già restituire 0, perchè i punti non sono conformi alla
    definizione di scorciatoia fornita dal testo.
  */
  if((inizioA.x != inizioB.x || inizioA.y != inizioB.y) || (fineA.x != fineB.x || fineA.y != fineB.y)) return 0;
  else {
    /*
      Se c'è la possibilità che il primo segmento sia scorciatoia del secondo, allora calcolo le due
      lunghezze e le confronto.
    */
    lunghezzaA = calcolaLunghezza(A);
    lunghezzaB = calcolaLunghezza(B);

    if(lunghezzaA < lunghezzaB) return 1;
    else return 0;
  }
}

PuntoDelPiano cercaInizio(Lista segmento)
{
  PuntoDelPiano toReturn;

  /*
    Estrapolo il primo punto del segmento.
  */
  toReturn.x = segmento->x;
  toReturn.y = segmento->y;

  return toReturn;
}

PuntoDelPiano cercaFine(Lista segmento)
{
  PuntoDelPiano toReturn;
  Lista cursore;

  /*
    Scorro la lista fino alla fine ed estrapolo l'ultimo punto.
  */
  cursore = segmento;
  while(cursore->pProx != NULL)
  {
    cursore = cursore->pProx;
  }

  toReturn.x = cursore->x;
  toReturn.y = cursore->y;

  return toReturn;
}

double calcolaLunghezza(Lista segmento)
{
  double lunghezza;
  Lista cursore;

  /*
    Calcolo la lunghezza con la classica formula distanza punto-punto nel piano.
  */
  lunghezza = 0;
  cursore = segmento;
  while(cursore->pProx != NULL)
  {
    lunghezza += sqrt(pow(fabs(cursore->pProx->x - cursore->x),2) + pow(fabs(cursore->pProx->y - cursore->y),2));
    cursore = cursore->pProx;
  }

  return lunghezza;
}

Lista compilaLista()
{
  Lista newList,punt;
  int numeroInseritoX,numeroInseritoY,inputEnd;

  newList = NULL;
  punt = NULL;

  do
  {
    printf("Inserisci coordinata x: ");
    scanf("%d",&numeroInseritoX);
    printf("Inserisci coordinata y: ");
    scanf("%d",&numeroInseritoY);

    if(newList == NULL)
    {
      punt = malloc(sizeof(punto_t));
      punt->x = numeroInseritoX;
      punt->y = numeroInseritoY;
      punt->pProx = NULL;
      newList = punt;
    } else {
      punt->pProx = malloc(sizeof(punto_t));
      punt = punt->pProx;
      punt->x = numeroInseritoX;
      punt->y = numeroInseritoY;
      punt->pProx = NULL;
    }

    printf("Vuoi ancora inserire punti? Inserisci 1 per continuare o 0 per terminare : ");
    scanf("%d",&inputEnd);
  } while(inputEnd != 0);

  return newList;
}
