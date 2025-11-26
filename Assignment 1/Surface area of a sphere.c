#include <stdio.h>
#define PI 3.14159265358979323846

int main() {
    double r;
    printf("Enter radius of the sphere: ");

    if (scanf("%lf", &r) != 1 || r < 0) {
        printf("Invalid radius\n");
        return 1;
    }

    double area = 4.0 * PI * r * r;
    printf("Surface area: %6.6g\n", area);
    return 0;
}
