#include <stdio.h>

#define FILE_INPUT "./Input.txt"
#define FILE_OUTPUT "./Output.txt"

int main(int argc, char const *argv[]) {
  FILE *pInput,*pOutput;
  int numCarLetti['z'-'a'+1];
  int carLetto;
  char cursore;

  /*
    Apro i file e gestisco le eccezioni, ovvero eventuali errori in apertura.
    Inizialmente apro il file in uscita:
      1. Se qualcosa va storto stampo un messaggio di errore e chiudo il programma
      2. Altrimenti vado avanti

    Apro il file di input:
      1. Se qualcosa va storto:
        1.1 Stampo un messaggio di errore.
        1.2 Chiudo il file di Output precedentemente aperto. Se qualcosa va storto nella chiusura:
          1.2.1 Stampo un messaggio di errore.
        1.3 Chiud il programma
      2. Altrimenti vado avanti.
  */
  pOutput = fopen(FILE_OUTPUT,"w");
  if(pOutput == NULL)
  {
    printf("\nErrore apertura file output.");
    return 1;
  }

  pInput = fopen(FILE_INPUT,"r");
  if(pInput == NULL)
  {
    printf("\nErrore apertura file input.");
    if(0 != fclose(pOutput))
    {
      printf("\nErrore in chiusura.");
    }
    return 1;
  }

  for(cursore = 'a';cursore <= 'z';cursore++)
  {
    numCarLetti[cursore-'a'] = 0;
  }

  carLetto = fgetc(pInput);
  while(('a' <= carLetto) && (carLetto <= 'z'))
  {
    ++numCarLetti[carLetto-'a'];
    carLetto = fgetc(pInput);
  }

  for(cursore = 'z';cursore >= 'a';cursore--)
  {
    if(numCarLetti[cursore-'a'] > 0) fprintf(pOutput,"%c%d\n",cursore,numCarLetti[cursore-'a']);
  }

  /*
    Chiudo i file e gestisco le eccezioni.
  */
  if(fclose(pInput) != 0)
  {
    printf("\nErrore nella chiusura del file di input.");
    return 1;
  }

  if(fclose(pOutput) != 0)
  {
    printf("\nErrore nella chiusura del file di output.");
    return 1;
  }

  printf("\nIl file e' stato compilato.");
  return 0;
}
