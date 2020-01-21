/*
  Autore: Paolo Pertino
  Esercizio 2 - Tema Esame 13-09-2017

  Descrizione:
    - Parte 1: date in input due parole, la funzione ricorsiva checkParteIniziale controlla se nella
               parte iniziale della parola B è contenuta la parola A. Restituisce 1 in tal caso,
               oppure 0 altrimenti.
    . Parte 2: viene ricercato in un vocabolario ordinato se esiste una parola che abbia come parte
               iniziale la stringa A. Se esiste, viene restituito 1, altrimenti 0. La ricerca è
               effettuata con un algoritmo che minimizza il numero di controlli
*/

#include <stdio.h>
#include <string.h>

#define LUNGHEZZA_MAX_PAROLA 20
#define DIMENSIONE_VOCABOLARIO 10

typedef char Stringa[LUNGHEZZA_MAX_PAROLA];
typedef Stringa Vocabolario[DIMENSIONE_VOCABOLARIO];

int checkParteIniziale(Stringa A,Stringa B);
int ricercaInVocabolario(Vocabolario vocabolario,Stringa A,int min, int max);

int main(int argc, char const *argv[]) {
  Vocabolario insiemeParole = {
    "arbanella",
    "banana",
    "digestivo",
    "erba",
    "fonografo",
    "luogo",
    "mamma",
    "nonna",
    "ritardo",
    "serpente"
  };
  Stringa parola1,parola2;
  int risultatoParte1,risultatoParte2;

  /*
    Richiedo all'utente di inserire le due parole.
  */
  printf("Inserisci la prima parola : ");
  scanf("%s",parola1);
  printf("Inserisci la seconda parola : ");
  scanf("%s",parola2);

  /*
    Eseguo il controllo tramite la funzione ricorsiva richiesta.
  */
  risultatoParte1 = checkParteIniziale(parola1,parola2);

  /*
    Gestisco il risultato della funzione. Se il valore restituito è uguale a 0, allora la parte
    iniziale di B non coincide con A, viceversa se restituisce 1, la contiene.
  */
  if(risultatoParte1==1) printf("\nLa parte iniziale di B contiene A.");
  else printf("\nLa parte iniziale di B non contiene A.");

  /*
    Parte 2 Esercizio - Ricerco all'interno del vocabolario ordinato se c'è una parola che ha come parte
    iniziale la Stringa parola1 fornita in input.
  */
  risultatoParte2 = ricercaInVocabolario(insiemeParole,parola1,0,DIMENSIONE_VOCABOLARIO-1);

  /*
    Gestisco il risultato ottenuto. Viene restituito 1 se esiste una parola all'interno del Vocabolario
    che ha come parte iniziale la stringa parola1 passata come input, altrimenti restituisce 0.
  */
  if(risultatoParte2==1) printf("\nEsiste una parola nel vocabolario, la cui parte iniziale contiene A.");
  else printf("\nNon esiste una parola nel vocabolario, la cui parte iniziale contiene A.");

  return 0;
}

int checkParteIniziale(Stringa A,Stringa B)
{
  int risultatoSuccessivo;
  /*
    Controllo inizialmente la lunghezza delle due parole; ovviamente se la lunghezza
    della stringa B è minore della lunghezza della stringa A, non c'è possibilità che
    B abbia come parte iniziale l'intera stringa A. Pertanto se tale caso è verificato
    restituisco 0.
  */
  if(strlen(A) > strlen(B)) return 0;

  /*
    Gestisco il caso base. Se la variabile puntata da A è \n restituisco 1.
  */
  if(*A == '\0') return 1;

  /*
    Controllo se la lettera attuale e delego allo schiavo il controllo della parte seguente.
  */
  risultatoSuccessivo = checkParteIniziale(A + 1,B + 1);

  if(risultatoSuccessivo == 0) return 0;
  else if(*A == *B) return 1;
  else return 0;
}

int ricercaInVocabolario(Vocabolario vocabolario,Stringa A,int min, int max)
{
  int risultato1,risultato2,risultatoSuccessivo;
  /*
    Devo effettuare una ricerca nell'elenco ordinato. Prima di tutto controllo che la stringa non sia parte
    della prima o dell'ultima parola del vocabolario.
  */
  risultato1 = checkParteIniziale(A,vocabolario[min]);
  risultato2 = checkParteIniziale(A,vocabolario[max]);

  if(risultato1 == 1 || risultato2 == 1)return 1;

  /*
    Se la parola nè all'inizio nè alla fine del vocabolario contengono nella loro parte iniziale la stringa A
    devo effettuare la chiamata ricorsiva, tenendo conto dell'ordine alfabetico.

    Se gli indici puntano alla stessa cosa e la stringa A non è comunque contenuta nella parola del
    vocabolario, allora la prola cercata non esiste; pertanto in tal caso viene restituito 0.
  */
  if((min+max)/2 > min && (min+max)/2 < max)
  {
    if(strcmp(A,vocabolario[(min+max)/2]) < 1) risultatoSuccessivo = ricercaInVocabolario(vocabolario,A,min,(min+max)/2);
    else risultatoSuccessivo = ricercaInVocabolario(vocabolario,A,(min+max)/2,max);
    return risultatoSuccessivo;
  } else return 0;
}
