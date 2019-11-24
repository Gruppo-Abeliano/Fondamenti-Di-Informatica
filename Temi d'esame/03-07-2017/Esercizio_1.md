# Quesito 1

## Testo
a - Rappresentare in base 2 il numero decimale 0.6
b - Sapendo che 0.6 è pari a 3/5, calcolare la rappresentazione in virgola mobile del numero 3/40

## Svolgimento

a)
0.6 * 2 = 1.2  --- 1 ---  (1.2-1=0.2)
0.2 * 2 = 0.4  --- 0 ---
0.4 * 2 = 0.8  --- 0 ---
0.8 * 2 = 1.6  --- 1 ---  (1.6-1=0.6)
...
... periodico

## Risposta (a) = [0.6]dec = [0.1001]bin (periodico con periodo 1001)

b) 3/40 -- Devo cercare una potenza di 2 che mi fornisca, moltiplicata al valore di partenza, un numero compreso tra 1 e 2.
           In questo caso la potenza cercata è 16 (dunque 2^4).

   3/40 = (1 + 1/5) * 2^(-4)

   SGN * 1.MANTISSA * 2^(-4+127) ---> dove -4+127 è la polarizzazione dell'esponente.

   (1/5)dec ---> (1/5)bin
  -> 0.2 * 2 = 0.4 --- 0 ---
     0.4 * 2 = 0.8 --- 0 ---
     0.8 * 2 = 1.6 --- 1 ---      (1.6-1=0.6)
     0.6 * 2 = 1.2 --- 1 ---      (1.2-1=0.2)
     ...
     ... periodico

     (123)dec ---> (123)bin
  -> 01111011

## Risposta (b) = [3/40]dec = [ 0 | 01111011 | 00110011001100110011001 ]IEEE754 singola precisione
