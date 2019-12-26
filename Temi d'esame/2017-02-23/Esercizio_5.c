/*
  Autore: Paolo Pertino
  Descrizione : data una parola, la funzione trovaOccorrenze, costruisce una lista sequenziale di elementi,
                i cui singoli elementi sono formati da una lettera della parola e dal numero di volte
                che tale lettera si presenta nella parola.
                I caratteri della lista sono inseriti nell'ordine con cui si presentano nella parola.

  Quesito 5 - Tema d'esame 23-02-2017

  Tempo di esecuzione: 17 minuti
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LUNGHEZZA 20

typedef char Parola[MAX_LUNGHEZZA];
typedef enum{false,true}bool;
typedef struct
{
  char carattere;
  int numCaratteriInParola;
} Occorrenza;
typedef struct
{
  Occorrenza occorrenze[MAX_LUNGHEZZA-1];
  int numeroOccorrenze;
} ListaOccorrenze;

void trovaOccorrenze(ListaOccorrenze *lista,Parola parola);
void leggiLista(ListaOccorrenze listaDaLeggere);

int main(int argc, char const *argv[]) {
  Parola parolaDaValutare;
  ListaOccorrenze lista;

  /*
    Chiedo all'utente di inserire la parola desiderata.
  */
  printf("Inserisci una parola da valutare : ");
  scanf("%s",parolaDaValutare);
  //fgets(parolaDaValutare,MAX_LUNGHEZZA,stdin);

  /*
    Inizializzo la listaOccorrenze e chiamo la procedura per la sua compilazione.
  */
  lista.numeroOccorrenze = 0;
  trovaOccorrenze(&lista,parolaDaValutare);

  /*
    Eseguo l'output della lista occorrenze appena creata.
  */
  leggiLista(lista);

  return 0;
}

void trovaOccorrenze(ListaOccorrenze *lista,Parola parola)
{
  int scorriLista;
  bool trovatoCarattereCorrente;

  /*
    Definisco il caso base, ovvero quando la parola passata è finita.
  */
  if(*parola == '\0') return;

  /*
    Se la lista sequenziale è vuota inserisco subito la prima lettera
  */
  if((*lista).numeroOccorrenze == 0)
  {
    (*lista).occorrenze[(*lista).numeroOccorrenze].carattere = *parola;
    (*lista).occorrenze[(*lista).numeroOccorrenze].numCaratteriInParola = 1;
    (*lista).numeroOccorrenze += 1;
  } else {
    /*
      Altrimenti entro nella lista e verifico uno dei due seguenti casi:
        1. La lettera era già stata trovata, quindi aggiorno soltanto il contatore nella cella della
           lettera in questione.
        2. La lettera è nuova, dunque inserisco un nuovo campo nella lista sequenziale
    */
    scorriLista = 0;
    trovatoCarattereCorrente = false;
    while(scorriLista < (*lista).numeroOccorrenze && trovatoCarattereCorrente == false)
    {
      if(*parola == (*lista).occorrenze[scorriLista].carattere)
      {
        (*lista).occorrenze[scorriLista].numCaratteriInParola += 1;
        trovatoCarattereCorrente = true;
      }
      ++scorriLista;
    }

    if(trovatoCarattereCorrente == false)
    {
      (*lista).occorrenze[(*lista).numeroOccorrenze].carattere = *parola;
      (*lista).occorrenze[(*lista).numeroOccorrenze].numCaratteriInParola = 1;
      (*lista).numeroOccorrenze += 1;
    }
  }

  /*
    Eseguo infine la chiamata ricorsiva, passando una parola più piccola alla stessa funzione.
  */
  trovaOccorrenze(lista,parola+1);
}

void leggiLista(ListaOccorrenze listaDaLeggere)
{
  int scorriLista;

  scorriLista = 0;
  while(scorriLista < listaDaLeggere.numeroOccorrenze)
  {
    printf("[%c,%d]\t",listaDaLeggere.occorrenze[scorriLista].carattere,listaDaLeggere.occorrenze[scorriLista].numCaratteriInParola);
    ++scorriLista;
  }
}
