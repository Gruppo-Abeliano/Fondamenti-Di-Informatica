# Esercizio - Gioco Tris

Si consideri una matrice (o griglia) di caratteri di dimensione NxN, definita come segue:
typedef char griglia[N][N];

## Parte A
Si codifichi in C una funzione char ennuplaVert(griglia g) che, se esiste una colonna in g costituita da un allineamento verticale di N caratteri tutti uguali, restituisce il carattere presente su tale colonna, altrimenti restituisce il carattere ‘\0’. Si trascuri il caso in cui più colonne godano della proprietà da verificare, considerando il primo allineamento rilevato (ad es., il più a sinistra).

## Parte B
Si codifichi una funzione char ennuplaOriz(griglia g) che effettui analoga verifica per un allineamento orizzontale.

## Parte C
Si codifichi in C una funzione char ennuplaDiag(griglia g) che verifica in modo analogo alle precedenti se vi è un allineamento su una delle due diagonali principali.

## Parte D
Nel popolarissimo gioco del tic tac toe (tris in italiano) i giocatori tentano di disporre 3 simboli uguali su una griglia 3x3 apponendovi a turno delle 'X' (il simbolo del 1° giocatore) e delle 'O' (simbolo del 2°). Nella griglia a lato la partita è terminata in parità (come sempre succede, se nessun giocatore commette errori). Vogliamo generalizzare il gioco al caso NxN, usando le definizioni dei punti precedenti. Si codifichi in C una funzione int esito(griglia g) che restituisce 0 se la partita rappresentata da g non è finita, 1 se ha vinto il “giocatore X”, 2 se ha vinto il “giocatore O”, 3 se è un pareggio.

## Parte E
Si consideri la seguente definizione di una partita rappresentata come lista di mosse, in cui ogni mossa è una coppia di interi compresi tra 0 e N-1 che indicano la riga e la colonna in cui i giocatori appongono i simboli. La prima mossa è del giocatore X, la seconda del giocatore O, … . Si assuma per semplicità che le mosse di una partita siano sempre valide (coordinate corrette, simboli non sovrapposti, …).
``` bash
typedef struct mo
{
  int  r,c;  
  struct mo * next;
} Mossa;
typedef Mossa * Partita;
```
Si codifichi in C una funzione ...gioca(...) che riceve come parametro una Partita e ne indica l’esito finale secondo le convenzioni del punto precedente (simulandone opportunamente l’esecuzione, applicando le mosse ad una griglia inizialmente vuota).
