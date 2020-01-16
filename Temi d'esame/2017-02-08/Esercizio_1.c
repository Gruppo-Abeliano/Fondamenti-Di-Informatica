/*
  Autore: Paolo Pertino
  Esercizio 1 - Tema esame 2017-02-08

  Descrizione: dato un file di testo in input contenente una serie di numeri interi
               separati dal carattere \n, la funzione creaLista crea una lista
               dinamica i cui nodi contengono i numeri della sequenza e quante volte
               essi si ripetono nella stessa.

  Tempo di esecuzione: 20 minuti
*/
#include <stdio.h>
#include <stdlib.h>

#define INPUT_PATH "./input.txt"

typedef enum{false,true}bool;
typedef struct NODO
{
  int cifra;
  int numeroRipetizioni;
  struct NODO *pProx;
} Cifre;
typedef Cifre *Lista;

Lista creaLista(FILE *input);
void leggiLista(Lista daLeggere);

int main(int argc, char const *argv[]) {
  FILE *fInput;
  Lista listaDinamica;

  /*
    Apro il file e gestisco eventuali errori in apertura.
  */
  fInput = fopen(INPUT_PATH,"r");

  if(fInput == NULL)
  {
    printf("Errore durante l'apertura del file.");
    return 1;
  }

  /*
    Eseguo il compito richiesto,
  */
  listaDinamica = creaLista(fInput);

  /*
    Eseguo l'output della lista appena creata
  */
  leggiLista(listaDinamica);

  return 0;
}

Lista creaLista(FILE *input)
{
  Lista newList,punt,scorriLista;
  bool trovatoCorrente;
  int numeroCorrente;

  /*
    Inizializzo la lista dinamica
  */
  newList = NULL;
  punt = NULL;

  /*
    Scorro il contenuto del file.
  */
  while(fscanf(input,"%d\n",&numeroCorrente) == 1)
  {
    /*
      Gestisco i due possibili casi:
        1. La lista dinamica è vuota, quindi aggiungo subito il primo elemento.
        2. La lista non è vuota, dunque devo controllare se l'elemento è gia presente
    */
    if(newList == NULL)
    {
      punt = malloc(sizeof(Cifre));
      punt->cifra = numeroCorrente;
      punt->numeroRipetizioni = 1;
      punt->pProx = NULL;
      newList = punt;
    } else {
      /*
        Scorro la lista già presente dall'inizio per controllare se il numero che
        sto analizzando è già presente.
        Se è presente incremento semplicemente il contatore, altrimenti lo aggiungo
        alla coda della lista, inizializzando il suo contatore a 1.
      */
      scorriLista = newList;
      trovatoCorrente = false;
      while(scorriLista != NULL && trovatoCorrente == false)
      {
        if(scorriLista->cifra == numeroCorrente)
        {
          scorriLista->numeroRipetizioni += 1;
          trovatoCorrente = true;
        }

        scorriLista = scorriLista->pProx;
      }

      if(trovatoCorrente == false)
      {
        punt->pProx = malloc(sizeof(Cifre));
        punt = punt->pProx;
        punt->cifra = numeroCorrente;
        punt->numeroRipetizioni = 1;
        punt->pProx = NULL;
      }
    }
  }

  return newList;
}

void leggiLista(Lista daLeggere)
{
  while(daLeggere != NULL)
  {
    printf("(%d:%d) ",daLeggere->cifra,daLeggere->numeroRipetizioni);
    daLeggere = daLeggere->pProx;
  }
}
