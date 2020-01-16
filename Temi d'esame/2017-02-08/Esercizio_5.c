#include <stdio.h>
#include <stdlib.h>

typedef struct EL
{
  enum{oper,val}tipo;
  char operatore;
  float valore;
  struct EL *pProx;
} Elemento;

float Calcola(Elemento *Punt)
{
  Elemento *pPrimoOperando,*pSecondoOperando;
  Elemento *Cursore;
  int differenzaOperatoriValori = 0;

  if(Punt->tipo == val) return Punt->valore;
  pPrimoOperando = Punt->pProx;
  Cursore = Punt;

  /*
    Gli elementi che precedono il secondo operando sono sempre per metà operatori e per metà valori
  */
  while(differenzaOperatoriValori <= 0)
  {
    if(Cursore->tipo == val) differenzaOperatoriValori++;
    else differenzaOperatoriValori--;
    Cursore = Cursore->pProx;
  }

  pSecondoOperando = Cursore;
  if(Punt->operatore == '+') return(Calcola(pPrimoOperando) + Calcola(pSecondoOperando));
  if(Punt->operatore == '-') return(Calcola(pPrimoOperando) - Calcola(pSecondoOperando));
  if(Punt->operatore == '*') return(Calcola(pPrimoOperando) * Calcola(pSecondoOperando));
  if(Punt->operatore == '/') return(Calcola(pPrimoOperando) / Calcola(pSecondoOperando));
}
