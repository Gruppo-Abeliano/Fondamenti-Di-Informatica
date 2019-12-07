# Esercizio 3

## Testo
Si consideri il seguente programma C. Allo studente è richiesto di:

  1. Sostituire il proprio numero di matricola alle cifre tra virgolette nella istruzione indicata con @@@
  2. indicare che cosa stampa a schermo il programma.

  ``` bash
  #include <stdio.h>
  #define MAX 100
  void M(char *S1, char *S2, char *S3);

  int main()
  {
    char A[MAX] = "test";
    char B[MAX] = "000000";    /* @@@ */
    char C[2*MAX];
    M(A, B, C);
    return 0;
  }

  void M(char *S1, char *S2, char *S3)
  {
    if (('\0' == *S1) && ('\0' == *S2))
    {
      *S3 = '\0';
      return;
    }

    if ('\0' != *S2)
    {
      *S3 = *S1;
      ++S1;
      ++S3;
    }

    if ('\0' != *S2)
    {
      *S3 = *S2;
      ++S2;
      ++S3;
    }

    M(S1, S2, S3);
  }
  ```

  Sostituendo alla riga indicata con @@@ il mio numero di matricola (ovvero 937175), il risultato è t9e3s7t175

  N.B. : non viene stampato il carattere \0 perchè scanf legge la stringa fino a tale carattere escludendolo.


  Tempo esecuzione : 5 minuti. 
