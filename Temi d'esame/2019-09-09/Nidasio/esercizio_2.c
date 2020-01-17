#include <stdio.h>
#include <stdbool.h>

#define N_CARATTERI 10000

typedef char Testo[N_CARATTERI];

bool controllaIniziali(Testo testo);

int main()
{
    Testo testo = "matteo mammaABCDEmela+-*/malvagio";

    bool check = controllaIniziali(testo);

    if (check)
        printf("Tutte le parole nel testo hanno la stessa iniziale\n");
    else
        printf("Non tutte le parole nel testo hanno la stessa iniziale\n");

    return 0;
}

bool controllaIniziali(Testo testo)
{
    char carattereIniziale = 0; // Imposto l'iniziale a 0 per indicare che non è ancora stata impostata
    bool iniziale = false;
    int i;

    // Cerco le iniziali
    for (i = 0; testo[i] != '\0'; i++)
    {
        if (testo[i] >= 'a' && testo[i] <= 'z')
        {
            if (!iniziale)
            {
                // Se il carattere attuale è l'iniziale di una parola allora la controllo
                if (!carattereIniziale)
                    carattereIniziale = testo[i];
                else if (carattereIniziale != testo[i])
                    return false;
                iniziale = true;
            }
        }
        else
        {
            iniziale = false;
        }
    }

    return true;
}