# Raccomandazioni

## Esercitazione, laboratorio e temi d'esame

Per inserire una sessione di esercitazione, laboratorio o tema d'esame adoperare le cartelle ```Esercitazioni```, ```Laboratorio``` e ```Temi d'esame``` creando una una nuova sottocartella riportando, nel nome, la data di creazione (con formato ```dd-mm-yyyy```) oppure il numero della lezione (es: ```Lab 1```) o, per ciascun esercizio svolto, il titolo del problema (con nomi minuscoli e separati da ```_```). Se necessario organizzare i file in cartelle nominate con i rispettivi cognomi di chi ha svolto gli esercizi.

È consigliato salvare nella cartella di ogni esercizio eventuali pdf relativi al problema risolto.

Si raccomanda di nominare i file degli esercizi con lo stesso nome della cartella e, in generale, utilizzando parole in minuscolo separate da ```_```.

## Esercizi vari

Per inserire eventuali esercizi supplementari adoperare la cartella ```Esercizi vari``` creando una sottocartella nominandola con il titolo dell'esercizio (con parole minuscole e separate da ```_```).

## Intestazione programmi

Per permettere una migliore comprensione dei programmi si prega di creare in ogni file ```.c``` un commento ad inizio programma rispettanto il seguente formato:

``` c
/**
 * Autore: ...
 * Scopo: ...
 * Descrizione: ...
*/
```

## Esecuzione programmi

Per l'esecuzione dei programmi creati può essere comodo inserire un file eseguibile (ad esempio chiamato ```run```) nella cartella dell'esercizio contenente il seguente codice:

``` bash
clear && gcc $1 -o compiled && ./compiled
```

In questo modo per compilare ed avvire il proprio programma basterà eseguire ```./run path_to_file```

E' possibile trovare questo file nella root della master branch (oppure è possibile crearlo e renderlo eseguibile tramite ```chmod +x run```)

N.B. Qualunque file chiamato ```compiled``` verrà ignorato da .gitignore

## Note utili

Link ftp Ing. Giulio Fontana: ftp://ftp.elet.polimi.it/users/Giulio.Fontana/didattica

Link ftp Ing. Alessandro Gabrielli: ftp://ftp.elet.polimi.it/users/ALESSANDRO.GABRIELLI/didattica

[Comandi terminale utili](./comandi_terminale)
