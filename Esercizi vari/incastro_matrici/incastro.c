#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 2

typedef enum{false,true}bool;

/*
  * Funzione richiesta dall'esercizio
*/
void incastro(int mat1[][N],int mat2[][M],int *riga,int *colonna);
bool verificaIncastro(int mat1[][N],int mat2[][M],int rigaCorrente,int colonnaCorrente);

/*
  * Funzioni utilizzate per debuggare
*/
void compilaMatrici(int matriceDaCompilare1[][N],int matriceDaCompilare2[][M]);
void leggiMatrici(int matriceDaLeggere1[][N],int matriceDaLeggere2[][M]);

/*
  * Main function :
  * - Dichiarazione variabili da utilizzare,
  * - Compilazione matrici
  * - Chiamata funzione incastro
  * - Output phase
*/
int main(int argc, char const *argv[]) {
  int matriceGrande[N][N],matricePiccola[M][M];
  int rigaIncastro,colonnaIncastro;

  /*
    * Compilo le due matrici, quella grande e quella piccola.
    * Le mostro infine a schermo.
  */
  compilaMatrici(matriceGrande,matricePiccola);

  system("@cls||clear"); //NON GUARDARE. SERVE SOLO A PULIRE IL TERMINALE

  leggiMatrici(matriceGrande,matricePiccola);

  /*
    * Eseguo l'algoritmo per la ricerca del punto di incastro della matrice piccola.
    * I parametri passati alla funzione sono:
    *   1. Matrice grande
    *   2. Matrice piccola
    *   3. Indirizzo della cella di memoria che deve contenere la riga di incastro
    *   4. Indirizzo della cella di memoria che deve contenere la colonna di incastro
  */
  incastro(matriceGrande,matricePiccola,&rigaIncastro,&colonnaIncastro);

  /*
    * Gestisco il risultato ottenuto:
    *   1. Se in rigaIncastro e colonnaIncastro è contenuto il valore -1, allora non è stato trovato un punto
    *      di incastro.
    *   2. Altrimenti viene mostrato in output il punto di incastro.
  */
  if(rigaIncastro == -1 && colonnaIncastro == -1) printf("\nNessun punto di incastro trovato.");
  else printf("\nRiga incastro : %d\nColonna incastro : %d\n",rigaIncastro,colonnaIncastro);

  return 0;
}

/*
  * Funzione incastro :
  *   - la funzione verifica se è possibili incastrale la seconda matrice(quella più piccola) nella prima,
  *     in modo tale che nessun elemento positivo della matrice piccola si vada a sovrapporre con un elemento
  *     positivo della matrice grande.
  *   - Se l'incastro come definito prima è possibile, la funzione inserisce nelle variabili riga e colonna,
  *     il punto di incastro (ovvero il punto della matrice grande ove si inserisce l'angolo in alto a sinistra
  *     della matrice piccola); altrimenti viene inserito in tali variabili il valore -1.
*/
void incastro(int mat1[][N],int mat2[][M],int *riga,int *colonna)
{
  int scorriRiga,scorriColonna;
  bool incastroTrovato;

  /*
    * Utilizzo una variabile booleana per verificare quando trovo un punto di incastro. Quest'ultimo
    * viene ricercato utilizzando una funzione ausiliaria definita di seguito.
  */
  incastroTrovato = false;
  /*
    * scorriRiga e scorriColonna non possono scorrere tutta la matrice, altrimenti durante il controllo,
    * la matrice più piccola sborderebbe fuori da quella più grande e non sarebbe sovrapponibile.
    * ALLEGO NELLA STESSA DIRECTORY DI QUESTO FILE 2 IMMAGINI, CHE CERCANO DI RENDERE CHIARO IL PROBLEMA
    * CHE SI PRESENTEREBBE IN CASO NON VENISSE FATTA QUEST'OSSERVAZIONE.
  */
  for(scorriRiga = 0;scorriRiga<N-M+1 && incastroTrovato == false;scorriRiga++)
  {
    for(scorriColonna = 0;scorriColonna<N-M+1 && incastroTrovato == false;scorriColonna++)
    {
      incastroTrovato = verificaIncastro(mat1,mat2,scorriRiga,scorriColonna);
    }
  }

  /*
    * Se trovo l'incastro segno le coordinate corrette :
    *   NOTA BENE : il -1 non è casuale, in quanto quando il ciclo for si interrompe quando la variabile
    *               booleana diventa true, tuttavia per entrambi i cicli viene incrementato di 1 il
    *               valore del contatore e successivamente viene interroto il ciclo (questo incremento
                    viene fatto proprio per costruzione del costrutto for).
  */
  if(incastroTrovato == true)
  {
    *riga = scorriRiga - 1;
    *colonna = scorriColonna - 1;
  } else {
    *riga = -1;
    *colonna = -1;
  }
}

