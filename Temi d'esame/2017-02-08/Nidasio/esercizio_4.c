#include <stdio.h>

#define N 3
#define TRUE 1
#define FALSE 0

typedef int Boolean;
typedef int Matrice[N][N];

Boolean controllaSimmetria(Matrice matrice, int i);

int main()
{
    Matrice matrice = {
        {1, 2, 3},
        {2, 4, 5},
        {3, 5, 6}
    };

    Boolean simmetrica = controllaSimmetria(matrice, 0);

    if(simmetrica) printf("La metrice è simmetrica\n");
    else printf("La matrice non è simmetrica\n");
    
    return 0;
}

Boolean controllaSimmetria(Matrice matrice, int i)
{
    int j;

    // Se siamo arrivati alla fine dell'array restituisco true
    if (i == N)
        return TRUE;

    // Controllo la i-esima riga e la i-esima colonna partendo alla i esima posizione e poi passo alla successiva
    for (j = i; j < N; j++)
        if (matrice[j][i] != matrice[i][j])
            return FALSE;

    return controllaSimmetria(matrice, ++i);
}