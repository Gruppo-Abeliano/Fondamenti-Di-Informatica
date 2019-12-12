/*
  Autore : Paolo Pertino
  Esercizio 2 - Tema Esame 02-07-2018
  Descrizione : date due liste dinamiche Lista1 e Lista2 di interi disposti in ordine crescente alla funzione Fusione,
                essa le elabora restituendo una lista dinamica ordinata contenente gli elementi di Lista1 fusi con quelli di Lista2
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct EL
{
  int numero;
  struct EL *prox;
} ElementoLista;
typedef ElementoLista *Lista;

Lista Fusione(Lista lista1, Lista lista2);
void aggiungiElemento(Lista *toCompile, int Elemento);
void mostraLista(Lista toRead);

int main(int argc, char const *argv[])
{
  Lista l1, l2, listaFinale;
  int toAdd;

  l1 = NULL;
  l2 = NULL;

  do
  {
    printf("LISTA 1 - Inserisci un numero : (STOP quando numero < 0) ");
    scanf("%d", &toAdd);
    if (toAdd >= 0)
      aggiungiElemento(&l1, toAdd);
  } while (toAdd >= 0);

  do
  {
    printf("LISTA 2 - Inserisci un numero : (STOP quando numero < 0) ");
    scanf("%d", &toAdd);
    if (toAdd >= 0)
      aggiungiElemento(&l2, toAdd);
  } while (toAdd >= 0);

  printf("\nLista 1 :");
  mostraLista(l1);
  printf("\nLista 2 :");
  mostraLista(l2);

  listaFinale = Fusione(l1, l2);

  printf("\n\n\n");
  mostraLista(listaFinale);

  return 0;
}

Lista Fusione(Lista lista1, Lista lista2)
{
  Lista puntPrec, puntCor, puntTemp, listaFinale, listaStatica;

  if (lista1 == NULL && lista2 == NULL)
  {
    printf("\nLe due liste sono vuote.");
    return NULL;
  }
  else if (lista1 == NULL)
    return lista2;
  else if (lista2 == NULL)
    return lista1;

  if (lista1->numero > lista2->numero)
  {
    listaFinale = lista2;
    listaStatica = lista1;
  }
  else
  {
    listaFinale = lista1;
    listaStatica = lista2;
  }

  while (listaStatica != NULL)
  {
    puntPrec = NULL;
    puntCor = listaFinale;
    while ((puntCor != NULL) && (listaStatica->numero >= puntCor->numero))
    {
      puntPrec = puntCor;
      puntCor = puntCor->prox;
    }

    puntTemp = puntPrec->prox;
    puntPrec->prox = listaStatica;
    listaStatica = listaStatica->prox;
    (puntPrec->prox)->prox = puntTemp;
  }

  return listaFinale;
}

void aggiungiElemento(Lista *toCompile, int Elemento)
{
  Lista punt;
  if (*toCompile == NULL)
  {
    punt = malloc(sizeof(ElementoLista));
    punt->numero = Elemento;
    punt->prox = NULL;
    *toCompile = punt;
  }
  else
  {
    aggiungiElemento(&((*toCompile)->prox), Elemento);
  }
}

void mostraLista(Lista toRead)
{
  int contatore;

  contatore = 1;
  while (toRead != NULL)
  {
    printf("\nElemento %d : %d", contatore, toRead->numero);
    toRead = toRead->prox;
    ++contatore;
  }
}
