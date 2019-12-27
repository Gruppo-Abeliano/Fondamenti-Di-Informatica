# Quesito 3
## Testo
Cosa stampa a schermo il seguente programma?

``` bash
#include <stdio.h>

void Funz(char *S):

int main()
{
  char S[100] = "abcdefghilmnopq";
  Funz(S);
  return 0;
}

void Funz(char *S)
{
  if('\0' != S[0])
  {
    Funz(S+1);
    printf("%c", *S);
  }
}
```

## Risposta
Il programma stampa semplicemente la stringa letta al contrario, ovvero qponmlihgfedcba.

Tempo Risposta: 1 minuto.
