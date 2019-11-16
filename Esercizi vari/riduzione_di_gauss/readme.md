# Metodo di riduzione di Gauss
Autore: Alberto Nidasio

Scopo: Eseguire la riduzione di Gauss
## Descrizione:
Questo programma esegue il metodo della riduzione di Gauss
che si sviluppa in questi 3 passaggi:
1. Si ordinano le righe per la posizione dei propri pivot
2. Si modificano le righe successive alla prima in modo tale che i loro pivot non siano nella stessa posizione di quello della prima riga (tramite la moltiplicazione)
3. Si ripete il procedimento dal punto 1 considerando la matrice senza la prima riga

## Come provare la libreria
Tra i file della libreria è presente ```librarytest.c``` che permette di testare le funzionalità del codice.
Per eseguirlo usare i seguenti comandi:
```console
user@pc:riduzione_di_gauss$ make && ./librarytest
...
Inserisci il numero di righe della matrice: 3
Insersci il numero di colonne della matrice: 4
Preparati ad inserire gli elementi del vettore (3, 4)
Riga n 1
        Inserisci il parametro n 1:
...
```
Per utilizzarla nel tuo progetto compilala 