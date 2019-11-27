#include <stdio.h>
#include <stdlib.h>

#define DIMENSIONE 4

typedef int array[DIMENSIONE];
typedef array matrice[DIMENSIONE];
typedef enum{false,true}bool;
typedef struct
{
  matrice matriceModificata;
  bool isMassimo[DIMENSIONE][DIMENSIONE];
} matriceMassimiLocali;
typedef int contatore;

void compilaMatrice(matrice toCompile);
void leggiMatrice(matrice toRead);
matriceMassimiLocali modificaMatrice(matrice mat);

int main(int argc, char const *argv[]) {
  matrice matrix;
  matriceMassimiLocali nuovaMatrice;

  compilaMatrice(matrix);
  leggiMatrice(matrix);
  nuovaMatrice = modificaMatrice(matrix);
  leggiMatrice(nuovaMatrice.matriceModificata);
  return 0;
}

matriceMassimiLocali modificaMatrice(matrice mat)
{
  contatore i,j;
  matriceMassimiLocali newMat;

  for(i=0;i<DIMENSIONE;i++)
  {
    for(j=0;j<DIMENSIONE;j++)
    {
      newMat.matriceModificata[i][j] = mat[i][j];
      newMat.isMassimo[i][j] = false;
      if(i==0)
      {
        if(j==0)
        {
          if(mat[i][j]>mat[i+1][j] && mat[i][j]>mat[i][j+1] && mat[i][j]>mat[i+1][j+1]) newMat.isMassimo[i][j]=true;
        } else if(j==DIMENSIONE-1) {
          if(mat[i][j]>mat[i+1][j] && mat[i][j]>mat[i][j-1] && mat[i][j]>mat[i+1][j-1]) newMat.isMassimo[i][j]=true;
        } else {
          if(mat[i][j]>mat[i][j-1] && mat[i][j]>mat[i][j+1] && mat[i][j]>mat[i+1][j-1] && mat[i][j]>mat[i+1][j] && mat[i][j]>mat[i+1][j+1]) newMat.isMassimo[i][j]=true;
        }
      } else if(i==DIMENSIONE-1) {
        if(j==0)
        {
          if(mat[i][j]>mat[i-1][j] && mat[i][j]>mat[i-1][j+1] && mat[i][j]>mat[i][j+1]) newMat.isMassimo[i][j]=true;
        } else if(j==DIMENSIONE-1) {
          if(mat[i][j]>mat[i-1][j] && mat[i][j]>mat[i][j-1] && mat[i][j]>mat[i-1][j-1]) newMat.isMassimo[i][j]=true;
        } else {
          if(mat[i][j]>mat[i][j-1] && mat[i][j]>mat[i][j+1] && mat[i][j]>mat[i-1][j-1] && mat[i][j]>mat[i-1][j+1] && mat[i][j]>mat[i-1][j]) newMat.isMassimo[i][j]=true;
        }
      } else {
        if(j==0)
        {
          if(mat[i][j]>mat[i+1][j] && mat[i][j]>mat[i+1][j+1] && mat[i][j]>mat[i][j+1] && mat[i][j]>mat[i-1][j+1] && mat[i][j]>mat[i-1][j]) newMat.isMassimo[i][j]=true;
        } else if(j==DIMENSIONE-1)
        {
          if(mat[i][j]>mat[i-1][j] && mat[i][j]>mat[i-1][j-1] && mat[i][j]>mat[i][j-1] && mat[i][j]>mat[i+1][j-1] && mat[i][j]>mat[i+1][j]) newMat.isMassimo[i][j]=true;
        } else {
          if(mat[i][j]>mat[i-1][j-1] && mat[i][j]>mat[i-1][j] && mat[i][j]>mat[i-1][j+1] && mat[i][j]>mat[i][j-1] && mat[i][j]>mat[i][j+1] && mat[i][j]>mat[i+1][j-1] && mat[i][j]>mat[i+1][j] && mat[i][j]>mat[i+1][j+1]) newMat.isMassimo[i][j]=true;
        }
      }

      if(newMat.isMassimo[i][j]==false) newMat.matriceModificata[i][j]=0;
    }
  }

  return newMat;
}

void compilaMatrice(matrice toCompile)
{
  contatore scorriRiga,scorriColonna;

  for(scorriRiga=0;scorriRiga<DIMENSIONE;scorriRiga++)
  {
    for(scorriColonna=0;scorriColonna<DIMENSIONE;scorriColonna++)
    {
      printf("Inserisci un valore nella cella (%d,%d) : ",scorriRiga+1,scorriColonna+1);
      scanf("%d",&(toCompile[scorriRiga][scorriColonna]));
    }
  }
}

void leggiMatrice(matrice toRead)
{
  contatore scorriRiga,scorriColonna;

  printf("\n\nMatrice :\n");
  for(scorriRiga=0;scorriRiga<DIMENSIONE;scorriRiga++)
  {
    for(scorriColonna=0;scorriColonna<DIMENSIONE;scorriColonna++)
    {
      printf("%d\t",toRead[scorriRiga][scorriColonna]);
    }
    printf("\n");
  }
}
