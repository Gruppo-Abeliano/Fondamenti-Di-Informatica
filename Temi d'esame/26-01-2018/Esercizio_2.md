# Quesito 2

## Produzione di spazzatura
E' memoria allocata(non libera) e non accessibile.
Il fenomeno si verifica quando un puntatore punta ad una variabile dinamica, e successivamente, per una particolare istruzione, il puntatore stesso cambia indirizzo e punta ad altro. Non avendo però deallocato la memoria puntata precedentemente, essa non è più accessibile ed è dunque memoria occupata inutilizzabile.
Per risolvere il problema, è necessario essere accorti e precedere il cambio di indirizzo del puntatore con il comando di deallocazione free(puntatore).

## Dangling references(riferimenti fluttuanti)
Sono puntatori a zone di memoria deallocata.
Esempio :
``` bash
  int *p,*q;
  q = malloc(sizeof(int));
  p=q;
  free(q);
```
Alla fine dell'esecuzione p punta a memoria deallocata.
Per la risoluzione, ricordarsi di resettare a NULL il contenuto di p.

## Riferimenti a variabili automatiche
Sono puntatori che puntano inizialmente a variabili automatiche (allocate e deallocate automaticamente), tuttavia successivamente ad un particolare evento del programma, essi puntano a memoria deallocata, come nell'esempio che segue
Esempio :
``` bash
int *boh();
int main() {
  int x=1;
  int *p;
  p = boh();
  printf("Risultato%d",*p);
  return 0;
}
int *boh() {
  int x=55;
  return(&x);
}
```
Con l'esecuzione del codice viene effettivamente stampato 55, tuttavia dopo l'esecuzione di boh(), p punta a memoria deallocata.
Per risolvere, basterebbe resettare a NULL il contenuto di p.
