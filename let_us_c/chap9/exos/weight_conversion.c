/* Weight conversion program */
#include <stdio.h>
void convert(float, float *, float *, float *);
int main() {
    float kg, gm, ton, pound;
    printf("\nEnter weight in Kilograms: ");
    scanf("%f", &kg);
    convert(kg, &gm, &ton, &pound);
    printf("Kg = %f\n", kg);
    printf("Gm = %f Tonne = %f Pounds = %f\n", gm, ton, pound);
    return 0;
}

void convert(float kg, float *g, float *t, float *p) {
    *g = kg * 1000;
    *t = kg * 0.001;
    *p = kg * 2.204;
}

