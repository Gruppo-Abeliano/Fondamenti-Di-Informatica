#include <stdio.h>
#include <stdlib.h>

typedef struct ELEMENTO
{
  char Dato;
  struct ELEMENTO *pProx;
} Carattere;
typedef Carattere *Lista;

void cancellaElementoMedio(Lista *list);
void leggiLista(Lista toRead);
void aggiungiElemento(Lista *toCompile,char Elemento);

int main(int argc, char const *argv[]) {
  /* code */
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
  puntCor = *lits;
  saltaGiro = 1;

  while(puntNext->prox != NULL)
  {
    if(saltaGiro == 1)
    {
      puntNext = puntNext->prox;
      saltaGiro = -1;
    } else {
      puntNext = puntNext->prox;
      ppElemento = &(puntCor->prox);
      puntCor = puntCor->prox;
      saltaGiro = 1;
    }
  }

  temp = puntCor->prox;
  free(puntCor);
  *ppElemento = temp;
}

void aggiungiElemento(Lista *toCompile, char Elemento)
{
  Lista punt;
  if (*toCompile == NULL)
  {
    punt = malloc(sizeof(numeroLista));
    punt->numero = Elemento;
    punt->prox = NULL;
    *toCompile = punt;
  }
  else
  {
    aggiungiElemento(&((*toCompile)->prox), Elemento);
  }
}
