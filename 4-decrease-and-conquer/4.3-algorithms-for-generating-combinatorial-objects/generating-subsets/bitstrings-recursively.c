#include <stdbool.h>
#include <stdio.h>
#include <math.h>

void bitStringsRec(int n, int B[], int bSize);

int main() {
    int n = 0;
    printf("BitString's Recursively Alghorithm to generate subsets on bitstring representation\n\n"); 
    while (n <= 0) {
        printf("Please insert a non-zero positive integer value: ");
        scanf("%d", &n);
    }
    printf("\n");
    
    int B[n];
    for (int i = 0; i < n; i++) B[i] = 0;

    printf("Subsets:\n");
    bitStringsRec(n, B, n);
    printf("\nTotal: %.0f\n\n", pow(2, n));

    return 0;
}

void bitStringsRec(int n, int B[], int bSize) {
    if (n == 0) {
        for (int i = 0; i < bSize - 1; i++) printf("%d ", B[i]);
        printf("%d\n", B[bSize - 1]);
    }

    else {
        B[n - 1] = 0; bitStringsRec(n - 1, B, bSize);
        B[n - 1] = 1; bitStringsRec(n - 1, B, bSize);
    }
}