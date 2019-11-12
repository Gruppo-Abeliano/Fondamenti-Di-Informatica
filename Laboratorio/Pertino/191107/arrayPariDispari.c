#include <stdio.h>
#include <stdlib.h>

#define NUM_ELEM 10

typedef int Vettore[NUM_ELEM];
typedef int Contatore;
typedef enum{false,true} bool;
typedef enum{pari,dispari,ingresso} typeOfVect;

void compilaVettore(Vettore Ingresso,int daInserire,int startOfArray,int SizeOfArray,bool daUtente);
void analisiVettore(Vettore Ingresso,Vettore Pari,Vettore Dispari,int *PariInseriti,int *DispariInseriti);
void leggiVettore(Vettore daLeggere,int SizeOfArray,typeOfVect tipoVettore);

int main(int argc, char const *argv[]) {
  Vettore Ingresso,Pari,Dispari;
  int PariInseriti,DispariInseriti;

  PariInseriti = 0;
  DispariInseriti = 0;

  compilaVettore(Ingresso,0,0,NUM_ELEM,true);
  analisiVettore(Ingresso,Pari,Dispari,&PariInseriti,&DispariInseriti);
  leggiVettore(Ingresso,NUM_ELEM,ingresso);
  leggiVettore(Pari,PariInseriti,pari);
  leggiVettore(Dispari,DispariInseriti,dispari);
  return 0;
}

void compilaVettore(Vettore Ingresso,int daInserire,int startOfArray,int SizeOfArray,bool daUtente)
{
  Contatore indiceArray;

  if(daUtente == true)
  {
    for(indiceArray = startOfArray;indiceArray<SizeOfArray;++indiceArray)
    {
      printf("\nInserisci il %d elemento : ",indiceArray+1);
      scanf("%d", &Ingresso[indiceArray]);
    }
  } else {
    for(indiceArray = startOfArray;indiceArray<SizeOfArray;++indiceArray)
    {
      Ingresso[indiceArray] = daInserire;
    }
  }
}

void analisiVettore(Vettore Ingresso,Vettore Pari,Vettore Dispari,int *PariInseriti,int *DispariInseriti)
{
  Contatore indiceArray;

  for(indiceArray = 0;indiceArray<NUM_ELEM;++indiceArray)
  {
    if(Ingresso[indiceArray] % 2 == 0)
    {
      ++(*PariInseriti);
      compilaVettore(Pari,Ingresso[indiceArray],(*PariInseriti)-1,NUM_ELEM,false);
    } else {
      ++(*DispariInseriti);
      compilaVettore(Dispari,Ingresso[indiceArray],(*DispariInseriti)-1,NUM_ELEM,false);
    }
  }
}

void leggiVettore(Vettore daLeggere,int SizeOfArray,typeOfVect tipoVettore)
{
  Contatore indiceArray;

  switch (tipoVettore) {
    case pari: printf("\nNumeri pari : "); break;
    case dispari: printf("\nNumeri dispari : "); break;
    case ingresso: printf("\nNumeri inseriti : "); break;
  }

  for(indiceArray=0;indiceArray<SizeOfArray;++indiceArray)
  {
    printf("%d\t", daLeggere[indiceArray]);
  }
}
