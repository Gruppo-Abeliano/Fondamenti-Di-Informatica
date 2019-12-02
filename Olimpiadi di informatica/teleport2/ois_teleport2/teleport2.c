/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>
#include <math.h>

// input data
int T, i;
int Xa, Ya, Xb, Yb, Xc, Yc, R;

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &T));
    for(i=0; i<T; i++) {
        assert(7 == scanf("%d %d %d %d %d %d %d",
                    &Xa, &Ya, &Xb, &Yb, &Xc, &Yc, &R));

        // insert your code here

        double result = 1.54368512435;

        // print result (round down and print six decimals)
        // DO NOT EDIT!
        result = floor(result * 1000000) / 1000000;
        printf("%.6f\n", result);
    }
    return 0;
}
