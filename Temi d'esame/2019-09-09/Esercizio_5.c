#include <stdio.h>

#define MAX_DIM_PATH 32

typedef char Path[MAX_DIM_PATH];
typedef int Mazzo[13][4];

int MazzoCompleto(Path posizioneFile);

int main(int argc, char const *argv[]) {
  Path posizioneFile;
  int isCompleto;

  /*
    Chiedo all'utente dov'è il file nel sistema
  */
  printf("Inserisci la posizione del file nel sistema : ");
  scanf("%s",posizioneFile);

  /*
    Elaboro il contenuto del file. Se il mazzo di carte è completo senza ripetizioni restituisco 1
    altrimenti 0.
  */
  isCompleto = MazzoCompleto(posizioneFile);

  /*
    Gestisco il risultato ottenuto
  */
  if(isCompleto == 1) printf("\nIl mazzo e' completo.");
  else printf("\nIl mazzo non e' completo.");

  return 0;
}

int MazzoCompleto(Path posizioneFile)
{
  Mazzo mazzoCarte;
  int i,j;
  FILE *fInput;

  /*
    Inizializzo la matrice che rappresenta il mazzo a 0.
  */
  for(i=0;i<13;i++)
  {
    for(j=0;j<4;j++)
    {
      mazzoCarte[i][j] = 0;
    }
  }

  /*
    Apro il file e gestisco eventuali errori.
  */
  fInput = fopen(posizioneFile,"r");
  if(fInput == NULL)
  {
    printf("\nErrore durante l'apertura del file.");
    return 0;
  }

  /*
    Compilo la matrice finchè ci sono elementi nel file.
  */
  while(fscanf(fInput,"(%d,%d)",&i,&j) == 2)
  {
    mazzoCarte[i-1][j-1] += 1;
  }

  /*
    Ora ricontrollo la matrice. Il mazzo di carte è completo e senza ripetizioni solo se essa è
    formata da soli 1.

      -- se ci sono valori maggiori di 1, tale carte è ripetuta.
      -- se ci sono valori ancora uguali a 0, tale carta non è presente nel mazzo.
  */
  for(i=0;i<13;i++)
  {
    for(j=0;j<4;j++)
    {
      if(mazzoCarte[i][j] != 1) return 0;
    }
  }

  /*
    Se arrivo qui, il mazzo è sicuramente completo.
  */
  return 1;
}
