//Librerie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definizione costanti
#define MAX_LUNGHEZZA_ESPRESSIONE 100

//Definizione tipi utilizzati
typedef int Contatore;
typedef enum {parentesi,numero,operatore} Tipo;
typedef struct
{
  Tipo Tipologia;
  char Parentesi;
  char Operatore;
  unsigned int Numero;
} Oggetto;
typedef struct
{
  Oggetto Lista[MAX_LUNGHEZZA_ESPRESSIONE];
  int Numero_elementi;
} Espressione;

/*Definizione funzioni - BUGGED ATM
void compilaEspressione(Espressione expression);
void leggiEspressione(Espressione expression);
*/
void removeSpaces(char espressione[]);


//Main
int main(int argc, char const *argv[]) {
  Espressione expression;
  char espressione[MAX_LUNGHEZZA_ESPRESSIONE];
  Contatore i,j;

  // Starting input Phase
  printf("\nInserisci l'espressione da calcolare:\nL'espressione deve essere scritta nella seguente maniera : ((a+(b+c))+d), ovvero con ogni operazione separata dall'apertura e chiusura delle parentesi.\n!!!CARATTERI CONSENTITI!!! ---> numeri, '+' , '-' , '*' , '/' , ' '\nDigita la tua espressione : ");
  fgets(espressione, MAX_LUNGHEZZA_ESPRESSIONE, stdin);

  if ((strlen(espressione) > 0) && (espressione[strlen(espressione)-1] == '\n'))
  {
    espressione[strlen(espressione)-1] = '\0';
  }
  //End of input phase

  //Removing useless spaces ;)
  removeSpaces(espressione);

  //Compiling the List
  expression.Numero_elementi = 0;
  for(i=0; espressione[i]!='\0'; i++)
  {
    if(espressione[i]=='(' || espressione[i]==')')
    {
      expression.Lista[expression.Numero_elementi].Tipologia = parentesi;
      expression.Lista[expression.Numero_elementi].Parentesi = espressione[i];
    }
    else if(espressione[i]=='+' || espressione[i]=='-' || espressione[i]=='*' || espressione[i]=='/')
    {
      expression.Lista[expression.Numero_elementi].Tipologia = operatore;
      expression.Lista[expression.Numero_elementi].Operatore = espressione[i];
    }
    else if(espressione[i]>='0' && espressione[i]<='9')
    {
      expression.Lista[expression.Numero_elementi].Tipologia = numero;
      expression.Lista[expression.Numero_elementi].Numero = (int)(espressione[i] - '0');
    }

    ++expression.Numero_elementi;
  }

  for(j=0;j<expression.Numero_elementi;j++)
  {
    switch(expression.Lista[j].Tipologia)
    {
      case parentesi:
        printf("%c", expression.Lista[j].Parentesi);
        break;
      case operatore:
        printf("%c", expression.Lista[j].Operatore);
        break;
      case numero:
        printf("%d", expression.Lista[j].Numero);
        break;
    }
  }

  //compilaEspressione(expression);   BUGGED ATM
  //leggiEspressione(expression);     BUGGED ATM
  return 0;
}

/*void compilaEspressione(Espressione expression)       BUGGED ATM
{
  char espressione[MAX_LUNGHEZZA_ESPRESSIONE];
  Contatore i;

  // Starting input Phase
  printf("\nInserisci l'espressione da calcolare:\nL'espressione deve essere scritta nella seguente maniera : ((a+(b+c))+d), ovvero con ogni operazione separata dall'apertura e chiusura delle parentesi.\n!!!CARATTERI CONSENTITI!!! ---> numeri, '+' , '-' , '*' , '/' , ' '\nDigita la tua espressione : ");
  fgets(espressione, MAX_LUNGHEZZA_ESPRESSIONE, stdin);

  if ((strlen(espressione) > 0) && (espressione[strlen(espressione)-1] == '\n'))
  {
    espressione[strlen(espressione)-1] = '\0';
  }
  //End of input phase

  //Removing useless spaces ;)
  removeSpaces(espressione);

  //Compiling the List
  expression.Numero_elementi = 0;
  for(i=0; espressione[i]!='\0'; i++)
  {
    if(espressione[i]=='(' || espressione[i]==')')
    {
      expression.Lista[expression.Numero_elementi].Tipologia = parentesi;
      expression.Lista[expression.Numero_elementi].Parentesi = espressione[i];
    }
    else if(espressione[i]=='+' || espressione[i]=='-' || espressione[i]=='*' || espressione[i]=='/')
    {
      expression.Lista[*expression.Numero_elementi].Tipologia = operatore;
      expression.Lista[*expression.Numero_elementi].Operatore = espressione[i];
    }
    else if(espressione[i]>='0' && espressione[i]<='9')
    {
      expression.Lista[expression.Numero_elementi].Tipologia = numero;
      expression.Lista[expression.Numero_elementi].Numero = (int)(espressione[i] - '0');
    }

    ++expression.Numero_elementi;
  }
  printf("\n%d", expression.Numero_elementi);
}*/

/*void leggiEspressione(Espressione *expression)    BUGGED
{
  Contatore j;
  for(j=0;j<expression.Numero_elementi;j++)
  {
    switch(expression.Lista[j].Tipologia)
    {
      case parentesi:
        printf("%c", expression.Lista[j].Parentesi);
        break;
      case operatore:
        printf("%c", expression.Lista[j].Operatore);
        break;
      case numero:
        printf("%d", expression.Lista[j].Numero);
        break;
    }
  }
}*/

void removeSpaces(char espressione[])
{
  Contatore i, counter;

  counter = 0;
  for(i=0;espressione[i]!='\0';i++)
  {
    if(espressione[i] != ' ')
    {
      espressione[counter++] = espressione[i];
    }
  }
  espressione[counter] = '\0';
}
