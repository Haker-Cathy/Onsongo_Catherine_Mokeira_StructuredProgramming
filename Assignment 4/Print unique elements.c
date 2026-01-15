#include <stdio.h>

int main() {
    int n, i, j, count;
    int arr[n];

    printf("Insert the number of elements to be stored in the array: \n");
    scanf("%d", &n);

    printf("Enter %d elements in the array: \n", n);
    for (i = 0; i < n; i++){
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }
//printing the unique elements....
    printf("\nThe unique elements found in the array are: ");
    for (i = 0; i < n; i++) {
        count = 0;
        for (j = 0; j < n; j++) {
            if (arr[i] == arr[j] && i != j) {
                count++;
                break;
            }
        }
        if (count == 0) {
            printf("%d ", arr[i]);
        }
    }
    return 0;
}

