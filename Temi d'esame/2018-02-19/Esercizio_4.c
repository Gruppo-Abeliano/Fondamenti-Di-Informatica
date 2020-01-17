#include <stdio.h>
#include <stdlib.h>

#define N 5

typedef struct EL
{
  char carattere;
  struct EL *pProx;
} ElemLista;
typedef ElemLista *Lista;

int AlmenoN(Lista list,char carattereDaCercare,int k);
int AlmenoNConsec(Lista list,char carattereDaCercare,int k);
Lista creaLista();
void leggiLista(Lista daLeggere);

int main(int argc, char const *argv[]) {
  Lista nuovaLista;
  char carDaCercare;

  /*
    * Creo una nuova lista dinamica.
  */
  nuovaLista = creaLista();
  printf("La lista iniziale e' : ");
  leggiLista(nuovaLista);

  /*
    * Chiedo all'utente di inerire un carattere da cercare nalla lista.
  */
  printf("\nInserisci un carattere da cercare : ");
  fflush(stdin);
  scanf("%c",&carDaCercare);

  /*
    * Cerco nella lista se ci sono almeno N cararatteri uguali a quello immesso in input.
  */
  if(AlmenoN(nuovaLista,carDaCercare,N) == 1) printf("\nNella lista il carattere %c si presenta almeno %d volte.",carDaCercare,N);
  else printf("\nNella lista, il carattere %c non si presenta almeno %d volte.",carDaCercare,N);

  /*
    * Cerco nella lista se il carattere inserito dall'utente si presenta almeno N volte
    * consecutivamente nella lista.
  */
  if(AlmenoNConsec(nuovaLista,carDaCercare,N) == 1) printf("\nNella lista il carattere %c si presenta almeno %d volte consecutivamente",carDaCercare,N);
  else printf("\nNella lista, il carattere %c non si presenta almeno %d volte consecutivamente",carDaCercare,N);

  return 0;
}

int AlmenoN(Lista list,char carattereDaCercare,int k)
{
  /*
    * Caso base:
    *   -- k=0, ovvero ho trovato tutte le ricorrenze richieste --> restituisco 1.
    *   -- list = NULL e k>0, vuol dire che sono arrivato a fine lista senza trovare tutti
    *      i caratteri richiesti.
  */
  if(k==0) return 1;
  else if(list==NULL) return 0;

  /*
    * Se il carattere da trovare è uguale a quello in esame, passo a me stesso la lista più
    * corta con un elemento in meno da cercare. Altrimenti passo sempre la lista più corta
    * ma con il numero attuale di elementi da cercare.
  */
  if(list->carattere == carattereDaCercare) return AlmenoN(list->pProx,carattereDaCercare,k-1);
  else return AlmenoN(list->pProx,carattereDaCercare,k);
}

int AlmenoNConsec(Lista list,char carattereDaCercare,int k)
{
  /*
    * Il caso base cambia leggermente, perchè oltre a controllare me stesso, devo controllare
    * di esere uguale al successivo. Facendo già il controllo sul successivo, quando k arriva
    * ad 1 può già bastare per dire che ho trovato N caratteri consecutivi cercati uguali.
  */
  if(k == 1) return 1;
  else if(list->pProx == NULL) return 0;

  /*
    * Se sono uguale al carattere cercato e al mio successivo restituisco il valore restituito
    * dalla chiamata ricorsiva a cui passo la coda della lista ed un carattere in meno da cercare.
    * Altrimenti se sono diverso dal carattere o sono diverso da chi mi segue, se sono arrivato
    * a questo punto della funzione vuol dire che non ho ancora trovato una sequenza di lunghezza
    * N di caratteri cercati consecutiva. Pertanto devo ricominciare a cercare tale sequenza dalla
    * lunghezza iniziale, quindi passo alla chiamata ricorsiva la coda della lista e la lunghezza
    * iniziale N.
  */
  if(list->carattere == carattereDaCercare && list->carattere == list->pProx->carattere) return AlmenoNConsec(list->pProx,carattereDaCercare,k-1);
  else return AlmenoNConsec(list->pProx,carattereDaCercare,N);
}

Lista creaLista()
{
  Lista Punt,newList;
  char carattereDaInserire;
  int continuareAdInserire;

  /*
    Inizializzo i due puntatori.
  */
  Punt = NULL;
  newList = NULL;

  /*
    Inserisco i dati con un ciclo do-while, finchè l'utente non decide di fermarsi.
  */
  do {
    printf("Inserisci un carattere : ");
    fflush(stdin);
    scanf("%c",&carattereDaInserire);

    if(newList == NULL)
    {
      newList = malloc(sizeof(ElemLista));
      newList->carattere = carattereDaInserire;
      newList->pProx = NULL;
      Punt = newList;
    } else {
      Punt->pProx = malloc(sizeof(ElemLista));
      Punt = Punt->pProx;
      Punt->carattere = carattereDaInserire;
      Punt->pProx = NULL;
    }

    printf("\nVuoi inserire altri numeri?\n1. SI\n2.NO\nScelta : ");
    scanf("%d",&continuareAdInserire);
  } while(continuareAdInserire == 1);

  return newList;
}

void leggiLista(Lista daLeggere)
{
  while(daLeggere != NULL)
  {
    printf("[%c]",daLeggere->carattere);
    daLeggere = daLeggere->pProx;
  }
}
