/*
  Autore: Paolo Pertino
  Esercizio 4 - Tema Esame 13-09-2017

  Descrizione : Scrivere un sottoprogramma List2File che
                1. riceve in ingresso la testa di una lista dinamica,
                ciascun elemento della quale contiene (come campo dati) una struct composta da un int e un char;
                2. crea su disco fisso un file binario chiamato "Contents.dat";
                3. memorizza nel file Contents.dat tutte le struct contenute nella lista dinamica, nello stesso ordine;
                4. chiude il file binario.
                Scrivere poi un secondo sottoprogramma File2List che
                1. apre da disco fisso il file binario chiamato "Contents.dat";
                2. legge le struct contenute nel file e le memorizza (nello stesso ordine oppure in ordine inverso)
                in una lista dinamica i cui elementi hanno lo stesso tipo di quella che il sottoprogramma List2File
                riceve in ingresso;
                3. chiude il file;
                4. restituisce al programma chiamante la testa della lista.
                Prima di implementare i sottoprogrammi, si definiscano i tipi di dato necessari e
                si dica quali direttive include occorrono.
*/

#include <stdio.h>
#include <stdlib.h>

#define FILE_PATH "./Contents.dat"

typedef struct ELEMENTO
{
  int numero;
  char carattere;
  struct ELEMENTO *pProx;
} NodoLista;
typedef NodoLista *Lista;
typedef enum{false,true}bool;

Lista creaLista();
void leggiLista(Lista listaDaLeggere);
void List2File(Lista listaDaCopiare);
Lista File2List();
void clearScreen();

int main(int argc, char const *argv[]) {
  Lista listaDaElaborare,nuovaLista;

  /*
    Compilo la lista dinamica
  */
  listaDaElaborare = creaLista();
  leggiLista(listaDaElaborare);

  /*
    Elaboro la lista dinamica, salvando il contenuto su FILE.
  */
  List2File(listaDaElaborare);

  /*
    Costruisco una nuova lista leggendo dal file il contenuto.
  */
  nuovaLista = File2List();

  /*
    Stampo a schermo la nuova lista dinamica creata.
  */
  leggiLista(nuovaLista);

  return 0;
}

void List2File(Lista listaDaCopiare)
{
  FILE *pFile;
  Lista Punt;

  /*
    Apro il file in modalità scrittura.
  */
  pFile = fopen(FILE_PATH,"wb");

  if(pFile == NULL)
  {
    printf("\nErrore durante l'apertura del file.");
    return;
  }

  /*
    Scorro la lista dinamica elemento per elemento e lo scrivo sul file.
  */
  Punt = listaDaCopiare;
  while(fwrite(Punt,sizeof(NodoLista),1,pFile) == 1)
  {
    Punt = Punt->pProx;
  }

  /*
    Chiudo il file.
  */
  if(fclose(pFile) != 0) printf("\nErrore durante la chiusura del file.");
}

Lista File2List()
{
  Lista nuovaLista,Punt;
  NodoLista nuovoBlocco;
  FILE *pFile;

  /*
    Apro il file in modalità lettura binaria.
  */
  pFile = fopen(FILE_PATH,"rb");
  if(pFile == NULL)
  {
    printf("\nErrore durante l'apertura del file.");
    return NULL;
  }

  /*
    Scorro gli elementi del file uno alla volta e lo copio nella nuova lista dinamica.
  */
  nuovaLista = NULL;
  Punt = NULL;
  while(fread(&nuovoBlocco,sizeof(NodoLista),1,pFile) == 1)
  {
    if(nuovaLista == NULL)
    {
      nuovaLista = malloc(sizeof(NodoLista));
      nuovaLista->numero = nuovoBlocco.numero;
      nuovaLista->carattere = nuovoBlocco.carattere;
      nuovaLista->pProx = NULL;
      Punt = nuovaLista;
    } else {
      Punt->pProx = malloc(sizeof(NodoLista));
      Punt = Punt->pProx;
      Punt->numero = nuovoBlocco.numero;
      Punt->carattere = nuovoBlocco.carattere;
      Punt->pProx = NULL;
    }
  }

  /*
    Chiudo il file e restituisco la nuova lista.
  */
  if(fclose(pFile) != 0)
  {
    printf("\nErrore nella chiusura del file.");
    return NULL;
  }

  return nuovaLista;
}

/*
  * FUNZIONI PER DEBUGGARE - NON RICHIESTE DALL'ESERCIZIO
*/
Lista creaLista()
{
  Lista listaDaCompilare,Punt;
  int numeroDaInserire;
  char carattereDaInserire;
  int continuareInserimento;

  listaDaCompilare = NULL;
  Punt = NULL;

  do {
    printf("\nInserisci un numero : ");
    scanf("%d",&numeroDaInserire);
    fflush(stdin);
    printf("Inserisci un carattere : ");
    scanf("%c",&carattereDaInserire);

    /*
      Inserisco i dati nella lista dinamica.
    */
    if(listaDaCompilare == NULL)
    {
      listaDaCompilare = malloc(sizeof(NodoLista));
      listaDaCompilare->numero = numeroDaInserire;
      listaDaCompilare->carattere = carattereDaInserire;
      listaDaCompilare->pProx = NULL;
      Punt = listaDaCompilare;
    } else {
      Punt->pProx = malloc(sizeof(NodoLista));
      Punt = Punt->pProx;
      Punt->numero = numeroDaInserire;
      Punt->carattere = carattereDaInserire;
      Punt->pProx = NULL;
    }

    /*
      Chiedo all'utente se vuole continuare ad inserire elementi nella lista, e gestisco la risposta.
    */
    printf("\nVuoi continuare ad inserire elementi?\n1.Si\n2.No\nScelta : ");
    scanf("%d",&continuareInserimento);
  } while(continuareInserimento == 1);

  return listaDaCompilare;
}

void leggiLista(Lista listaDaLeggere)
{
  while(listaDaLeggere != NULL)
  {
    printf("\n[%d:%c]",listaDaLeggere->numero,listaDaLeggere->carattere);
    listaDaLeggere = listaDaLeggere->pProx;
  }
}

void clearScreen()
{
  system("@cls||clear");
}
