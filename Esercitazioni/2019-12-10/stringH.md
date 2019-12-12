# Libreria <string.h>

## Intestazione della libreria
Includere la libreria :
``` bash
#include <string.h>
```

## Funzioni Utili

1. strlen - String lenght
``` bash
size_t strlen(const char* Stringa)
```

  Parametri attesi : Stringhe, ovvero array di caratteri terminate da \0.
  Valore restituito : numero di caratteri contenuti nella stringa a partire dalla posizione passata (escluso \0).

  NOTA BENE:
  definito :
  ``` bash
  char stringa[6] = "Gatto";
  printf("%d",stringa+2);
  ```
  verrà stampato a schermo 3, perchè io passo alla funzione la posizione della prima lettera 't',

2. strcpy - String copy
``` bash
char* strcpy(char *Destinazione,const char *Origine)
```

  Parametri attesi : un array di caratteri in cui viene copiata la stringa di origine, stringa di origine.
  Parametri restituiti : puntatore a char (inutilizzato).

3. strcmp - String compare
``` bash
int strcmp(const char *str1,const char *str2)
```

  Parametri attesi : due stringhe da confrontare tra loro
  Parametri restituiti : 0 se le due stringhe sono uguali
                         >0 se la stringa1 ha il primo carattere diverso più grande
                         <0 se la stringa2 ha il primo carattere diverso più grande

4. strstr - Ricerca di stringa all'interno di un'altra stringa
``` bash
char *strstr(const char *Pagliaio,const char *Ago)
```

  Parametri attesi : la PRIMA stringa è quella in cui cercare la SECONDA stringa passata
  Parametri restituiti : puntatore al punto della PRIMA stringa passata, dove inzia l'occorrenza della seconda.

5. strcasestr - Uguale a strstr ma case insensitive

# Libreria <ctype.h>

## Intestazione della libreria
Includere la libreria :
``` bash
#include <ctype.h>
```

## Funzioni Utili

1. toupper - Converti in maiuscolo
``` bash
int toupper(int Lettera)
```

2. tolower - Converti in minuscolo
``` bash
int tolower(int Lettera)
```
