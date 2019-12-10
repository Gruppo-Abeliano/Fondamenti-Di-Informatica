#include <stdio.h>

#define INPUT_FILE "./Input.txt"
#define CHIAVE '#'

typedef struct
{
  int valore;
  char chiave;
} Dato;
typedef enum{false,true}bool;

int main(int argc, char const *argv[]) {
  FILE *fInput;
  Dato DatoLetto;
  bool ChiaveTrovata;
  int nuovoValore,esitoChiusura;

  fInput = fopen(INPUT_FILE,"rb+");
  if(fInput == NULL)
  {
    printf("\nErrore durante l'apertura del file.");
    return 1;
  }

  fread(&DatoLetto,sizeof(Dato),1,fInput);    //Salto il primo file, perchè non mi interessa (c'è almeno un altro blocco oltre il primo contenente la chiave)
  ChiaveTrovata = false;
  while(ChiaveTrovata==false) && (fread(&DatoLetto,sizeof(Dato),1,fInput))
  {
    if(Dato.chiave == CHIAVE)
    {
      ChiaveTrovata = true;
      nuovoValore = Dato.valore;
    }
  }

  if(ChiaveTrovata == true)
  {
    rewind(fInput);
    fread(&DatoLetto,sizeof(Dato),1,fInput);
    DatoLetto->valore = nuovoValore;
    rewind(fInput);
    fwrite(&DatoLetto,sizeof(Dato),1,fInput);
  }

  esitoChiusura = fclose(fInput);
  if(esitoChiusura != 0)
  {
    printf("\nErrore chiusura del file %s.",INPUT_FILE);
    return 1;
  } else {
    printf("\nChiusura effettuata correttamente.");
  }

  return 0;
}
