/*
  Nome : pigFarm.c
  Testo esercizio : pigFarm.pdf

  Autore : Paolo Pertino
*/

//LIBRERIE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//DEFINIZIONE COSTANTI
#define N 10

//DICHIARAZIONE TIPI UTILIZZATI
typedef char Nome[20];
typedef int Contatore;
typedef enum{false,true}bool;
typedef struct
{
  int giorno;
  int mese;
  int anno;
} Data;
typedef struct
{
  Nome nome;
  Data datanascita;
  float peso;
  int popolarita;
} Maialino;
typedef struct
{
  Maialino pigs[N];
  int num_maialini;
} Allevamento;

//DICHIARAZIONE FUNZIONI UTILIZZATE
void compilaAllevamento(Allevamento *farm);
void visualizzaAllevamento(Allevamento *farmToRead);
void visualizzaMaialiOrdinati(Maialino *arrayMaiali[],int tipoOrdine);
void OrdinamentoMaiali(Allevamento *farm,Maialino *arrayToCompile[],int tipoOrdinamento);
int Confronta(Data d1,Data d2);
void clearScreen();

int main(int argc, char const *argv[]) {
  //DICHIARAZIONE VARIABILI
  Allevamento FictionalPigsFarm;
  Maialino *ordAlfabetico[N],*ord_data[N],*ord_pop[N],*ord_peso[N];

  //FASE DI COMPILAZIONE DELL'ALLEVAMENTO
  compilaAllevamento(&FictionalPigsFarm);
  clearScreen();
  visualizzaAllevamento(&FictionalPigsFarm);

  //ORDINAMENTO MAIALI & OUTPUT PHASE
  OrdinamentoMaiali(&FictionalPigsFarm,ordAlfabetico,1);
  visualizzaMaialiOrdinati(ordAlfabetico,1);
  OrdinamentoMaiali(&FictionalPigsFarm,ord_data,2);
  visualizzaMaialiOrdinati(ord_data,2);
  OrdinamentoMaiali(&FictionalPigsFarm,ord_pop,3);
  visualizzaMaialiOrdinati(ord_data,3);
  OrdinamentoMaiali(&FictionalPigsFarm,ord_peso,4);
  visualizzaMaialiOrdinati(ord_data,4);
  return 0;
}

/*
  Nome : compilaAllevamento
  Descrizione : vengono fatti inserire all'utente i dati dei maiali dell'allevamento
*/
void compilaAllevamento(Allevamento *farm)
{
  Maialino maiale;
  Contatore scorriLista;

  farm->num_maialini=0;
  for(scorriLista=0;scorriLista<N;scorriLista++)
  {
    printf("\nInserisci dati Maiale %d :",scorriLista+1);
    printf("\n\tNome : ");
    scanf("%s", &(maiale.nome));
    printf("\tData (formato accettato gg/mm/aaaa) : ");
    scanf("%d/%d/%d", &(maiale.datanascita.giorno),&(maiale.datanascita.mese),&(maiale.datanascita.anno));
    printf("\tPeso : ");
    scanf("%f",&(maiale.peso));
    printf("\tPopolarita' : ");
    scanf("%d",&(maiale.popolarita));

    farm->pigs[scorriLista] = maiale;
    farm->num_maialini++;
  }
}

/*
  Nome : visualizzaAllevamento
  Descrizione : Visualizza (senza ordine) i maiali dell'allevamento e i loro dati
*/
void visualizzaAllevamento(Allevamento *farmToRead)
{
  Contatore scorriLista;

  for(scorriLista=0;scorriLista<farmToRead->num_maialini;scorriLista++)
  {
    printf("\nMaiale %d :",scorriLista+1);
    printf("\n\tNome :\t%s",farmToRead->pigs[scorriLista].nome);
    printf("\n\tData :\t%d/%d/%d",farmToRead->pigs[scorriLista].datanascita.giorno,farmToRead->pigs[scorriLista].datanascita.mese,farmToRead->pigs[scorriLista].datanascita.anno);
    printf("\n\tPeso :\t%f",farmToRead->pigs[scorriLista].peso);
    printf("\n\tPopolarita':\t%d",farmToRead->pigs[scorriLista].popolarita);
  }
}

