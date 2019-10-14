/***
  Nome : Esercizio sulle Struct - Suddivisione Frase
  Descrizione : Viene fornita in input una frase di massimo 60 caratteri. Viene successivamente suddivisa parola per parola ed identificata la lunghezza delle singole parole.
***/

#include <stdio.h>
#include <stdlib.h>

//Definizione costanti
#define LUNGHEZZA_MAX_FRASE 60
#define LUNGHEZZA_MAX_PAROLA 15
#define NUM_MAX_PAROLE 10
#define TERMINATORE_FRASE '.'
#define SEPARATORE_PAROLE '_'

//Definizione tipi
typedef char frase[LUNGHEZZA_MAX_FRASE];
typedef char parola[LUNGHEZZA_MAX_PAROLA];
typedef int contatore;
typedef struct                                                //Sto descrivendo un tipo di dato | Struct con dentro un array di tipo Parola (char di massimo 15 caratteri) e un intero lunghezza
{
  parola Parola;
  int Lunghezza;
} TipoDescrParola;
typedef struct                                                        //Sto inizializzando una variabile di nome ElencoParole che ha 2 elementi : un oggetto di tipo TipoDescrParola precedentemente definito e un intero che indica il numero di elementi
{
  TipoDescrParola DatiParola[NUM_MAX_PAROLE];
  int NumeroElementi;
} elencoParole;

//Dichiarazione funzioni
void richiediFrase(frase Frase);
void compilaListaSequenziale(frase Frase);
void leggiListaSequenziale(elencoParole ElencoParole);

//Main
int main(int argc, char const *argv[]) {
  //Inizio fase dichiarativa
  frase Frase;

  richiediFrase(Frase);
  compilaListaSequenziale(Frase);

  return 0;
}

/***
  Nome : richiediFrase
  Descrizione : Richiede in Input all'utente una frase.
***/

void richiediFrase(frase Frase)
{
  printf("\nInserisci la frase (per separare una parola dall'altra della frase utilizzare il carattere _ | Concludere la frase con il carattere .) : ");
  scanf("%s", Frase);
}

/***
  Nome : compilaListaSequenziale
  Descrizione : Analizza la frase e la suddivide parola per parola, ne calcola la lunghezza e le istanzia nella struttura dati
***/

void compilaListaSequenziale(frase Frase)
{
  //Fase Dichiarativa
  contatore IndiceCoreFrase, IndiceCoreParola, IndiceCoreElemento;
  elencoParole ElencoParole;

  ElencoParole.NumeroElementi = 0;
  IndiceCoreFrase = 0;
  IndiceCoreParola = 0;

  while(Frase[IndiceCoreFrase] != TERMINATORE_FRASE)                                                            //Il ciclo si ripete finchè non incontro il punto '.'
  {
    if(SEPARATORE_PAROLE != Frase[IndiceCoreFrase])                                                             //Se il carattere della frase che sto controllando non è il separatore '_' allora scrivo il carattere della parola nell'array di tipo TipoDescrParola
    {
      ElencoParole.DatiParola[ElencoParole.NumeroElementi].Parola[IndiceCoreParola] = Frase[IndiceCoreFrase];
      ++IndiceCoreParola;
    } else {                                                                                                    //Se incontro il separatore, aggiungo al termine della parola il carattere \0, azzero l'indice con cui scorro le parole nel nuovo array TipoDescrParola ed aumento di 1 il numero di elementi della lista sequenziale
      ElencoParole.DatiParola[ElencoParole.NumeroElementi].Parola[IndiceCoreParola] = '\0';
      ElencoParole.DatiParola[ElencoParole.NumeroElementi].Lunghezza = IndiceCoreParola;
      IndiceCoreParola = 0;
      ++ElencoParole.NumeroElementi;
    }
    ++IndiceCoreFrase;
  }
  ElencoParole.DatiParola[ElencoParole.NumeroElementi].Parola[IndiceCoreParola] = '\0';                         //Quando incontro il punto, l'ultima parola deve essere ancora salvata, quindi lo faccio aggiungendo \0 e la sua lunghezza (faccio questo perchè non incontrerò alla fine un SEPARATORE_PAROLE '_' che mi farà entrare nell'else, bensì un TERMINATORE_FRASE '.')
  ElencoParole.DatiParola[ElencoParole.NumeroElementi].Lunghezza = IndiceCoreParola;
  ++ElencoParole.NumeroElementi;

  leggiListaSequenziale(ElencoParole);
}

/***
  Nome : leggiListaSequenziale
  Descrizione : Legge gli elementi della lista sequenziale all'interno della struttura dati
***/

void leggiListaSequenziale(elencoParole ElencoParole)
{
  contatore i;

  i = 0;
  while(i<ElencoParole.NumeroElementi)
  {
    printf("%s\tLUNGHEZZA : %d\n",ElencoParole.DatiParola[i].Parola, ElencoParole.DatiParola[i].Lunghezza);
    i++;
  }
}
