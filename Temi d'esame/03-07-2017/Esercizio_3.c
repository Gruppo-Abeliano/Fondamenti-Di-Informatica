#include <stdio.h>
#include <stdlib.h>

typedef struct NODO
{
  int numero;
  struct NODO *prox;
} numeroLista;
typedef numeroLista *Lista;
typedef enum{false,true}bool;

Lista inserisciValorePosizioneK(Lista L,int valore,int posizione);
void aggiungiElemento(Lista *toCompile, int Elemento);
void mostraLista(Lista toRead);

int main(int argc, char const *argv[]) {
  Lista listaIniziale,listaModificata;
  int toAdd,val,pos;

  listaIniziale = NULL;
  listaModificata = NULL;

  //INPUT PHASE
  do
  {
    printf("Inserisci un numero : (STOP quando numero < 0) ");
    scanf("%d", &toAdd);
    if (toAdd >= 0)
      aggiungiElemento(&listaIniziale, toAdd);
  } while (toAdd >= 0);

  mostraLista(listaIniziale);

  printf("\nValore da inserire : ");
  scanf("%d",&val);
  printf("Posizione in cui inserire l'elemento (dalla fine della lista: se viene inserito 1 il valore e' inserito in ultima posizione, se 2 in penultima e cosi' via...) : ");
  scanf("%d",&pos);

  //ELABORAZIONE
  listaModificata = inserisciValorePosizioneK(listaIniziale,val,pos);

  //OUTPUT PHASE
  printf("La lista modificata e' :\n");
  mostraLista(listaModificata);
  return 0;
}

Lista inserisciValorePosizioneK(Lista L,int valore,int posizione)
{
  Lista puntPrec,puntCor,temp;
  bool isUltimo,isPrimo;

  if(posizione==1) isUltimo = true;
  else isUltimo = false;

  puntPrec = NULL;
  puntCor = L;

  while(posizione!=1)
  {
    puntCor = puntCor->prox;
    posizione--;
  }

  if(puntCor == NULL) isPrimo = true;
  else isPrimo = false;

  while(isPrimo == false && (puntCor->prox!=NULL))
  {
    puntPrec = puntPrec->prox;
    puntCor = puntCor->prox;
  }

  if(isUltimo==true)
  {
    puntPrec->prox = malloc(sizeof(numeroLista));
    (puntPrec->prox)->numero = valore;
    (puntPrec->prox)->prox = NULL;
  } else {
    if(isPrimo == true)
    {
      puntPrec = L;
      temp = puntPrec;
      puntPrec = malloc(sizeof(numeroLista));
      puntPrec->numero = valore;
      puntPrec->prox = temp;
      return puntPrec;
    } else {
      temp = puntPrec->prox;
      puntPrec->prox=malloc(sizeof(numeroLista));
      (puntPrec->prox)->numero = valore;
      (puntPrec->prox)->prox = temp;
      return L;
    }
  }
}

void aggiungiElemento(Lista *toCompile, int Elemento)
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
