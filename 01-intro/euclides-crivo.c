#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int * crivo(int n); 

int main() {
    int n;
    printf("Insert a positive integer value: "); scanf("%d", &n);

    if (n < 1) {
        printf("The input value must be a positive integer\n");
        return 1;
    }

    int * L = crivo(n);

    for (int i = 0; i < n; i++) {
        printf("L[%d] = %d\n", i, *(L + i));
    }
    printf("\n");

    free(L);

    return 0;
}

int * crivo(int n) {
    int A[n - 2];

    for (int p = 2; p < n; p++) {
        A[p] = p;
    }

    int j;
    int inferiorLimit = floor(sqrt(n));
    printf(">> %d\n", inferiorLimit);

    for (int p = 2; p < inferiorLimit; p++) {
        if (A[p] != 0) {
          j = p * p;
          while (j <= n) {
            A[j] = 0;
            j += p;
          }  
        }
    }

    int i = 0;
    int * L = malloc(n - 2);
    for (int p = 2; p < n; p++) {
        if (A[p] != 0) {
            L[i] = A[p];
            i++;
        }
    }

    return L;
}
