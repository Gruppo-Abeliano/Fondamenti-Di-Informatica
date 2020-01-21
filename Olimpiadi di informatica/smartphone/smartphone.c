#include <assert.h>
#include <stdio.h>

#define MAXN 1000000

// input data
int N;
int P[MAXN];

int main()
{
    //  uncomment the following lines if you want to read/write from files
    //  freopen("ois_smartphone/input1.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for (int i = 0; i < N; i++)
        assert(1 == scanf("%d", &P[i]));

    int costoMassimoIncontrato = 0;
    long long spesaTotale = 0;

    for (int i = 0; i < N; i++)
    {
        if (P[i] > costoMassimoIncontrato)
        {
            costoMassimoIncontrato = P[i];
            spesaTotale += costoMassimoIncontrato;
        }
    }

    // insert your code here
    long long res = spesaTotale;

    printf("%lld\n", res); // print the result
    return 0;
}
