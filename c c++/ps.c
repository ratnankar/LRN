#include <stdio.h>

int main() {
    int *p;
    char *c;
    float *f;
    double *d;

    printf("Size of int pointer: %zu\n", sizeof(p));
    printf("Size of char pointer: %zu\n", sizeof(c));
    printf("Size of float pointer: %zu\n", sizeof(f));
    printf("Size of double pointer: %zu\n", sizeof(d));

    return 0;
}
