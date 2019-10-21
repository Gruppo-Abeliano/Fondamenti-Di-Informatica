/*
 * Autore: Paolo Pertino
 * Nome File : calcolo_crf_area.c
 * Esercizio : Scrivere un programma C che legge da tastiera il raggio di un cerchio, calcola circonferenza ed area del cerchio, e stampa i due valori a video.
 *             Definire Pigreco = 3.14159 come parametro costante(direttiva #define)
 *             Si scriva, compili, esegua e corregga il programma. Una volta che esso funziona correttamente, lo si modifichi in modo che continui a chiedere
 *             nuovi valori di raggio all'utente (e a fornire risultati) finche' l'utente non inserisce un valore negativo
 */

//Librerie
#include <stdio.h>

//Costanti utilizzate
#define PIGRECO 3.14159

//Definizione funzioni
void getRaggio(float *raggio);
void circonferenza(float *raggio);
void area(float *raggio);

//Main
int main(int argc, char const *argv[]) {
  //Fase dichiarativa
  float raggio;

  getRaggio(&raggio);

  return 0;
}

//Funzioni

/*
   getRaggio : prende in input il raggio e restituisce il valore della circonferenza e dell'area (invocando le rispettive funzioni).
               vengono richiesti in input valori finchè non ne viene inserito uno NEGATIVO
*/
void getRaggio(float *raggio)
{
  do {
    printf("\nInserisci il raggio della circonferenza per calcolarne la circonferenza e l'area\nN.B. : il programma continuera' a chiedere e fornire risultati finche' non viene fornito in input un valore negativo.\nRaggio : ");
    scanf("%f", raggio);
    if(*raggio>=0)        //CONTROLLO FATTO ESCLUSIVAMENTE PER IL PRIMO VALORE INSERITO - IN CASO DI VALORE NEGATIVO NON CALCOLA CRF E AREA
    {
      circonferenza(raggio);
      area(raggio);
    }
  } while(*raggio >= 0);
}

/*
  circonferenza : calcola la circonferenza del cerchio di raggio passato
*/
void circonferenza(float *raggio)
{
  float circonferenza;

  circonferenza = 2*PIGRECO*(*raggio);
  printf("\nLa circonferenza del cerchio di raggio %f e' %f\n",*raggio,circonferenza);
}

/*
  area : calcola l'area del cerchio di raggio passato
*/
void area(float *raggio)
{
  float area;

  area = PIGRECO*(*raggio)*(*raggio);
  printf("\nL'area del cerchio di raggio %f e' %f\n",*raggio,area);
}
