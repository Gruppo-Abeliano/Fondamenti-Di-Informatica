# Quesito 1
## Testo
Calcolare la rappresentazione in base 2 del numero frazionario 0.4. Osservando che 0.4 è pari a 2/5, calcolare la rappresentazione in virgola mobile del numero 1/10.

## Svolgimento
0.4 * 2 = 0.8    ---  0
0.8 * 2 = 1.6    ---  1
0.6 * 2 = 1.2    ---  1
0.2 * 2 = 0.4    ---  0
...
periodo
...

(0.4)dec = (0.0110)bin con periodo 0110

Per rappresentare il numero 1/10 nella forma in virgola mobile, devo trovare quella potenza di 2 che moltiplicata a tale numero mi fornisca un valore compreso tra 1 e 2.

In questo caso è 2^4, perchè 2^4 = 16, che moltiplicata ad 1/10 fornisce 1.6.

1/10 = (segno).esponente_polarizzato(ovvero (-4+127)bin).mantissa

Segno = 0, perchè il numero è positivo
Esponente polarizzato = (123)bin = 01111011
123/2 = 61 resto 1
61/2  = 30 resto 1
30/2  = 15 resto 0
15/2  = 7  resto 1
7/2   = 3  resto 1
3/2   = 1  resto 1
1/2   = 0  resto 1

Mantissa: 10011001100110011001100
So che 1/10 * 2^4 = 16/10 = 1 + 3/5

3/5 * 2 = 6/5    ---   1
1/5  * 2 = 2/5    ---   0
Utilizzo ora il risultato prima ottenuto, ovvero il periodo 0110 e ricavo velocemente la mantissa

## Risultato
(0.4)dec = (0.0110)bin con periodo 0110
(1/10)dec = (0 01111011 10011001100110011001100)IEEE754


Tempo di risoluzione = 10 minuti
