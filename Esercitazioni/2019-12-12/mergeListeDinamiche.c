/*
  Autore : Paolo Pertino
  Descrizione : date due liste dinamica di numeri reali tali che essi siano disposti in ordine crescente in entrambe
                le liste e che non vi siano elementi uguali nelle due liste, la funzione Fondi(ricorsiva) crea una nuova
                lista dinamica contenente gli elementi delle due liste di partenza fuse insieme, ancora in ordine crescente.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct ELEMENTO
{
  float numero;
  struct ELEMENTO *pProx;
} ElemLista;
typedef ElemLista *Lista;

Lista Fondi(Lista l1,Lista l2);
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
    printf("LISTA 1 - Inserisci un numero : (per stoppare l'inserimento inserire 1000) ");
    scanf("%f", &toAdd);
    if (toAdd != 1000)
      aggiungiElemento(&l1, toAdd);
  } while (toAdd != 1000);

  do
  {
    printf("LISTA 2 - Inserisci un numero : (per stoppare l'inserimento inserire 1000) ");
    scanf("%f", &toAdd);
    if (toAdd != 1000)
      aggiungiElemento(&l2, toAdd);
  } while (toAdd != 1000);

  printf("\n\nLista 1 :\n");
  mostraLista(l1);
  printf("\n\nLista 2 :\n");
  mostraLista(l2);

  listaOrdinata = Fondi(l1,l2);

  printf("\n\nLista Ordinata :\n");
  mostraLista(listaOrdinata);
  return 0;
}

Lista Fondi(Lista l1,Lista l2)
{
  Lista punt;
  if(l1==NULL && l2==NULL) return NULL;

  punt = malloc(sizeof(ElemLista));
  if(l1!=NULL)
  {
    if(l2!=NULL)
    {
      if(l1->numero<l2->numero)
      {
        punt->numero = l1->numero;
        punt->pProx = Fondi(l1->pProx,l2);
      } else {
        punt->numero = l2->numero;
        punt->pProx = Fondi(l1,l2->pProx);
      }
    } else {
      punt->numero = l1->numero;
      punt->pProx = Fondi(l1->pProx,NULL);
    }
  } else {
    punt->numero = l2->numero;
    punt->pProx = Fondi(NULL,l2->pProx);
  }

  return punt;
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
    printf("\nElemento %d : %.2f", contatore, toRead->numero);
    toRead = toRead->pProx;
    ++contatore;
  }
}
