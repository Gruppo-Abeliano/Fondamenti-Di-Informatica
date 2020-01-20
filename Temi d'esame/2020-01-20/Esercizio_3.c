#include <stdio.h>
#include <stdlib.h>

#define DIMENSIONE 9

typedef int arrayInteri[DIMENSIONE];
typedef struct EL
{
  int pArray;
  struct EL *pProx;
} Nodo;
typedef Nodo *Lista;

void MaxLoc(arrayInteri arr,int dimensione,Lista *pTesta);
void mostraMassimi(Lista list);

int main(int argc, char const *argv[]) {
  arrayInteri arrayCompleto = {3,2,1,4,7,3,4,2,6};
  Lista lista;

  /*
    Inizializzo la lista dinamica.
  */
  lista = NULL;

  /*
    Creo la lista dinamica con la funzione, passando un puntatore alla testa della lista.
  */
  MaxLoc(arrayCompleto,DIMENSIONE-1,&lista);

  /*
    Mostro i massimi locali.
  */
  mostraMassimi(lista);

  return 0;
}

void MaxLoc(arrayInteri arr,int dimensione,Lista *pTesta)
{
  /*
    I casi base sono 2:
      1. La dimensione passata è massima, quindi controllo solo l'elemento alla sinistra:
          1.1 Se quest'ultimo è massimo locale, aggiungo il puntatore alla lista e richiamo la
              funzione ricorsiva.
      2. La dimensione passata è uguale a 0, quindi controllo solo l'elemento alla destra:
          2.1 Se è un massimo locale, aggiungo il puntatore alla lista e stoppo la funzione perchè
              ho finito di scorrere l'array.
      3. Altrimenti controllo sia l'elemento successivo sia il precedente (son sicuro che esistono per i
         controlli precedenti). Se è un massimo locale lo aggiungo, altrimenti no. Inoltre faccio la chiamata
         ricorsiva passando la dimensione - 1.
  */

  if(dimensione == 0)
  {
    if(arr[dimensione] > arr[dimensione+1])
    {
      (*pTesta) = malloc(sizeof(Nodo));
      (*pTesta)->pArray = (arr[dimensione]);
      (*pTesta)->pProx = NULL;
    }
    return;
  } else if(dimensione == DIMENSIONE-1)
  {
    if(arr[dimensione] > arr[dimensione-1])
    {
      (*pTesta) = malloc(sizeof(Nodo));
      (*pTesta)->pArray = (arr[dimensione]);
      (*pTesta)->pProx = NULL;
      MaxLoc(arr,dimensione-1,&((*pTesta)->pProx));
    } else {
      MaxLoc(arr,dimensione-1,pTesta);
    }
  } else {
    if((arr[dimensione] > arr[dimensione+1]) && (arr[dimensione] > arr[dimensione-1]))
    {
      (*pTesta) = malloc(sizeof(Nodo));
      (*pTesta)->pArray = (arr[dimensione]);
      (*pTesta)->pProx = NULL;
      MaxLoc(arr,dimensione-1,&((*pTesta)->pProx));
    } else {
      MaxLoc(arr,dimensione-1,pTesta);
    }
  }
}

void mostraMassimi(Lista list)
{
  while(list != NULL)
  {
    printf("%d",(list->pArray));
    list = list->pProx;
  }
}
