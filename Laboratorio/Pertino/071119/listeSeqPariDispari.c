#include <stdio.h>
#include <stdlib.h>

#define NUM_ELEM 10

typedef int Vettore[NUM_ELEM];
typedef int Contatore;
typedef enum{false,true} bool;
typedef enum{pari,dispari,ingresso} typeOfVect;
typedef struct {
  Vettore lista;
  int numeroElementi;
} ListaInteri;

void compilaLista(ListaInteri *Ingresso,int daInserire,bool daUtente);
void analisiLista(ListaInteri *Ingresso,ListaInteri *Pari,ListaInteri *Dispari);
void leggiLista(ListaInteri *daLeggere,typeOfVect tipoVettore);

int main(int argc, char const *argv[]) {
  ListaInteri Ingresso,Pari,Dispari;

  Pari.numeroElementi = 0;
  Dispari.numeroElementi = 0;

  compilaLista(&Ingresso,0,true);
  analisiLista(&Ingresso,&Pari,&Dispari);
  leggiLista(&Ingresso,ingresso);
  leggiLista(&Pari,pari);
  leggiLista(&Dispari,dispari);
  return 0;
}

void compilaVettore(ListaInteri *Ingresso,int daInserire,bool daUtente)
{
  Contatore indiceArray;
  int numeroElementiDaInserire;

  if(daUtente == true)
  {
    (*Ingresso).numeroElementi = 0;

    do {
      printf("\nQuanti elementi vuoi inserire nella lista?");
      scanf("%d",&numeroElementiDaInserire);

      if(numeroElementiDaInserire<0) printf("\nValore non valido");
    } while(numeroElementiDaInserire>=0);

    while(numeroElementiDaInserire > 0)
    {
      printf("\nInserisci il %d elemento : ",((*Ingresso).numeroElementi + 1));
      scanf("%d", Ingresso.lista[(*Ingresso).numeroElementi]);

      ++(*Ingresso).numeroElementi;
      --numeroElementiDaInserire;
    }
  } else {
    (*Ingresso).lista[(*Ingresso).numeroElementi] = daInserire;
    ++(*Ingresso).numeroElementi;
  }
}

void analisiVettore(ListaInteri *Ingresso,ListaInteri *Pari,ListaInteri *Dispari)
{
  Contatore indiceLista;

  for(indiceLista = 0;indiceLista<(*Ingresso).numeroElementi;++indiceLista)
  {
    if((*Ingresso).lista[indiceLista] % 2 == 0)
    {
      compilaVettore(Pari,(*Ingresso).lista[indiceLista],false);
    } else {
      compilaVettore(Dispari,(*Ingresso).lista[indiceLista],false);
    }
  }
}

void leggiVettore(ListaInteri *daLeggere,typeOfVect tipoVettore)
{
  Contatore indiceLista;

  switch (tipoVettore) {
    case pari: printf("\nNumeri pari : "); break;
    case dispari: printf("\nNumeri dispari : "); break;
    case ingresso: printf("\nNumeri inseriti : "); break;
  }

  for(indiceLista=0;indiceLista<(*daLeggere).numeroElementi;++indiceLista)
  {
    printf("%d\t", (*daLeggere).lista[indiceLista]);
  }
}
