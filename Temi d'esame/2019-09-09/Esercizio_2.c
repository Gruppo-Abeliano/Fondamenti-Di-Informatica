#include <stdio.h>

#define MAX_CARATTERI 10

typedef char Testo[MAX_CARATTERI];

int cercaInTesto(Testo testo);

int main(int argc, char const *argv[]) {
  Testo testo = {'5','r','l','a','4','5','r','4','R','r'};

  printf("%d",cercaInTesto(testo));
  return 0;
}

int cercaInTesto(Testo testo)
{
  char carattereInizioParola;
  int scorriArray;

  /*
    Scorro l'array presupponendo che tutte le parole inizino con il medesimo carattere minuscolo.
    Quindi setto carattereDiverso = 0. Inizializzo inoltre carattereInizioParola ad un valore standard,
    per poi sovrascriverlo con il primo carattere minuscolo utile.
  */
  scorriArray = 0;
  carattereInizioParola = '/';
  while(scorriArray < MAX_CARATTERI-1)
  {
    /*
      Inizializzo il carattere da controllare.
    */
    if((testo[scorriArray] >= 'a' && testo[scorriArray] <= 'z') && carattereInizioParola == '/')
    {
      carattereInizioParola = testo[scorriArray];
      ++scorriArray;
    }
    /*
      Se sono all'interno della parola, non devo fare nulla, semplicemente avanzare.
    */
    else if(testo[scorriArray] >= 'a' && testo[scorriArray] <= 'z') scorriArray++;
    /*
      Se il testo dovesse iniziare con caratteri speciali, devo essere sicuro di inizializzare il
      carattere di controllo, quindi se esso non è effettivamente inizializzato lo faccio con il
      primo carattere utile.

      Altrimenti controllo, essendo fuori dalla parola, se il carattere immediatamente successivo è
      un carattere minuscolo, e se lo è lo confronto con il carattere di controllo :
          1) se sono diversi interrompo la funzione restituendo 0, perchè vorrebbe dire che c'è
          una parola che non inizia con lo stesso carattere minuscolo delle altre.
          2) se sono uguali proseguo.
    */
    else {
      if(testo[scorriArray+1] >= 'a' && testo[scorriArray+1] <= 'z')
      {
        if(carattereInizioParola == '/') carattereInizioParola = testo[scorriArray+1];
        if(testo[scorriArray+1] != carattereInizioParola) return 0;
      }
      ++scorriArray;
    }
  }

  return 1;
}
