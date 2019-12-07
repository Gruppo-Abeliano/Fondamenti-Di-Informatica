/*
  Autore : Paolo Pertino
  Esercizio 3 - Tema Esame 26-01-2018
  Descrizione : data una lista dinamica in ingresso, la funzione cancellaElementoMedio elimina l'elemento situato al
                centro della lista. (dove con posizione centrale si intende (NUMERO_ELEMENTI + 1)/2 ). Se la lista è
                vuota non verrà ovviamente cancellato nulla.

  Tempo impiegato : 17 minuti __ scrittura funzione cancellaElementoMedio
*/

#include <stdio.h>
#include <stdlib.h>

#define TERMINATORE '/'

typedef struct ELEMENTO
{
  char Dato;
  struct ELEMENTO *pProx;
} Carattere;
typedef Carattere *Lista;

void cancellaElementoMedio(Lista *list);
void mostraLista(Lista toRead);
void aggiungiElemento(Lista *toCompile,char Elemento);

int main(int argc, char const *argv[]) {
  Lista lista;
  char toAdd;

  lista = NULL;

  do
  {
    printf("Inserisci un carattere : (Carattere di STOP : /)");
    scanf("%c", &toAdd);
    fflush(stdin);
    if (toAdd != TERMINATORE)
      aggiungiElemento(&lista, toAdd);
  } while(toAdd != TERMINATORE);

  mostraLista(lista);
  cancellaElementoMedio(&lista);
  mostraLista(lista);

  return 0;
}

void cancellaElementoMedio(Lista *list)
{
  Lista *ppElemento;
  Lista puntCor,puntNext,temp;
  int saltaGiro;

  if((*list) == NULL) return;

  ppElemento = list;
  puntNext = *list;
  puntCor = *list;
  saltaGiro = 1;

  while(puntNext->pProx != NULL)
  {
    if(saltaGiro == 1)
    {
      puntNext = puntNext->pProx;
      saltaGiro = -1;
    } else {
      puntNext = puntNext->pProx;
      ppElemento = &(puntCor->pProx);
      puntCor = puntCor->pProx;
      saltaGiro = 1;
    }
  }

  temp = puntCor->pProx;
  free(puntCor);
  *ppElemento = temp;
}

void aggiungiElemento(Lista *toCompile, char Elemento)
{
  Lista punt;
  if (*toCompile == NULL)
  {
    punt = malloc(sizeof(Carattere));
    punt->Dato = Elemento;
    punt->pProx = NULL;
    *toCompile = punt;
  }
  else
  {
    aggiungiElemento(&((*toCompile)->pProx), Elemento);
  }
}

void mostraLista(Lista toRead)
{
  int contatore;

  if(toRead==NULL) { printf("\nLista vuota."); return; }

  contatore = 1;
  while (toRead != NULL)
  {
    printf("\nElemento %d : %c", contatore, toRead->Dato);
    toRead = toRead->pProx;
    ++contatore;
  }
}
