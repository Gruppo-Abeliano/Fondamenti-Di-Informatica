/*
  Autore : Paolo Pertino
  Descrizione : Gioco da tavolo Tic-tac-toe
  Gioco Completo
*/

#include <stdio.h>
#include <stdlib.h>

#define N 3
#define CELLA_LIBERA '-'

#ifdef __linux__
  #define OS "LINUX"
#elif __APPLE__
  #define OS "LINUX"
#else
  #define OS "WINDOWS"
#endif

//DEFINIZIONE TIPI RICHIESTI DALL'ESERCIZIO
typedef struct MOSSA
{
  int riga;
  int colonna;
  struct MOSSA *pProssimaMossa;
} Mossa;
typedef Mossa *Partita;
typedef char griglia[N][N];

//DEFINIZIONE TIPI AUSILIARI
typedef enum{false,true}bool;

//DICHIARAZIONE FUNZIONI UTILIZZATE PER DEBUGGARE
void mosseGiocatori(griglia grigliaDaCompilare);
void mostraGriglia(griglia grigliaDaLeggere);
void clearScreen();

//DICHIARAZIONE FUNZIONI RICHIESTE DALL'ESERCIZIO
char ennuplaVert(griglia g);   //Parte (a)
char ennuplaOriz(griglia g);   //Parte (b)
char ennuplaDiag(griglia g);   //Parte (c)
int esito(griglia g);          //Parte (d)
void inizializzaGriglia(griglia g);

//COLORI
void Red();
void BoldRed();
void Green();
void BoldGreen();
void Yellow();
void Blue();
void BoldBlue();
void Magenta();
void BoldMagenta();
void Cyan();
void BoldCyan();
void Reset();

int main(int argc, char const *argv[]) {
  griglia tavoloDaGioco;
  int qualeGiocatore;
  int rigaDaInserire,colonnaDaInserire;

  inizializzaGriglia(tavoloDaGioco);
  mostraGriglia(tavoloDaGioco);
  mosseGiocatori(tavoloDaGioco);

  return 0;
}

//FUNZIONI RICHIESTE DALL'ESERCIZIO, SCRITTE IN ORDINE.

void mosseGiocatori(griglia grigliaDaCompilare)
{
  int esitoGame,contaPlayer;
  int rigaInserire,colonnaInserire;

  contaPlayer = 1;

  do {
    if(contaPlayer%2 != 0)
    {
      printf("\nGiocatore X - Inserisci la tua mossa [RIGA:COLONNA] : ");
      scanf("%d:%d",&rigaInserire,&colonnaInserire);

      grigliaDaCompilare[rigaInserire-1][colonnaInserire-1] = 'X';
    } else {
      printf("\nGiocatore O - Inserisci la tua mossa [RIGA:COLONNA] : ");
      scanf("%d:%d",&rigaInserire,&colonnaInserire);

      grigliaDaCompilare[rigaInserire-1][colonnaInserire-1] = 'O';
    }
    ++contaPlayer;

    esitoGame = esito(grigliaDaCompilare);
    clearScreen();
    mostraGriglia(grigliaDaCompilare);
  } while(esitoGame==0);

  switch(esitoGame)
  {
    case 1:
      printf("\nHa vinto il giocatore X.");
      break;
    case 2:
      printf("\nHa vinto il giocatore O.");
      break;
    case 3:
      printf("\nLa partita si e' conclusa con un pareggio.");
      break;
  }
}

/*
  Nome funzione : ennuplaVert
  Parametri : dato di tipo griglia, ovvero una matrice di caratteri.
  Descrizione : cerca in una griglia compilata, se c'è una colonna che presenta il medesimo carattere
                in tutte le sue celle, ed in tal caso restituisce tale carattere.
  Esercizio 4 - Parte A
*/
char ennuplaVert(griglia g)
{
  int scorriRighe,scorriColonne;
  bool sonoUguali;

  /*
    Scorro la matrice per colonne e controllo se tutti i caratteri di una colonna sono uguali.
    In tal caso restituisco tale carattere; altrimenti viene restituito '\0'.

    NOTA BENE : l'indice interno scorre fino a N-1 in modo tale che nel controllo dell'if immediatamente
                successivo, non venga interpellata una cella non esistente(in caso non ci fosse il -1,
                verrebbe scansionata l'ultima riga e confrontata con la riga successiva, che ovviamente non
                esiste).
  */
  for(scorriColonne=0;scorriColonne<N;scorriColonne++)
  {
    sonoUguali = true;
    for(scorriRighe=0;scorriRighe<N-1;scorriRighe++)
    {
      if(g[scorriRighe][scorriColonne] != g[scorriRighe+1][scorriColonne])
      {
        sonoUguali = false;
      }
    }

    if(sonoUguali==true) return g[scorriRighe][scorriColonne];
  }

  return '\0';
}

