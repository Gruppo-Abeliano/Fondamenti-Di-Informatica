/***
    Author : Paolo Pertino

    Name : Contour Filling
    Type : Esercizio Prova Esame - Fondamenti di Informatica
    
***/

//Librerie
#include <stdio.h>

//Definizione costanti
#define MAX_SIZE 12
#define BORDER -1

//Definizione tipo matrice di taglia costante impostata
typedef int matrice[MAX_SIZE][MAX_SIZE];
typedef enum{false,true} bool;

//Definizione funzioni
void mostraMatrice (matrice mat);
void contourFilling (matrice mat);


//Main
int main(int argc, char const *argv[]) {
  matrice mat={
    {0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,-1,-1,-1,-1,0,0,0,0},
    {0,0,-1,-1,1,1,1,1,-1,0,0,0},
    {0,-1,1,1,0,0,0,0,1,-1,0,0},
    {-1,1,0,0,0,1,1,0,0,1,-1,0},
    {-1,1,0,0,1,-1,-1,1,0,1,-1,0},
    {0,-1,1,0,0,1,1,0,0,1,-1,0},
    {-1,1,0,0,0,0,0,0,0,0,1,-1},
    {-1,1,1,0,1,1,1,1,0,1,-1,0},
    {0,-1,-1,1,-1,-1,-1,-1,1,1,-1,0},
    {0,0,0,-1,0,0,0,0,-1,-1,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0}
  };

  contourFilling(mat);
  mostraMatrice(mat);

  return 0;
}

//Funzioni

/*** mostraMatrice : Visualizza la matrice completa passata alla funzione ***/
void mostraMatrice(matrice mat)
{
  int i,j;

  i=0;
  while (i<MAX_SIZE)
  {
    j=0;
    while(j<MAX_SIZE)
    {
      printf("%d\t",mat[i][j]);
      j++;
    }
    printf("\n\n\n");
    i++;
  }
}

/*** contourFilling : esegue l'algoritmo per riempire gli spazi all'interno del contorno definito ***/
void contourFilling(matrice mat)
{
  int i,j,k;                              //Contatori Utilizzati per scorrere i valori della matrice
  bool interno=false;                     //Variabile booleana per vedere quando mi trovo dentro al contorno

  /*
    1. Viene definito se nella cella corrente è presente un bordo(-1)
    2. Se alla sua destra è presente il corrispettivo bordo interno(1) allora si entra nel ciclo di riempimento
       N.B: Se nella cella successiva al bordo esterno vi è un altro bordo esterno, non si entra nel ciclio suddetto.
    3. Per ogni valore della regione aggiornato si controlla che non vi sia alla sua destra un bordo esterno. Se vi si
       presenta allora viene aggiornata la variabile booleana per uscire dal ciclo di riempimento.
    4. Una volta riempita la riga interessata, i bordi esterni utilizzati nel confronto vengono annullati.
  */

  i=0;
  while (i<MAX_SIZE)
  {
    j=0;
    while(j<MAX_SIZE)
    {
      if (mat[i][j]==BORDER)
      {
        if (mat[i][j+1]==1)
        {
          interno=true;
          k=j+1;
        }
        mat[i][j]=0;
      }
      while (interno==true && k<(MAX_SIZE-1))
      {
        mat[i][k]=1;
        if (mat[i][k]==1 && mat[i][k+1]==BORDER)
        {
          interno=false;
          mat[i][k+1]=0;
        }
        k++;
      }
      j++;
    }
    i++;
  }
}
