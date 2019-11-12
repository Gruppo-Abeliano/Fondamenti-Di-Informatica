/*Esercizio 1
Definire un parametro (tramite una direttiva #define  o una dichiarazione const) chiamato CAPIENZA avente valore 10.
Definire un tipo di dato, chiamato TipoL, corrispondente ad una lista sequenziale in grado di contenere al massimo CAPIENZA 
dati di tipo carattere. Scrivere un programma C che legge da tastiera CAPIENZA lettere minuscole tutte diverse tra loro e le memorizza 
una dopo l'altra in una variabile (chiamata Lista) di tipo TipoL.   
Assicurarsi che i caratteri inseriti siano effettivamente lettere minuscole e che essi siano diversi tra di loro è a cura dell'utente 
del programma.
Una volta conclusa la fase di input, il programma deve stampare a schermo in sequenza i caratteri contenuti in Lista
*/

#include <stdio.h>
#include <stdlib.h>

#define CAPIENZA 10

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

  printf("\nInserisci il 1 elemento nella lista : ");
  scanf("%c",&((*toCompile).Caratteri[(*toCompile).numeroElementi]));
  ++(*toCompile).numeroElementi;

  for(ScorriLista=1;ScorriLista<CAPIENZA;++ScorriLista)
  {
    printf("\nInserisci il %d elemento nella lista : ",ScorriLista+1);
    scanf("%*c%c",&((*toCompile).Caratteri[(*toCompile).numeroElementi]));
    ++(*toCompile).numeroElementi;
  }
}

void leggiLista(TipoL *toRead)
{
  Contatore ScorriLista;

  printf("\nLa lista inserita e' : ");
  for(ScorriLista=0;ScorriLista<(*toRead).numeroElementi;++ScorriLista)
  {
    printf("%c",(*toRead).Caratteri[ScorriLista]);
  }
}