/*
  Nome funzione : ennuplaOriz
  Parametri : dato di tipo griglia, ovvero una matrice di caratteri.
  Descrizione : cerca in una griglia compilata, se c'è una riga che presenta il medesimo carattere
                in tutte le sue celle, ed in tal caso restituisce tale carattere.
  Esercizio 4 - Parte B
*/
char ennuplaOriz(griglia g)
{
  int scorriRighe,scorriColonne;
  bool sonoUguali;

  /*
    Scorro la matrice per righe e controllo se tutti i caratteri di una riga sono uguali.
    In tal caso restituisco tale carattere; altrimenti viene restituito '\0'.

    NOTA BENE : l'indice interno scorre fino a N-1 in modo tale che nel controllo dell'if immediatamente
                successivo, non venga interpellata una cella non esistente(in caso non ci fosse il -1,
                verrebbe scansionata l'ultima colonna e confrontata con la colonna successiva, che ovviamente non
                esiste).
  */
  for(scorriRighe=0;scorriRighe<N;scorriRighe++)
  {
    sonoUguali = true;
    for(scorriColonne=0;scorriColonne<N-1;scorriColonne++)
    {
      if(g[scorriRighe][scorriColonne] != g[scorriRighe][scorriColonne+1])
      {
        sonoUguali = false;
      }
    }

    if(sonoUguali==true) return g[scorriRighe][scorriColonne];
  }

  return '\0';
}

/*
  Nome funzione : ennuplaDiag
  Parametri : dato di tipo griglia, ovvero una matrice di caratteri.
  Descrizione : cerca in una griglia compilata, se una delle due diagonali (la principale o la secondaria),
                sono compilate con il medesimo carattere, ed in tal caso restituiscono tale carattere.
  Esercizio 4 - Parte C
*/
char ennuplaDiag(griglia g)
{
  int scorriDiagonale;
  bool sonoUguali;

  sonoUguali = true;
  for(scorriDiagonale=0;scorriDiagonale<N-1;scorriDiagonale++)
  {
    if(g[scorriDiagonale][scorriDiagonale] != g[scorriDiagonale+1][scorriDiagonale+1])
    {
      sonoUguali = false;
    }
  }

  if(sonoUguali == true) return g[scorriDiagonale][scorriDiagonale];

  sonoUguali = true;
  for(scorriDiagonale=0;scorriDiagonale<N-1;scorriDiagonale++)
  {
    if(g[scorriDiagonale][(N-1)-scorriDiagonale] != g[scorriDiagonale+1][(N-1)-scorriDiagonale-1])
    {
      sonoUguali = false;
    }
  }

  if(sonoUguali == true) return g[scorriDiagonale][(N-1)-scorriDiagonale];

  return '\0';
}

/*
  Nome funzione : esito
  Parametri : dato di tipo griglia, ovvero una matrice di caratteri.
  Descrizione : Data una griglia compilata (secondo il gioco del Tris), la funzione restituisce:
                  0. se la griglia rappresenta una partita ancora in corso.
                  1. se la griglia rappresenta una partita vinta dal giocatore X
                  2. se la griglia rappresenta una partita vinta dal giocatore O
                  3. se la griglia rappresneta una partita finita in parità
  Esercizio 4 - Parte D
*/
int esito(griglia g)
{
  int esito;
  int contaRighe,contaColonne;
  char n_uplaVert,n_uplaOriz,n_uplaDiag;

  /*
    Chiamo subito le 3 funzioni precedentemente create, per verificare successivamente se qualche
    giocatore ha vinto.
  */

  n_uplaVert = ennuplaVert(g);
  n_uplaOriz = ennuplaOriz(g);
  n_uplaDiag = ennuplaDiag(g);

  /*
    Con il seguente ciclo FOR controllo che tutte le caselle della partita siano state utilizzate.

    !!! NOTA BENE !!! : il ciclo parte se non è stato decretato ancora un vincitore, ovvero se tutte
                        le variabili prima inizializzate contengono \0. Il controllo preliminare viene
                        effettuato perchè generalmente nel gioco, se un giocatore vince, la compilazione
                        della tabella non viene più portata a termine.
                        Se tuttavia, la partita è terminata e quindi la funzione non è terminata, ho già
                        incluso il caso in cui la partita sia finita in pareggio, perciò come richiesto
                        dal testo, restituisco 3.

    Se così non fosse, ciò vorrebbe dire che i giocatori stanno ancora giocando. La partita non è
    dunque ancora terminata, perciò (come richiesto dal testo) viene restituito il valore 0.
  */

  if((n_uplaVert == '\0' && n_uplaOriz == '\0' && n_uplaDiag == '\0') || (n_uplaVert == CELLA_LIBERA || n_uplaOriz == CELLA_LIBERA || n_uplaDiag == CELLA_LIBERA))
  {
    for(contaRighe=0;contaRighe<N;contaRighe++)
    {
      for(contaColonne=0;contaColonne<N;contaColonne++)
      {
        if(g[contaRighe][contaColonne] == CELLA_LIBERA) return 0;
      }
    }

    return 3;
  }

  /*
    Se il programma arriva qui, vuol dire che i giocatori hanno concluso la partita, quindi rimane
    da decretare l'esito.

    !!! NOTA BENE !!! : si presuppone che la tabella inserita sia valida, ovvero che l'inserimento
                        delle X o degli O,sia avvenuto rispettando i turni e le regole del gioco.
  */

  if(n_uplaVert == 'X' || n_uplaOriz == 'X' || n_uplaDiag == 'X') return 1;
  else return 2;
}

