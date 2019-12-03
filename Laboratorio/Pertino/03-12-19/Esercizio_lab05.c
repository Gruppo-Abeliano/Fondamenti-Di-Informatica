/*
  Autore: Paolo Pertino
  Descrizione: Esercizio lab05.pdf
*/

#include <stdio.h>
#include <stdlib.h>

typedef enum{false,true}bool;
typedef struct ELEMENTO
{
  int numero;
  struct ELEMENTO *pProx;
} TipoElemento;
typedef TipoElemento *Lista;

Lista creaLista();
void stampaLista(Lista toRead);
bool checkDoppioni(Lista Testa);

int main(int argc, char const *argv[]) {
  Lista lista;
  bool doppioni;

  lista = creaLista();

  printf("Lista iniziale :\n");
  stampaLista(lista);

  doppioni = checkDoppioni(lista);
  if(doppioni == true) printf("\nCi sono doppioni.");
  else printf("\nNon ci sono doppioni.");

  return 0;
}

Lista creaLista()
{
  Lista *TestaLista,punt;
  int numeroDaAggiungere;

  *TestaLista = NULL;
  punt = NULL;

  do {
    printf("Inserisci un numero (stop quando il numero inserito e' < 0): ");
    scanf("%d",&numeroDaAggiungere);

    if(numeroDaAggiungere >= 0)
    {
      if(*TestaLista == NULL)
      {
        *TestaLista = malloc(sizeof(TipoElemento));
        (*TestaLista)->numero = numeroDaAggiungere;
        (*TestaLista)->pProx = punt;
        punt = *TestaLista;
      } else {
        punt->pProx = malloc(sizeof(TipoElemento));
        punt = punt->pProx;
        punt->numero = numeroDaAggiungere;
        punt->pProx = NULL;
      }
    }
  } while (numeroDaAggiungere >= 0);

  return (*TestaLista);
}

void stampaLista(Lista toRead)
{
  while(toRead != NULL)
  {
    printf("\n%d",toRead->numero);
    toRead = toRead->pProx;
  }
}

bool checkDoppioni(Lista Testa)
{
  Lista puntTesta,puntScorrimento;
  bool doppioniPresenti;
  int numeroDaControllare;

  doppioniPresenti = false;
  puntTesta = Testa;

  while(puntTesta != NULL)
  {
    numeroDaControllare = puntTesta->numero;
    puntScorrimento = puntTesta->pProx;

    while(puntScorrimento != NULL)
    {
      if(numeroDaControllare == puntScorrimento->numero) doppioniPresenti = true;
      puntScorrimento = puntScorrimento->pProx;
    }

    puntTesta = puntTesta->pProx;
  }

  return doppioniPresenti;
}
