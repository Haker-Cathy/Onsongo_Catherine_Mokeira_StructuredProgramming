#include <stdio.h>

int main(){
    int n,i;
    int arr[n];
    int sum = 0;

    printf("Insert the number or elements to be stored in the array: \n");
    scanf("%d", &n);

    printf("Enter the elements in the array: \n");
    for(i = 0; i < n; i++){
        printf("Element - %d: " , i);
        scanf("%d", &arr[i]);
    }
// to sum up the elements i the array

    for(i = 0; i < n; i++){
        sum = sum + arr[i];
    }
    printf("The sum of the elements in the array is = %d\n", sum);

    return 0;

}
