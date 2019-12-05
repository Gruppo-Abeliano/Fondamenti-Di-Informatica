#include <stdio.h>
#include <stdlib.h>

int main()
{
    freopen("ois_23/input1.txt", "w", stdout);

    printf("%d\n%d", 10000, 100000000);

    for (int i = 1; i < 100000; i++)
        printf(" %d", 100000000 - i);

    printf("\n");
}