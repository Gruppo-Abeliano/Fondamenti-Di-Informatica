/*
 * Autore: Paolo Pertino
 * Nome File : carattere_triangoli.c
 * Esercizio : Scrivere un programma C che legge da tastiera tre numeri interi, e verifica se è possibile che essi siano le lunghezze dei tre lati di un triangolo
 *             Cio' richiede che ognuno dei tre lati sia minore della somma degli altri 2. Se i tre interi sono le lunghezze dei lati di un triangolo, il programma
 *             stampa a schermo qual e' il carattere di tale triangolo, secondo le seguenti proprieta' :
 *                  - EQUILATERO : i 3 lati hanno lunghezza uguale
 *                  - ISOSCELE : 2 lati su 3 sono uguali
 *                  - SCALENO : tutti e tre i lati sono diversi
 *
 *             In caso contrario venga visualizzato un messaggio di errore seguito dalla terminazione del programma.
 *             Una volta che il programma funzione correttamente, lo si modifichi per utilizzare lunghezze dei lati di tipo float.
 */

//Librerie
#include <stdio.h>

//Definizione funzioni
float getLato(int numero_lato);
void checkLati(float lato1,float lato2,float lato3);

//Main
int main(int argc, char const *argv[]) {
  float lato1,lato2,lato3;

  printf("\nInserisci i lati del triangolo\n");

  lato1 = getLato(1);
  lato2 = getLato(2);
  lato3 = getLato(3);

  checkLati(lato1,lato2,lato3);

  return 0;
}

/*
  getLato : richiede il lato e lo restituisce alla variabile nel main
*/
float getLato(int numero_lato)
{
  float l;

  do {
    printf("\n\tLato %d : ",numero_lato);
    scanf("%f",&l);
  } while(l<=0);

  return l;
}

/*
  checkLati : fa i dovuti controlli: viene inizialmente controllato che il triangolo non sia degenere, e successivamente viene controllato il suo carattere
*/
void checkLati(float lato1,float lato2,float lato3)
{
  if((lato1<lato2+lato3) && (lato2<lato1+lato3) && (lato3<lato1+lato2))
  {
    if((lato1==lato2) && (lato1==lato3)) { printf("\nIl triangolo e' equilatero\n"); }
    else if((lato1==lato2) || (lato1==lato3) || (lato2==lato3)) { printf("\nIl triangolo e' isoscele\n"); }
    else { printf("\nIl triangolo e' scaleno\n"); }
  } else {
    printf("\nERRORE : TRIANGOLO DEGENERE\nInterruzione programma\n");
  }
}