/*
  Nome : OrdinamentoMaiali
  Descrizione : vengono ordinati i maiali in appositi array di puntatori. L'ordinamento avviene con algoritmo BubbleSort
                per tutti i tipi di ordinamento.
*/
void OrdinamentoMaiali(Allevamento *farm,Maialino *arrayToCompile[],int tipoOrdinamento)
{
  Contatore i,j,curCarattere;
  Maialino transferMaiale;
  bool ordineLocale;
  int checkOrder;

  switch(tipoOrdinamento)
  {
    case 1:
      for(i=0;i<farm->num_maialini;i++)
      {
        for(j=0;j<farm->num_maialini - 1;j++)
        {
          checkOrder = strcmp(farm->pigs[j].nome,farm->pigs[j+1].nome);
          if(checkOrder >= 0)
          {
            transferMaiale = farm->pigs[j];
            farm->pigs[j] = farm->pigs[j+1];
            farm->pigs[j+1] = transferMaiale;
          }
        }
      }
      for(i=0;i<N;i++)
      {
        arrayToCompile[i]=&(farm->pigs[i]);
      }
      break;
    case 2:
      for(i=0;i<farm->num_maialini;i++)
      {
        for(j=0;j<farm->num_maialini;j++)
        {
          curCarattere = 0;
          ordineLocale = false;
          do
          {
            checkOrder = Confronta(farm->pigs[j].datanascita,farm->pigs[j+1].datanascita);
            if(checkOrder == 1 || checkOrder == 0)
            {
              arrayToCompile[j] = &(farm->pigs[j]);
              ordineLocale = true;
            } else {
              transferMaiale = farm->pigs[j];
              farm->pigs[j] = farm->pigs[j+1];
              farm->pigs[j+1] = transferMaiale;
              arrayToCompile[j] = &(farm->pigs[j]);
              ordineLocale = true;
            }
          } while(ordineLocale==false);
        }
      }
      break;
    case 3:
      for(i=0;i<farm->num_maialini;i++)
      {
        for(j=0;j<farm->num_maialini - 1;j++)
        {
          if(farm->pigs[j].peso > farm->pigs[j+1].peso)
          {
            transferMaiale = farm->pigs[j];
            farm->pigs[j] = farm->pigs[j+1];
            farm->pigs[j+1] = transferMaiale;
          }
        }
      }
      for(i=0;i<N;i++)
      {
        arrayToCompile[i]=&(farm->pigs[i]);
      }
      break;
    case 4:
    for(i=0;i<farm->num_maialini;i++)
    {
      for(j=0;j<farm->num_maialini - 1;j++)
      {
        if(farm->pigs[j].popolarita > farm->pigs[j+1].popolarita)
        {
          transferMaiale = farm->pigs[j];
          farm->pigs[j] = farm->pigs[j+1];
          farm->pigs[j+1] = transferMaiale;
        }
      }
    }
    for(i=0;i<N;i++)
    {
      arrayToCompile[i]=&(farm->pigs[i]);
    }
    break;
  }
}

/*
  Nome : visualizzaMaialiOrdinati
  Descrizione : visualizza il contenuto di un array di puntatori.
*/
void visualizzaMaialiOrdinati(Maialino *arrayMaiali[],int tipoOrdine)
{
  Contatore scorriArray;

  switch(tipoOrdine)
  {
    case 1: printf("\n\nElenco maiali ordinati per Nome :"); break;
    case 2: printf("\n\nElenco maiali ordinati per data di nascita :"); break;
    case 3: printf("\n\nElenco maiali ordinati per peso :"); break;
    case 4: printf("\n\nElenco maiali ordinati per popolarita' :"); break;
  }

  for(scorriArray=0;scorriArray<N;scorriArray++)
  {
    printf("\nDati maiale %d :",scorriArray+1);
    printf("\n\tNome :\t%s",arrayMaiali[scorriArray]->nome);
    printf("\n\tData :\t%d/%d/%d",arrayMaiali[scorriArray]->datanascita.giorno,arrayMaiali[scorriArray]->datanascita.mese,arrayMaiali[scorriArray]->datanascita.anno);
    printf("\n\tPeso :\t%f",arrayMaiali[scorriArray]->peso);
    printf("\n\tPoplarita' :\t%d",arrayMaiali[scorriArray]->popolarita);
  }
}

/*
  Nome : Confronta
  Descrizione : confronta due date. Restituisce 1 se le due date sono passate in ordine crescente, 0 se sono uguali e -1 se sono
                passate in ordine descrescente.
*/
int Confronta(Data d1,Data d2)
{
  if(d1.anno < d2.anno) return 1;
  else if(d2.anno < d1.anno) return -1;
  else {
    if(d1.mese < d2.mese) return 1;
    else if(d2.mese < d1.mese) return -1;
    else {
      if(d1.giorno < d2.giorno) return 1;
      else if(d2.giorno < d1.giorno) return -1;
      else return 0;
    }
  }
}

/*
  Nome : clearScreen
  Descrizione : pulisce lo schermo del terminale.
*/
void clearScreen()
{
  system("@cls||clear");
}