bool verificaIncastro(int mat1[][N],int mat2[][M],int rigaCorrente,int colonnaCorrente)
{
  int scorriRiga,scorriColonna;

  /*
    * Viene semplicemente verificato come richiesto dal testo, che la matrice piccola si possa inserire
    * in una determinata posizione :
    *   - questo controllo viene effettuato scorrendo la matrice grande da una determinata posizione;
    *     dato quel punto in input alla funzione, viene comparata la sottomatrice 2x2 della matrice grande
    *     con la matrice piccola, e confronto parallelamente le singole celle delle due matrici.
    *   - Se incontro due valori entrambi positivi (rispettivamente nella cella della matrice piccola, e
    *     nella cella della sottomatrice 2x2) allora la matrice piccola non è sovrapponibile a partire da
    *     quel punto, pertanto restituisco false. (Ricordiamo che la matrice è sovrapponibile se e solo se
    *     tutti gli elementi positivi della matrice grande non sono in compresenza di elementi positivi della
    *     matrice piccola).
  */
  for(scorriRiga = 0;scorriRiga<M;scorriRiga++)
  {
    for(scorriColonna = 0;scorriColonna<M;scorriColonna++)
    {
      if(mat2[scorriRiga][scorriColonna] > 0 && mat1[rigaCorrente+scorriRiga][colonnaCorrente+scorriColonna] > 0) return false;
    }
  }

  /*
    * Se arrivo qui, la matrice è incastrabile(/sovrapponibile) nel punto passato come input, pertanto
    * restituisco true.
  */
  return true;
}


/*
  * Funzione di debugging :
  *   1. compilaMatrici - compila le matrici
  *   2. leggiMatrici   - stampa a schermo le matrici
*/
void compilaMatrici(int matriceDaCompilare1[][N],int matriceDaCompilare2[][M])
{
  int scorriRiga,scorriColonna;

  printf("\nInserimento matrice grande :\n");
  for(scorriRiga = 0;scorriRiga<N;scorriRiga++)
  {
    for(scorriColonna = 0;scorriColonna<N;scorriColonna++)
    {
      printf("Inserisci l'elemento [%d:%d] : ",scorriRiga+1,scorriColonna+1);
      scanf("%d",&matriceDaCompilare1[scorriRiga][scorriColonna]);
    }
  }

  printf("\nInserimento matrice piccola :\n");
  for(scorriRiga = 0;scorriRiga<M;scorriRiga++)
  {
    for(scorriColonna = 0;scorriColonna<M;scorriColonna++)
    {
      printf("Inserisci l'elemento [%d:%d] : ",scorriRiga+1,scorriColonna+1);
      scanf("%d",&matriceDaCompilare2[scorriRiga][scorriColonna]);
    }
  }
}

void leggiMatrici(int matriceDaLeggere1[][N],int matriceDaLeggere2[][M])
{
  int scorriRiga,scorriColonna;

  printf("\nMatrice grande :\n");
  for(scorriRiga = 0;scorriRiga<N;scorriRiga++)
  {
    for(scorriColonna = 0;scorriColonna<N;scorriColonna++)
    {
      printf("%d\t",matriceDaLeggere1[scorriRiga][scorriColonna]);
    }
    printf("\n");
  }

  printf("\nMatrice piccola :\n");
  for(scorriRiga = 0;scorriRiga<M;scorriRiga++)
  {
    for(scorriColonna = 0;scorriColonna<M;scorriColonna++)
    {
      printf("%d\t",matriceDaLeggere2[scorriRiga][scorriColonna]);
    }
    printf("\n");
  }
}
