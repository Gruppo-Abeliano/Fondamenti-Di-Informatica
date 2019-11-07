#include <stdio.h>
#include <stdlib.h>

#define NUM_ELEM 10

typedef int Vettore[NUM_ELEM];
typedef int Contatore;
typedef enum{false,true} bool;
typedef enum{pari,dispari,ingresso} typeOfVector;
typedef struct
{
  Vettore lista;
  int numeroElementi;
} ListaInteri;

void compilaLista(ListaInteri *toCompile,int toInsert,bool fromUser);
void analisiLista(ListaInteri *toAnalize, ListaInteri *Pari, ListaInteri *Dispari);
void leggiLista(ListaInteri *toRead,typeOfVector vectorType);

int main(int argc, char const *argv[]) {
  ListaInteri Ingresso,Pari,Dispari;

  Ingresso.numeroElementi = 0;
  Pari.numeroElementi = 0;
  Dispari.numeroElementi = 0;

  compilaLista(&Ingresso,0,true);
  analisiLista(&Ingresso,&Pari,&Dispari);
  leggiLista(&Ingresso,ingresso);
  leggiLista(&Pari,pari);
  leggiLista(&Dispari,dispari);
  return 0;
}

void compilaLista(ListaInteri *toCompile,int toInsert,bool fromUser)
{
  Contatore contaElementiLista;
  int numeroElementiDaInserire;

  if(fromUser == true)
  {
    do {
      printf("\nQuanti numeri vuoi inserire? (Massimo %d) : ",NUM_ELEM);
      scanf("%d", &numeroElementiDaInserire);

      if(numeroElementiDaInserire<0 || numeroElementiDaInserire>NUM_ELEM) printf("\nValore non valido");
    } while(numeroElementiDaInserire<0 || numeroElementiDaInserire>NUM_ELEM);

    for(contaElementiLista=0;contaElementiLista<numeroElementiDaInserire;contaElementiLista++)
    {
      printf("\nInserisci il %d numero : ", contaElementiLista+1);
      scanf("%d", &toInsert);
      (*toCompile).lista[contaElementiLista] = toInsert;

      ++(*toCompile).numeroElementi;
    }
  } else {
    (*toCompile).lista[(*toCompile).numeroElementi] = toInsert;
    ++(*toCompile).numeroElementi;
  }
}

void analisiLista(ListaInteri *toAnalize, ListaInteri *Pari, ListaInteri *Dispari)
{
  Contatore scorriLista;
  int NumeroElementi;

  for(scorriLista=0;scorriLista<(*toAnalize).numeroElementi;scorriLista++)
  {
    if((*toAnalize).lista[scorriLista] % 2 == 0) compilaLista(Pari,(*toAnalize).lista[scorriLista],false);
    else compilaLista(Dispari,(*toAnalize).lista[scorriLista],false);
  }
}

void leggiLista(ListaInteri *toRead,typeOfVector vectorType)
{
  Contatore scorriLista;

  switch(vectorType)
  {
    case ingresso: printf("\nNumeri inseriti : "); break;
    case pari: printf("\nNumeri pari : "); break;
    case dispari: printf("\nNumeri dispari : "); break;
  }

  for(scorriLista=0;scorriLista<(*toRead).numeroElementi;scorriLista++)
  {
    printf("%d\t",(*toRead).lista[scorriLista]);
  }
}
