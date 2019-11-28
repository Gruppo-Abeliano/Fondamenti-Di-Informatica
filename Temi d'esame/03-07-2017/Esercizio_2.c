/*
  Autore : Paolo Pertino
  Esercizio 2 - Tema Esame 03-07-2017
  Descrizione : data una matrice di dimensione NxN, la funzione differenzaDiagonali calcola la differenza
                tra la somma degli elementi sulla diagonale principale e la somma degli elementi sulla
                diagonale secondaria.
*/

#include <stdio.h>
#include <stdlib.h>

#define N 4

typedef int array[N];
typedef array matrice[N];

int differenzaDiagonali(matrice matrix,int inizio,int fine);
void compilaMatrice(matrice toCompile);
void leggiMatrice(matrice toRead);
void clearScreen();

int main(int argc, char const *argv[]) {
  matrice mat;
  int differenza;

  //INPUT PHASE
  compilaMatrice(mat);
  clearScreen();
  leggiMatrice(mat);

  //ELABORAZIONE
  differenza = differenzaDiagonali(mat,0,N-1);

  //OUTPUT PHASE
  printf("\nLa differenza tra la somma degli elementi della diagonale principale e quelli della diagonale secondaria e' %d",differenza);

  return 0;
}

int differenzaDiagonali(matrice matrix,int inizio,int fine)
{
  int sommaPrincipale,sommaSecondaria,differenza;

  differenza = 0;

  if(inizio >= fine) return differenza; //caso base - restituisce 0 quando gli indici si scambiano di parte o quando sono uguali

  sommaPrincipale = matrix[inizio][inizio] + matrix[fine][fine];
  sommaSecondaria = matrix[inizio][fine] + matrix[fine][inizio];

  differenza = sommaPrincipale - sommaSecondaria;
  differenza += differenzaDiagonali(matrix,inizio+1,fine-1);

  return differenza;
}

void compilaMatrice(matrice toCompile)
{
  int scorriRighe,scorriColonne;

  for(scorriRighe=0;scorriRighe<N;scorriRighe++)
  {
    for(scorriColonne=0;scorriColonne<N;scorriColonne++)
    {
      printf("Inserisci l'elemento nella cella (%d,%d) : ",scorriRighe+1,scorriColonne+1);
      scanf("%d",&toCompile[scorriRighe][scorriColonne]);
    }
  }
}

void leggiMatrice(matrice toRead)
{
  int scorriRighe,scorriColonne;

  printf("Matrice :\n\n");
  for(scorriRighe=0;scorriRighe<N;scorriRighe++)
  {
    for(scorriColonne=0;scorriColonne<N;scorriColonne++)
    {
      printf("%d\t",toRead[scorriRighe][scorriColonne]);
    }
    printf("\n");
  }
}

void clearScreen()
{
  system("@cls||clear");
}
