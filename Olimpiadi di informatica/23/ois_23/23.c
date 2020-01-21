/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>

// constraints
#define MAXT 10000

// input data
int T, i;
int N[MAXT];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &T));
    for(i=0; i<T; i++) {
        assert(1 == scanf("%d", &N[i]));

        // insert your code here
    
        printf("%d ", 42); // print the result
    }
    printf("\n");
    return 0;
}
