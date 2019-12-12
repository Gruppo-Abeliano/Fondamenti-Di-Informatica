#include <stdio.h>

#define LUNGH_DESCR 20
#define FILE_INPUT "./Input"
#define FILE_LEGGERI "./Leggeri"
#define FILE_PESANTI "./Pesanti"
#define FILE_RAPPORTO "./Rapporto.txt"

typedef struct
{
  char Descrizione[LUNGH_DESCR];
  float Peso;
} Imballo;

void StampaFile(char *NomeFile);
int ClassificaImballi(float Soglia);

int main(int argc, char const *argv[]) {
  /*
    Codice per debuggare.
  */
  return 0;
}

int ClassificaImballi(float Soglia)
{
  FILE *pInput,*pPesanti,*pLeggeri,*pRapporto,*pDestinazione;
  Imballo ImbCorrente;
  int ContDati;           //Teniamo conto di quanti Imballi abbiamo già elaborato

  /*
    Il file viene semplicemente letto, e viene trattato come file binario
  */
  pInput = fopen(FILE_INPUT,"rb");
  pPesanti = fopen(FILE_PESANTI,"wb");
  pLeggeri = fopen(FILE_LEGGERI,"wb");
  pRapporto = fopen(FILE_RAPPORTO,"w");

  if(pInput == NULL || pPesanti == NULL || pLeggeri == NULL || pRapporto == NULL)
  {
    printf("\nErrore durante l'apertura dei file.\n");
    return EOF;
  }

  ContDati = 0;
  /*
    Voglio leggere un blocco alla volta, finchè non sono finiti.
  */
  while(fread(&ImbCorrente,sizeof(Imballo),1,pInput) > 0)
  {
    /*
      A ogni ciclo ImbCorrente assume una nuova forma, che deve essere elaborata.
    */
    ++ContDati;

    /*
      Se il peso è sopra la soglia, salverò l'imballo nel file pPesanti, altrimenti in pLeggeri
    */
    if(ImbCorrente.Peso > Soglia)
    {
      pDestinazione = pPesanti;
    } else {
      pDestinazione = pLeggeri;
    }

    fwrite(&ImbCorrente,sizeof(Imballo),1,pDestinazione);
    fprintf(pRapporto,"[ %s, %f ]\n",ImbCorrente.Descrizione,ImbCorrente.Peso);
  }

  fclose(pInput);
  fclose(pPesanti);
  fclose(pLeggeri);
  fclose(pRapporto);

  return ContDati;
}

/*
  Stampa il contenuto di un file.
*/
void StampaFile(char *NomeFile)
{
  FILE *pDaStampare;
  Imballo ImballoCorrente;

  pDaStampare = fopen(NomeFile,"rb");

  while(fread(&ImballoCorrente,sizeof(Imballo),1,pDaStampare) > 0)
  {
    printf("%s,%f\n",ImballoCorrente.Descrizione,ImballoCorrente.Peso);
  }

  fclose(pDaStampare);
}
