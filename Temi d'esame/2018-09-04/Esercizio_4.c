/*
  Autore: Paolo Pertino
  Esercizio 4 - Tema Esame 04-09-2018

  Descrizione: . Si consideri un file binario contenente dati di tipo Dato. Il tipo Dato è una struct
                 composta da due campi: un campo intero chiamato Valore e un campo carattere chiamato
                 Chiave. Il file contiene uno o più di questi dati.

                 Si scriva un programma C che:
                  1. apre un file binario del tipo sopra descritto, situato nella directory corrente,
                     il cui nome è "Archivio";
                  2. legge le struct contenute nel file alla ricerca di quella (se presente) il cui
                     campo Chiave vale '#';
                  3. se tale struct esiste, il programma modifica la prima delle struct contenute nel
                     file, copiando nel suo campo Valore il campo Valore della struct il cui campo
                     Chiave vale '#' (senza modificare le struct successive contenute nel file);
                  4. chiude il file.

                Se il file non contiene alcuna struct il cui campo Chiave vale '#', il programma lascia
                inalterato il file. Se il file contiene più struct il cui campo Chiave vale '#', solo la
                prima di esse viene presa in considerazione.
                Ogniqualvolta esegue operazioni di apertura o chiusura file, il programma deve segnalare
                (con appositi messaggi a schermo) eventuali errori riscontrati nel loro svolgimento.

                Nota: aprendo un file in modalità lettura+scrittura, una operazione di scrittura
                eseguita in testa al file sovrascrive solo il dato situato in testa al file, senza
                alterare la parte restante del file.
*/

#include <stdio.h>

#define INPUT_PATH "./Archivio.bin"
#define CHIAVE '#'

typedef struct
{
  int Valore;
  char Chiave;
} Dato;
typedef enum{false,true}bool;

int main(int argc, char const *argv[]) {
  FILE *fInput;
  Dato datoLetto,datoDaScrivere;
  char chiaveTemp;
  bool chiaveTrovata;
  int tempValore;

  /*
    * Apro il file e gestisco eventuali errori.
  */
  fInput = fopen(INPUT_PATH,"rb+");
  if(fInput == NULL)
  {
    printf("Errore apertura file.");
    return 1;
  }

  /*
    * Cerco la struct contenente la chiave # scorrendo la lista:
    *   -- se essa viene trovata, salvo il valore situato nel campo valore in una variabile
           ausiliaria ed arresto il ciclo di ricerca;
        -- altrimenti proseguo fino a fine file.
  */
  chiaveTrovata = false;
  while(chiaveTrovata == false && fread(&datoLetto,sizeof(Dato),1,fInput) == 1)
  {
    if(datoLetto.Chiave == CHIAVE)
    {
      temp = datoLetto.Valore;
      chiaveTrovata = true;
    }
  }

  /*
    * Se ho trovato la chiave, sostituisco il dato in prima posizione con un nuovo dato dal valore
    * aggiornato.
  */
  if(chiaveTrovata == true)
  {
    /*
      * Resetto il cursore del file ad inizio file e copio la chiave del primo Dato in una variabile
      * temporanea.
    */
    rewind(fInput);
    fread(&datoLetto,sizeof(Dato),1,fInput);
    chiaveTemp = datoLetto.Chiave;

    /*
      * Costruisco il nuovo dato da inserire.
    */
    datoDaScrivere.Valore = tempValore;
    datoDaScrivere.Chiave = chiaveTemp;

    /*
      * Resetto nuovamente il cursore del file e sovrascrivo il primo dato.
    */
    rewind(fInput);
    fwrite(&datoDaScrivere,sizeof(Dato),1,fInput);
  }

  /*
    * Se la chiave non è stata trovata, la lista non è modificata. Rimane da chiudere il file
    * e gestire eventuali errori.
  */
  if(fclose(fInput) != 0)
  {
    printf("Errore in chiusura file.");
    return 1;
  }
  
  return 0;
}
