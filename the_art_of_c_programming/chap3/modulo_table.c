#include <stdio.h>

// Function to print addition table for a given n
void print_addition_table(int n) {
    printf("Addition Table modulo %d:\n", n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", (i + j) % n);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print multiplication table for a given n
void print_multiplication_table(int n) {
    printf("Multiplication Table modulo %d:\n", n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", (i * j) % n);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    for (int n = 1; n <= 10; n++) {
        print_addition_table(n);
        print_multiplication_table(n);
    }
    return 0;
}

