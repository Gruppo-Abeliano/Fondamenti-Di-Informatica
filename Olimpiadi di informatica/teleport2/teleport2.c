#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

// input data
int T, i;
int Xa, Ya, Xb, Yb, Xc, Yc, R;

double calcolaPercorsoConLetto();

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("ois_teleport2/input0.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &T));
    for(i=0; i<T; i++) {
        assert(7 == scanf("%d %d %d %d %d %d %d",
                    &Xa, &Ya, &Xb, &Yb, &Xc, &Yc, &R));

        // Calcolo due percorsi: quello tra un insetto e l'altro e quello passando per il letto
        double percorsoDiretto = sqrt(pow(abs(Xa - Xb), 2) + pow(abs(Ya - Yb), 2));
        double percorsoConLetto = calcolaPercorsoConLetto();

        // Il risultato sarà il percorso con la lunghezza (rumore) minore
        double result = fmin(percorsoDiretto, percorsoConLetto);

        // print result (round down and print six decimals)
        // DO NOT EDIT!
        result = floor(result * 1000000) / 1000000;
        printf("%.6f\n", result);
    }
    return 0;
}

double calcolaPercorsoConLetto() {
    double percorsoA_C = sqrt(pow(abs(Xa - Xc), 2) + pow(abs(Ya - Yc), 2));
    double percorsoB_C = sqrt(pow(abs(Xb - Xc), 2) + pow(abs(Yb - Yc), 2));

    double percorsoA_Cerchio = fmax(percorsoA_C - R, 0);
    double percorsoB_Cerchio = fmax(percorsoB_C - R, 0);

    return percorsoA_Cerchio + percorsoB_Cerchio;
}