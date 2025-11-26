#include<stdio.h>

int main(){
    double num1, num2;

    printf("Enter two numbers separated by space: ");
    if (scanf("%lf %lf", &num2, &num2)!= 2) {
        printf("Invalid input\n");
        return 1;
    }

    printf("Addition (%.6g + %.6g) =%.6g\n", num1, num2, num1 + num2);
    printf("Subtraction (%.6g - %.6g) = %.6g\n", num1, num2, num1 - num2);
    printf("Multiplication (%.6g * %.6g) = %.6g\n", num1, num2, num1 * num2);
    if (num2 != 0){
        printf("Division (%.6g / %.6g) = %.6g\n", num1, num2, num1 / num2);
    } else {
        printf("Division: Cannot divide by zero.\n");
    }

    //modulus requires operands
    int int_num1 = (int)num1;
    int int_num2 = (int)num2;

    if (int_num2 != 0) {
        printf("modulus (on integers %d %% %d) =%d\n",int_num1, int_num2, int_num1 % int_num2);
    } else {
        printf("Modulus: Cannot perform modulus with zero divisor.\n");
    }

    return 0;
}


