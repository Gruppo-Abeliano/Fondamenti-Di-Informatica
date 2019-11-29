# Quesito 1

## Testo
Si consideri il numero razionale 1/12. Calcolarne la mantissa(compresa tra 1 e 2) e l'esponente in base 2; fornire la rappresentazione di -1/12 in virgola mobile in singola precisione secondo il formato IEEE 754

## Svolgimento
Per trovare l'esponente devo trovare quella potenza di 2 che moltiplicata a 1/12 mi fornisca un valore compreso tra 1 e 2. In questo caso 2^4.

  1/12 = (1 + 1/3) * 2^(-4)

  SGN * 1.MANTISSA * 2^(-4+127) ---> dove -4+127 è la polarizzazione dell'esponente.

  per trovare la mantissa, dunque, converto

  (1/3)dec ---> (1/3)bin
  (1/3) * 2 = (2/3) --- 0 ---
  (2/3) * 2 = (4/3) --- 1 ---  (4/3 - 1 = 1/3)
  (1/3) * 2 = (2/3) --- 0 ---
  (2/3) * 2 = (4/3) --- 1 --- (4/3 - 1 = 1/3)
  ...
  ... periodico

  La mantissa vale dunque : 01010101010101010101010

  Per trovare l'esponente invece converto

  (123)dec ---> (123)bin
-> 01111011


## Mantissa 01010101010101010101010
## Esponente 01111011

## -1/12 in IEEE754

Assegno 1 al primo bit per il segno -
Utilizzo l'esponente e la mantissa precedentemente calcolati per fornire il risultato

## (-1/12)IEEE754 = 1 | 01111011 | 01010101010101010101010




Tempo esecuzione dell'esercizio : 7 minuti
