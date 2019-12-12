#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LUNG_DESCR 30
#define LUNG_MAX_MESE 31
#define LUNG_MAX_AGENDA 12

typedef struct EL
{
  int OraInizio;
  int Durata;
  char Descrizione[LUNG_DESCR];
  struct EL *pProssimo;
} TipoImpegno;                                      //Singolo elemento della lista dinamica
typedef TipoImpegno *TipoGiorno;                    //Testa di Lista
typedef TipoGiorno TipoMese[LUNG_MAX_MESE];
typedef TipoMese TipoAgenda[LUNG_MAX_AGENDA];

void AggiungiImpegno(TipoAgenda Agenda,int Mese,int Giorno,int Ora,int Dur,char Descr[]);

int main(int argc, char const *argv[]) {
  //DEBUG
  return 0;
}

void AggiungiImpegno(TipoAgenda Agenda,int Mese,int Giorno,int Ora,int Dur,char Descr[])
{
  TipoImpegno *pCorrente,*pPrecedente,*pNuovoImpegno;

  pNuovoImpegno = malloc(sizeof(TipoImpegno));
  /*
    sizeof restituisce quanto è grosso in bytes un dato di tipo TipoImpegno
    malloc restituisce un puntatore alla zona di RAM dove ora si possono scrivere dati
    Il solo modo di sapere dove sono le variabili dinamiche è sapere il puntatore al loro indirizzo di memoria.
  */

  pNuovoImpegno->OraInizio = Ora;  //pNuovoImpegno->OraInizio  equivalente a (*pNuovoImpegno).OraInizio
  pNuovoImpegno->Durata = Dur;
  strcpy(pNuovoImpegno->Descrizione,Descr);

  if((NULL==Agenda[Mese-1][Giorno-1]) || (Agende[Mese-1][Giorno-1]->OraInizio>Ora))
  {
    /*
      Inserimento in testa alla lista. Avviene se:
        - La lista è vuota
      oppure
        - Il primo elemento della lista ha un orario di inizio più alto di quello in esame.
    */
    pNuovoImpegno->pProssimo = Agenda[Mese-1][Giorno-1];
    Agenda[Mese-1][Giorno-1] = pNuovoImpegno;
  } else {
    /*
      posiziono due puntatori all'inizio della lista (uno davanti all'altro) e scorro la lista facendoli avanzare insieme
      finchè non trovo il punto giusto(confrontando le ore) dove inserirlo.
    */
    pPrecedente = Agenda[Mese-1][Giorno-1];       //Testa di lista
    pCorrente = pPrecedente->pProssimo;           //Puntatore (del primo elemento della lista) che punta al secondo elemento

    while((NULL!=pCorrente)&&(pCorrente->OraInizio<=Ora))
    {
      pPrecedente = pCorrente;
      pCorrente = pCorrente->pProssimo;
    }

    pNuovoImpegno->pProssimo = pCorrente;
    pPrecedente->pProssimo = pNuovoImpegno;
  }
}
