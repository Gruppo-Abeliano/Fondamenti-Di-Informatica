/*
  Autore: Paolo Pertino
  Esercizio 4 - Tema Esame 03-07-2017
  Descrizione: data una sequenza di massimo 500 caratteri scritti in ordine alfabetico in un file di testo
               (eventualmente ripetuti), viene scritto su un secondo file in ordine alfabetico inverso, i
               caratteri del file di partenza e quante volte essi si ripetono.

  Tempo di esecuzione: 18 minuti
*/

#include <stdio.h>

#define INPUT_PATH "./input.txt"
#define OUTPUT_PATH "./output.txt"
#define MAX_LENGHT 500

int main(int argc, char const *argv[]) {
  FILE *fInput,*fOutput;
  char stringa[MAX_LENGHT+1]; //Viene inserito il + 1 per contenere il carattere \0
  int contaRicorrenze;
  int cursoreStringa;

  /*
    Apro il file e controllo l'avvenuta apertura
  */

  fInput = fopen(INPUT_PATH,"r");
  fOutput = fopen(OUTPUT_PATH,"w");

  if(fInput == NULL)
  {
    printf("Errore in apertura del file di input.");
    return 1;
  } else if(fOutput == NULL)
  {
    printf("Errore in apertura del file di output.");
    return 1;
  }

  /*
    Inserisco nella stringa il contenuto del file di input.
    Mi sposto alla fine della stringa, per poterla successivamente scorrere in ordine alfabetico inverso.
  */

  fgets(stringa,MAX_LENGHT+1,fInput);

  cursoreStringa = 0;
  while(stringa[cursoreStringa] != '\0')
  {
    ++cursoreStringa;
  }

  cursoreStringa -= 2; //Sposto il cursore sull'ultimo carattere utile

  /*
    Scorro all'indietro la stringa e tengo conto di quanti caratteri uguali ci sono.
    Scrivo mano a mano sul file i risultati richiesti.
  */

  while(cursoreStringa >= 0)
  {
    contaRicorrenze = 1;
    while(cursoreStringa > 0 && stringa[cursoreStringa] == stringa[cursoreStringa-1])
    {
      ++contaRicorrenze;
      --cursoreStringa;
    }

    fprintf(fOutput," %c%d \n",stringa[cursoreStringa],contaRicorrenze);
    --cursoreStringa;
  }

  /*
    Chiudo i file aperti e gestisco eventuali errori.
  */

  if(fclose(fInput) != 0)
  {
    printf("Errore nella chiusura del file di input.");
    return 2;
  }
  if(fclose(fOutput) != 0)
  {
    printf("Errore nella chiusura del file di output.");
    return 2;
  }

  return 0;
}
