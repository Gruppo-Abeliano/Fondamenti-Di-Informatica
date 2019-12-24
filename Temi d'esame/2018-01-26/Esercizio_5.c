/*
  Autore: Paolo Pertino
  Esercizio 5 - Tema Esame 26-01-2018
  Descrizione: Dato un file contenente caratteri e il proprio numero di matricola in input, il programma
               verifica che tutte le cifre(lette sottoforma di caratteri) sono presenti almeno una volta
               all'interno del contenuto del file di input. Se così è viene stampato a schermo OK,
               altrimenti KO.

  Tempo esecuzione: 17 minuti
*/

#include <stdio.h>

#define INPUT_PATH "input.txt"
#define MAX_LENGHT 6

typedef enum{false,true}bool;

int main(int argc, char const *argv[]) {
  FILE *fInput;
  char numeroMatricola[MAX_LENGHT+1];
  char currentChar,fileCurrentChar;
  bool eContenuto,trovatoCorrente;
  int cursoreStringa;

  /*
    Chiedo all'utente di inserire il proprio numero di matricola.
    Lo salvo in una stringa di massimo 6 + 1 caratteri dove il + 1 è per il carattere \0
  */

  printf("Inserisci il tuo numero di matricola : ");
  scanf("%s",numeroMatricola);

  /*
    Apro il file di input e gestisco eventuali errori di apertura.
  */

  fInput = fopen(INPUT_PATH,"r");
  if(fInput == NULL)
  {
    printf("KO");
    return 1;
  }

  /*
    Scorro il numero di matricola escluso il carattere \0
  */
  cursoreStringa = 0;
  eContenuto = true;
  while(numeroMatricola[cursoreStringa] != '\0' && eContenuto == true)
  {
    /*
      Controllo carattere per carattere a partire dall'inizio del file tutti i caratteri presenti in tale file.
      Se il carattere del numero di matricola non compare esco dal ciclo.
    */
    trovatoCorrente = false;
    currentChar = numeroMatricola[cursoreStringa];
    rewind(fInput); //Ad ogni ciclo resetto il cursore del file all'inizio.
    while(((fileCurrentChar = fgetc(fInput)) != EOF) && trovatoCorrente == false)
    {
      if(currentChar == fileCurrentChar) trovatoCorrente = true;
    }

    if(trovatoCorrente == false) eContenuto = false;

    ++cursoreStringa;
  }

  /*
    Chiudo il file e gestisco eventuali errori.
  */
  if(fclose(fInput) != 0)
  {
    printf("Errore in chiusura del file.");
    return 2;
  }

  /*
    Output phase
  */
  if(eContenuto == true) printf("OK");
  else printf("KO");

  return 0;
}
