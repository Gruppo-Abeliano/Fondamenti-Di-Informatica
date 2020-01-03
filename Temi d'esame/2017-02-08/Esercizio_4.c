/*
  Autore: Paolo Pertino
  Esercizio 4 - Tema esame 2017-02-08

  Descrizione: data una matrice in ingresso quadrata di ordine N alla funzione checkSimmetrica, essa
               restituisce true, se la matrice è simmetrica o false se non lo è.
               La funzione opera in modo ricorsivo.
*/

#include <stdio.h>
#include <stdlib.h>

#define N 3

typedef int Vettore[N];
typedef Vettore Matrice[N];
typedef enum{false,true}bool;

void compilaMatrice(Matrice daCompilare);
void leggiMatrice(Matrice daLeggere);
bool checkSimmetrica(Matrice mat,int dimensione);
void clearScreen();

int main(int argc, char const *argv[]) {
  Matrice matrice;
  bool isSimmetrica;

  /*
    Compilo la matrice e la stampo a schermo
  */
  compilaMatrice(matrice);
  clearScreen();
  leggiMatrice(matrice);

  /*
    Eseguo il controllo in modo ricorsivo, utilizzando l'apposita funzione.
  */
  isSimmetrica = checkSimmetrica(matrice,0);

  /*
    Gestisco il risultato ottenuto.
  */
  if(isSimmetrica == true) printf("\nLa matrice inserita e' simmetrica.");
  else printf("\nLa matrice inserita non e' simmetrica.");

  return 0;
}

bool checkSimmetrica(Matrice mat,int dimensione)
{
  int cursore;
  bool simmetrica;

  /*
    Se la matrice e' 1X1, allora sicuramente la matrice e' simmetrica.
  */
  if(dimensione == N-1) return true;

  /*
    Controllo singolarmente le righe e le colonne dello stesso indice, e controllo che siano simmetrici
    i loro elementi.
    Se trovo un valore che non rispetta la simmetria restituisco false, altrimenti proseguo.
  */
  cursore = dimensione;
  while(cursore<N)
  {
    if(mat[cursore][dimensione] != mat[dimensione][cursore]) return false;
    ++cursore;
  }

  /*
    Controllo se la matrice più piccola (chiamata ricorsiva) è simmetrica e restituisco il risultato.
  */
  simmetrica = checkSimmetrica(mat,dimensione+1);
  return simmetrica;
}

void compilaMatrice(Matrice daCompilare)
{
  int scorriRighe,scorriColonne;

  for(scorriRighe = 0;scorriRighe < N;scorriRighe++)
  {
    for(scorriColonne = 0;scorriColonne < N;scorriColonne++)
    {
      printf("Inserisci l'elemento [%d:%d] : ",scorriRighe+1,scorriColonne+1);
      scanf("%d",&daCompilare[scorriRighe][scorriColonne]);
    }
  }
}

void leggiMatrice(Matrice daLeggere)
{
  int contaRighe,contaColonne;

  for(contaRighe = 0;contaRighe < N;contaRighe++)
  {
    for(contaColonne = 0;contaColonne < N;contaColonne++)
    {
      printf("%d ",daLeggere[contaRighe][contaColonne]);
    }
    printf("\n");
  }
}

void clearScreen()
{
  system("clear || cls");
}
