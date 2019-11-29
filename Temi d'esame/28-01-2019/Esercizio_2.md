# Quesito 2

## Testo
Dato il numero frazionario 2/5 (due quinti), calcolarne la rappresentazione floating point a singola precisione secondo il formato IEEE 754

## Svolgimento
Ricordiamo che il formato IEEE 754 prevede una struttura del genere

  SGN * 2^(exp + 127) * 1.MANTISSA

Essendo 2/5 positivo, posso affermare che il bit da utilizzare per il segno è 0.

Per trovare l'esponente(da polarizzare), devo trovare quella potenza di 2 tale che se moltiplicata a 2/5 mi fornisce un valore compreso tra 1 e 2. Nel nostro caso è 2, infatti

-> 2/5 = 8/5 * 2^(-2)

L'esponente polarizzato sarà dunque -2 + 127 = 125, da trasformare in base 2.

125/2 = 62 resto 1
62/2  = 31 resto 0
31/2  = 15 resto 1
15/2  = 7  resto 1
7/2   = 3  resto 1
3/2   = 1  resto 1
1/2   = 0  resto 1

(125)dec = (01111101)bin

Rimane da calcolare la mantissa del numero.

2/5 * 2 = 4/5  --- 0 ---
4/5 * 2 = 8/5  --- 1 --- (8/5 - 1 = 3/5)
3/5 * 2 = 6/5  --- 1 --- (6/5 - 1 = 1/5)
1/5 * 2 = 2/5  --- 0 ---
...
... periodico

Mantissa = 01100110011001100110011

## Risultato

(2/5)IEEE754 = 0 | 01111101 | 01100110011001100110011



Tempo impiegato = 8 minuti
