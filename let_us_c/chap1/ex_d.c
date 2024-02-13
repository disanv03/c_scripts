/* Conversion of temperature from Fahrenheit to Centigrade degrees */
#include<stdio.h>

int main() {
    float fr, cent;
    printf("\nEnter the temperature (F):");
    scanf("%f", &fr);

    cent = 5.0 / 9.0 * (fr - 32);
    printf("Temperature in centigrade = %f\n", cent);
    return 0;
}

