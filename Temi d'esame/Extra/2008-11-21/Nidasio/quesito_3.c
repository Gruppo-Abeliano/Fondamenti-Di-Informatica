#include <stdio.h>
#include <string.h>

#define MAX_TITOLO 30
#define MAX_TESTO 500
#define MAX_AUTORE 50
#define ARTICOLI_PRESENTI 2 // 50
#define SOGLIA_CARATTERI 20 // 1000
#define COLONNE 2

typedef struct
{
    char titolo[MAX_TITOLO + 1];
    char testo[MAX_TESTO + 1];
    char autore[MAX_AUTORE + 1];
    int pagina;
    int colonna;
} Articolo;

void inserisciArticolo(Articolo *articolo);

int main()
{
    Articolo articoli[ARTICOLI_PRESENTI];
    int i, j;
    int pagina;
    int caratteriColonne[COLONNE] = {0};
    int tmp;

    // Leggo gli articoli
    for (i = 0; i < ARTICOLI_PRESENTI; i++)
        inserisciArticolo(&articoli[i]);

    // Chiedo il numero di una pagina
    printf("Inserisci il numero di una pagina: ");
    scanf("%d", &pagina);

    //1: Cerco gli articoli presenti nella pagina specificata e conto il testo complessivo degli articoli
    for (i = 0; i < ARTICOLI_PRESENTI; i++)
    {
        if (articoli[i].pagina == pagina)
        {
            tmp = 0;

            // Conto i caratteri dell'articolo
            tmp += strlen(articoli[i].titolo);
            tmp += strlen(articoli[i].testo);
            tmp += strlen(articoli[i].autore);

            caratteriColonne[articoli[i].colonna] += tmp;
            printf("Hey %d\n", caratteriColonne[articoli[i].colonna]);
        }
    }

    //2: Per le colonne con un numero di caratteri che supera la soglia mostro le informazioni
    for (i = 0; i < ARTICOLI_PRESENTI; i++)
    {
        if (articoli[i].pagina == pagina)
        {
            for (j = 0; j < COLONNE; j++)
            {
                if (caratteriColonne[j] > 0 && articoli[i].colonna == j)
                {
                    printf("Articolo a pagina %d, colonna %d:\n", pagina, j);
                    printf("Titolo %s\n", articoli[i].titolo);
                    printf("Autore %s\n", articoli[i].autore);
                    printf("Testo %s\n", articoli[i].testo);
                }
            }
        }
    }

    return 0;
}

void inserisciArticolo(Articolo *articolo)
{
    printf("Inserisci il titolo dell'articolo: ");
    gets(articolo->titolo);
    printf("Inserisci il testo dell'articolo: ");
    gets(articolo->testo);
    printf("Inserisci l'autore dell'articolo: ");
    gets(articolo->autore);
    printf("Inserisci la pagina dell'articolo: ");
    scanf("%d", &articolo->pagina);
    printf("Inserisci la colonna dell'articolo: ");
    scanf("%d", &articolo->colonna);
}