/***
    Author : Paolo Pertino

    Name : Path Planning
    Type : Esercizio Prova Esame - Fondamenti di Informatica

***/

//Librerie Utilizzate
#include <stdio.h>
#include <stdlib.h>

//Definizione Costanti
#define MAX_SIZE 10                                   //Dimensione della matrice
#define EMPTY_CELL -1                                 //Cella a cui deve essere ancora assegnato il valore
#define OSTACOLO 1000                                 //Cella contenente un ostacolo

//Definizione tipi
typedef int matriceInt[MAX_SIZE][MAX_SIZE];

//Definizione funzioni utilizzate
void leggiMatrice(matriceInt mat,int type);
void pathLenght(matriceInt mat);
void cercaMeta(matriceInt mat, int* coordMetaX, int* coordMetaY);
void pathSearch(matriceInt mat);
void clearScreen();

//Main
int main(int argc, char const *argv[]) {
  matriceInt mat = {
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
  char scelta;

  pathLenght(mat);
  leggiMatrice(mat,0);

  printf("\nVuoi visualizzare il tragitto da percorrere da un determinato punto di partenza?\n\na. Si\nb. No\n\nScelta : ");
  scanf("%c",&scelta);

  if (scelta=='a')
  {
    pathSearch(mat);
    leggiMatrice(mat,1);
  } else {
    printf("\nInterruzione programma\n");
  }

  return 0;
}

//Funzioni

/*** leggiMatrice : stampa a schermo la matrice passata come argomento ***/
void leggiMatrice(matriceInt mat,int type)
{
  int i,j;

  i=0;
  while (i<MAX_SIZE)
  {
    j=0;
    while (j<MAX_SIZE)
    {
      switch(type)
      {
        case 0: printf("%d\t",mat[i][j]); break;
        case 1: printf("%c\t",(char) mat[i][j]); break;
      }
      j++;
    }
    printf("\n");
    i++;
  }
}

/*** pathLenght : esegue l'algoritmo risolutore dell'esercizio per assegnare alle celle il valore della loro distanza dal punto meta 0 ***/
void pathLenght(matriceInt mat)
{
  int i,j;                                                      //Definisco i contatori utilizzati
  int currentMaxDistance;
  int empty_cells;

  empty_cells=1;
  currentMaxDistance=0;

  do
  {
    empty_cells=0;
    i=0;
    while(i<MAX_SIZE)
    {
      j=0;
      while(j<MAX_SIZE)
      {
        if (mat[i][j]==EMPTY_CELL) {empty_cells++;}
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
  } while(empty_cells != 0);
}

/*** cercaMeta : individua la posizione nella matrice della meta impostata ***/
void cercaMeta(matriceInt mat, int* coordMetaX, int* coordMetaY)
{
  int i,j;

  i=0;
  while(i<MAX_SIZE)
  {
    j=0;
    while(j<MAX_SIZE)
    {
      if(mat[i][j] == 0)
      {
        *coordMetaX = i;
        *coordMetaY = j;
      }
      j++;
    }
    i++;
  }
}

/*** pathSearch : esegue l'algoritmo per la costruzione del percorso da una determinata cella di partenza ***/
void pathSearch(matriceInt mat)
{
  int minimo;                                               //Utilizzata per storare il valore minimo delle celle adiacenti
  int rigaCercata,colonnaCercata,x,y;                       //Coordinate del punto di partenza
  int metaX,metaY;                                          //Coordinate della meta - vedi cercaMeta
  int i,j;                                                  //Contatori utilizzati

  clearScreen();

  printf("\nScegli la posizione da cui partire indicandone le coordinate\n\n Inserisci la riga : ");
  scanf("%d",&rigaCercata);
  printf("\nInserisci la colonna : ");
  scanf("%d",&colonnaCercata);

  x = rigaCercata - 1;
  y = colonnaCercata - 1;

  if(mat[x][y] != OSTACOLO && mat[x][y] != 0) {
    mat[x][y] = 'P';

    cercaMeta(mat,&metaX,&metaY);

    while(mat[metaX][metaY] == 0)                               //Serie di controlli sulle celle per individuare quella con valore minimo, e riassegnamento caratteri
    {
      if(mat[x][y]==0)
      {
        mat[x][y]='G';
      } else {
        if (mat[x-1][y]<=mat[x+1][y] && mat[x-1][y]<=mat[x][y-1] && mat[x-1][y]<=mat[x][y+1]) {
          mat[x][y]='^';
          x=x-1;
        } else if(mat[x+1][y]<=mat[x-1][y] && mat[x+1][y]<=mat[x][y-1] && mat[x+1][y]<=mat[x][y+1]) {
          mat[x][y]='v';
          x=x+1;
        } else if(mat[x][y-1]<=mat[x][y+1] && mat[x][y-1]<=mat[x+1][y] && mat[x][y-1]<=mat[x-1][y]) {
          mat[x][y]='<';
          y=y-1;
        } else if(mat[x][y+1]<=mat[x][y-1] && mat[x][y+1]<=mat[x+1][y] && mat[x][y+1]<=mat[x-1][y]) {
          mat[x][y]='>';
          y=y+1;
        }
      }
    }
    i=0;
    while(i<MAX_SIZE)                                                           //Ultima rilettura della matrice per riformattarla con i caratteri corretti
    {
      j=0;
      while(j<MAX_SIZE)
      {
        if(mat[i][j]==OSTACOLO) { mat[i][j]='*'; }
        if(mat[i][j]!='<' && mat[i][j]!='>' && mat[i][j]!='v' && mat[i][j]!='^' && mat[i][j]!='P' && mat[i][j]!='G' && mat[i][j]!='*') { mat[i][j]='-'; }
        j++;
      }
      i++;
    }
  }
}

/*** clearScreen : pulisce il terminale ***/
void clearScreen()
{
  system("cls");
}
