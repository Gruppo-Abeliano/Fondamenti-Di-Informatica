/*
  Autore : Paolo Pertino
  Esercizio 4 - Tema Esame 02-07-2018
  Descrizione : dato un file di input contenente una lista di coppie di valori interi, essa controlla
                se queste seguono la regola del domino oppure no (vedere file pdf allegato per pià info)
*/

#include <stdio.h>

#define INPUT_PATH "./input.txt"
#define ZERO 48

typedef enum{false,true}bool;

bool checkCatena(FILE *stream);

int main(int argc, char const *argv[]) {
  FILE *fInput;
  bool isCatena;

  /*
    Apro il file e controllo che l'apertura venga effettuata correttamente.
  */
  fInput = fopen(INPUT_PATH,"r");
  if(fInput == NULL)
  {
    printf("Errore durante l'apertura del file.");
    return 1;
  }

  /*
    Controllo se il file che mi è stato passato contiene una catena oppure no attraverso una funzione ausiliaria
  */
  isCatena = checkCatena(fInput);

  /*
    Chiudo il file e controllo l'avvenuta chiusura.
  */

  if(fclose(fInput) == EOF)
  {
    printf("Errore nella fase di chiusura del file.");
    return 1;
  }

  /*
    Gestisco il risultato ottenuto.
  */
  if(isCatena == true) printf("Il file passato in input contiene una catena.");
  else printf("Il file passato in input non contiene una catena.");

  return 0;
}

bool checkCatena(FILE *stream)
{
  int primoNumero,numeroCorrente,numeroSuccessivo;

  /*
    Prendo il primo carattere utile e lo ignoro.Mi interessano dal secondo in poi.
    Controllo inoltre che la lista sia valida ed inserita correttamente.
  */
  if(fscanf(stream,"(%d",&primoNumero) != 1)
  {
    printf("\nLista vuota.");
    return false;
  }

  /*
    Inizio a scorrere i numeri a due a due e faccio i dovuti controlli. Prendendo i numeri in questo modo
    riesco a controllare ad ogni ciclo l'ultimo numero della coppia corrente con il primo della coppia
    successiva.
  */
  while(fscanf(stream,",%d)(%d",&numeroCorrente,&numeroSuccessivo) == 2)
  {
    if(numeroCorrente != numeroSuccessivo) return false;
  }

  return true;
}
