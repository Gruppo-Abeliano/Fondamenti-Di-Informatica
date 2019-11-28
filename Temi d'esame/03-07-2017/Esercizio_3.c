/*
  Autore : Paolo Pertino
  Esercizio 3 - Tema Esame 03-07-2017
  Descrizione : la funzione inserisci valore riceve in ingresso una lista dinamica già compilata, un valore da
                inserire in tale lista e la i-esima posizione dal fondo in cui inserirlo.

                Il file comprende anche funzioni di compilazione e lettura della lista per effettuare debugging.
*/

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

//Main
int main(int argc, char const *argv[]) {
  Lista listaIniziale,listaModificata;
  int toAdd,val,pos;

  //INIZIALIZZAZIONE
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

  //Controllo se devo aggiungere il valore in ultima posiione.
  if(posizione==1) isUltimo = true;
  else isUltimo = false;

  puntPrec = NULL;
  puntCor = L;

  /*
    Porto avanti il puntCor, prima di far partire il puntPrec(il puntPrec mi indicherà la posizione subit
    precedente di dove inserire il nuovo valore).
  */
  while(posizione!=1)
  {
    puntCor = puntCor->prox;
    posizione--;
  }

  /*
    A questo punto possono verificarsi 2 casi:
      1) puntCor è NULL e quindi il nuovo valore va inserito all'inizio della lista
      2) puntCor non è NULL quindi procedo.
  */
  if(puntCor == NULL) isPrimo = true;
  else isPrimo = false;

  /*
    Finchè è piena la lista (puntCor->prox!=NULL) mando avanti i puntatori temporanei. Il distacco tra puntPrec
    e puntCor è già ben definito dalle istruzioni precedenti.
  */
  while(isPrimo == false && (puntCor->prox!=NULL))
  {
    puntPrec = puntPrec->prox;
    puntCor = puntCor->prox;
  }

  /*
    Inizia la fase di inserimento e devo trattare tutti i casi:
      1) l'elemento va inserito in coda
      2) l'elemento va inserito per primo:
        2.1)Sovrascrivo il puntPrec ed inserisco il valore.
        2.2)Ritorno puntPrec
      3) l'elemento va inserito in mezzo alla lista -> mi servo di un puntatore temporaneo "temp".
  */
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
