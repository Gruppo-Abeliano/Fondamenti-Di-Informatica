#include <stdio.h>

#define CAPIENZA 10

typedef char ArrayCaratteri[CAPIENZA];
typedef struct
{
  ArrayCaratteri caratteri;
  int numeroElementi;
} TipoL;

void leggiListaCaratteri(TipoL *lista);
int trovaOccorrenze(TipoL listaSequenziale, char daTrovare);
void mostraLista(TipoL lista);

int main() {
  TipoL lista;

  // Popolo la lista sequenziale
  leggiListaCaratteri(&lista);

  // La mostro a schermo
  mostraLista(lista);
}

// Riepe la lista con lettere minuscole e diverse tra loro (anche se non era da fare)
void leggiListaCaratteri(TipoL *lista) {
  // Creo un'istanza di tipo TipoL
  lista->numeroElementi = 0;

  // Riempio tutti i posti della lista sequenziale
  int i;
  for(i = 0; i < CAPIENZA; i++) {
    // Leggo un carattere da tastiera e lo inserisco nella lista
    printf("Inserici un carattere per la posizione %d: ", i + 1);
    scanf("%c%*c", &lista->caratteri[i]);
    lista->numeroElementi++;

    // Controllo se il carattere inserito è un carattere piccolo
    if(lista->caratteri[i] < 97 || lista->caratteri[i] > 122) {
      // Il carattere inserito è già presente
      printf("Il valore inserito non è una lettera minuscola \n");
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