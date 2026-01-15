#include <stdio.h>

int main() {
    int n, i;
    int Maximum, Minimum;
    int arr[n];

    printf("Insert the number of elements to be stored in the array : ");
    scanf("%d", &n);

    printf("Enter %d elements in the array :\n", n);
    for (i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }
//finding the maximum and minimum elements in the array
    Minimum = arr[0];
    Maximum = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > Maximum) {
            Maximum = arr[i];
        }
        if (arr[i] < Minimum) {
            Minimum = arr[i];
        }
    }

    printf("\nMaximum element is : %d\n", Maximum);
    printf("Minimum element is : %d\n", Minimum);

    return 0;
}
