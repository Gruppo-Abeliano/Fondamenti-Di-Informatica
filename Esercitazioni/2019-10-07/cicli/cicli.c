#include <stdio.h>
#include <stdlib.h>

#define MAX_QUADRATI 3

void quadratoWhile(float num);
void quadratoFor(float num);
void quadratoDoWhile(float num);
void clearScreen();

int main(int argc, char const *argv[]) {

  float numero;
  char scelta;

  printf("\nInserisci un numero : ");
  scanf("%f",&numero);
  printf("\nScegli il ciclo da utilizzare :\na. Ciclo While\nb. Ciclo For\nc. Ciclo Do-While\nScelta : ");
  scanf("%*c%c",&scelta);

  clearScreen();

  switch (scelta) {
    case 'a':
      quadratoWhile(numero);
      break;
    case 'b':
      quadratoFor(numero);
      break;
    case 'c':
      quadratoDoWhile(numero);
      break;
  }

  return 0;
}

void quadratoWhile(float num)
{
  int numero_quadrati;

  numero_quadrati=0;
  while(num>=0 && numero_quadrati<MAX_QUADRATI)
  {
    printf("Quadrato di %f : %f", num, num*num);
    ++numero_quadrati;
    if (numero_quadrati<MAX_QUADRATI)
    {
      printf("\nInserisci un nuovo numero : ");
      scanf("%f",&num);
    }
  }
}

void quadratoFor(float num)
{
  int numero_quadrati;

  for(numero_quadrati=0;(num>=0 && numero_quadrati<MAX_QUADRATI);numero_quadrati++)
  {
    printf("\nQuadrato di %f : %f", num, num*num);

    if(numero_quadrati<MAX_QUADRATI-1)
    {
      printf("\nInserisci un nuovo numero : ");
      scanf("%f",&num);
    }
  }
}

void quadratoDoWhile(float num)
{
  int numero_quadrati;

  numero_quadrati=0;
  do
  {
    printf("\nQuadrato di %f : %f", num, num*num);
    numero_quadrati++;

    if (numero_quadrati<MAX_QUADRATI)
    {
      printf("\nInserisci un nuovo numero : ");
      scanf("%f",&num);
    }
  } while(num>=0 && numero_quadrati<MAX_QUADRATI);
}

void clearScreen()
{
  system("clear||cls");
}
