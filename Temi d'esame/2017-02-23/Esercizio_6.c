/*
  Autore : Paolo Pertino
  Descrizione : data una parola, la funzione creaListaDinamica, costruisce una lista dinamica di elementi,
                i cui nodi sono formati da una lettera della parola e dal numero di volte che tale lettera
                si presenta nella parola. I caratteri della lista sono inseriti in ordine alfabetico.

  Quesito 6 - Tema d'esame 23-02-2017

  Tempo di esecuzione : 15 minuti
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LUNGH 20
//#define DEBUG

typedef char Parola[MAX_LUNGH];
typedef struct NODO
{
  char carattere;
  int numeroRicorrenze;
  struct NODO *pProx;
} ElemLista;
typedef ElemLista *Lista;

void creaListaDinamica(Parola parola,Lista *testaLista);
void ordinaParola(Parola daOrdinare);
void mostraLista(Lista listaDaLeggere);

int main(int argc, char const *argv[]) {
  Parola parola;
  Lista testaLista = NULL;

  printf("\nInserisci una parola (massimo 20 caratteri) : ");
  scanf("%s",parola);

  creaListaDinamica(parola,&testaLista);
  mostraLista(testaLista);
  return 0;
}

void creaListaDinamica(Parola parola, Lista *testaLista)
{
  Lista punt;
  int scorriParola,occorrenzeCorrenti;
  /*
    Ordino i caratteri della parola in ordine alfabetico.
  */

  ordinaParola(parola);

  #ifdef DEBUG
    printf("%s",parola);
  #endif

  /*
    Costruisco la lista dinamica in modo non ricorsivo.
  */

  scorriParola = 0;
  while(parola[scorriParola] != '\0')
  {
    occorrenzeCorrenti = 0;
    while(parola[scorriParola] != '\0' && parola[scorriParola] == parola[scorriParola+1])
    {
      occorrenzeCorrenti += 1;
      ++scorriParola;
    }

    occorrenzeCorrenti += 1;
    if(*testaLista == NULL)
    {
      punt = malloc(sizeof(ElemLista));
      punt->carattere = parola[scorriParola];
      punt->numeroRicorrenze = occorrenzeCorrenti;
      punt->pProx = NULL;
      *testaLista = punt;
    } else {
      punt->pProx = malloc(sizeof(ElemLista));
      punt = punt->pProx;
      punt->carattere = parola[scorriParola];
      punt->numeroRicorrenze = occorrenzeCorrenti;
      punt->pProx = NULL;
    }

    ++scorriParola;
  }
}

void ordinaParola(Parola daOrdinare)
{
  int i,j;
  char temp;

  for(i=0;i<strlen(daOrdinare);i++)
  {
    for(j=0;j<strlen(daOrdinare)-1;j++)
    {

      if(daOrdinare[j]>= daOrdinare[j+1])
      {
        #ifdef DEBUG
          printf("\nScambio %c con %c",daOrdinare[j+1],daOrdinare[j]);
        #endif
        temp = daOrdinare[j+1];
        daOrdinare[j+1] = daOrdinare[j];
        daOrdinare[j] = temp;
      }
    }
  }
}

void mostraLista(Lista listaDaLeggere)
{
  while(listaDaLeggere != NULL)
  {
    printf("\n[%c:%d]",listaDaLeggere->carattere,listaDaLeggere->numeroRicorrenze);
    listaDaLeggere = listaDaLeggere->pProx;
  }
}