/*
  Nome funzione : inizializzaGriglia
  Parametri : dato di tipo griglia, ovvero una matrice di caratteri.
  Descrizione : data una griglia di caratteri, la funzione la inizializza settando il carattere '-' in tutte
                le sue celle.
  Esercizio 4 - Parte E
*/
void inizializzaGriglia(griglia g)
{
  int contaRighe,contaColonne;

  for(contaRighe=0;contaRighe<N;contaRighe++)
  {
    for(contaColonne=0;contaColonne<N;contaColonne++)
    {
      g[contaRighe][contaColonne] = CELLA_LIBERA;
    }
  }
}

//FUNZIONI DI DEBUGGING - NON RILEVANTI PER LO SVOLGIMENTO DELL'ESERCIZIO

/*
  Nome funzione : mostraGriglia
  Parametri : dato di tipo griglia, ovvero una matrice di caratteri
  Descrizione : la funzione stampa a schermo la griglia passata come parametro.
  Esercizio 4 - Funzione Debugging
*/
void mostraGriglia(griglia grigliaDaLeggere)
{
  int contaRighe,contaColonne;

  for(contaRighe=0;contaRighe<N;contaRighe++)
  {
    for(contaColonne=0;contaColonne<N;contaColonne++)
    {
      if(grigliaDaLeggere[contaRighe][contaColonne] == 'X' && OS == "LINUX") BoldRed();
      else if(grigliaDaLeggere[contaRighe][contaColonne] == 'O' && OS == "LINUX") Red();
      else Reset();
      printf("%c\t",grigliaDaLeggere[contaRighe][contaColonne]);
      Reset();
    }
    printf("\n");
  }
}

/*
  Nome funzione : clearScreen
  Parametri : void
  Descrizione : la funzione, quando chiamata, pulisce il terminale.
  Esercizio 4 - Funzione Debugging
*/
void clearScreen()
{
  system("@cls||clear");
}

//COLORI

void Red()
{
  if(OS == "LINUX") printf("\033[0;31m");
  else system("color C");
}

void BoldRed()
{
  if(OS == "LINUX") printf("\033[1;31m");
  else system("color 4");
}

void Green()
{
  if(OS == "LINUX") printf("\033[0;32m");
  else system("color A");
}

void BoldGreen()
{
  if(OS == "LINUX") printf("\033[1;32m");
  else system("color 2");
}

void Yellow()
{
  if(OS == "LINUX") printf("\033[0;33m");
  else system("color E");
}

void Blue()
{
  if(OS == "LINUX") printf("\033[0;34m");
  else system("color 9");
}

void BoldBlue()
{
  if(OS == "LINUX") printf("\033[1;34m");
  else system("color 1");
}

void Magenta()
{
  if(OS == "LINUX") printf("\033[0;35m");
  else system("color D");
}

void BoldMagenta()
{
  if(OS == "LINUX") printf("\033[1;35m");
  else system("color 5");
}

void Cyan()
{
  if(OS == "LINUX") printf("\033[0;36m");
  else system("color B");
}

void BoldCyan()
{
  if(OS == "LINUX") printf("\033[1;36m");
  else system("color 3");
}

void Reset()
{
  if(OS == "LINUX") printf("\033[0m");
  else system("color F");
}
