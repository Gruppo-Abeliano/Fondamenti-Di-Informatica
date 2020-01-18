# Esercizio 2 prova 2018-01-26

## Produzione di spazzatura

La produzione di spazzatura si verifica quando non è più possibile accedere ad una cella di memoria allocata.
Questo fenomeno può verificare, ad esempio, quando nella rimozione di un elemento da una lista dinamica non si
utilizza la funzione free per deallocare l'elemento da rimuovere. Non eseguendo free la cella di memoria non viene
deallocata e ne si perde il puntatore per accederci.
Per evitare questo preblema bisogna prestare attenzione nell'utilizzo dei puntatori prestando l'accortezza necessaria
a utilizzare la funzione free ogni qualvota si cambia il valore di un puntatore perdendo l'indirizzo di una cella.

## Dangling references

I riferimenti fluttuanti sono degli indirizzi a celle di memoria non più allocate allo stesso programma. In queste
celle possono essere presenti dei valori casuali in quanto potrebbero essere utilizzate da altri programmi o contenere
valori residui da precedenti esecuzioni.
Questo fenomeno può verificarsi ad esempio:

- Quando si utilizza la funzione free senza poi assegnare NULL al puntatore. In quest'ultimo rimano l'indirizzo della cella
  di memoria che non è più allocata al programma.
- Oppure se si incrementa il puntatore di un array più volte rispetto alla sua dimensione (il puntatore potrebbe finire su una cella di
  un'altro programma). Talvolta in funzioni ricorsive si passa alla successiva iterazione il puntatore di un array incrementato di 1 (molto
  spesso questo avviene con le stringhe).

Per evitare questo problema, come per gli altri, bisogna prestare attenzione ricordandosi si impostare a NULL i puntatori dopo
l'utilizzo di free e, nel caso degli array implementare dei controlli appropriati per rilevare la loro fine.

## Riferimenti a variabili automatiche

Le variabili automatiche sono le variabili presenti in un blocco di codice, o meglio quelle destinate a un sottoprogramma specifico e non
dichiarate globalmente. Queste variabili vengono allocate a runtime e sono accessibili soltanto al blocco di codice a cui appartengono.
I riferimenti a queste variabili, tramite puntatori può causare errori o comportamenti non prevedibili. Ad esempio se una funzione
restituisce un puntatore a una variabile allocata all'interno della funzione (ovvero a una su variabile automatica appartenente) quest'ultimo,
quando verrà utilizzato nella funzione chiamante sarà simile a una dengling reference sicome punta a una variabile che è stata deallocata (siccome era una variabile automatica della funzione).
Per risolvere questo problema bisogna capire se il puntatore a variabile automatica che si utilizza potrebbe puntare a una cella di memoria
deallocata, l'esempio proposto prima è concettualmente errato ad esempio (una sua possibile soluzione potrebbe essere quella di restituire
il valore e non il puntatore, oppure passare alla funzione il puntatore a una cella di memoria in cui inserire il risultato).
