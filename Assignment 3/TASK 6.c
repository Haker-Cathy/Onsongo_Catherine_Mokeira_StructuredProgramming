#include <stdio.h>

void incrementByValue(int x) {
    x = x + 1;
}

void incrementByReference(int *x) {
    *x = *x + 1;
}

int main() {
    int num = 10;

    printf("Initial value of num: %d\n", num);

    incrementByValue(num);
    printf("After incrementByValue call: %d\n", num);

    incrementByReference(&num);
    printf("After incrementByReference call: %d\n", num);

    return 0;
}

