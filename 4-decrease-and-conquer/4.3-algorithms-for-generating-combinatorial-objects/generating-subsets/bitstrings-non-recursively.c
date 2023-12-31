#include <stdbool.h>
#include <stdio.h>
#include <math.h>

void bitStringsRec(int n);

int main() {
    int n = 0;
    printf("BitString's Non Recursively Alghorithm to generate subsets on bitstring representation\n\n"); 
    while (n <= 0) {
        printf("Please insert a non-zero positive integer value: ");
        scanf("%d", &n);
    }
    printf("\n");

    printf("Subsets:\n");
    bitStringsRec(n);
    printf("\nTotal: %.0f\n\n", pow(2, n));

    return 0;
}

void bitStringsRec(int n) {
    int B[n];
    for (int i = 0; i < n; i++) B[i] = 0;

    int k = -1;
    do
    {
        for (int i = 0; i < n - 1; i++) printf("%d ", B[i]);
        printf("%d\n", B[n - 1]);

        k = n - 1;

        while (k >= 0 && B[k] == 1) k--;

        if (k >= 0) {
            B[k] = 1;
            for (int i = k + 1; i < n; i++) B[i] = 0;
        }

    } while (k != -1);
}