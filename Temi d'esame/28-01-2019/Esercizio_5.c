/*
  '#' --> DIRETTIVE
  '/' --> COMMENTI
  altro --> ISTRUZIONI
*/

#include <stdio.h>
#include <string.h>

#define LUNGH_MAX_LINEA 1000
#define INIZIO_DIRETTIVA '#'
#define INIZIO_COMMENTO '/'
#define CARATTERE_SPAZIO ' '

int main(int argc, char const *argv[]) {
  FILE *fInput;
  char LineaCorrente[LUNGH_MAX_LINEA+1];
  char* primoNonSpazio;
  int NumDirettive,NumIstruzioni,NumCommenti,NumCarUtili;
  int LunghLineaCorrente;

  /*
    Il nome del file da aprire viene passato al programma da linea di comando, quindi controllo che esso sia stato
    effettivamente inserito.
  */
  if(argc == 1)
  {
    printf("\nManca il nome file.");
    return 1;
  }

  /*
    Apro il file e controllo che l'apertura sia andata a buon fine.
  */
  fInput = fopen(argv[1],"r");
  if(fInput == NULL)
  {
    printf("\nErrore nell'apertura del file.");
    return 1;
  }

  NumIstruzioni = 0;
  NumDirettive = 0;
  NumCarUtili = 0;
  NumCommenti = 0;

  /*
    Leggo il file scandendolo per linee.
    Devo eliminare per ogni riga il \n perchè se no verrebbe contato come carattere utile. Lo sovrascrivo con \0

    RICORDA : strlen è una funzione che accetta come unico parametro il puntatore a elemento dell'array e inizia a contare
              da lì i caratteri fino ad arrivare a \0. Se io passo la posizione a metà dell'array, lui conterà metà dimensione
              dell'array stesso.
  */
  while(fgets(LineaCorrente,LUNGH_MAX_LINEA+1,fInput) != NULL)
  {
    LineaCorrente[strlen(LineaCorrente)-1] = '\0';        //Sovrascrivo \n
    /*
      Devo mandare avanti primoNonSpazio finchè nell'array iniziale non trovo il primo carattere diverso dallo spazio.
    */
    for(primoNonSpazio = LineaCorrente;*primoNonSpazio==CARATTERE_SPAZIO;++primoNonSpazio);

    LunghezzaCorrente = strlen(primoNonSpazio)-1;
    NumCarUtili += LunghezzaCorrente;

    if(*primoNonSpazio == INIZIO_DIRETTIVA) ++NumDirettive;
    else if(*primoNonSpazio == INIZIO_COMMENTO) ++NumCommenti;
    else if(*primoNonSpazio != '\0') ++NumIstruzioni;
  }

  printf("\nNumero Istruzioni : %d", NumIstruzioni);
  printf("\nNumero Direttive : %d", NumDirettive);
  printf("\nNumero Commenti : %d", NumCommenti);
  printf("\nNumero Caratteri utili : %d",NumCarUtili);

  if(fclose(fInput) != 0)
  {
    printf("\nErrore in fase di chiusura del file.");
    return 1;
  }
  
  return 0;
}
