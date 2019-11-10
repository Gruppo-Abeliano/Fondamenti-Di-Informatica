/*
Corso di Fondamenti di Informatica
Esercizio: tema d'esame (leggermente modificato per rendere più semplici le
           parti non richieste all'esame)
Autore: Paolo Pertino
*/

/*
Un array di caratteri e' utilizzato per rappresentare una sequenza di 1000
cifre binarie. Ciascun elemento dell'array assume valore '0' qualora la cifra da
rappresentare sia 0, e '1' altrimenti. Si consideri il problema di codificare la
sequenza binaria usando la codifica Run Length Code (RLC) mediante un array di
interi, ciascuno dei quali rappresenta la lunghezza di una sequenza di '0'
consecutivi o di '1' consecutivi compresi nell’array. Si suppone che la
codifica RLC di un array cominci -per convenzione- sempre con il numero di cifre
binarie consecutive pari a 0 che si trovano all’inizio dell’array.
Si scriva una funzione che riceve in ingresso un
array binario e restituisca la sua codifica RLC. Ad esempio l’array
    0000000111001111000000111110...  ha codifica RLC  7 3 2 4 6 5...
mentre l’array
    111001111000000111110...  ha codifica RLC  0 3 2 4 6 5...
*/

#include <stdio.h>
#include <stdlib.h>

#define ARR_LENGHT 1000
#define ZERO_ASCII 48


typedef char arrayOriginale[ARR_LENGHT+1];
typedef char arrayCodificato[ARR_LENGHT];
typedef int contatore;
typedef struct
{
  arrayCodificato arrayFinale;
  contatore numeroElementi;
} listaFinale;

void compilaArray(arrayOriginale *toCompile);
void rlc(arrayOriginale *toCode,listaFinale *result);
void leggiRLC(listaFinale *toPrint);

int main(int argc, char const *argv[]) {
  arrayOriginale arrayToCode;
  listaFinale arrayRLC;

  compilaArray(&arrayToCode);
  arrayRLC.numeroElementi = 0;
  rlc(&arrayToCode,&arrayRLC);
  leggiRLC(&arrayRLC);
  return 0;
}

void compilaArray(arrayOriginale *toCompile)
{
  printf("\nInserisci una sequenza di %d elementi : ",ARR_LENGHT);
  scanf("%s",toCompile);
}

void rlc(arrayOriginale *toCode,listaFinale *result)
{
  contatore scorriArray,scorriUguali;
  contatore contaElementiUguali;
  int Start;
  char daConfrontare;

  if(1==((*toCode)[0]-ZERO_ASCII))
  {
    (*result).arrayFinale[0] = '0';
    ++(*result).numeroElementi;
    scorriArray=0;
    while((*toCode)[scorriArray]==((char)(1+ZERO_ASCII)))
    {
      ++scorriArray;
    }
    Start = scorriArray;
  } else {
    Start = 0;
  }

  for(scorriArray=Start;scorriArray<ARR_LENGHT+1;++scorriArray)
  {
    contaElementiUguali = 0;
    daConfrontare = (*toCode)[scorriArray];

    for(scorriUguali=scorriArray;(*toCode)[scorriUguali]==daConfrontare;++scorriUguali)
    {
      ++contaElementiUguali;
    }

    (*result).arrayFinale[(*result).numeroElementi] = (char)(contaElementiUguali+ZERO_ASCII);
    ++(*result).numeroElementi;

    scorriArray=scorriUguali-1;
  }
}

void leggiRLC(listaFinale *toPrint)
{
  contatore scorriLista;

  printf("\nLa sequenza compressa in formato RLC e' : ");
  for(scorriLista=0;scorriLista<(*toPrint).numeroElementi;++scorriLista)
  {
    printf("%c.",(*toPrint).arrayFinale[scorriLista]);
  }
}
