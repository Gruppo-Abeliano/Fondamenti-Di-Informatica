#include <stdio.h>

typedef struct {
    int valore;
} Test;

void modificaValore(Test *daModificare, int valore);

int main() {
    Test test = {
        .valore = 0,
    };

    printf("Valore: %d\n", test.valore);

    modificaValore(&test, 42);

    printf("Valore: %d\n", test.valore);

    return 0;
}

void modificaValore(Test *daModificare, int valore) {
    daModificare->valore = valore;
}
