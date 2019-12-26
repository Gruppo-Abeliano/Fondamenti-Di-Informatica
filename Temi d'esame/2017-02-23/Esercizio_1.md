# Esercizio 1 - Testo

## Parte A
Dati due numeri A = +57 in base 10 e B = +3A in base 16, effettuare la conversione in base 2, notazione complemento a 2 (2C2), sul numero minimo di bit necessari a rappresentare entrambi gli operandi.

## Parte B
Si effettuino quindi le operazioni A+B e A-B indicando esplicitamente se si verifichi o meno overflow e motivando la risposta. Mostrare i passaggi svolti.

# Svolgimento

## Parte A

(57)dec = (00111001)bin = (00111001)c2
(3A)esa = (00111010)bin = (00111010)c2

Il primo bit della codifica C2C è riservato al segno, tuttavia possiamo esprimere gli stessi numeri appena descritti con il numero minimo di bit necessari, per trasmettere l'informazione, ovvero in questo caso 7.

(57)dec = (0111001)c2
(3A)esa = (0111010)c2

## Parte B

A+B = 0111001 + 0111010 = 1010011
Avendo utilizzato solamente 7 bit per la descrizione dei numeri, la loro somma va in overflow, in quanto il numero sommato non è rappresentabile in soli 7 bit. Mi accorgo dell'overflow perchè la somma di due numeri positivi deve essere positiva, tuttavia il primo bit del risultato in C2C è un 1, dunque il risultato è negativo --> OVERFLOW

A-B = va trasformato in A+(-B), dunque va calcolato -(3A) in C2C

(3A)esa = (58)dec
-(58)dec = (11000110)c2

A-B = A+(-B) = 00111001 + 11000110 = (11111111)c2

I segni dei due addendi sono discordi, perciò non si verifica OVERFLOW.


Tempo esecuzione : 15 minuti.
