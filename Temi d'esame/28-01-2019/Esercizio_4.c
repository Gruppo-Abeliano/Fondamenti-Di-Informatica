/*
  Autore : Paolo Pertino
  Esercizio 4 - Tema Esame 28-01-2019
  Descrizione : date due liste dinamica di numeri reali tali che essi siano disposti in ordine crescente in entrambe
                le liste e che non vi siano elementi uguali nelle due liste, la funzione Fondi(ricorsiva) crea una nuova
                lista dinamica contenente gli elementi delle due liste di partenza fuse insieme, ancora in ordine crescente.

  Tempo impiegato : 27 minuti __ scrittura funzione Fondi
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct ELEMENTO
{
  float numero;
  struct ELEMENTO *pProx;
} ElemLista;
typedef ElemLista *Lista;

void Fondi(Lista l1,Lista l2,Lista *pL);
void aggiungiElemento(Lista *toCompile, float Elemento);
void mostraLista(Lista toRead);

int main(int argc, char const *argv[]) {
  Lista l1,l2,listaOrdinata;
  float toAdd;

  l1 = NULL;
  l2 = NULL;
  listaOrdinata = NULL;

  do
  {
    printf("LISTA 1 - Inserisci un numero : (STOP quando numero < 0) ");
    scanf("%f", &toAdd);
    if (toAdd >= 0)
      aggiungiElemento(&l1, toAdd);
  } while (toAdd >= 0);

  do
  {
    printf("LISTA 2 - Inserisci un numero : (STOP quando numero < 0) ");
    scanf("%f", &toAdd);
    if (toAdd >= 0)
      aggiungiElemento(&l2, toAdd);
  } while (toAdd >= 0);

  printf("\n\nLista 1 :\n");
  mostraLista(l1);
  printf("\n\nLista 2 :\n");
  mostraLista(l2);

  Fondi(l1,l2,&listaOrdinata);

  printf("\n\nLista Ordinata :\n");
  mostraLista(listaOrdinata);
  return 0;
}

void Fondi(Lista l1,Lista l2,Lista *pL)
{
  Lista punt;
  if(l1==NULL && l2==NULL) return;

  if(l1!=NULL && ((l2==NULL || (l1->numero < l2->numero))))
  {
    punt = malloc(sizeof(ElemLista));
    punt->numero = l1->numero;
    punt->pProx = NULL;
    *pL = punt;
    Fondi(l1->pProx,l2,&((*pL)->pProx));
  } else if(l2!=NULL && ((l1==NULL) || (l2->numero < l1->numero))){
    punt = malloc(sizeof(ElemLista));
    punt->numero = l2->numero;
    punt->pProx = NULL;
    *pL = punt;
    Fondi(l1,l2->pProx,&((*pL)->pProx));
  }
}

void aggiungiElemento(Lista *toCompile, float Elemento)
{
  Lista punt;
  if (*toCompile == NULL)
  {
    punt = malloc(sizeof(ElemLista));
    punt->numero = Elemento;
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

  contatore = 1;
  while (toRead != NULL)
  {
    printf("\nElemento %d : %f", contatore, toRead->numero);
    toRead = toRead->pProx;
    ++contatore;
  }
}
