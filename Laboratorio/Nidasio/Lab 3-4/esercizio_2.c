#include <stdio.h>

#define CAPIENZA 10
#define TERMINATORE '0'

typedef char ArrayCaratteri[CAPIENZA];
typedef struct
{
  ArrayCaratteri caratteri;
  int numeroElementi;
} TipoL;

void leggiListaCaratteri(TipoL *lista, int n);
int trovaOccorrenze(TipoL listaSequenziale, char daTrovare);
void mostraLista(TipoL lista);

int main() {
  TipoL lista;
  int n;

  printf("Scegli quanti caratteri inserire (massimo %d):", CAPIENZA);
  scanf("%d", &n);

  // Popolo la lista sequenziale
  leggiListaCaratteri(&lista, n);

  // La mostro a schermo
  mostraLista(lista);
}

// Riepe la lista con lettere minuscole e diverse tra loro (anche se non era da fare)
void leggiListaCaratteri(TipoL *lista, int n) {
  // Creo un'istanza di tipo TipoL
  lista->numeroElementi = 0;

  if(n > CAPIENZA) n = CAPIENZA;

  // Riempio tutti i posti della lista sequenziale
  int i;
  for(i = 0; i < n; i++) {
    // Leggo un carattere da tastiera e lo inserisco nella lista
    printf("Inserici un carattere per la posizione %d: ", i + 1);
    fflush(stdin);
    scanf("%c", &lista->caratteri[i]);
    fflush(stdin);
    lista->numeroElementi++;

    // Controllo se l'utente ha inserito il carattere teminatore
    if(lista->caratteri[i] == TERMINATORE) {
      lista->numeroElementi--;
      printf("hey\n");
      return; // Oppure i = CAPIENZA per terminare il ciclo
    }

    // Controllo se il carattere inserito è un carattere piccolo
    if(lista->caratteri[i] < 97 || lista->caratteri[i] > 122) {
      // Il carattere inserito è già presente
      printf("Il carattere inserito non è valido ed è stato ignorato\n");
      lista->numeroElementi--;
      i--;
    }

    // Controllo se questo carattere ha più di una occorrenza nell'array
    if(trovaOccorrenze(*lista, lista->caratteri[i]) >= 2) {
      // Il carattere inserito è già presente
      printf("Il carattere inserito è già presente\n");
      lista->numeroElementi--;
      i--;
    }
  }
}

// Questa funzione cerca un elemento all'interno della lista sequenziale data. Restituisce il numero di occorrenze
int trovaOccorrenze(TipoL listaSequenziale, char daTrovare) {
  // Cerco negli elementi della lista il carattere specificato
  int i, occorrenze = 0;
  for(i = 0; i < listaSequenziale.numeroElementi; i++)
    if(listaSequenziale.caratteri[i] == daTrovare) occorrenze++;
  return occorrenze;
}

// Mosta la lista nella console
void mostraLista(TipoL lista) {
  printf("La lista contiene %d elementi\n", lista.numeroElementi);

  int i;
  for(i = 0; i < lista.numeroElementi; i++) {
    printf("Elemento %d: %c\n", i, lista.caratteri[i]);
  }
}