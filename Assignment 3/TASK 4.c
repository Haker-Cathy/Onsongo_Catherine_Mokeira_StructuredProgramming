#include <stdio.h>

int main() {
    int num1 = 5;
    int num2 = 7;
    int *ptr1;
    int *ptr2;

    ptr1 = &num1;
    ptr2 = &num2;

    int sum;
    sum = *ptr1 + *ptr2;

    printf("Sum of num1 and num2: %d\n", sum);

    return 0;
}

