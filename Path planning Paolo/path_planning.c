/***
    Author : Paolo Pertino

    Name : Path Planning
    Type : Esercizio Prova Esame - Fondamenti di Informatica

***/

//Librerie Utilizzate
#include <stdio.h>

//Definizione Costanti
#define MAX_SIZE 10                                   //Dimensione della matrice
#define EMPTY_CELL -1                                 //Cella a cui deve essere ancora assegnato il valore
#define OSTACOLO 1000                                 //Cella contenente un ostacolo

//Definizione tipi
typedef int matrice[MAX_SIZE][MAX_SIZE];

//Definizione funzioni utilizzate
void leggiMatrice(matrice mat);
void pathLenght(matrice mat);

//Main
int main(int argc, char const *argv[]) {
  matrice mat = {
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,0,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,1000,1000,1000,-1,-1,-1,-1},
    {-1,-1,-1,1000,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,1000,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,1000,1000,1000,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
  };

  pathLenght(mat);
  leggiMatrice(mat);
  return 0;
}

//Funzioni

/*** leggiMatrice : stampa a schermo la matrice passata come argomento ***/
void leggiMatrice(matrice mat)
{
  int i,j;

  i=0;
  while (i<MAX_SIZE)
  {
    j=0;
    while (j<MAX_SIZE)
    {
      printf("%d\t",mat[i][j]);
      j++;
    }
    printf("\n");
    i++;
  }
}

/*** pathLenght : esegue l'algoritmo risolutore dell'esercizio per assegnare alle celle il valore della loro distanza dal punto meta 0 ***/
void pathLenght(matrice mat)
{
  int i,j;                                                      //Definisco i contatori utilizzati
  int currentMaxDistance;

  currentMaxDistance=0;
  while(currentMaxDistance<(MAX_SIZE*2))
  {
    i=0;
    while(i<MAX_SIZE)
    {
      j=0;
      while(j<MAX_SIZE)
      {
        /*
          La matrice viene ciclata MAX_SIZE*2 volte e ad ogni ciclo si occupa dell'aggiornamento delle celle
          adiacenti a quelle che hanno valore pari a currentMaxDistance, solo se esse sono vuote ed assumono
          valore diverso da OSTACOLO
        */
        if(mat[i][j]==currentMaxDistance)
        {
          if((mat[i][j-1] != OSTACOLO) && (mat[i][j-1] == EMPTY_CELL)) {mat[i][j-1]=currentMaxDistance+1;}
          if((mat[i][j+1] != OSTACOLO) && (mat[i][j+1] == EMPTY_CELL)) {mat[i][j+1]=currentMaxDistance+1;}
          if((mat[i-1][j] != OSTACOLO) && (mat[i-1][j] == EMPTY_CELL)) {mat[i-1][j]=currentMaxDistance+1;}
          if((mat[i+1][j] != OSTACOLO) && (mat[i+1][j] == EMPTY_CELL)) {mat[i+1][j]=currentMaxDistance+1;}
        }
        j++;
      }
      i++;
    }
    currentMaxDistance++;
  }

}
