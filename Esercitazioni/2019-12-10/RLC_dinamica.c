#include <stdio.h>
#include <stdlib.h>

typedef struct ELEMENTO
{
  int dato;
  struct ELEMENTO *pProx;
} ElemLista;
typedef ElemLista *Binario;
typedef ElemLista *RLC;

RLC CalcolaRLC(Binario NumBin);

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}

RLC CalcolaRLC(Binario NumBin)
{
  Binario cursore;
  RLC Testa;
  int cifraCorrente;

  if(NumBin == NULL) return NULL;

  Testa = malloc(sizeof(ElemLista));
  Testa->Dato = 0;
  cifraCorrente = NumBin->Dato;
  cursore = NumBin;

  do {
    ++Testa->Dato;
    cursore = cursore->pProx;
  } while((cursore!=NULL) && (cursore->Dato == cifraCorrente));

  Testa->pProx = CalcolaRLC(cursore);
  return Testa;
}
