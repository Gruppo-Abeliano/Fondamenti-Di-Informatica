/*
  Autore : Paolo Pertino
  Descrizione : La funzione checkSimmetrica restituisce true se la matrice passata come parametro è simmetrica, o false se non
                lo è.
*/

#include <stdio.h>

#define DIMENSIONE 3

typedef int vettore[DIMENSIONE];
typedef vettore matrice[DIMENSIONE];
typedef enum{false,true}bool;
typedef int Contatore;

void creaMatrice(matrice daCompilare);
void stampaMatrice(matrice daStampare);
bool checkSimmetrica(matrice toCheck,int dimensione);

int main(int argc, char const *argv[]) {
  matrice matriceIniziale;
  bool isSimmetrica;

  creaMatrice(matriceIniziale);
  stampaMatrice(matriceIniziale);

  isSimmetrica = checkSimmetrica(matriceIniziale,DIMENSIONE);

  if(isSimmetrica==true) printf("\nSimmetrica");
  else printf("\nNon simmetrica");
  return 0;
}

bool checkSimmetrica(matrice toCheck,int dimensione)
{
  bool simmetrica;
  Contatore cursore;

  if(dimensione == 1) return true;

  simmetrica = true;
  for(cursore = DIMENSIONE-dimensione;cursore<DIMENSIONE;cursore++)
  {
    if(toCheck[DIMENSIONE-dimensione][cursore] != toCheck[cursore][DIMENSIONE-dimensione])
    {
      simmetrica = false;
    }
  }

  if(simmetrica == false) return false;
  else return(checkSimmetrica(toCheck,dimensione-1));
}

void creaMatrice(matrice daCompilare)
{
  Contatore scorriRiga,scorriColonna;

  for(scorriRiga=0;scorriRiga<DIMENSIONE;scorriRiga++)
  {
    for(scorriColonna=0;scorriColonna<DIMENSIONE;scorriColonna++)
    {
      printf("Inserisci il valore nella cella [%d:%d] : ",scorriRiga+1,scorriColonna+1);
      scanf("%d",&daCompilare[scorriRiga][scorriColonna]);
    }
  }
}

void stampaMatrice(matrice daStampare)
{
  Contatore scorriRiga,scorriColonna;

  for(scorriRiga=0;scorriRiga<DIMENSIONE;scorriRiga++)
  {
    for(scorriColonna=0;scorriColonna<DIMENSIONE;scorriColonna++)
    {
      printf("%d\t",daStampare[scorriRiga][scorriColonna]);
    }
    printf("\n");
  }
}
