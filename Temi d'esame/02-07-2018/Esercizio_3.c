/*
  Autore : Paolo Pertino
  Esercizio 3 - Tema Esame 02-07-2018
  Descrizione: passati due numeri alla funzione Converti, uno rappresentante un numero in base 10, l'altro, un numero che rappresenta
               la base in cui voglio convertire il primo valore, trasforma in modo ricorsivo _int numero_ in base _int base_ e
               accumula i dati in una lista sequenziale ListaConversione.
*/

#include <stdio.h>
#include <stdlib.h>

#define DIMENSIONE_MASSIMA 64

typedef int arrayInteri[DIMENSIONE_MASSIMA];
typedef int Contatore;
typedef struct
{
  arrayInteri numero;
  Contatore numeroElementi;
} ListaConversione;

ListaConversione Converti(int numero,int base,ListaConversione NumeroConvertito);
void leggiLista(ListaConversione toRead);

int main(int argc, char const *argv[]) {
  int numeroDaConvertire;
  int baseConversione;
  ListaConversione numeroConvertito;

  //INPUT PHASE
  printf("Inserisci il numero da convertire : ");
  scanf("%d",&numeroDaConvertire);

  printf("Inserisci la base in cui vuoi convertire il numero : ");
  scanf("%d",&baseConversione);

  //ELABORAZIONE DATI
  numeroConvertito.numeroElementi = 0;
  numeroConvertito = Converti(numeroDaConvertire,baseConversione,numeroConvertito);

  //OUTPUT PHASE
  leggiLista(numeroConvertito);
  return 0;
}

ListaConversione Converti(int numero,int base,ListaConversione NumeroConvertito)
{
  if(numero/base > 0)
  {
    /*
      Prima di inserire il mio(numero%base) resto, lo faccio inserire e chi è più piccolo di me
    */
    NumeroConvertito = Converti(numero/base,base,NumeroConvertito);

    /*
      Una volta fatto posso inserire il mio resto subito dopo.
    */
    NumeroConvertito.numero[NumeroConvertito.numeroElementi] = numero%base;
    ++NumeroConvertito.numeroElementi;
  } else {
    NumeroConvertito.numero[NumeroConvertito.numeroElementi] = numero%base;
    ++NumeroConvertito.numeroElementi;
  }

  return NumeroConvertito;
}

void leggiLista(ListaConversione toRead)
{
  Contatore scorriLista;

  scorriLista = 0;
  while(scorriLista<toRead.numeroElementi)
  {
    printf("|%d|",toRead.numero[scorriLista]);
    ++scorriLista;
  }
}
