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

void richiediFrase(frase Frase)
{
  printf("\nInserisci la frase (per separare una parola dall'altra della frase utilizzare il carattere _ | Concludere la frase con il carattere .) : ");
  scanf("%s", Frase);
}

void compilaListaSequenziale(frase Frase)
{
  contatore IndiceCoreFrase, IndiceCoreParola, IndiceCoreElemento;
  elencoParole ElencoParole;

  ElencoParole.NumeroElementi = 0;
  IndiceCoreFrase = 0;
  IndiceCoreParola = 0;

  while(Frase[IndiceCoreFrase] != TERMINATORE_FRASE)
  {
    if(SEPARATORE_PAROLE != Frase[IndiceCoreFrase])
    {
      ElencoParole.DatiParola[ElencoParole.NumeroElementi].Parola[IndiceCoreParola] = Frase[IndiceCoreFrase];
      ++IndiceCoreParola;
    } else {
      ElencoParole.DatiParola[ElencoParole.NumeroElementi].Parola[IndiceCoreParola] = '\0';
      ElencoParole.DatiParola[ElencoParole.NumeroElementi].Lunghezza = IndiceCoreParola;
      IndiceCoreParola = 0;
      ++ElencoParole.NumeroElementi;
    }
    ++IndiceCoreFrase;
  }
  ElencoParole.DatiParola[ElencoParole.NumeroElementi].Parola[IndiceCoreParola] = '\0';
  ElencoParole.DatiParola[ElencoParole.NumeroElementi].Lunghezza = IndiceCoreParola;
  ++ElencoParole.NumeroElementi;

  leggiListaSequenziale(ElencoParole);
}

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
