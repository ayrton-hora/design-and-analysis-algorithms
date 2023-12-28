#include <stdbool.h>
#include <stdio.h>
#include <math.h>

void heapPermute(int n, int A[], int sizeA);
int stepForwardFactorial(int n);

int main() {
    int n = 0;
    printf("Heap's Alghorithm to generating permutations\n\n"); 
    while (n <= 0) {
        printf("Please insert a non-zero positive integer value: ");
        scanf("%d", &n);
    }
    printf("\n");

    int A[n];
    for (int i = 0; i < n; i++) A[i] = i + 1;

    printf("Permutations:\n");
    heapPermute(n, A, n);
    printf("\nTotal: %d\n\n", stepForwardFactorial(n));

    return 0;
}

void heapPermute(int n, int A[], int sizeA) {
    if (n == 1) {
        for (int i = 0; i < sizeA - 1; i++) printf("%d ", A[i]);
        printf("%d\n", A[sizeA - 1]);
    }

    else {
        for (int i = 0; i < n; i++) {
            heapPermute(n - 1, A, sizeA);
            int temp = A[n - 1];

            // Verify if n is odd
            if (!(n % 2 == 0)) {
                A[n - 1] = A[0];
                A[0] = temp;
            }
            // Otherwise, n is even
            else {
                A[n - 1] = A[i];
                A[i] = temp;
            }
        }
    }
}

int stepForwardFactorial(int n) {
    int x = 1;
    int fact = 1;

    while (x <= n) {
        fact = fact * x;
        x++;
    }

    return fact;
}