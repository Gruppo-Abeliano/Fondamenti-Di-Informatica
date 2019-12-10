# Passaggio parametri al programma

Partiamo con un esempio :
``` bash
gcc -Wall -o test mioProg.c
```

Sto chiamando il programma gcc passandogli una serie di parametri :
  1. -Wall
  2. -o
  3. test
  4. mioProg.c


Vogliamo ora passare qualcosa al programma main()
Il formato di main, pertanto è il seguente

``` bash
int main(int argc, char *argv[])
{
  ...
}
```

  - argc = ARGUMENT COUNT - ovvero conteggio dei parametri. Assume automaticamente il numero di parametri complessivi che
  c'erano sulla linea di comando. Anche il nome del programma è parametro.

  Secondo l'esempio fatto precedentemente, ovvero quello per l'esecuzione del programma gcc, argc ha valore 5("gcc","-Wall","-o","test" e "mioProg.c"). Tutti i parametri sono passati come stringhe.

  - argv[] = ARGUMENT VECTOR - array di puntatori a carattere. Ha tanti elementi quanto è il valore assunto da argc. Sono puntatori al primo carattere di ciascuna delle stringhe passate al programma come parametro.
  (Sempre facendo riferimento all'esempio precedente, argv ha dimensione 5 (char* argv[5]) e contiene pertanto 5 puntatori ai 5 primi caratteri delle 5 stringhe passate al programma come parametri).

## PROPRIETA'
argc >= 1, in qualsiasi situazione, perchè il nome del programma ci sarà sempre.

Se il programma accetta parametri che contengono spazi, devo mettere la frase tra ""
ESEMPIO :
  ./leggiFrase Il mio gatto -> al programma passo 4 parametri (argc = 4 ||| char* argv[4])
  ./leggiFrase "Il mio gatto" -> al programma passo 2 parametri (argc = 2 ||| char* argv[2])

## PARSING
E' detta Parsing l'operazione di interpretazione di ciò che è stato passato al programma, quindi dell'interpretazione delle stringhe contenenti i parametri.
